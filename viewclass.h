void view_class()
{
    FILE *fp;
    
    struct classes data;
    fp = fopen("classes.db", "r");

    if(fp == NULL)
    {
        printf("\n Error: Cannot open file");
        exit(1);
    }
    printf("\n\nClasses in the database\n");
    while(fread(&data, sizeof(struct classes), 1, fp))
    {
        printf("\nID: %d, Title = %s \n", data.id, data.title);
    }
    return;
}