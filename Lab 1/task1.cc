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

    // GOTO implementation
    int i = 0;
    s0:
    if (str[i] == 'a'){
        i++;
    }
    else {
        goto s4;
    }
    
    s1:
    if (str[i] == 'b'){
        i++;
    }
    else {
        goto s4;
    }

    s2:
    if (str[i] == 'c'){
        i++;
    }
    else if(str[i] == 'b'){
        i++;
        goto s1;
    }
    else {
        goto s4;
    }

    s3: // State Final
    if (str.length() == i){
    cout << "[+]Your entered string '" << str << "' is acceptable\n\n";
    return 1;    
    }
    
    s4: //Garbage state
    cout << "[-]Your entered string '" << str << "' is unacceptable\n\n";
    return 0; 
} 