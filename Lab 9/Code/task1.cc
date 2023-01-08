#include <iostream>
using namespace std;

#include <vector>
#include<string>

#include <typeinfo>

/********************************* DECLARATIONS ******************************/

string input;

vector<char> num_list = {'0','1','2','3','4','5','6','7','8','9','.'};

int main(){
    cout<<"\n\t ********** TASK 1 ************* \n\n";



    cout<<"[?] Enter any value : ";
    getline(cin, input);
    
    int mode = -1; // 0 : STRING, 1: INT, 2: FLOAT, 3: DOUBLE


    for(char c : input){
        
        int num_check = 0;
        for(char n : num_list){
            if (c == n){
                num_check = 1;
                if(n == '.' && mode !=2){
                    mode =2;
                }
                else if(n == '.' && mode == 2){
                    num_check = 0 ;
                }
                break;
            }
        }

        if(num_check == 0){
            mode=0;
            break;
        }
    }

    if(mode == 0){
        string value = input;

        cout<<"\n\t[+] Value Entered : "<<value<<endl;
        cout<<"\n\t[+] Value Type : String ("<<typeid(value).name()<<")"<<endl;
    }
    else if (mode != 2){
        int value = stoi(input);

        cout<<"\n\t[+] Value Entered : "<<value<<endl;
        cout<<"\n\t[+] Value Type : Int ("<<typeid(value).name()<<")"<<endl;
    }
    else{
        string partA = "";

        string partB = "";
        int bCounter = 0;

        int gear = 0;
        for(char c : input){
            if(gear == 0){
                if(c == '.'){
                    gear =1;
                    continue;
                }
                partA = partA + c;
            }
            else if ( gear == 1){
                partB = partB + c;
                bCounter++;
            }
        }


        if (partA.length()==0){
            partA+='0';
        }

        if (partB.length()==0){
            partB+='0';
        }

        if(bCounter > 7){
             double value = stod(partA+"."+partB);

            cout<<"\n\t[+] Value Entered : "<<value<<endl;
            cout<<"\n\t[+] Value Type : Double ("<<typeid(value).name()<<")"<<endl;
        }
        else{
            float value = stof(partA+"."+partB);

            cout<<"\n\t[+] Value Entered : "<<value<<endl;
            cout<<"\n\t[+] Value Type : Float ("<<typeid(value).name()<<")"<<endl;
        }
    }

    cout<<endl;
}
