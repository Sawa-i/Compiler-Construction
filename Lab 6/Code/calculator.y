%{
#include <stdio.h>

void Push(int data);
int Pop();  
int Top();

%}

%token T_Int

%%
S : S E '\n' { printf("= %d\n", Top()); }
|
;
E : E E '+' { Push(Pop() + Pop()); }
| E E '-' { int op2 = Pop(); Push(Pop() - op2); }
| E E '*' { Push(Pop() * Pop()); }
| E E '/' { int op2 = Pop(); Push(Pop() / op2); }
| T_Int { Push(yylval); }
;
%%

const int MAXSIZE = 40;       
static int stack[40];     

void Push(int data){
    for (int i = MAXSIZE-1; i>0;i--){
        stack[i]=stack[i-1];
    }
    stack[0] = data;
}   

int Pop(){
    int data = stack[0];
    for (int i = 0; i<MAXSIZE;i++){
        stack[i]=stack[i+1];
    }
    return data;
}            

int Top(){
    return stack[0];
}

int main() {
return yyparse();
}