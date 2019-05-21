void delete_student_enrollment_relationship(char * ssn)
{
    FILE *fp;
    
    struct enrollment data;
    int counter = 0;
    int found = 0;
    int response;
    fp = fopen("enrollment.db", "r");

    if(fp == NULL)
    {
        printf("\n Cannot open file consisiting relation with enrollment\n");
        return;
    }
    while(fread(&data, sizeof(struct enrollment), 1, fp))
    {
        if (strncmp(data.ssn, ssn, 9) == 0)
        {
            found = 1;
            break;
        }
        counter++; 
    }


    if(! found)
    {
        printf("No relationship with enrollment found\n");
        fclose(fp);
        return;
    }
    else
    {
        found = 0;
        fseek(fp, counter*sizeof(struct enrollment), SEEK_SET);
        fread(&data, sizeof(struct enrollment), 1, fp);
        rewind(fp);
        FILE *fp_tmp;
        fp_tmp = fopen("tmp3.db", "w");
        if(fp_tmp == NULL)
        {
            printf("\n Error: Cannot open file");
            exit(1);
        } 
        while (fread(&data, sizeof(struct enrollment), 1, fp)) {
            if (strncmp(data.ssn, ssn, 9) == 0)
            {
                found = 1;
            } 
            else
            {
                fwrite(&data, sizeof(struct enrollment), 1, fp_tmp);
            }
        }

        if(found)
        {
            printf("\n Relationship with enrollment found and deleted\n\n");
        }
        fp = fp_tmp;
        fclose(fp);

        remove("enrollment.db");
        rename("tmp3.db", "enrollment.db");

    }
}

void delete_student_grade_relationship(char * ssn)
{
    FILE *fp;
    
    struct grades data;
    int counter = 0;
    int found = 0;
    int response;
    fp = fopen("grades.db", "r");

    if(fp == NULL)
    {
        printf("\n Cannot open file with its relation with grade\n\n");
        return;
    }
    while(fread(&data, sizeof(struct grades), 1, fp))
    {
        if (strncmp(data.ssn, ssn, 9) == 0)
        {
            found = 1;
            break;
        }
        counter++; 
    }


    if(! found)
    {
        printf("No relationship with grade found\n");
        fclose(fp);
        return;
    }
    else
    {
        found = 0;
        fseek(fp, counter*sizeof(struct grades), SEEK_SET);
        fread(&data, sizeof(struct grades), 1, fp);
        rewind(fp);
        FILE *fp_tmp;
        fp_tmp = fopen("tmp2.db", "w");
        if(fp_tmp == NULL)
        {
            printf("\n Error: Cannot open file");
            exit(1);
        } 
        while (fread(&data, sizeof(struct grades), 1, fp)) {
            if (strncmp(data.ssn, ssn,9) == 0)
            {
                found = 1;
            } 
            else
            {
                fwrite(&data, sizeof(struct grades), 1, fp_tmp);
            }
        }

        if(found)
        {
            printf("\n Relationship with grades found and deleted\n\n");
        }

        fp = fp_tmp;
        fclose(fp);
        remove("grades.db");
        rename("tmp2.db", "grades.db");

    }
}


void delete_student_relationships(char * ssn)
{
    delete_student_grade_relationship(ssn);
    delete_student_enrollment_relationship(ssn);
}

void delete_student(char *social)
{
    if(strlen(social) != 9)
    {
        printf("Social Security Should have 9 characters to delete student record\n\n");
        return;
    }

    FILE *fp;
    
    struct student data;
    int counter = 0;
    int found = 0;
    int response;
    fp = fopen("students.db", "r");

    

    if(fp == NULL)
    {
        printf("\n Error: Cannot open file");
        exit(1);
    }

    while(fread(&data, sizeof(struct student), 1, fp))
    {
        if (strncmp(data.ssn,social,9) == 0)
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
        getchar();
        
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

            if(found)
            {
                delete_student_relationships(social);
            }

            fp = fp_tmp;
            fclose(fp);

            remove("students.db");
            rename("tmp.db", "students.db");
            return;
        }
        else
        {
            printf("data not deleted.\n\n");
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
