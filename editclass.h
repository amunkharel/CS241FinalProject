void edit_class(int id, char * title)
{
    if(strlen(title) < 5)
    {
        printf("Title should atleast be 5 character \n\n");
        return;
    }
    FILE *fp;
    struct classes data;
    int counter = 0;
    int found = 0;

    fp = fopen("classes.db", "r+");
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
        printf("Class Id not found in the database to edit\n");
        fclose(fp);
        return;
    }
    else
    {
        fseek(fp, counter*sizeof(struct classes), SEEK_SET);
        strcpy(data.title, title);
        fwrite (&data, sizeof(struct classes), 1, fp); 
        printf("Class Title in the database changed\n\n");
        fclose(fp);
    }
    

}

void edit_class_menu()
{
    int id;
    char title[30];

    printf("Enter Class ID or (-1 for Class List): ");
    scanf("%d", &id);
    getchar();

    if(id == -1)
    {
        view_class();
        edit_class_menu();
        return;
        
    }

    printf("\nEnter class title (or leave blank for no change) ");
    fgets(title, 30, stdin);

    if(title[0] == '\n')
    {
        printf("No changes made to class \n\n");
        return;
    }
    else
    {
        delete_endline(title);
    }

    edit_class(id, title);
}