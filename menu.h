
void view_grades_menu()
{

	int choice = 0;

	printf("View Grades Menu\n");
	printf("		1. View Class Average Grade \n");
	printf("		2. View Student Average Grades \n");
	printf("		3. View Class Assignment Average Grades\n");
	printf("		4. View Class Assignment Grades\n");
	printf("		5. Return to Main Menu\n");
	printf("Please enter 1-5: ");

	scanf( "%d", &choice );
	
	clear_buffer();

	switch( choice )
	{
		case 1:
			view_average_class_grade_menu();
			break;
		case 2:
			view_average_student_grade_menu();
			break;
		case 3:
			view_class_assignment_average_grade_menu();
			break;
		case 4:
			view_class_assignment_grade_menu();
			break;
		case 5:
			return;
		default:
			printf("\n\nPlease type a number from 1-5\n\n");
			break;
	}

	view_grades_menu();
}

void view_data_menu()
{

	int choice = 0;

	printf("View Data Menu\n");
	printf("		1. View Student \n");
	printf("		2. View Classes \n");
	printf("		3. View Assignment\n");
	printf("		4. View Grade\n");
	printf("		5. View Enrollment\n");
	printf("		6. Return to Main Menu\n");
	printf("Please enter 1-6: ");

	scanf( "%d", &choice );
	
	clear_buffer();

	switch( choice )
	{
		case 1:
			view_student_data_menu();
			break;
		case 2:
			view_class();
			break;
		case 3:
			view_assignment_menu();
			break;
		case 4:
			view_grades_menu();
			break;
		case 5:
			view_enrollment_menu();
			break;
		case 6:
			return;
		default:
			printf("\n\nPlease type a number from 1-6\n\n");
			break;
	}

	view_data_menu();
}

void delete_menu()
{

	int choice = 0;

	printf("Delete Data Menu\n");
	printf("		1. Delete Student \n");
	printf("		2. Delete Class \n");
	printf("		3. Delete Assignment\n");
	printf("		4. Delete Grade\n");
	printf("		5. Drop Student\n");
	printf("		6. Return to Main Menu\n");
	printf("Please enter 1-6: ");

	scanf( "%d", &choice );
	
	clear_buffer();

	switch( choice )
	{
		case 1:
			delete_student_data_menu();
			break;
		case 2:
			delete_class_menu();
			break;
		case 3:
			delete_assignment_menu();
			break;
		case 4:
			delete_grade_menu();
			break;
		case 5:
			delete_enrollment_menu();
			break;
		case 6:
			return;
		default:
			printf("\nPlease type a number from 1-6\n\n");
			break;
	}

	delete_menu();
}

void edit_menu()
{

	int choice = 0;

	printf("Edit Data Menu\n");
	printf("		1. Edit Student \n");
	printf("		2. Edit Class \n");
	printf("		3. Edit Assignment\n");
	printf("		4. Edit Grade\n");
	printf("		5. Return to Main Menu\n");
	printf("Please enter 1-5: ");

	scanf( "%d", &choice );
	
	clear_buffer();

	switch( choice )
	{
		case 1:
			edit_student_data_menu();
			break;
		case 2:
			edit_class_menu();
			break;
		case 3:
			edit_assignment_menu();
			break;
		case 4:
			edit_grade_menu();
			break;
		case 5:
			return;
		default:
			printf("\nPlease type a number from 1-5\n\n");
			break;
	}

	edit_menu();
}

void add_data_menu()
{
	int choice;
	printf( "Add Data Menu\n" );
	printf( "      1. Add Student\n" );
	printf( "      2. Add Class\n" );
	printf( "      3. Add Assignment\n" );
	printf( "      4. Add Grade\n" );
	printf( "      5. Enroll Student\n" );
	printf( "      6. Return to Main Menu\n" );
	printf( "Please enter 1-6: " );

	scanf( "%d", &choice );
	
	clear_buffer();

	switch( choice )
	{
		case 1:
			get_student_data_menu();
			break;
		case 2:
			add_class_menu();
			break;
		case 3:
			add_assignment_menu();
			break;
		case 4:
			add_grade_menu();
			break;
		case 5:
			enroll_student_menu();
			break;
		case 6: 
			return;
		default:
			printf( "\nPlease type a number from 1-6\n\n" );
			break;
	}

	add_data_menu();
}

void main_menu()
{
    int choice;
	printf( "Main Menu\n" );
	printf( "1. Add Data\n" );
	printf( "2. Edit Data\n" );
	printf( "3. Delete Data\n" );
	printf( "4. View Data\n" );
	printf( "5. Use Command Line Argument\n" );
	printf( "6. Exit\n" );
	printf( "Please enter 1-6: " );

	scanf( "%d", &choice );
	
	clear_buffer();

	switch( choice )
	{
		case 1:
			add_data_menu();
			break;
		case 2:
			edit_menu();
			break;
		case 3:
			delete_menu();
			break;
		case 4:
			view_data_menu();
			break;
		case 5:
			custom_command();
			break;
		case 6: 
			return;
		default:
			printf( "\nPlease type a number from 1-5\n\n" );
			break;
	}

	main_menu();
}

