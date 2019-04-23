struct student
{
    char fname[30];
    char lname[30];
    char ssn[10];
};

struct classes
{
    int id;
    char title[30];
};

struct enrollement
{
    int id;
    char ssn[10];
};

struct assignment
{
    int id;
    char title[30];
    int point;
    int class_id;
};

struct grades
{
    int class_id;
    char ssn[10];
    int grade;
};