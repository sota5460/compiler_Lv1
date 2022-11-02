#include "main.h"

int main(int argc, char const *argv[])
{
    FILE *file;
    file = fopen("./sample","r");
    if(file == NULL){
        printf(" file is not found");
        return 0;
    }

    const int max_token_num = count_token_num(file);

    printf("token total nubmer is %d\n", max_token_num);

    //fclose(file);

    // file = fopen(argv[1],"r");

    printf("tokanaizer starts !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    fseek(file, 0, SEEK_SET); // set the file location to initial

    TOKEN *token;
    token = (TOKEN*)malloc(sizeof(TOKEN)*max_token_num);

    int i = 0;
    for(i; i < max_token_num; i++){
        token[i] = get_next_token(file);
    }

    for(int j=0; j< max_token_num;j++){
        printf("%d : %s\n", token[j].kind,token[j].str);
    }

    return 0;
}
