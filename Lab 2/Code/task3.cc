#include <iostream>
#include <list>
#include <fstream> 
#include <algorithm>
#include <bits/stdc++.h> 

using namespace std;

void commentLess(ifstream *file);

// Reading File and lexer_seg Analysis
int main(){
    string filename = "../Lab2Files/input_scanner.c";
    ifstream file(filename);

    commentLess(&file);


    file.close();
}

void commentLess(ifstream *file){
    ofstream file_new("commentless.c");

    string iLine;
    string tempLine="";
    char tempW='\0'; 
    int commentMulti=0;
    char c_shadow='\0';
    
    while(getline(*file,iLine)){
        for (char c: iLine){
            if(commentMulti==1){
                if(c=='/' && c_shadow == '*'){
                    if(tempW=='/'){
                        tempW='\0';
                    }
                    commentMulti = 0;
                }
            }
            else if(c=='/' && c_shadow!='/' ){
                tempW='/';
            }
            else if(c=='/' && c_shadow=='/'){
                if(tempW == '/'){
                    tempW='\0';
                }
                tempLine+='\n';
                break;
            }
            else if(c=='*' && c_shadow == '/'){
                if(tempW=='/'){
                    tempW='\0';
                }
                commentMulti = 1;
            }
            else{
                if(tempW == '/'){
                    tempLine+=tempW;
                    tempW='\0';
                }
                tempLine+=c;
            }
            c_shadow = c;
        }
        if(commentMulti==1){
            tempLine+='\n';
        }
        file_new << tempLine;                        
        tempLine.clear();
    }
    file_new.close();
}
