void view_student_data_menu()
{
    FILE *fp;
    
    struct student data;
    fp = fopen("students.db", "r");

    if(fp == NULL)
    {
        printf("\n Error: Cannot open file");
        exit(1);
    }
    printf("\n\nStudents in the database\n");
    while(fread(&data, sizeof(struct student), 1, fp))
    {
        int i = 0;

        printf("First Name: ");
        for (i = 0; i < 30; i++)
        {
            printf("%c", data.fname[i]);
        }

        printf(", Last Name: ");
        for (i = 0; i < 30; i++)
        {
            printf("%c", data.lname[i]);
        }

        printf(", SSN: ");
        for (i = 0; i < 9; i++)
        {
            printf("%c", data.ssn[i]);
        }

        
        printf("\n");
    }
    fclose(fp);
    printf("\n\n");
}
