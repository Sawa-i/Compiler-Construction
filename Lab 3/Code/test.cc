#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

class Token{
    public:
    string name;
    string value;
    int hash;
};

int main() {    
    list<Token> lol;
    Token sample;
    sample.name = "OP";
    sample.value = "+";
    sample.hash= 44412;
    lol.push_back(sample);

    for (Token a: lol){
           cout<<a.name<<'\t'<<a.value<<'\t'<<a.hash<<'\n';
    }

} 