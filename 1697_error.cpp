//시간 복잡도가 o(3^(M-N))임 즉, 최악으로는 o(3^(100,000))이기에 o(N)의 최대 경우의 수인 10,000,000을 초과함....
#include <iostream>
using namespace std;

int N, M, result;
void solve(int location, int cnt){
    if(cnt >= result) return;
    if(location == M) {
        result = min(cnt, result); 
        return;
    }
    
    int move[3] = {1, -1, location};
    for(int i=0; i<3; i++){
        solve(location + move[i], cnt+1);
    }
}
int main(){
    cin >> N >> M;
    
    result = abs(N-M);
    solve (N, 0);
    
    cout << result;
    return 0;
}
