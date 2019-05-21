void delete_grade(int class_id, int aid, char * ssn)
{

    if(! check_student_enrollment(class_id, ssn))
    {
        printf("Student Not enrolled in the class_id given\n\n");
        return;
    }

    if(! check_valid_class_id(class_id))
    {
        printf("Not a valid class Id\n");
        return;
    }

    if(! check_valid_assignment_id(aid))
    {
        printf("Not a valid Assignment Id\n");
        return;
    }

    if(! check_cid_aid_match(class_id, aid))
    {
        printf("Class Id and Assignment Id do not match\n");
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
    
    struct grades data;
    int counter = 0;
    int found = 0;
    int response;
    fp = fopen("grades.db", "r");

    if(fp == NULL)
    {
        printf("\n Error: Cannot open file");
        exit(1);
    }
    while(fread(&data, sizeof(struct grades), 1, fp))
    {
        if (data.aid == aid && strncmp(data.ssn, ssn,9) == 0)
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
        fseek(fp, counter*sizeof(struct grades), SEEK_SET);
        fread(&data, sizeof(struct grades), 1, fp);
        printf("Are you sure you want to delete Grade,  Aid = %d, SSN = %s, Grade = %d, from the database [Y/N]: ",  data.aid, data.ssn, data.grade);
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
            while (fread(&data, sizeof(struct grades), 1, fp)) {
                if (data.aid == aid && strncmp(data.ssn, ssn,9) == 0)
                {
                    printf("A record with requested id found and deleted.\n\n");
                    found = 1;
                } 
                else
                {
                    fwrite(&data, sizeof(struct grades), 1, fp_tmp);
                }
            }
            fp = fp_tmp;
            fclose(fp);

            remove("grades.db");
            rename("tmp.db", "grades.db");
            return;
        }
        else
        {
            printf("ID not found and not deleted\n\n");
        }

        fclose(fp);

    }
    getchar();

}

void delete_grade_menu()
{
    int check = 0;
    int class_id;
    int aid;
    char ssn[11];

    printf("Enter Class ID or (-1 for Class List): ");
    scanf("%d", &class_id);
    getchar();
    if(class_id == -1)
    {
        view_class();
        delete_grade_menu();
        return;
        
    }
    while(check != 1)
    {
        printf("Enter Assignment ID or (-1 for Assignment List): ");
        scanf("%d", &aid);
        clear_buffer();
        if(aid != -1)
        {
            check = 1;
        }
        else
        {
            view_assignment();
        }
    }


    printf("\nEnter Student SSN: ");
    fgets(ssn,11, stdin);
    delete_endline(ssn);
    delete_grade(class_id,aid,ssn);
}
