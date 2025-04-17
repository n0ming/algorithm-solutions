#include <string>
#include <vector>
#include <queue>

using namespace std;

class ChangeTarget{
  public:
    string str;
    int result;
    vector<bool> visited;
    ChangeTarget(string begin, int size):str(begin), result(0), visited(size, false){      
    }
};

int bfs(string begin, string target, vector<string> words){
    ChangeTarget CT(begin, words.size());
    
    queue<ChangeTarget> q;
    q.push(CT);
    
    while(!q.empty()){
        ChangeTarget curCT = q.front();
        q.pop();
        
        if(curCT.str==target) return curCT.result;
        for(int idx =0; idx<words.size(); idx++){
            if(curCT.visited[idx]) continue;
            
            int count =0;
            string word = words[idx];
            
            for(int i=0; i<begin.size(); i++) {
                if(word[i]!=curCT.str[i]) count++;
            }
            
            if(count ==1) {
                ChangeTarget nextCT = curCT; 
                nextCT.visited[idx] = true;
                nextCT.str = word;
                nextCT.result++;
                q.push(nextCT);
            }
        }
    }
    return 0;
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    bool targetExists = false;
    for (const auto& word : words) {
        if (word == target) {
            targetExists = true;
            break;
        }
    }
    answer = bfs(begin, target, words);
    return answer;
}
