void edit_class(int id, char * title_name)
{
    if(strlen(title_name) < 1)
    {
        printf("Title should atleast be 5 character \n\n");
        return;
    }

    char title[30];
    memcpy(title, title_name, 30);
    null_terminate_name(title, strlen(title));
    
    FILE *fp;
    struct classes data;

    
    int counter = 0;
    int found = 0;

    fp = fopen("classes.db", "r+");
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
        printf("Class Id not found in the database to edit\n");
        fclose(fp);
        return;
    }
    else
    {
        fseek(fp, counter*sizeof(struct classes), SEEK_SET);
        memcpy(data.title, title, 30);
        fwrite (&data, sizeof(struct classes), 1, fp); 
        printf("Class Title in the database changed\n\n");
        fclose(fp);
    }
    

}

void edit_class_menu()
{
    int id;
    char title[31];

    printf("Enter Class ID or (-1 for Class List): ");
    scanf("%d", &id);
    clear_buffer();

    if(id == -1)
    {
        view_class();
        edit_class_menu();
        return;
        
    }

    printf("\nEnter class title (or leave blank for no change) ");

    fgets(title, 31, stdin);
    if(title[0] == '\n')
    {
        printf("No change made to the title\n");
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

    edit_class(id, title);
}
