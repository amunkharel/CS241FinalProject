void custom_command()
{
    char c;
	char *in = malloc(1000);
	int i;
	int index = 0;
	int num_args = 1;
	int curr_arg = 0;
	int inc = 0;
	int length = 0;

	printf( ">>" );

	while( ( c = getchar() ) != '\n' )
	{
		if ( c == ' ' )
			num_args++;

		in[index] = c;
		index++;
	}
	
	length = index;
	index = 0;

	char **strs = malloc( sizeof( char * ) * num_args );

	while ( index < length + 1)
	{
		if( in[index] == ' ' || in[index] == '\0' )
		{
			strs[curr_arg] = malloc( index - inc + 1 );


			for ( i = inc; i < index; i++ )
			{
				strs[curr_arg][i - inc] = in[i];
			}
			strs[curr_arg][i - inc] = '\0';

			inc = index + 1;
			curr_arg++;  
		}
		
		index++;
	}
	
	if ( num_args == 1 && strcmp( strs[0], "exit" ) == 0  )
	{
			return;
	}


	else if ( strcmp( strs[0], "add" ) == 0 )
	{
		if(strcmp( strs[1], "grade") == 0 && num_args == 6 )
		{
			printf("Add Grade\n");
		}

		else if(strcmp( strs[1], "student") == 0 && num_args == 5 )
		{
			printf("Add Student\n");
		}

		else if(strcmp( strs[1], "class") == 0 && num_args == 3 )
		{
			printf("Add Class\n");
		}

		else if(strcmp( strs[1], "assignment") == 0 && num_args == 5 )
		{
			printf("Add Assignment\n");
		}

		else
		{
			printf("Please type a valid add command\n");
		}
	}
	else if ( strcmp( strs[0], "enroll" ) == 0 )
	{
		if(num_args == 3)
		{
			printf("Enroll Student\n");
		}

		else
		{
			printf("Please enter a valid enroll command \n");
		}
		
	}

	else if ( strcmp( strs[0], "edit" ) == 0 )
	{
		if(strcmp( strs[1], "student") == 0 && num_args == 5 )
		{
			printf("Edit Student\n");
		}

		else if(strcmp( strs[1], "class") == 0 && num_args == 4 )
		{
			printf("Edit Class\n");
		}

		else if(strcmp( strs[1], "assignment") == 0 && num_args == 6 )
		{
			printf("Edit Assignment\n");
		}

		else if(strcmp( strs[1], "grade") == 0 && num_args == 6 )
		{
			printf("Edit Grade\n");
		}
		else
		{
			printf("Please enter a valid Edit command \n");
		}
		
	}

	else if ( strcmp( strs[0], "delete" ) == 0 )
	{
		if(strcmp( strs[1], "student") == 0 && num_args == 3 )
		{
			printf("Delete Student\n");
		}
		else if(strcmp( strs[1], "class") == 0 && num_args == 3 )
		{
			printf("Delete Class\n");
		}

		else if(strcmp( strs[1], "assignment") == 0 && num_args == 4 )
		{
			printf("Delete assignment\n");
		}

		else if(strcmp( strs[1], "grade") == 0 && num_args == 5 )
		{
			printf("Delete Grade\n");
		}
		else
		{
			printf("Please enter a valid delete command \n");
		}
	}

	else if ( strcmp( strs[0], "drop" ) == 0 )
	{
		if(num_args == 3)
		{
			printf("Drop Student\n");
		}

		else
		{
			printf("Please enter a valid drop command \n");
		}
		
	}

	else if ( strcmp( strs[0], "view" ) == 0 )
	{
		if(strcmp( strs[1], "students") == 0 && num_args == 2 )
		{
			printf("View Students\n");
		}
		else if(strcmp( strs[1], "classes") == 0 && num_args == 2 )
		{
			printf("View Classes\n");
		}

		else if(strcmp( strs[1], "assignments") == 0 && num_args == 3 )
		{
			printf("View assignments\n");
		}

		else if(strcmp( strs[1], "grades") == 0 && num_args == 4 )
		{
			printf("View Grades\n");
		}
		else if(strcmp( strs[1], "average") == 0 && strcmp( strs[2], "grade") == 0 && num_args == 5)
		{
			printf("View Average Grade\n");
		}

		else
		{
			printf("Please enter a valid view command \n");
		}
	}
	else
	{
		printf("Please enter a valid command\n");
	}

	custom_command();
}