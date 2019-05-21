void enroll_student(int class_id, char * social)
{
    if(! check_valid_class_id(class_id))
    {
        printf("Not a valid class Id\n");
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
    struct enrollment data;

    

    fp = fopen("enrollment.db", "a");
    if(fp == NULL)
    {
        printf("\n Error: Cannot Open Enrollment File");
        exit(1);
    }
    data.class_id = class_id;
    memcpy(data.ssn, ssn, 9);

    fwrite (&data, sizeof(struct enrollment), 1, fp); 
    printf("Students successsfully enrolled to the class!\n"); 
    fclose(fp);
}

void enroll_student_menu()
{
    int class_id;
    char ssn[12];

    printf("Enter Class ID or (-1 for Class List): ");
    scanf("%d", &class_id);
    clear_buffer();
    if(class_id == -1)
    {
        view_class();
        enroll_student_menu();
        return;
        
    }

    printf("Enter SSN: ");
    fgets(ssn, 12, stdin);
    if(strlen(ssn) > 10)
    {
        printf("SSN should have 9 characters\n");
        return;
    }

    else if(strlen(ssn) < 10)
    {
        printf("SSN should have 9 characters\n");
        return;
    }

    else
    {
        delete_endline_ssn(ssn);
    }


    enroll_student(class_id, ssn);
}
