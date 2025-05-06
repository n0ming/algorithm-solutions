#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector <int>> mentors;
void conbination(int k, int n, vector<int> mentor){
    if(k==0&&n==0){
        mentors.push_back(mentor);
        return;
    }
    
    for(int i=1; i<=n; i++){
        mentor.push_back(i);
        conbination(k-1, n-i, mentor);
        mentor.pop_back();
    }
}

int cal(vector<int> mentor,int k, vector<vector<int>> reqs){
    priority_queue<int,vector<int>,greater<int>> q[k];
    
    int result = 0;
    
    //가장 작은 멘토 시간과 요청 시간을 비교해서 / 멘토<요청 이면, 바로 pop하고 push
    //멘토>요청 이면, 멘토-요청만큼 대기시간 발생 후, pop하고 push
    
    for(int i=0; i<k; i++){
        for(int j=0; j<mentor[i]; j++) q[i].push(0);
    }
    
    for(auto req: reqs){
        int req_time = req[0];
        int talk_time = req[1];
        int mentor_num = req[2]-1;
        
        int mentor_time = q[mentor_num].top();
        q[mentor_num].pop();
        
        if(mentor_time<=req_time) {
            q[mentor_num].push(req_time+talk_time);
        } else if(mentor_time>req_time){
            q[mentor_num].push(mentor_time+talk_time);
            result += mentor_time-req_time;
        }
    }
    
    return result;
    
}
int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 99999999;
    
    vector<int> tmp;
    conbination(k,n,tmp);
    
    for(auto mentor: mentors){
        answer = min(answer, cal(mentor, k, reqs));
    }
    return answer;
}
