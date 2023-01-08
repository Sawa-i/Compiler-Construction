%{
    #include "scope.tab.h"
%}


%%

[0-9]+ { yylval.val = atoi(yytext); return T_int;}
[=;{}<] { return yytext[0];}
[i][n][t] { return keyword_int;}
[c][o][u][t] {return cout;}
[a-zA-Z_][a-zA-Z_0-9]* { yylval.name = yytext; return identifier;}
. { /* ignore everything else */ }

%%


/*
int main(int argc, char **argv)
{
FILE *file = fopen("testcode","r");
if(!file){
printf("[-] Can't open the file!\n");
return -1;
}
yyin=file;
while(yylex());
fclose(file);
printf("\n");
}*/