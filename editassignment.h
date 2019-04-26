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

void edit_assignment(int id, int class_id, int point, char *title)
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

    if(strlen(title) < 5)
    {
        printf("Assignment Title must be atleast 5 characters \n");
        return;
    }


    
}

void edit_assignment_menu()
{
    int id;
    int class_id;
    int point;
    char grade[10];
    char title[30];

    printf("Enter Class ID or (-1 for Class List): ");
    scanf("%d", &class_id);
    getchar();
    if(class_id == -1)
    {
        view_class();
        edit_assignment_menu();
        return;
    }

    printf("Enter Assignment ID or (-1 for Assignment List): ");
    scanf("%d", &id);
    getchar();
    if(id == -1)
    {
        view_assignment();
        edit_assignment_menu();
        return;
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

    printf("Enter New Earned Point (or leave blank for no change): ");
    fgets(grade, 10, stdin);
    if(grade[0] == '\n')
    {
        point = 662497;
    }
    else
    {
        point = atoi(grade);
    }

    //printf("Point = %d, Class Id = %d, Assignment Id = %d, Title = %s\n\n", point,class_id,id,title);
    edit_assignment(id,  class_id,  point, title);
}