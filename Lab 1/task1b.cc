#include <iostream>
using namespace std;

int main() {    
    string str;

    cout << "Enter a String: ";
    cin >> str;


    // Validation of ALphabet
    for (char c : str){
        if (c != 'a' && c!= 'b' && c!='c'){
            cout << "[-] Input string is invalid ( i.e. doesn't belong to {a,b,c} )\n\n";
            return 0;
        }
    }

    // Switch implementation
    int state = 0;

    for (char c : str){
        switch(state){
            case 0:{
                switch(c){
                    case 'a':{
                        state = 1;
                        break;
                    }
                    default:{
                        state = 4;
                        break;
                    }
                }
                break;
            }
            case 1:{
                switch(c){
                    case 'b':{
                        state = 2;
                        break;
                    }
                    default:{
                        state = 4;
                        break;
                    }
                }
                break;
            }
            case 2:{
                switch(c){
                    case 'c':{
                        state=3;
                        break;
                    }
                    case 'b':{
                        state = 1;
                        break;
                    }
                    default:{
                        state = 4;
                        break;
                    }
                }
                break;
            }
            case 3:{
                switch(c){
                    case 'a':
                    case 'b':
                    case 'c':{
                        state = 4;
                        break;
                        }
                }
                break;
            }            
        }
    }
    
    switch(state){
        case 3:{
            cout << "[+]Your entered string '" << str << "' is acceptable\n\n";
            return 1; 
        }
        default:{
            cout << "[-]Your entered string '" << str << "' is unacceptable\n\n";
            return 0; 
        }
    }
}