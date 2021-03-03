#include "common_header.h"
#include "parameter_package.h"

void menu_struct_show();

void option_struct_selected(){
    int choice = 0;
    scanf("%d", &choice);
    printf("%d\n", choice);
    switch(choice) {
        case 1 :
            add_parameter();
            menu_struct_show();
            break;
        default :
            printf("Invalid\n" );
   }
}


void menu_struct_show(){
    printf("=================================\n");
    printf("Create Struct\n");
    printf("=================================\n");
    printf("1.Add Parameter\n");
    printf("5.Back\n");
    option_struct_selected();
}
