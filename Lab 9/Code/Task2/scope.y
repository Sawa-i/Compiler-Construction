%{
#include <string> 

#include <iostream>

#include <vector>
#include <array>

#include <math.h>

#define YYDEBUG 1

void Push();
std::vector<std::vector<int>> Pop();  
std::vector<std::vector<int>> Top();


std::vector<std::string> id_list = {};

void newIdentifier(std::string id_name, int id_value);
void Identifier(std::string id_name, int id_value);
int returnIdentifier(std::string id_name);


int yylex();
void yyerror();
extern FILE * yyin;

%}

%union {
int val;
char *name;
};



%token keyword_int
%token T_int
%token identifier
%token cout


%%
S : E {  };

E : keyword_int identifier  '=' T_int ';' {newIdentifier(yylval.name, yylval.val);}
| keyword_int identifier';' {newIdentifier(yylval.name, NULL);}
| identifier  '=' T_int ';' {Identifier(yylval.name, yylval.val);}
| cout '<''<' identifier ';'{std::cout<<">> "<<yylval.name<<" = "<<returnIdentifier(yylval.name)<<std::endl;}
| '{' E '}' { Push();}
| '}' E {Pop();}


%%

const int MAXSIZE = 40;
static std::array<std::vector<std::vector<int>>,MAXSIZE> stack;


void Push(){

    std::vector<std::vector<int>> data = {};

    for (int i = MAXSIZE-1; i>0;i--){
        stack[i]=stack[i-1];
    }
    stack[0] = data;
}

std::vector<std::vector<int>> Pop(){
    std::vector<std::vector<int>> data = stack[0];
    for (int i = 0; i<MAXSIZE;i++){
        stack[i]=stack[i+1];
    }
    return data;
}            

std::vector<std::vector<int>> Top(){
    return stack[0];
}


void newIdentifier(std::string id_name, int id_value){
    int detect = 0;
    int target_id = -1;
    for( int i = 0; i<id_list.size() ; i++){
        if(id_name==id_list[i]){
            detect = 1;
            target_id = i;
            break;
        }
    }

    if(detect == 0){
        id_list.push_back(id_name);
        target_id = id_list.size();
    }

    detect = 0;
    for ( int i = 0; i<stack[0].size(); i++){
        if(stack[0][i][0]==target_id){
            detect = 1;
            break;
        }
    }

    if(detect==1){
        // ERROR BECAUSE TWO DECLARATIONS IN SAME SCOPE
        std::cout<< " GIVE ERROR YOU FOOL [NEW]";
    }
    else{
        stack[0].push_back({target_id,id_value});
    }
}

void Identifier(std::string id_name, int id_value){
    int detect = 0;
    int target_id = -1;
    for( int i = 0; i<id_list.size() ; i++){
        if(id_name==id_list[i]){
            detect = 1;
            target_id = i;
            break;
        }
    }

    if(detect == 0){
         // ERROR BECAUSE TWO DECLARATIONS IN SAME SCOPE
        std::cout<< " GIVE ERROR YOU FOOL [ SIMPLE ]";
    }

    detect = 0;
    int detect_j = -1;
    int detect_i = -1;
    for(int j = 0; j<stack.size();j++){
        for ( int i = 0; i<stack[j].size(); i++){
            if(stack[j][i][0]==target_id){
                detect = 1;
                detect_j = j;
                detect_i = i;
                break;
            }
        }
        if(detect == 1){
            break;
        }
    }

    if(detect==1){
        stack[detect_j][detect_i][1]=id_value;
    }
    else{
        // ERROR BECAUSE TWO DECLARATIONS IN SAME SCOPE
        std::cout<< " GIVE ERROR YOU FOOL [SIMPLE 2]";
    }
}

int returnIdentifier(std::string id_name){
    int detect = 0;
    int target_id = -1;
    for( int i = 0; i<id_list.size() ; i++){
        if(id_name==id_list[i]){
            detect = 1;
            target_id = i;
            break;
        }
    }

    if(detect == 0){
         // ERROR BECAUSE TWO DECLARATIONS IN SAME SCOPE
        std::cout<< " GIVE ERROR YOU FOOL [ RETURN SIMPLE ]";
    }

    detect = 0;
    int detect_j = -1;
    int detect_i = -1;
    for(int j = 0; j<stack.size();j++){
        for ( int i = 0; i<stack[j].size(); i++){
            if(stack[j][i][0]==target_id){
                detect = 1;
                detect_j = j;
                detect_i = i;
                break;
            }
        }
        if(detect == 1){
            break;
        }
    }

    if(detect!=1){
        // ERROR BECAUSE TWO DECLARATIONS IN SAME SCOPE
        std::cout<< " GIVE ERROR YOU FOOL [RETRUN SIMPLE 2]";
    }

    return stack[detect_j][detect_i][1];
}

int main() {
    //return yyparse();

    FILE *file = fopen("testcode","r");
    if(!file){
        printf("[-] Can't open the file!\n");
        return -1;
    }
    yyin=file;
    //while(yyparse());
    do
    {
        yyparse();
    } while (!feof(yyin));  
    fclose(file);
    printf("\n");

    return 0;
}
