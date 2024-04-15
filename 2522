#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    for(int i=1; i<=2*N-1; i++){
        if(i>N){
            for(int j=0; j<=i-N-1; j++){
                cout <<" ";
            }
            for(int j=0; j<=2*N-1-i;j++){
                cout <<"*";
            }
        }
        else{
            for(int j=0; j<N-i; j++){
                cout <<" ";
            }
            for(int j=0; j<i; j++){
                cout << "*";
            }
        }
        cout << "\n";
    }
}
