void view_enrollment(int class_id)
{
    if(! check_valid_class_id(class_id))
    {
        printf("Not a valid class Id\n");
        return;
    }

    FILE *fp;
    int found = 0;
    
    struct enrollment data;
    fp = fopen("enrollment.db", "r");

    if(fp == NULL)
    {
        printf("\n Error: Cannot open file");
        exit(1);
    }

    printf("\n\nStudents enrolled in the Class of Class_ID = %d \n", class_id);
    while(fread(&data, sizeof(struct enrollment), 1, fp))
    {
        if(data.class_id == class_id){

            int i = 0;

            printf("Class Id: %d, ", data.class_id);

            printf(" SSN: ");
            for (i = 0; i < 9; i++)
            {
                printf("%c", data.ssn[i]);
            }

            
            printf("\n");
            found = 1;
        }    
    }

    if(!found)
    {
        printf("\n\nStudent enrolled in class not found \n");
    }
    printf("\n\n");


    fclose(fp);
    return;
}

void view_enrollment_menu()
{
    int class_id;

    printf("Enter Class ID or (-1 for Class List): ");
    scanf("%d", &class_id);
    getchar();

    if(class_id == -1)
    {
        view_class();
        view_enrollment_menu();
        return; 
    }

    view_enrollment(class_id);

}
