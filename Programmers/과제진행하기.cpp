#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

struct Task{
    string name;
    int start;
    int playTime;
};

int toMinutes(string time){
    int h = stoi(time.substr(0,time.find(":")));
    int m = stoi(time.substr(time.find(":")+1));
    return h*60 + m;
}

bool compare(Task a, Task b){
    return a.start < b.start;
}
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<Task> task;
    
    for(auto plan: plans){
        task.push_back({plan[0], toMinutes(plan[1]), stoi(plan[2])});
    }
    
    sort(task.begin(), task.end(), compare);
    
    stack<Task> st;
    for(int i=0; i<task.size()-1; i++){
        Task cur = task[i];
        Task next = task[i+1];
        
        int timeGap = next.start - cur.start;
        
        if(cur.playTime <= timeGap){
            answer.push_back(cur.name);
            int spare = timeGap - cur.playTime;
            
            while(spare>0 && !st.empty()){
                Task top = st.top();
                st.pop();
                
                if(top.playTime <= spare) {
                    spare -= top.playTime;
                    answer.push_back(top.name);
                } else {
                    top.playTime -= spare;
                    st.push(top);
                    break;
                }
            }
        } else {
            cur.playTime -= timeGap;
            st.push(cur);
        }
    }
    
    answer.push_back(task.back().name);
    
    while(!st.empty()){
        answer.push_back(st.top().name);
        st.pop();
    }

    return answer;
}
