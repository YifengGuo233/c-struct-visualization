#include "common_header.h"
#include "struct_package.h"



void option_main_selected(){
    int choice = 0;
    scanf("%d", &choice);
    printf("%d\n", choice);
    switch(choice) {
        case 1 :
            menu_struct_show();
            break;
        default :
            printf("No option selected\n" );
   }
}


void menu_main_show(){
    printf("=================================\n");
    printf("Struct PlayGround\n");
    printf("=================================\n");
    printf("1.Create a struct\n");
    printf("5.Exit\n");
    option_main_selected();
}

void init(){
    param_init();
}

int main()
{
    init();
    menu_main_show();
}
