void command_line(int length, char *args[])
{
    //Change arguments from user for effective handling
    int i = 1;
    int j = 0;
    char par1[30];
    char par2[30];
    char par3[30];
    char par4[30];
    strcpy(par1, "NULL");
    strcpy(par2, "NULL");
    strcpy(par3, "NULL");
    strcpy(par4, "NULL");

    for(i = 1; i < 2; i++)
    {
        for(j = 0; args[i][j]; j++)
        {
            args[i][j] = tolower(args[i][j]);
        }
    }

    //printf("length = %d,  argument = %s \n", length, args[1]);

    if ( length == 8 && strcmp( args[1], "-add-student" ) == 0  )
	{
        for(i = 2; i < length; i = i + 2 )
        {
            if(strcmp( args[i], "-f" ) == 0 || strcmp( args[i], "-l" ) == 0 || strcmp( args[i], "-s" ) == 0)
            {
                if(strcmp( args[i], "-f" ) == 0 )
                {
                    strcpy(par1, args[i+1]);
                }

                else if(strcmp( args[i], "-l" ) == 0 )
                {
                    strcpy(par2, args[i+1]);
                }
                else if(strcmp( args[i], "-s" ) == 0 )
                {
                    strcpy(par3, args[i+1]);
                }
            }
            else
            {
                printf("Please type a valid command\n");
                return;
            } 
        }

        if(strcmp( par1, "NULL" ) == 0 || strcmp( par2, "NULL" ) == 0 || strcmp( par3, "NULL" ) == 0 )
        {
            printf("Please type a valid command\n");
            return;
        }
        else
        {
            printf("First = %s , Last = %s, SSN = %s \n", par1, par2, par3);
            printf("Add students\n");
        }
        
	}

}