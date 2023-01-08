
 #include <iostream>

using namespace std;

int main(){



    cout<<"\n\t { Program to compare two programs million executions }\n";

    int T = 1000000;


    clock_t begin_time = clock();


    cout<<"\n[+] Program 1 (Loop Non-Fusion) - No. of Executions : "<<T<<" :-\n";
    for(int i = 0; i<T; i++){
        system("./prog1");

        if(i%100000==0){
            cout<<"\n< 1/10th Part Covered >\n";
        }

    }

    float duration = float( clock () - begin_time ) /  CLOCKS_PER_SEC;
    
    cout<<"\n\t>Processor Time Taken = "<<duration<<" seconds\n";


    begin_time = clock();

    cout<<"\n[+] Program 2 (Loop Fusion) - No. of Executions : "<<T<<" :-\n";

    for(int i = 0; i<T; i++){
        system("./prog2");

        if(i%100000==0){
            cout<<"\n< 1/10th Part Covered >\n";
        }
    }

    duration = float( clock () - begin_time ) /  CLOCKS_PER_SEC;

    cout<<"\n\t>Processor Time Taken = "<<duration<<" seconds\n\n";

}