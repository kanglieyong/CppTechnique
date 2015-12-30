%{
#include <stdio.h>
#include <string.h>
 
void yyerror(const char* s)
{
    printf("ERROR:%s\n",s);
}
 
int main()
{
    FILE * infp = NULL;
    infp = fopen("config.file","r");
    yyrestart(infp);
    yyparse();
    fclose(infp);
    return 0;
}
 
%}
 
%token QUOTE COMMA BRACE_LEFT BRACE_RIGHT BRACEETS_LEFT BRACEETS_RIGHT COLON VALUE_STRING VALUE_FLOAT VALUE_INT
 
%%
root: 
    |
    BRACEETS_LEFT items BRACEETS_RIGHT
    ;
     
items: 
    |
    items COMMA item
    |
    item
    ;
     
item: 
    item_int
    |
    item_float
    |
    item_string
    |
    item_item
    ;
     
item_int: QUOTE VALUE_STRING QUOTE COLON VALUE_INT
    {
        printf("Model item_int![Name:%s]\n",$2);
    }
    ;
     
item_float: QUOTE VALUE_STRING QUOTE COLON VALUE_FLOAT
    {
        printf("Model item_float![Name:%s]\n",$2);
    }
    ;
     
item_string: QUOTE VALUE_STRING QUOTE COLON  QUOTE VALUE_STRING QUOTE
    {
        printf("Model item_string![Name:%s]\n",$2);
    }
    ;
     
roots:
    |
    roots COMMA root
    |
    root
    ;
     
item_item: QUOTE VALUE_STRING QUOTE COLON  BRACE_LEFT roots BRACE_RIGHT
    {
        printf("Model item_item![Name:%s]\n",$2);
    }
    ;
    
