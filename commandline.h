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

    else if ( length == 4 && strcmp( args[1], "-add-class" ) == 0  )
    {
        for(i = 2; i < length; i = i + 2 )
        {
            if(strcmp( args[i], "-t" ) == 0)
            {
                strcpy(par1, args[i+1]);   
            }
            else
            {
                printf("Please type a valid command\n");
                return;
            } 
        }
        printf("Title = %s \n", par1);
        printf("Add class\n");
    }


    else if ( length == 8 && strcmp( args[1], "-add-assignment" ) == 0  )
	{
        for(i = 2; i < length; i = i + 2 )
        {
            if(strcmp( args[i], "-cid" ) == 0 || strcmp( args[i], "-t" ) == 0 || strcmp( args[i], "-p" ) == 0)
            {
                if(strcmp( args[i], "-cid" ) == 0 )
                {
                    strcpy(par1, args[i+1]);
                }

                else if(strcmp( args[i], "-t" ) == 0 )
                {
                    strcpy(par2, args[i+1]);
                }
                else if(strcmp( args[i], "-p" ) == 0 )
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
            printf("Class Id = %s , Title = %s, PointValue = %s \n", par1, par2, par3);
            printf("Add Assignment\n");
        }
        
	}

    else if ( length == 10 && strcmp( args[1], "-add-grade" ) == 0  )
	{
        for(i = 2; i < length; i = i + 2 )
        {
            if(strcmp( args[i], "-cid" ) == 0 || strcmp( args[i], "-aid" ) == 0 || strcmp( args[i], "-s" ) == 0 || strcmp( args[i], "-p" ) == 0)
            {
                if(strcmp( args[i], "-cid" ) == 0 )
                {
                    strcpy(par1, args[i+1]);
                }

                else if(strcmp( args[i], "-aid" ) == 0 )
                {
                    strcpy(par2, args[i+1]);
                }
                else if(strcmp( args[i], "-s" ) == 0 )
                {
                    strcpy(par3, args[i+1]);
                }

                else if(strcmp( args[i], "-p" ) == 0 )
                {
                    strcpy(par4, args[i+1]);
                }
            }
            else
            {
                printf("Please type a valid command\n");
                return;
            } 
        }

        if(strcmp( par1, "NULL" ) == 0 || strcmp( par2, "NULL" ) == 0 || strcmp( par3, "NULL" ) == 0  || strcmp( par4, "NULL" ) == 0)
        {
            printf("Please type a valid command\n");
            return;
        }
        else
        {
            printf("Class Id = %s , Assignment Id = %s, Student SSN = %s ,  Points = %s \n", par1, par2, par3,par4);
            printf("Add Grade\n");
        }
        
	}

    else if ( length == 6 && strcmp( args[1], "-enroll" ) == 0  )
	{
        for(i = 2; i < length; i = i + 2 )
        {
            if(strcmp( args[i], "-cid" ) == 0 || strcmp( args[i], "-s" ) == 0 )
            {
                if(strcmp( args[i], "-cid" ) == 0 )
                {
                    strcpy(par1, args[i+1]);
                }

                else if(strcmp( args[i], "-s" ) == 0 )
                {
                    strcpy(par2, args[i+1]);
                }
            }
            else
            {
                printf("Please type a valid command\n");
                return;
            } 
        }

        if(strcmp( par1, "NULL" ) == 0 || strcmp( par2, "NULL" ) == 0 )
        {
            printf("Please type a valid command\n");
            return;
        }
        else
        {
            printf("Class Id = %s , SSN = %s\n", par1, par2);
            printf("Enroll Student\n");
        }
        
	}

    else if ( length == 8 && strcmp( args[1], "-edit-student" ) == 0  )
	{
        for(i = 2; i < length; i = i + 2 )
        {
            if(strcmp( args[i], "-s" ) == 0 || strcmp( args[i], "-f" ) == 0 || strcmp( args[i], "-l" ) == 0)
            {
                if(strcmp( args[i], "-s" ) == 0 )
                {
                    strcpy(par1, args[i+1]);
                }

                else if(strcmp( args[i], "-f" ) == 0 )
                {
                    strcpy(par2, args[i+1]);
                }
                else if(strcmp( args[i], "-l" ) == 0 )
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
            printf("SSN = %s , First Name = %s, Last Name = %s \n", par1, par2, par3);
            printf("Edit Student\n");
        }
        
	}

    else if ( length == 6 && strcmp( args[1], "-edit-class" ) == 0  )
	{
        for(i = 2; i < length; i = i + 2 )
        {
            if(strcmp( args[i], "-cid" ) == 0 || strcmp( args[i], "-t" ) == 0 )
            {
                if(strcmp( args[i], "-cid" ) == 0 )
                {
                    strcpy(par1, args[i+1]);
                }

                else if(strcmp( args[i], "-t" ) == 0 )
                {
                    strcpy(par2, args[i+1]);
                }
            }
            else
            {
                printf("Please type a valid command\n");
                return;
            } 
        }

        if(strcmp( par1, "NULL" ) == 0 || strcmp( par2, "NULL" ) == 0 )
        {
            printf("Please type a valid command\n");
            return;
        }
        else
        {
            printf("Class Id = %s , Title = %s\n", par1, par2);
            printf("Edit Class\n");
        }
        
	}


    else if ( length == 10 && strcmp( args[1], "-edit-assignment" ) == 0  )
	{
        for(i = 2; i < length; i = i + 2 )
        {
            if(strcmp( args[i], "-cid" ) == 0 || strcmp( args[i], "-aid" ) == 0 || strcmp( args[i], "-t" ) == 0 || strcmp( args[i], "-p" ) == 0)
            {
                if(strcmp( args[i], "-cid" ) == 0 )
                {
                    strcpy(par1, args[i+1]);
                }

                else if(strcmp( args[i], "-aid" ) == 0 )
                {
                    strcpy(par2, args[i+1]);
                }
                else if(strcmp( args[i], "-t" ) == 0 )
                {
                    strcpy(par3, args[i+1]);
                }

                else if(strcmp( args[i], "-p" ) == 0 )
                {
                    strcpy(par4, args[i+1]);
                }
            }
            else
            {
                printf("Please type a valid command\n");
                return;
            } 
        }

        if(strcmp( par1, "NULL" ) == 0 || strcmp( par2, "NULL" ) == 0 || strcmp( par3, "NULL" ) == 0  || strcmp( par4, "NULL" ) == 0)
        {
            printf("Please type a valid command\n");
            return;
        }
        else
        {
            printf("Class Id = %s , Assignment Id = %s,  Title = %s ,  Points = %s \n", par1, par2, par3,par4);
            printf("Edit Assignment\n");
        }
        
	}

    else if ( length == 10 && strcmp( args[1], "-edit-grade" ) == 0  )
	{
        for(i = 2; i < length; i = i + 2 )
        {
            if(strcmp( args[i], "-cid" ) == 0 || strcmp( args[i], "-aid" ) == 0 || strcmp( args[i], "-s" ) == 0 || strcmp( args[i], "-p" ) == 0)
            {
                if(strcmp( args[i], "-cid" ) == 0 )
                {
                    strcpy(par1, args[i+1]);
                }

                else if(strcmp( args[i], "-aid" ) == 0 )
                {
                    strcpy(par2, args[i+1]);
                }
                else if(strcmp( args[i], "-s" ) == 0 )
                {
                    strcpy(par3, args[i+1]);
                }

                else if(strcmp( args[i], "-p" ) == 0 )
                {
                    strcpy(par4, args[i+1]);
                }
            }
            else
            {
                printf("Please type a valid command\n");
                return;
            } 
        }

        if(strcmp( par1, "NULL" ) == 0 || strcmp( par2, "NULL" ) == 0 || strcmp( par3, "NULL" ) == 0  || strcmp( par4, "NULL" ) == 0)
        {
            printf("Please type a valid command\n");
            return;
        }
        else
        {
            printf("Class Id = %s , Assignment Id = %s,  Student SSN = %s ,  Points = %s \n", par1, par2, par3,par4);
            printf("Edit Grade\n");
        }
        
	}

    else if ( length == 4 && strcmp( args[1], "-delete-student" ) == 0  )
    {
        for(i = 2; i < length; i = i + 2 )
        {
            if(strcmp( args[i], "-s" ) == 0)
            {
                strcpy(par1, args[i+1]);   
            }
            else
            {
                printf("Please type a valid command\n");
                return;
            } 
        }
        printf("SSN = %s \n", par1);
        printf("Delete Student\n");
    }

    else if ( length == 4 && strcmp( args[1], "-delete-class" ) == 0  )
    {
        for(i = 2; i < length; i = i + 2 )
        {
            if(strcmp( args[i], "-cid" ) == 0)
            {
                strcpy(par1, args[i+1]);   
            }
            else
            {
                printf("Please type a valid command\n");
                return;
            } 
        }
        printf("Class ID = %s \n", par1);
        printf("Delete Class\n");
    }

    else if ( length == 6 && strcmp( args[1], "-delete-assignment" ) == 0  )
	{
        for(i = 2; i < length; i = i + 2 )
        {
            if(strcmp( args[i], "-cid" ) == 0 || strcmp( args[i], "-aid" ) == 0 )
            {
                if(strcmp( args[i], "-cid" ) == 0 )
                {
                    strcpy(par1, args[i+1]);
                }

                else if(strcmp( args[i], "-aid" ) == 0 )
                {
                    strcpy(par2, args[i+1]);
                }
            }
            else
            {
                printf("Please type a valid command\n");
                return;
            } 
        }

        if(strcmp( par1, "NULL" ) == 0 || strcmp( par2, "NULL" ) == 0 )
        {
            printf("Please type a valid command\n");
            return;
        }
        else
        {
            printf("Class Id = %s , AID = %s\n", par1, par2);
            printf("Delete Assignment\n");
        }
        
	}

    else if ( length == 8 && strcmp( args[1], "-delete-grade" ) == 0  )
	{
        for(i = 2; i < length; i = i + 2 )
        {
            if(strcmp( args[i], "-cid" ) == 0 || strcmp( args[i], "-aid" ) == 0 || strcmp( args[i], "-s" ) == 0)
            {
                if(strcmp( args[i], "-cid" ) == 0 )
                {
                    strcpy(par1, args[i+1]);
                }

                else if(strcmp( args[i], "-aid" ) == 0 )
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
            printf("CID = %s , AID = %s, SSN = %s \n", par1, par2, par3);
            printf("Delete Grade\n");
        }
        
	}

    else if ( length == 6 && strcmp( args[1], "-drop" ) == 0  )
	{
        for(i = 2; i < length; i = i + 2 )
        {
            if(strcmp( args[i], "-cid" ) == 0 || strcmp( args[i], "-s" ) == 0 )
            {
                if(strcmp( args[i], "-cid" ) == 0 )
                {
                    strcpy(par1, args[i+1]);
                }

                else if(strcmp( args[i], "-s" ) == 0 )
                {
                    strcpy(par2, args[i+1]);
                }
            }
            else
            {
                printf("Please type a valid command\n");
                return;
            } 
        }

        if(strcmp( par1, "NULL" ) == 0 || strcmp( par2, "NULL" ) == 0 )
        {
            printf("Please type a valid command\n");
            return;
        }
        else
        {
            printf("Class Id = %s , SSN = %s\n", par1, par2);
            printf("Drop Student\n");
        }
        
	}

    else
    {
        printf("Please type a valid command\n");
    }
    

}