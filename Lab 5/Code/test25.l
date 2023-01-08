%%
(("if"|("then")|("begin")|("end")|("procedure")|("function"))) {printf("A keyword: "); ECHO; printf("\n");}
([+-/*]) {printf("An Operator: "); ECHO; printf("\n");}
([\n\t" "]) {}
(([0-9]+)(.[0-9]+)) {printf("A float: "); ECHO; printf("\n");}
(([0-9]+)) {printf("A integer: "); ECHO; printf("\n");}
([a-z]+[0-9a-zA-Z]*) {printf("An id: "); ECHO; printf("\n");}

. {printf("Unrecognized character: "); ECHO; printf("\n");}
%%

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
}