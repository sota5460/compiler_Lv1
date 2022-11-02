#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define TOKEN_STRING_MAX_LENGTH 2
#define TOKEN_MAX_NUM 10


typedef enum {
    TERM_OPERATOR   ,
    FACTOR_OPERATOR ,
    COMPARE_OPERATOR
} TOKEN_KIND        ;

typedef struct {
    int kind;
    char str[TOKEN_STRING_MAX_LENGTH];
} TOKEN;

TOKEN initialize_token(void){
    TOKEN initialized_token;
    initialized_token.kind = 4;
    initialized_token.str[0] = 'Z';
    initialized_token.str[1] = '\0';

    return initialized_token;
}

void add_char_to_token_str(TOKEN* token,int* count,char ch){
    // token->str[*count]= ch;
    token->str[0]= ch;
    // *count++;
}

TOKEN get_next_token(FILE *file){
    TOKEN ret = initialize_token();

    int count = 0;

    char ch, ch_more;

    while (true){
        // ch = get_next_char(file);
        ch = fgetc(file);

        // printf("return char from file is %c \n", ch);

        if(isspace(ch)){

            int cnt = 0;
            while(true){
                cnt++;
                if(cnt > 20)break;

                ch = fgetc(file);
                // printf("return char from file is %c \n", ch);
                if(!isspace(ch)) {
                    break;
                }
            }
        }

        if(ch==EOF){
         printf("EOF is found \n");
            break;
        }

        if (ch == '+' || ch == '-'){
            add_char_to_token_str(&ret,&count,ch);
            ret.kind = TERM_OPERATOR;

            // printf("token is detected \n");

            break;
        }

        if (ch == '*' || ch == '/' || ch == '%'){
            add_char_to_token_str(&ret,&count,ch);
            ret.kind = FACTOR_OPERATOR;

            // printf("token is detected \n");

            break;
        }
    }

    // printf("%s is done\n",__func__);
    // printf("token:%c\n", ret.str[0]);

    // ret.str[count] = '\0'; // end of the line 
    return ret;
}

int count_token_num(FILE *file){
    int token_num = 0 ;

    for( int i = 0 ; i < TOKEN_MAX_NUM ; i ++){
        token_num++;
        TOKEN token = get_next_token(file);
        // if(token.str[0]== '\0'){
        //     break;
        // }else{
        //     continue;
        // }
        if(token.str[0]=='Z'||token.str[0]==EOF){
            // printf("Token find is end\n");
            break;
        }
    }

    // printf("token num inside function is %d \n", token_num);

    return token_num;

}
