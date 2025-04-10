#include <iostream>
using namespace std;

int main(){
    int N, M, tmp=0;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> M;
        tmp += M;
    }
    tmp = tmp - N +1;
    cout << tmp;
}
