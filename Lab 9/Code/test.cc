#include <iostream>

using namespace std;

int g = 20;

void glob(){
    cout<<"\n Global Variable? : "<<g<<endl;
}

int main () {
int i = 1;

int g = 10;

{
    int g = 5;
    cout<<"\n Inside IF : "<<g<<"\n";
}\

    cout<<"\n After IF , Inside Main : "<<g<<endl;

glob();
return 0;

}