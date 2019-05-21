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
		in = NULL;
		strs = NULL;
		free(in);
		free(strs);
		exit(0);
	}

	if ( num_args == 1 && strcmp( strs[0], "quit" ) == 0  )
	{
		in = NULL;
		strs = NULL;
		free(in);
		free(strs);
		exit(0);
	}

	if ( num_args == 1 && strcmp( strs[0], "use_menus" ) == 0  )
	{
		in = NULL;
		strs = NULL;
		free(in);
		free(strs);
		return;
	}


	else if ( strcmp( strs[0], "add" ) == 0 && num_args > 2 && num_args < 7)
	{
		if(strcmp( strs[1], "grade") == 0 && num_args == 6 )
		{
			add_grade( atoi(strs[2]), atoi(strs[3]), strs[4], atoi(strs[5]));
		}

		else if(strcmp( strs[1], "student") == 0 && num_args == 5 )
		{

			add_student(strs[2], strs[3], strs[4]);
		}

		else if(strcmp( strs[1], "class") == 0 && num_args == 3 )
		{
			add_class(strs[2]);
		}

		else if(strcmp( strs[1], "assignment") == 0 && num_args == 5 )
		{
			add_assignment(atoi(strs[2]), strs[3], atoi(strs[4]));
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
			enroll_student(atoi(strs[1]), strs[2]);
		}

		else
		{
			printf("Please enter a valid enroll command \n");
		}
		
	}

	else if ( strcmp( strs[0], "edit" ) == 0 && num_args > 3 && num_args < 7)
	{
		if(strcmp( strs[1], "student") == 0 && num_args == 5 )
		{
			edit_student(strs[3], strs[4], strs[2]);
		}

		else if(strcmp( strs[1], "class") == 0 && num_args == 4 )
		{
			edit_class(atoi(strs[2]), strs[3]);
		}

		else if(strcmp( strs[1], "assignment") == 0 && num_args == 6 )
		{
			edit_assignment(atoi(strs[2]), atoi(strs[3]), strs[4], atoi(strs[5]));
		}

		else if(strcmp( strs[1], "grade") == 0 && num_args == 6 )
		{
			edit_grade(atoi(strs[2]), atoi(strs[3]), strs[4], atoi(strs[5]));
		}
		else
		{
			printf("Please enter a valid Edit command \n");
		}
		
	}

	else if ( strcmp( strs[0], "delete" ) == 0 && num_args > 2 && num_args < 6)
	{
		if(strcmp( strs[1], "student") == 0 && num_args == 3 )
		{
			delete_student(strs[2]);
		}
		else if(strcmp( strs[1], "class") == 0 && num_args == 3 )
		{
			delete_class(atoi(strs[2]));
		}

		else if(strcmp( strs[1], "assignment") == 0 && num_args == 4 )
		{
			delete_assignment(atoi(strs[2]), atoi(strs[3]));
		}

		else if(strcmp( strs[1], "grade") == 0 && num_args == 5 )
		{
			delete_grade(atoi(strs[2]), atoi(strs[3]), strs[4]);
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
			drop_student(atoi(strs[1]), strs[2]);
		}

		else
		{
			printf("Please enter a valid drop command \n");
		}
		
	}

	else if ( strcmp( strs[0], "view" ) == 0 && num_args > 1 && num_args < 6)
	{
		if(strcmp( strs[1], "students") == 0 && num_args == 2 )
		{
			view_student_data_menu();
		}
		else if(strcmp( strs[1], "classes") == 0 && num_args == 2 )
		{
			view_class();
		}

		else if(strcmp( strs[1], "assignments") == 0 && num_args == 3 )
		{
			view_assignment_cid(atoi(strs[2]));
		}

		else if(strcmp( strs[1], "grades") == 0 && num_args == 4 )
		{
			if(strlen(strs[2]) != 9)
			{
				view_class_assignment_grade(atoi(strs[2]), atoi(strs[3]));
			}

			else
			{
				view_student_class_grade(strs[2], atoi(strs[3]));
			}
			
		}
		else if(strcmp( strs[1], "average") == 0 && strcmp( strs[2], "grade") == 0 && num_args == 5)
		{
			view_average_class_assignment_grade(atoi(strs[3]), atoi(strs[4]));
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

	in = NULL;
	strs = NULL;
	free(in);
	free(strs);

	custom_command();
}