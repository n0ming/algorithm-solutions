#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> targets) {
    vector<bool> visited(targets.size(),false);
    int answer = 0;

    sort(targets.begin(),targets.end());
    
    int i=0;
    while(i<targets.size()){
        int max = targets[i][1];
        answer++;

        while(i<targets.size() && targets[i][0]<max){
            max = min(max,targets[i][1]);
            i++;
        }
    }
    
    return answer;
}
