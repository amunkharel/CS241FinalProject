#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"clear_buffer.h"
#include "structs.h"
#include "viewstudent.h"
#include "addstudent.h"
#include "editstudent.h"
#include "deletestudent.h"
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