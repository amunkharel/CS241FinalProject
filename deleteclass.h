void delete_class(int id)
{
    printf("%d \n\n", id);

        FILE *fp;
    
    struct classes data;
    int counter = 0;
    int found = 0;
    int response;
    fp = fopen("classes.db", "r");

    if(fp == NULL)
    {
        printf("\n Error: Cannot open file");
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
                    printf("A record with requested title found and deleted.\n\n");
                    found = 1;
                } 
                else
                {
                    fwrite(&data, sizeof(struct classes), 1, fp_tmp);
                }
            }

            fclose(fp);
            fclose(fp_tmp);

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
    

}

void delete_class_menu()
{
    int id;
    char title[30];

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