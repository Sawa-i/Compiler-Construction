%{

    int result;

    int MAXSIZE = 4;       
    int stack[4];     

    void push(int data){
        for (int i = MAXSIZE-1; i>0;i--){
            stack[i]=stack[i-1];
        }
        stack[0] = data;
    }   

    int pop(){
        int data = stack[0];
        for (int i = 0; i<MAXSIZE;i++){
            stack[i]=stack[i+1];
        }
        return data;
    }            


    
%}
%%

([+-/*]) {
    int b = pop();
    int a = pop();
    int result=0;
    switch(yytext[0]){
        case '+':{
            result = a+b;
            break;
        }
        case '-':{
            result = a-b;
            break;
        }
        case '*':{
            result = a*b;
            break;
        }
        case '/':{
            result = a/b;
            break;
        }
    }
    push(result);
    printf("\n%d %d %d %d\n", stack[0], stack[1], stack[2], stack[3]);
}
([\n\t" "]) {}
(([0-9]+)) {
    push(atoi(yytext));
    printf("\n%d %d %d %d\n", stack[0], stack[1], stack[2], stack[3]);}

. {printf("Unrecognized character: "); ECHO; printf("\n");}
%%

int main(int argc, char **argv)
{
FILE *file = fopen("testcode2","r");
if(!file){
    printf("[-] Can't open the file!\n");
    return -1;
}
yyin=file;
while(yylex());
fclose(file);
printf("\n[+] Result = %d\n\n",stack[0]);
}