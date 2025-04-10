//여러번 틀리고, 결국 gpt한테 몇개 물어봄 (시간초과도 함)
#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;
int n, m;
int min_A = INT_MAX;
vector<vector<int>> sub_info;
vector<vector<vector <int>>> dp;

int sub_solution(int index, int total_A, int total_B){
    if(total_A >= n || total_B >= m) return INT_MAX;
    
    if(index == sub_info.size()) {
        return total_A;
    }
    
    if(dp[index][total_A][total_B] != -1) return dp[index][total_A][total_B];
    
    int take_A = sub_solution(index+1, total_A+sub_info[index][0], total_B); 
    int take_B = sub_solution(index+1, total_A, total_B+sub_info[index][1]);
    
    return dp[index][total_A][total_B] = min(take_A,take_B);
}

int solution(vector<vector<int>> info, int input_n, int input_m) {
    sub_info = info;
    n = input_n;
    m = input_m;
    
    dp.assign(info.size(), vector<vector<int>>(n+1, vector<int>(m+1, -1))); //[index][n][m]
    int result = sub_solution(0,0,0);
    
    return (result==INT_MAX) ? -1 : result;
}

int main(){
    vector<vector<int>> info(40,vector<int> (2));
    for(int i=0; i<40; i++){
            cin >> info[i][0] >> info[i][1];
    }
    
    cin >> n >> m;
    cout << solution(info, n, m);
    
    return 0;
}
