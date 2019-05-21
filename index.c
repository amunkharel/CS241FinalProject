#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "structs.h"
#include"clear_buffer.h"
#include "viewstudent.h"
#include "addstudent.h"
#include "editstudent.h"
#include "deletestudent.h"
#include "viewclass.h"
#include "editclass.h"
#include "addclass.h"
#include "deleteclass.h"
#include "viewassignment.h"
#include "addassignment.h"
#include "editassignment.h"
#include "deleteassignment.h"
#include "addgrade.h"
#include "editgrade.h"
#include "deletegrade.h"
#include "viewenrollment.h"
#include "enrollstudent.h"
#include "deleteenrollment.h"
#include "viewgrade.h"
#include "customcommands.h"
#include "commandline.h"
#include "menu.h"


int main(int argc, char * argv[])
{
    if(argc == 1)
    {
        main_menu();
    }
    else
    {
        command_line( argc, argv);
    }
    
    return 0;
}
