void add_student(struct student data)
{
    if(strlen(data.fname) < 2)
    {
        printf("First Name should be atleast two character \n\n");
        return;
    }


    if(strlen(data.lname) < 2)
    {
        printf("Last Name should be atleast two character \n\n");
        return;
    }

    if(strlen(data.ssn) != 9)
    {
        printf("Social Security Should have 9 characters \n\n");
        return;
    }

    FILE *fp;

    fp = fopen("students.db", "a");
    if(fp == NULL)
    {
        printf("\n Error: Cannot Open File");
        exit(1);
    }

    fwrite (&data, sizeof(struct student), 1, fp); 
    printf("Students successsfully added to database!\n"); 
    fclose(fp);
}

void get_student_data_menu()
{
    struct student data;

    printf("Enter First Name: ");
    scanf("%s", data.fname);
    clear_buffer();

    printf("\nEnter Last Name: ");
    scanf("%s", data.lname);

    printf("\n Enter SSN: ");
    scanf("%s", data.ssn);

    add_student(data);

}
