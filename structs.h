struct student
{
    char fname[30];
    char lname[30];
    char ssn[9];
};

struct __attribute__((packed)) classes
{
    int id;
    char title[30];
};

struct __attribute__((packed)) enrollment
{
    int class_id;
    char ssn[9];
};

struct __attribute__((packed)) assignment
{
    int id;
    char title[30];
    int point;
    int class_id;
};

struct __attribute__((packed)) grades
{
    int aid;
    char ssn[9];
    int grade;
};

