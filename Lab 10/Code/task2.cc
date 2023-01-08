#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main(){

    fstream my_file;
    fstream new_file;

    my_file.open("task1_sloppy.cc", ios::in);
    new_file.open("task2_resultant.cc",ios::out);
    if (!my_file) {
        cout << "[-]File not found.!";
    }
   
    cout << "[+] File opened successfully!\n";

    string line;
        
    string new_line = "";


    int mode = 0;
    while(getline (my_file, line)){

        for (int i=0; i<line.length(); i++){
            
            if(mode==-2){
                if(line[i]==';')
                {
                    new_line+=';';
                    mode = -1;
                }
            }
            else if (mode == -1){
                if(line[i]=='}'){
                mode=0;
                }
            }
            else if(line[i] == '{' ){
                mode =1;
            }
            else if(line.substr(i,6) == "return"&& mode ==1){
                mode = -2;
                new_line+="return";
                i=i+5;
                continue;
            }
            
            if(mode!=-1)
                new_line+=line[i];
        }
        
        
        
        new_line+="\n";
        }


    new_file<<new_line;
    my_file.close(); 
    new_file.close();

    cout<< "[+] New File Written successfully!\n";

}