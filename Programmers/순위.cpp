#include <string>
#include <vector>

using namespace std;

vector<vector<int>> graph(101,vector<int>(101,0));

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(auto result: results){
        graph[result[0]][result[1]]=1;
        graph[result[1]][result[0]]=-1;
    }
    
     // 플로이드-워셜 알고리즘
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][k] == 1 && graph[k][j] == 1) {
                    graph[i][j] = 1;
                }
                if (graph[i][k] == -1 && graph[k][j] == -1) {
                    graph[i][j] = -1;
                }
            }
        }
    }
    for(int i=1; i<n+1; i++){
        int count =0;
        for(int k=1; k<n+1; k++){
            if(i==k) continue; //자기자신은 넘김
            if(graph[i][k]!=0) count++;
        }
        if(count==n-1) answer++;
    }
    
    return answer;
}
