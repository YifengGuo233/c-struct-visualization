#include "common_header.h"
#define PARAM_SIZE 256
#define PARAM_NUM 3

struct key_value{
  char type[PARAM_SIZE];
  char value[PARAM_SIZE];
};

char** param;
struct key_value* param_arr;
int curr_num = 0;
int struct_size = sizeof(struct key_value);

void param_init(){
    printf("param_init\n");
    param = (char**) malloc(PARAM_NUM*sizeof(char*));
    int i = 0;
    for(i = 0; i < PARAM_NUM; i++){
        param[i] = malloc(PARAM_SIZE*sizeof(char));
    }
}
void param_free(){
    printf("param_free\n");
    int i = 0;
    for(i = 0; i < PARAM_NUM; i++){
        free(param[i]);
    }
    free(param);
}

void print_arr(){
    printf("print_arr\n");
    printf("arr length: %d\n", curr_num);
    int i;
    for(i = 0; i < curr_num; i++){
        printf("Index: %d, %s %s\n", i, param_arr[i].type, param_arr[i].value);
    }
}

void parameter_map(){
    struct key_value temp;
    char* type = (char*) malloc(PARAM_SIZE*sizeof(char));
    char* value = (char*) malloc(PARAM_SIZE*sizeof(char));
    strcpy(type, param[0]);
    strcpy(value, param[1]);
    param_arr = (struct key_value*) realloc(param_arr, (curr_num+1)*struct_size);
    if(!param_arr)
        printf("error: %s\n", errno);
    printf("%d\n", (curr_num+1)*struct_size);
    if(strcmp(type, "int") == 0){
        strcpy(temp.type,"int");
    }
    if(strcmp(type, "string") == 0){
        strcpy(temp.type,"string");
    }
    strcpy(temp.value, value);
    *(param_arr+curr_num) = temp;
    curr_num++;
    free(type);
    free(value);
    param_free();
}

void add_parameter(){
    param_init();
    print_arr();
    if(!param)
        printf("error: %s\n", errno);
    printf("=================================\n");
    printf("Add Parameter\n");
    printf("=================================\n");
    scanf("\n");
    scanf("%s %s", param[0], param[1]);
    printf("param[0]: %s\n", param[0]);
    printf("param[1]: %s\n", param[1]);
    parameter_map();
}
