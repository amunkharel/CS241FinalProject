void edit_student(char *first, char *last, char *social)
{
    FILE *fp;
    struct student data; 
    int counter = 0;
    int found = 0;

    fp = fopen("student.db", "r+");
    
    if(fp == NULL)
    {
        printf("\n Error: Cannot open file");
        exit(1);
    }

    while(fread(&data, sizeof(struct student), 1, fp))
    {
        if (strcmp(data.ssn,social) == 0)
        {
            found = 1;
            break;
        }
        counter++;
    }

    fseek(fp, counter*sizeof(struct student), SEEK_SET);

    if(! found)
    {
        printf("SSN not found in the database\n");
        return;
    }
    else
    {
        printf("SSN found\n");
    }
}

void edit_student_data_menu()
{
   struct student data;
   char social[10];
   char first[30];
   char last[30];

    printf("\n Enter SSN: ");
    fgets(social, 10, stdin);
    if(social[0] == '\n')
    {
        strcpy(social, "NULL");
    }

    printf("Enter new First Name (or leave blank for no change): ");
    fgets(first, 30, stdin);
    if(first[0] == '\n')
    {
        strcpy(first, "NULL");
    }
    

    printf("\nEnter new Last Name (or leave blank for no change): ");
    fgets(last, 30, stdin);
    if(last[0] == '\n')
    {
        strcpy(first, "NULL");
    }

    edit_student(first, last, social);
}