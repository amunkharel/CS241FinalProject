int check_valid_class_id(int id);

int check_valid_assignment_id(int id);

void delete_assignment_grade_relationship(int id)
{
    FILE *fp;
    
    struct grades data;
    int counter = 0;
    int found = 0;
    int response;
    fp = fopen("grades.db", "r");

    if(fp == NULL)
    {
        printf("\n  Cannot open file with relationship with grade\n");
        return;
    }
    while(fread(&data, sizeof(struct grades), 1, fp))
    {
        if (data.aid == id)
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
            if (data.aid == id)
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

void delete_assignment_relationships(int id)
{
    delete_assignment_grade_relationship(id);
}

void delete_assignment(int class_id, int id)
{
    if(! check_valid_class_id(class_id))
    {
        printf("Not a valid class Id\n");
        return;
    }

    if(! check_valid_assignment_id(id))
    {
        printf("Not a valid Assignment Id\n");
        return;
    }


    FILE *fp;
    
    struct assignment data;
    int counter = 0;
    int found = 0;
    int response;
    fp = fopen("assignments.db", "r");

    if(fp == NULL)
    {
        printf("\n Error: Cannot open file");
        exit(1);
    }
    while(fread(&data, sizeof(struct assignment), 1, fp))
    {
        if (data.id == id && data.class_id == class_id)
        {
            found = 1;
            break;
        }
        counter++; 
    }

    if(! found)
    {
        printf("Given AID and CID not found in the database\n");
        fclose(fp);
        return;
    }

    else
    {
        found = 0;
        fseek(fp, counter*sizeof(struct assignment), SEEK_SET);
        fread(&data, sizeof(struct assignment), 1, fp);
        printf("Are you sure you want to delete Assignment = %d, Title = %s, Point = %d, Class_id = %d from the database [Y/N]: ", data.id, data.title, data.point, data.class_id);
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
            while (fread(&data, sizeof(struct assignment), 1, fp)) {
                if (data.id == id && data.class_id == class_id)
                {
                    printf("A record with requested id found and deleted.\n\n");
                    found = 1;
                } 
                else
                {
                    fwrite(&data, sizeof(struct assignment), 1, fp_tmp);
                }
            }

            if(found)
            {
                delete_assignment_relationships(id);
            }

            fp = fp_tmp;
            fclose(fp);

            remove("assignments.db");
            rename("tmp.db", "assignments.db");
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

void delete_assignment_menu()
{
    int id;
    int class_id;
    int check = 0;

    printf("Enter Class ID or (-1 for Class List): ");
    scanf("%d", &class_id);
    getchar();
    if(class_id == -1)
    {
        view_class();
        delete_assignment_menu();
        return;
    }

    while(check != 1)
    {
        printf("Enter Assignment ID or (-1 for Assignment List): ");
        scanf("%d", &id);
        clear_buffer();
        if(id != -1)
        {
            check = 1;
        }
        else
        {
            view_assignment();
        }
    }
    delete_assignment(class_id, id);
}
