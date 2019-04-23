void add_class(char *title)
{
    if(strlen(title) < 5)
    {
        printf("Title must be atleast five characters \n\n");
        return;
    }

    FILE *fp;
    FILE *nfp;
    struct classes data;

    fp = fopen("classes.db", "r");
    if(fp == NULL)
    {
        nfp = fopen("classes.db", "w");
        data.id = 1;
        strcpy(data.title, title);
        fwrite (&data, sizeof(struct classes), 1, nfp); 
        printf("Class added successfully\n\n");
        
    }
    else
    {
        fseek(fp, -sizeof(struct classes), SEEK_END);
        fread(&data, sizeof(struct classes), 1, fp);
        data.id = data.id + 1;
        nfp = fopen("classes.db", "a");
        strcpy(data.title, title);
        fwrite (&data, sizeof(struct classes), 1, nfp); 
        printf("Class added successfully\n\n");
        
    }
    fclose(nfp);
    fclose(fp);
}

void add_class_menu()
{
    char title[30];

    printf("\nEnter class title: ");
    fgets(title, 30, stdin);
    delete_endline(title);
    //printf("length = %lu , Title = %s \n\n", strlen(title), title);
    add_class(title);
}