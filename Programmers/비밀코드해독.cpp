//오름차순에 서로다룬 숫자 5개가 조건이였음.. 조건을 잘보자
//간단하게 dfs로 11111부터 끝까지 구하면 됨. n은 30개이기때문에 30^5이 10^9보다 작아서 괜찮다...
#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<vector<int>> global_q; 
vector<int> global_ans;
int answer = 0;

bool checkcode(vector<int> pass){
    for(int i=0; i<global_q.size(); i++){
        int pass_cnt = 0;
        for(int e: global_q[i]){
            for(int p: pass){
                if(e==p) pass_cnt++;
            }
        }
        if(pass_cnt!=global_ans[i]) return false;
    }
    
    return true;
}
void conbination(vector<int> pass, int start, int max){
    if(start == 5) {
        if(checkcode(pass)) answer++;
        return;
    }
        for(int j=1; j<=max; j++){
            if(start !=0 && pass[start-1] >= j) continue;
            pass[start] = j;  
            conbination(pass, start+1, max);
        }
}
int solution(int n, vector<vector<int>> q, vector<int> ans) {
    for(auto qq: q){
        global_q.push_back(qq);
    }
    for(auto a: ans){
        global_ans.push_back(a);
    }
    
    vector<int> pass(5,0);
    
    conbination(pass,0,n);
    
    return answer;
}ㅂ
