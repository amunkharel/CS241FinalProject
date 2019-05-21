int check_valid_ssn(char * ssn);

void view_average_class_grade(int class_id)
{
    float sum = 0;
    float average = 0;
    int counter = 0;
    if(! check_valid_class_id(class_id))
    {
        printf("Not a valid class Id\n");
        return;
    }

    FILE *fp;
    FILE *nfp;
    struct assignment data;
    fp = fopen("assignments.db", "r");

    if(fp == NULL)
    {
        printf("\n Error: Cannot open file");
        exit(1);
    }
    while(fread(&data, sizeof(struct assignment), 1, fp))
    {
        if(data.class_id == class_id)
        {
            
    
            struct grades data1;
            nfp = fopen("grades.db", "r");

            if(nfp == NULL)
            {
                printf("\n Error: Cannot open file");
                exit(1);
            }
            while(fread(&data1, sizeof(struct grades), 1, nfp))
            {
                if(data.id == data1.aid)
                {
                    sum = sum + data1.grade;
                    counter++;
                }
                
            }

        } 
    }
    if(counter == 0)
    {
        printf("Class grades not found in the database\n");
        return;
    }
    average = sum/counter;
    printf("\n\nAverage Grade of the class is %.2f\n", average);
    printf("\n\n");
            
    fp = nfp;
    fclose(fp);
    return;
}

void view_average_class_grade_menu()
{
    int class_id;

    printf("Enter Class ID or (-1 for Class List): ");
    scanf("%d", &class_id);
    clear_buffer();
    if(class_id == -1)
    {
        view_class();
        view_average_class_grade_menu();
        return;
    }
    view_average_class_grade(class_id);

}

void view_average_student_grade(char * ssn)
{
    float sum = 0;
    float average = 0;
    int counter = 0;
    if(strlen(ssn) != 9)
    {
        printf("SSN must be 9 characters long\n");
        return;
    }

    if(! check_valid_ssn(ssn))
    {
        printf("Please enter SSN of a student in the database\n");
        return;
    }

    FILE *fp;
    
    struct grades data;
    fp = fopen("grades.db", "r");

    if(fp == NULL)
    {
        printf("\n Error: Cannot open file");
        exit(1);
    }
    while(fread(&data, sizeof(struct grades), 1, fp))
    {
        if(strncmp(data.ssn, ssn,9) == 0)
        {
            sum = sum + data.grade;
            counter++;
        }
        
    }

    if(counter == 0)
    {
        printf("Given Student grade not found in the db\n\n");
        return;
    }
    average = sum/counter;
    printf("\n\nAverage Grade of the student is %.2f\n", average);
    printf("\n\n");
    fclose(fp);
    return;

}


void view_average_student_grade_menu()
{
    char ssn[11];
    printf("\nEnter Student SSN: ");
    fgets(ssn,11, stdin);
    delete_endline(ssn);
    view_average_student_grade( ssn);
}

void view_average_class_assignment_grade(int  class_id, int aid)
{
    float sum = 0;
    float average = 0;
    int counter = 0;
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

    FILE *fp;
    
    struct grades data;
    fp = fopen("grades.db", "r");

    if(fp == NULL)
    {
        printf("\n Error: Cannot open file");
        exit(1);
    }
    while(fread(&data, sizeof(struct grades), 1, fp))
    {
        if(data.aid == aid)
        {
            sum = sum + data.grade;
            counter++;
        }
        
    }
    if(counter == 0)
    {
        printf("Given Assignment grade not found in the database\n\n");
        return;
    }
    average = sum/counter;
    printf("\n\nAverage Grade of assignment of the class is %.2f\n", average);
    printf("\n\n");
    fclose(fp);
    return;

}

void view_class_assignment_average_grade_menu()
{
    int check = 0;
    int class_id;
    int aid;

    printf("Enter Class ID or (-1 for Class List): ");
    scanf("%d", &class_id);
    getchar();
    if(class_id == -1)
    {
        view_class();
        view_class_assignment_average_grade_menu();
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

    view_average_class_assignment_grade(class_id, aid);

}


void view_class_assignment_grade(int  class_id, int aid)
{
    int i = 0;
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

    FILE *fp;
    
    struct grades data;
    fp = fopen("grades.db", "r");

    if(fp == NULL)
    {
        printf("\n Error: Cannot open file");
        exit(1);
    }
    while(fread(&data, sizeof(struct grades), 1, fp))
    {
        if(data.aid == aid)
        {
            printf("\n Assignment ID = %d, ", data.aid);
            printf("Student SSN = ");
            
            for ( i = 0; i < 9; i++)
            {
                printf("%c",data.ssn[i]);
            }
            printf(", Grade = %d", data.grade);
            
        }
        
    }
    printf("\n\n");
    fclose(fp);
    return;

}

void view_class_assignment_grade_menu()
{
    int check = 0;
    int class_id;
    int aid;

    printf("Enter Class ID or (-1 for Class List): ");
    scanf("%d", &class_id);
    getchar();
    if(class_id == -1)
    {
        view_class();
        view_class_assignment_grade_menu();
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

    view_class_assignment_grade(class_id, aid);
}

void view_student_class_grade_assign(char * ssn, int aid)
{
    int i = 0;

    if(! check_valid_assignment_id(aid))
    {
        printf("Not a valid Assignment Id\n");
        return;
    }


    FILE *fp;
    
    struct grades data;
    fp = fopen("grades.db", "r");

    if(fp == NULL)
    {
        printf("\n Error: Cannot open file");
        exit(1);
    }
    while(fread(&data, sizeof(struct grades), 1, fp))
    {
        if(data.aid == aid && strncmp(ssn, data.ssn, 9) == 0)
        {
            printf("\n Assignment ID = %d, ", data.aid);
            printf("Student SSN = ");
            
            for ( i = 0; i < 9; i++)
            {
                printf("%c",data.ssn[i]);
            }
            printf(", Grade = %d", data.grade);
            
        }
        
    }
    printf("\n\n");
    fclose(fp);
    return;
}
void view_student_class_grade(char * ssn, int class_id)
{
    if(strlen(ssn) != 9)
    {
        printf("SSN must be 9 characters long\n");
        return;
    }

    if(! check_valid_ssn(ssn))
    {
        printf("Please enter SSN of a student in the database\n");
        return;
    }

    if(! check_student_enrollment(class_id, ssn))
    {
        printf("Student Not enrolled in the class_id given\n\n");
        return;
    }

    FILE *fp;
    struct assignment data;
    fp = fopen("assignments.db", "r");

    if(fp == NULL)
    {
        printf("\n Error: Cannot open file");
        exit(1);
    }

    while(fread(&data, sizeof(struct assignment), 1, fp))
    {
        if (data.class_id == class_id)
        {
            view_student_class_grade_assign(ssn, data.id);
        }
    }
    fclose(fp);

}
