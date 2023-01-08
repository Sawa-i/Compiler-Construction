#include <iostream>
using namespace std;

int main() {    
    string str = "";

    cout << "Enter a String: ";
    getline(cin,str);

    // Validation of ALphabet
    for (char c : str){
        if (c != 'a' && c!= 'b'){
            cout << "[-] Input string is invalid ( i.e. doesn't belong to {a,b} )\n\n";
            return 0;
        }
    }

    // GOTO implementation
    int i = 0;
    s0:
    if (str[i] == 'a'){
        i++;
    }
    else if (str[i] == 'b'){
        i++;
        goto s3;
    }
    else if (str.length() == i){
        cout << "[+]Your entered string '" << str << "' is acceptable\n\n";
        return 1;    
    }
    
    s1:
    if (str[i] == 'b'){
        i++;
    }
    else if(str[i] =='a'){
        i++;
        goto s0;
    }

    s2:
    if (str[i] == 'a'){
        i++;
    }
    else if(str[i] == 'b'){
        i++;
        goto s1;
    }

    s3: // State Final
    if (str[i] == 'a'){
        i++;
        goto s2;
    }
    else if(str[i] == 'b'){
        i++;
        goto s0;
    }
    
    cout << "[-]Your entered string '" << str << "' is unacceptable\n\n";
    return 0; 
} 