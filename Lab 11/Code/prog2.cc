#include <iostream>

using namespace std;

int main(){

    int N = 100;
    int A[N], B[N], C[N], D[N];

    for(int i=0 ; i<N;i++){
        B[i] = rand()%100;
        A[i] = B[i] + 1;
        C[i] = A[i] / 2;
        D[i] = 1 / (C[i]+1); // C[i+1] is INDEX OUT OF BOUND, HENCE CHANGED
    }

}