#include <iostream>
using namespace std;

int main(){
    int N, student, apple;
    cin >> N;
    int total = 0;
    for(int i=0; i<N; i++){
        cin>> student >>  apple;
        for (int j=1;j<=100;j++){
            if(apple< student*j){
                total += apple - student*(j-1);
                break;    
            }
        }
    }
    cout << total;
    
}
