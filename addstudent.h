
void clear_buffer1() { while( getchar() != '\n' ) {} }



void add_student(struct student data)
{
    FILE *fp;

    fp = fopen("student.db", "a");
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
