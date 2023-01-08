%{
#include <stdio.h>
#include <math.h>
#define YYDEBUG 1

void Push(double data);
double Pop();  
double Top();

%}



%union {
	int i;
	float f;
};

%token T_float
%token T_int

%token func_exp
%token func_log

%%
S : S E '\n' { printf("= %.3lf\n", Top()); }
|
;

E : E '+' T { Push(Pop() + Pop()); }
| E '-' T { double op2 = Pop(); Push(Pop() - op2); }
| T;

T : T '*' F { Push(Pop() * Pop()); }
| T '/' F { double op2 = Pop(); Push(Pop() / op2); }
| B;

B : B '^' F { int power = Pop(); double x = Pop(); double res = 1; for(int i =0; i<power ; i++){ res *=x;} Push(res); res = 1;}
| func_exp '(' B ')' { Push(exp(Pop()));}
| func_log '(' B ')' { Push(log(Pop()));}
| F

F : '(' E ')'
| id ;

id : T_int {Push(yylval.i);}
|  T_float {Push(yylval.f);}

%%

const int MAXSIZE = 40;       
static double stack[40];     

void Push(double data){
    for (int i = MAXSIZE-1; i>0;i--){
        stack[i]=stack[i-1];
    }
    stack[0] = data;
}   

double Pop(){
    double data = stack[0];
    for (int i = 0; i<MAXSIZE;i++){
        stack[i]=stack[i+1];
    }
    return data;
}            

double Top(){
    return stack[0];
}

int main() {
return yyparse();
}