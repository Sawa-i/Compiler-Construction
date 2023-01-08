#include <iostream>

using namespace std;

int main(){

    cout<<"\nAverage Program\n\n";
    int a,b;

    int x = 2; // CONSTANT FOLDING : EVALUATED

    cout<<"Enter number A : ";
    cin>>a;

    // DEAD CODE : REMOVED


    cout<<"Enter number B : ";
    cin>>b;

    // ALGEBRAIC SIMPLIFICATION
    a = a*a; 
    b = b*b;
    
    int z = (a+b)/2;     // CONSTAMT PROPAGTION : SUBSTITUTED


    cout<<"\nSum Z : "<<z<<endl; 

    return 0;

    // UNREACHABLE CODE : REMOVED
}