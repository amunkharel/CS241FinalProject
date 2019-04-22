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

    if(! found)
    {
        printf("SSN not found in the database\n");
        fclose(fp);
        return;
    }
    else
    {
        fseek(fp, counter*sizeof(struct student), SEEK_SET);

        fread(&data, sizeof(struct student), 1, fp);

        if (strcmp(first,"NULL") == 0 && strcmp(last,"NULL") == 0 )
        {
            printf("Nothing in the database changed\n\n");
            fclose(fp);
            return;
        }
        else if (strcmp(first,"NULL") == 0)
        {
            memcpy(data.lname, last, strlen(last)+1);
            fseek(fp, counter*sizeof(struct student), SEEK_SET);
            fwrite (&data, sizeof(struct student), 1, fp); 
            printf("Last Name in the database changed\n\n");
        }
        else if (strcmp(last,"NULL") == 0)
        {
            memcpy(data.fname, first, strlen(first)+1);
            fseek(fp, counter*sizeof(struct student), SEEK_SET);
            fwrite (&data, sizeof(struct student), 1, fp); 
            printf("First Name in the database changed\n\n");

        }
        else
        {
            memcpy(data.lname, last, strlen(last)+1);
            memcpy(data.fname, first, strlen(first)+1);
            fseek(fp, counter*sizeof(struct student), SEEK_SET);
            fwrite (&data, sizeof(struct student), 1, fp); 
            printf("Both first Name and last Name database changed\n\n");
        }
        fclose(fp);

        
    }
}

void delete_endline(char * input)
{
    int i;
    int length = strlen(input);
    input[length - 1] = '\0';
}

void edit_student_data_menu()
{
   char social[10];
   char first[30];
   char last[30];

    printf("\nEnter SSN: ");
    fgets(social, 10, stdin);
    if(social[0] == '\n')
    {
        strcpy(social, "NULL");
    }

    if(strlen(social) != 9)
    {
        printf("Please enter social security number of 9 characters\n");
        return;
    }
    else
    {
        getchar();
    }
    
    printf("\nEnter new First Name (or leave blank for no change): ");
    fgets(first, 30, stdin);

    if(first[0] == '\n')
    {
        strcpy(first, "NULL");
    }
    else
    {
        delete_endline(first);
    }
    

    printf("\nEnter new Last Name (or leave blank for no change): ");
    fgets(last, 30, stdin);

    if(last[0] == '\n')
    {
        strcpy(last, "NULL");
    }
    else
    {
        delete_endline(last);
    }

    //printf(" first name %s\n, last name %s \n ssn %s \n ", first, last, social);
    //return;

    edit_student(first, last, social);
}