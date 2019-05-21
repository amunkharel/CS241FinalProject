void delete_enrollment_grade_relationship(int aid, char * ssn)
{
    FILE *fp;
    
    struct grades data;
    int counter = 0;
    int found = 0;
    int response;
    fp = fopen("grades.db", "r");

    if(fp == NULL)
    {
        printf("\n Cannot open file with relationship with grade\n");
        return;
    }
    while(fread(&data, sizeof(struct grades), 1, fp))
    {
        if (strncmp(data.ssn, ssn, 9) == 0 && data.aid == aid)
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
            if (strncmp(data.ssn, ssn, 9) == 0 && data.aid == aid)
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

void delete_enrollment_relationships(int class_id, char * ssn)
{
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
            delete_enrollment_grade_relationship(data.id, ssn);
        }
    }

}


void drop_student(int class_id, char * ssn)
{
    if(! check_valid_class_id(class_id))
    {
        printf("Not a valid class Id\n");
        return;
    }

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
    
    struct enrollment data;
    int counter = 0;
    int found = 0;
    int response;
    fp = fopen("enrollment.db", "r");

    if(fp == NULL)
    {
        printf("\n Error: Cannot open file");
        exit(1);
    }
    while(fread(&data, sizeof(struct enrollment), 1, fp))
    {
        if (data.class_id == class_id && strncmp(data.ssn, ssn,9) == 0)
        {
            found = 1;
            break;
        }
        counter++; 
    }

    if(! found)
    {
        printf("Given information not found in the database\n");
        fclose(fp);
        return;
    }

    else
    {
        found = 0;
        fseek(fp, counter*sizeof(struct enrollment), SEEK_SET);
        fread(&data, sizeof(struct enrollment), 1, fp);
        printf("Are you sure you want to drop student Class_id = %d, SSN = %s from the database [Y/N]: ", data.class_id, data.ssn);
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
            while (fread(&data, sizeof(struct enrollment), 1, fp)) {
                if (data.class_id == class_id && strncmp(data.ssn, ssn,9) == 0)
                {
                    found = 1;
                    printf("A record with requested ssn found and deleted.\n\n");
                } 
                else
                {
                    fwrite(&data, sizeof(struct enrollment), 1, fp_tmp);
                }
            }
            if(found)
            {
                delete_enrollment_relationships(class_id, ssn);
            }

            fp = fp_tmp;
            fclose(fp);

            remove("enrollment.db");
            rename("tmp.db", "enrollment.db");
            return;
        }
        else
        {
            printf("ID not found and not deleted. \n\n");
            
        }

        fclose(fp);
        

    }
    getchar();
}

void delete_enrollment_menu()
{
    int class_id;
    char ssn[11];
    printf("Enter Class ID or (-1 for Class List): ");
    scanf("%d", &class_id);
    clear_buffer();
    if(class_id == -1)
    {
        view_class();
        delete_enrollment_menu();
        return;
        
    }

    printf("\nEnter Student SSN: ");
    fgets(ssn,11, stdin);
    delete_endline(ssn);

    drop_student( class_id,  ssn);

}
