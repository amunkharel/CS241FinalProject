int check_cid_aid_match(int class_id, int aid)
{
    FILE *fp;
    struct assignment data;
    fp = fopen("assignments.db", "r");

    if(fp == NULL)
    {
        printf("\n Assignment DB not found");
        exit(1);
    }

    while(fread(&data, sizeof(struct assignment), 1, fp))
    {
        if (data.class_id == class_id && data.id == aid)
        {  
            return 1;
        }
    }
    return 0;

}

int check_student_enrollment(int class_id, char * ssn)
{
    FILE *fp;
    struct enrollment data;
    fp = fopen("enrollment.db", "r");

    if(fp == NULL)
    {
        printf("\n Enrollment DB not found");
        exit(1);
    }

    while(fread(&data, sizeof(struct enrollment), 1, fp))
    {
        if (data.class_id == class_id && strncmp(data.ssn, ssn,9) == 0)
        {  
            return 1;
        }
    }
    return 0;
}

int check_valid_ssn(char * ssn)
{
    FILE *fp;
    struct student data;
    fp = fopen("students.db", "r");

    if(fp == NULL)
    {
        printf("\n Class DB not found");
        exit(1);
    }

    while(fread(&data, sizeof(struct student), 1, fp))
    {
        if (strncmp(data.ssn, ssn,9) == 0)
        {  
            return 1;
        }
    }

    return 0;
}

void add_grade(int class_id, int aid, char * social, int grade)
{

    if(! check_student_enrollment(class_id, social))
    {
        printf("Student Not enrolled in the class_id given\n\n");
        return;
    }

    if(! check_valid_class_id(class_id))
    {
        printf("Not a valid class Id\n");
        return;
    }


    if(! check_valid_assignment_id(aid))
    {
        printf("Not a valid Assignment Id\n");
        return;
    }



    if(! check_cid_aid_match(class_id, aid))
    {
        printf("Class Id and Assignment Id do not match\n");
        return;
    }


    if(grade < 0 || grade > 100)
    {
        printf("Grade must be between 0 and 100 \n");
        return;
    }

    if(strlen(social) != 9)
    {
        printf("SSN must be 9 characters long\n");
        return;
    }


    if(! check_valid_ssn(social))
    {
        printf("Please enter SSN of a student in the database\n");
        return;
    }

    char ssn[9];

    memcpy(ssn, social, 9);

    FILE *fp;
    struct grades data;
    fp = fopen("grades.db", "a");

    if(fp == NULL)
    {
        printf("\n Error: Cannot Open File");
        exit(1);
    }

    memcpy(data.ssn, ssn, 9);
    data.grade = grade;
    data.aid = aid;
    fwrite (&data, sizeof(struct grades), 1, fp); 
    printf("Grade added successfully\n\n");

    fclose(fp);

}

void add_grade_menu()
{
    int class_id;
    int aid;
    int check = 0;
    char ssn[11];
    int point;

    printf("Enter Class ID or (-1 for Class List): ");
    scanf("%d", &class_id);
    clear_buffer();
    if(class_id == -1)
    {
        view_class();
        add_grade_menu();
        return;
        
    }

    while(check != 1)
    {
        printf("Enter Assignment ID or (-1 for Assignment List): ");
        scanf("%d", &aid);
        clear_buffer();
        if(aid != -1)
        {
            check = 1;
        }
        else
        {
            view_assignment();
        }
    }

    printf("\nEnter Student SSN: ");
    fgets(ssn,11, stdin);
    delete_endline(ssn);

    printf("Enter Earned Point: ");
    scanf("%d", &point);
    getchar();

    add_grade(class_id, aid,  ssn, point);
}
