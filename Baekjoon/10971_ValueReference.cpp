/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

int arr[10][10];
int visit[4];
int last, N;
int result = 2e9;
using namespace std;

void solve(int start, int cnt, int result_temp){
    if(cnt == N) {
        if(arr[start][last] !=0) {
            result = min(result,(result_temp + arr[start][last]));
        }
        return;
    }
    
    for(int i=0; i<N; i++){
        if(arr[start][i] !=0 && visit[i]==0) {
            visit[i] =1; //방문 처리
            result_temp += arr[start][i]; //다음 i 여행지 선택
            
            solve(i, cnt+1, result_temp); //그 다음 여행지를 선택하기 위해 재귀함수 호출
            
            visit[i] = 0; //복귀 (result_temp는 값을 참조하기에 복귀 자동으로 됨)
        }
    }
}

int main()
{
    cin >> N;
    for (int i=0; i<N; i++){
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int i=0; i<N; i++){
        last = i;
        visit[i] = 1;
        solve(i, 1, 0);
        visit[i] = 0;
    }
    cout << result <<endl;
    return 0;
}
