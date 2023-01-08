%{
    #include "calculator.tab.h"
%}


%%

[0-9]+ { yylval.i = atoi(yytext); return T_int;}
[0-9]+[.][0-9]+ {yylval.f = atof(yytext); return T_float;}
[-+*/^()\n] { return yytext[0];}
[l][o][g] { return func_log;}
[e][x][p] { return func_exp;}
. { /* ignore everything else */ }

%%