#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
map <string,int> m;
int mineral[3][3]={{1,1,1},{5,1,1},{25,5,1}};

void dfs(vector<int> &picks, vector<string> &minerals, int &answer, int location, int sum){
    if(location == minerals.size() || (picks[0]==0&&picks[1]==0&&picks[2]==0)) {
        answer = min(answer,sum);
        return;
    }
    
    for(int i=0; i<3; i++){
        if(picks[i]==0) continue;
        
        picks[i]--;  
        
        int tmp_location = location;
        int tmp_sum = sum;
        
        for(;tmp_location<location+5 &&tmp_location<minerals.size();tmp_location++){
            tmp_sum += mineral[i][m[minerals[tmp_location]]];
        }
        
        dfs(picks, minerals, answer, tmp_location, tmp_sum);
        picks[i]++;  
    }
}
int solution(vector<int> picks, vector<string> minerals) {
    int answer = 25*50+1;
    
    m.insert({"diamond",0});
    m.insert({"iron",1});
    m.insert({"stone",2});
    
    dfs(picks, minerals, answer, 0, 0);
    
    return answer;
}
