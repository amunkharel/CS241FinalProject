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