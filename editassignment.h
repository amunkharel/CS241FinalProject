int check_valid_class_id(int id);

int check_valid_assignment_id(int id)
{
    
    FILE *fp;
    struct assignment data;
    fp = fopen("assignments.db", "r");

    if(fp == NULL)
    {
        printf("\n Assignment DB not found\n\n");
        exit(1);
    }

    while(fread(&data, sizeof(struct assignment), 1, fp))
    {
        if (data.id == id)
        {  
            return 1;
        }
    }

    return 0;
}

void edit_assignment(int class_id, int id, char *title_name, int point)
{

    int point_val = 0;
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

    if(point == 662497)
    {
        point_val = 1;
    }

    if(!point_val)
    {
        if(point < 0 || point > 100)
        {
            printf("Point must be between 0 and 100 \n");
            return;
        }
    }

    char title[30];
    memcpy(title, title_name, 30);
    null_terminate_name(title, strlen(title));

    FILE *fp;
    struct assignment data;
    int counter = 0;
    int found = 0;

    fp = fopen("assignments.db", "r+");

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
        printf("Given data not found in the Assignment Database\n");
        fclose(fp);
        return;
    }

    else
    {
        fseek(fp, counter*sizeof(struct assignment), SEEK_SET);

        fread(&data, sizeof(struct assignment), 1, fp);

        if (strcmp(title,"NULL_CHAR") == 0 && point == 662497 )
        {
            printf("Nothing in the database changed\n\n");
            fclose(fp);
            return;
        }

        else if (strcmp(title,"NULL_CHAR") == 0)
        {
            data.point = point;
            fseek(fp, counter*sizeof(struct assignment), SEEK_SET);
            fwrite (&data, sizeof(struct assignment), 1, fp); 
            printf("Point in the database changed\n\n");
        }

        else if (point == 662497 )
        {
            memcpy(data.title, title, 30);
            fseek(fp, counter*sizeof(struct assignment), SEEK_SET);
            fwrite (&data, sizeof(struct assignment), 1, fp); 
            printf("Title in the database changed\n\n");

        }

        else
        {
            memcpy(data.title, title, 30);
            data.point = point;
            fseek(fp, counter*sizeof(struct assignment), SEEK_SET);
            fwrite (&data, sizeof(struct assignment), 1, fp); 
            printf("Both title and point changed in the database\n\n");
        }
        fclose(fp);
    }

    
}

void edit_assignment_menu()
{
    int id;
    int class_id;
    int point;
    int check = 0;
    char grade[10];
    char title[30];

    printf("Enter Class ID or (-1 for Class List): ");
    scanf("%d", &class_id);
    clear_buffer();

    if(class_id == -1)
    {
        view_class();
        edit_assignment_menu();
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

    printf("\nEnter New Title (or leave blank for no change): ");
    fgets(title, 30, stdin);

    if(title[0] == '\n')
    {
        strcpy(title, "NULL_CHAR");
    }
    else
    {
        delete_endline(title);
    }

    printf("Enter New  Point Value(or leave blank for no change): ");
    fgets(grade, 10, stdin);
    if(grade[0] == '\n')
    {
        point = 662497;
    }
    else
    {
        point = atoi(grade);
    }

    edit_assignment(class_id,  id,  title, point);
}
