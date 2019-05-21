void view_assignment_cid(int class_id)
{
    FILE *fp;
    int found = 0;
    
    struct assignment data;
    fp = fopen("assignments.db", "r");

    if(fp == NULL)
    {
        printf("\n Error: Cannot open file");
        exit(1);
    }
    printf("\n\nAssignment in the database with class id %d \n", class_id);
    while(fread(&data, sizeof(struct assignment), 1, fp))
    {
        if(data.class_id == class_id)
        {
            printf("\nID: %d, Title = %s, Class_Id = %d, Point = %d \n", data.id, data.title, data.class_id, data.point);
            found = 1;
        }
    }
    if(!found)
    {
        printf("No Assignment with the given class id found\n\n");
    }

    printf("\n\n");
    fclose(fp);
    return;
}

void view_assignment()
{
    FILE *fp;
    
    struct assignment data;
    fp = fopen("assignments.db", "r");

    if(fp == NULL)
    {
        printf("\n Error: Cannot open file");
        exit(1);
    }
    printf("\n\nAssignment in the database\n");
    while(fread(&data, sizeof(struct assignment), 1, fp))
    {
        printf("\nID: %d, Title = %s, Class_Id = %d, Point = %d \n", data.id, data.title, data.class_id, data.point);
    }
    printf("\n\n");
    fclose(fp);
    return;
}

void view_assignment_menu()
{
    int class_id;

    printf("Enter Class ID or (-1 for Class List): ");
    scanf("%d", &class_id);
    getchar();
    if(class_id == -1)
    {
        view_class();
        view_assignment_menu();
        return;
    }

    view_assignment_cid(class_id);

}
