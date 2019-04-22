void delete_student(char *social)
{
    FILE *fp;
    
    struct student data;
    int counter = 0;
    int found = 0;
    int response;
    fp = fopen("student.db", "r");

    

    if(fp == NULL)
    {
        printf("\n Error: Cannot open file");
        exit(1);
    }

    while(fread(&data, sizeof(struct student), 1, fp))
    {
        printf("first = %s , last = %s, ssn = %s \n\n", data.fname, data.lname, data.ssn);
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
        found = 0;
        fseek(fp, counter*sizeof(struct student), SEEK_SET);
        fread(&data, sizeof(struct student), 1, fp);
        
        printf("Are you sure you want to delete First Name = %s , Last Name = %s , ssn = %s from the database [Y/N]: ", data.fname, data.lname, data.ssn);
        rewind(fp);
        response = getchar();

        if(response == 'Y')
        {
            FILE *fp_tmp;
            fp_tmp = fopen("tmp.db", "w");
            if(fp_tmp == NULL)
            {
                printf("\n Error: Cannot open file");
                exit(1);
            } 
            while (fread(&data, sizeof(struct student), 1, fp)) {
                if (strcmp(data.ssn,social) == 0)
                {
                    printf("A record with requested name found and deleted.\n\n");
                    found = 1;
                } 
                else
                {
                    fwrite(&data, sizeof(struct student), 1, fp_tmp);
                }
            }

            fclose(fp);
            fclose(fp_tmp);

            remove("student.db");
            rename("tmp.db", "student.db");

        }
        else
        {
            printf("data not deleted");
        }

        fclose(fp);
    }

}

void delete_student_data_menu()
{
    char social[10];

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

    delete_student(social);
}