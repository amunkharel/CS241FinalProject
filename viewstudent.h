void view_student_data_menu()
{
    FILE *fp;
    
    struct student data;
    fp = fopen("student.db", "r");

    if(fp == NULL)
    {
        printf("\n Error: Cannot open file");
        exit(1);
    }
    printf("\n\nStudents in the database\n");
    while(fread(&data, sizeof(struct student), 1, fp))
    {
        printf("\nFirst name: %s, Last name = %s, ssn = %s \n", data.fname, data.lname, data.ssn);
    }

    printf("\n\n");
}