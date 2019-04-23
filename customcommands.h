void custom_command()
{
    char c;
	char *in = malloc(200);
	int i;
	int index = 0;
	int num_args = 1;
	int curr_arg = 0;
	int inc = 0;

	printf( ">>" );

	while( ( c = getchar() ) != '\n' )
	{
		if ( c == ' ' )
			num_args++;

		in[index] = c;
		index++;
	}

	index = 0;

	char **strs = malloc( sizeof( char * ) * num_args );

	while ( curr_arg <= num_args )
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
	//printf("%d\n", num_args);
    //printf("%s\n",strs[2]);
	if ( num_args == 1 )
	{
		if ( strcmp( strs[0], "exit" ) == 0 )
			return;
	}
	

	custom_command();
}