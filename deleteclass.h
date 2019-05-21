void delete_enrollment_relationship(int id)
{
    FILE *fp;
    
    struct enrollment data;
    int counter = 0;
    int found = 0;
    int response;
    fp = fopen("enrollment.db", "r");

    if(fp == NULL)
    {
        printf("\n Cannot open file with relation with enrollment\n");
        return;
    }
    while(fread(&data, sizeof(struct enrollment), 1, fp))
    {
        if (data.class_id == id)
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
            if (data.class_id == id)
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



void delete_grade_relationship(int id)
{
    FILE *fp;
    
    struct grades data;
    int counter = 0;
    int found = 0;
    int response;
    fp = fopen("grades.db", "r");

    if(fp == NULL)
    {
        printf("\n  Cannot open file relation with grade\n");
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

void delete_assignment_relationship(int id)
{
    FILE *fp;
    
    struct assignment data;
    int counter = 0;
    int found = 0;
    int response;
    fp = fopen("assignments.db", "r");

    if(fp == NULL)
    {
        printf("\n  Cannot open file with relationship with assignment\n\n");
        return;
    }
    while(fread(&data, sizeof(struct assignment), 1, fp))
    {
        if (data.class_id == id)
        {
            found = 1;
            break;
        }
        counter++; 
    }


    if(! found)
    {
        printf("No relationship with assignment found\n");
        fclose(fp);
        return;
    }
    else
    {
        found = 0;
        fseek(fp, counter*sizeof(struct assignment), SEEK_SET);
        fread(&data, sizeof(struct assignment), 1, fp);
        rewind(fp);
        FILE *fp_tmp;
        fp_tmp = fopen("tmp1.db", "w");
        if(fp_tmp == NULL)
        {
            printf("\n Error: Cannot open file");
            exit(1);
        } 
        while (fread(&data, sizeof(struct assignment), 1, fp)) {
            if (data.class_id == id)
            {
                found = 1;
            } 
            else
            {
                fwrite(&data, sizeof(struct assignment), 1, fp_tmp);
            }
        }

        if(found)
        {
            printf("\n Relationship with assignment found and deleted\n\n");
        }
        fp = fp_tmp;
        fclose(fp);

        remove("assignments.db");
        rename("tmp1.db", "assignments.db");

    }
}

void get_assignment_id(int id)
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
        if (data.class_id == id)
        {
            delete_grade_relationship(data.id);
        }
    }
    fclose(fp);
}

void delete_relationships(int id)
{
    delete_assignment_relationship(id);
    delete_enrollment_relationship(id);
}

void delete_class(int id)
{

    FILE *fp;
    
    struct classes data;
    int counter = 0;
    int found = 0;
    int response;
    fp = fopen("classes.db", "r");

    if(fp == NULL)
    {
        printf("\n Error: Cannot open Class DB file");
        exit(1);
    }
    while(fread(&data, sizeof(struct classes), 1, fp))
    {
        if (data.id == id)
        {
            found = 1;
            break;
        }
        counter++; 
    }


    if(! found)
    {
        printf("Class Id not found in the database\n");
        fclose(fp);
        return;
    }
    else
    {
        found = 0;
        fseek(fp, counter*sizeof(struct classes), SEEK_SET);
        fread(&data, sizeof(struct classes), 1, fp);
        printf("Are you sure you want to delete Class = %s from the database [Y/N]: ", data.title);
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
            while (fread(&data, sizeof(struct classes), 1, fp)) {
                if (data.id == id)
                {
                    get_assignment_id(id);
                    printf("A record with requested title found and deleted.\n\n");
                    found = 1;
                } 
                else
                {
                    fwrite(&data, sizeof(struct classes), 1, fp_tmp);
                }
            }

            if(found)
            {
                delete_relationships(id);
            }

            fp = fp_tmp;
            fclose(fp);

            remove("classes.db");
            rename("tmp.db", "classes.db");
            return;
        }
        else
        {
            printf("Class not deleted\n\n");
        }

        fclose(fp);

    }
    getchar();
    

}

void delete_class_menu()
{
    int id;

    printf("Enter Class ID or (-1 for Class List): ");
    scanf("%d", &id);
    getchar();

    if(id == -1)
    {
        view_class();
        delete_class_menu();
        return;
        
    }

    delete_class(id);
}
