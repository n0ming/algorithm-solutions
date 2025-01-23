#include <iostream>
#include <vector>
using namespace std;

int visit[11];
int arr[11][11];
int result_temp = 0;
int result = 2e9;
int N, M;

void solve(int i, int count, int start){
    count ++;
    if(count == N) {
        if(arr[i][start] !=0){
            result_temp += arr[i][start];
            result = min(result_temp, result);
            result_temp -= arr[i][start];  
        }
        return;
    }
    for(int j=0; j<N; j++){
        if(arr[i][j] !=0 && visit[j] == 0) {
            result_temp += arr[i][j];  
            visit[j]= 1;
            
            solve(j, count, start);
            
            result_temp -= arr[i][j];  
            visit[j] = 0;           
        }
    }
}
int main(){
    cin >> N;
    
    for(int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        visit[i]= 1;
        solve(i,0, i);
    }
    
    cout << result <<endl;
    return 0;
}
