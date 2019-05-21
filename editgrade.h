void edit_grade(int class_id, int aid, char * social, int grade)
{
    int point_val = 0;

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
        printf("Point must be between 0 and 100 \n");
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

    FILE *fp;
    struct grades data;
    int counter = 0;
    int found = 0;
    char ssn[9];

    memcpy(ssn, social, 9);

    fp = fopen("grades.db", "r+");

    if(fp == NULL)
    {
        printf("\n Error: Cannot open file");
        exit(1);
    }

    while(fread(&data, sizeof(struct grades), 1, fp))
    {
        if (data.aid == aid  && strncmp(data.ssn, ssn, 9) == 0)
        {
            found = 1;
            break;
        }
        counter++; 
    }

    if(! found)
    {
        printf("Given data not found in the Grades Database\n");
        fclose(fp);
        return;
    }

    else
    {
        fseek(fp, counter*sizeof(struct grades), SEEK_SET);

        fread(&data, sizeof(struct grades), 1, fp);

        data.grade = grade;
        fseek(fp, counter*sizeof(struct grades), SEEK_SET);
        fwrite (&data, sizeof(struct grades), 1, fp); 
        printf("Grade changed in the database\n\n");
        fclose(fp);
    }


}

void edit_grade_menu()
{
    int class_id;
    int check = 0;
    int aid;
    char ssn[11];
    char grade[10];
    int point;

    printf("Enter Class ID or (-1 for Class List): ");
    scanf("%d", &class_id);
    clear_buffer();
    if(class_id == -1)
    {
        view_class();
        edit_grade_menu();
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

    printf("Enter New Earned Point (or leave blank for no change): ");
    fgets(grade, 10, stdin);
    if(grade[0] == '\n')
    {
        printf("Grade not changed\n");
        return;
    }
    else
    {
        point = atoi(grade);
    }

    edit_grade(class_id,  aid, ssn, point);
    
}
