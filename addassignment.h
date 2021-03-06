int check_valid_class_id(int id)
{
    FILE *fp;
    struct classes data;
    fp = fopen("classes.db", "r");

    if(fp == NULL)
    {
        printf("\n Class DB not found");
        exit(1);
    }

    while(fread(&data, sizeof(struct classes), 1, fp))
    {
        if (data.id == id)
        {  
            return 1;
        }
    }

    return 0;
}

void add_assignment(int class_id, char * title_name, int point)
{
    if(! check_valid_class_id(class_id))
    {
        printf("Not a valid class Id\n");
        return;
    }

    if(point < 0 || point > 100)
    {
        printf("Point must be between 0 and 100 \n");
        return;
    }

    char title[30];
    memcpy(title, title_name, 30);
    null_terminate_name(title, strlen(title));
    FILE *fp;
    FILE *nfp;
    struct assignment data;

    fp = fopen("assignments.db", "r");
    if(fp == NULL)
    {
        nfp = fopen("assignments.db", "w");
        data.id = 1;
        memcpy(data.title, title, 30);
        data.class_id = class_id;
        data.point = point;
        fwrite (&data, sizeof(struct assignment), 1, nfp); 
        printf("Assignment added successfully\n\n");
        
    }
    else
    {
        fseek(fp, -sizeof(struct assignment), SEEK_END);
        fread(&data, sizeof(struct assignment), 1, fp);
        data.id = data.id + 1;
        nfp = fopen("assignments.db", "a");
        memcpy(data.title, title, 30);
        data.class_id = class_id;
        data.point = point;
        fwrite (&data, sizeof(struct assignment), 1, nfp); 
        printf("Assignment added successfully\n\n");
        
    }
    fp = nfp;
    fclose(fp);
    
}

void add_assignment_menu()
{
    int class_id;
    int point;
    char title[31];

    printf("Enter Class ID or (-1 for Class List): ");
    scanf("%d", &class_id);
    clear_buffer();
    if(class_id == -1)
    {
        view_class();
        add_assignment_menu();
        return;
        
    }
    printf("\nEnter Assignment Title: ");
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

    printf("Enter Point Value (1-100)");
    scanf("%d", &point);

    clear_buffer();

    add_assignment(class_id, title, point);

}
