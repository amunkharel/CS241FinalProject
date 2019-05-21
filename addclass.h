void add_class(char *title_name)
{
    if(strlen(title_name) < 1)
    {
        printf("Title must be atleast one characters \n\n");
        return;
    }

    char title[30];
    memcpy(title, title_name, 30);
    null_terminate_name(title, strlen(title));

    FILE *fp;
    FILE *nfp;
    struct classes data;
    

    fp = fopen("classes.db", "r");
    if(fp == NULL)
    {
        nfp = fopen("classes.db", "w");
        data.id = 1;
        memcpy(data.title, title, 30);
        fwrite (&data, sizeof(struct classes), 1, nfp); 
        printf("Class added successfully\n\n");
    }

    else
    {
        fseek(fp, -sizeof(struct classes), SEEK_END);
        fread(&data, sizeof(struct classes), 1, fp);
        data.id = data.id + 1;
        memcpy(data.title, title, 30);
        nfp = fopen("classes.db", "a");
        fwrite (&data, sizeof(struct classes), 1, nfp); 
        printf("Class added successfully\n\n");
        
    }
    
    fp = nfp;
    fclose(fp);
}

void add_class_menu()
{
    char title[31];

    printf("\nEnter class title: ");

    fgets(title, 31, stdin);
    if(title[0] == '\n')
    {
        printf("Title Cannot be empty\n");
        return;
    }

    else if(strlen(title) <= 30)
    {
        delete_endline(title);
    }

    else
    {
        delete_endline(title);
        getchar();
    }

    add_class(title);
}
