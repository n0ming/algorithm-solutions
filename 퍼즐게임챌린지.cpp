//첫번째로 40분 이내로 풀었지만 시간초과로 0점.
//두번째로 50분 이내로 품. 하지만 70점 맞음. 몇개 시간 초과가 있음

#include <iostream>
#include <string>
#include <vector>
//n번 틀리면 (time[i]+time[i-1])*n + time[i]
//안틀리면 time[i]
using namespace std;
int over_limit_level = 0;
void check(vector<int> diffs, vector<int> times, int level, long long limit){
    long long total_time = 0;
    for(int i=0; i<diffs.size(); i++){
        if(diffs[i]<= level) total_time += times[i];
        else {
            total_time += (times[i]+times[i-1]) * (diffs[i]-level) + times[i];
        }
    }
    if(total_time < limit) {
        check(diffs, times, level/2, limit);
    } else{
        over_limit_level = level;
    }
}
int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int max_diffs = 0;
    for(int i=0; i<diffs.size()-1; i++){
        max_diffs = max(diffs[i], diffs[i+1]);
    }
    
    int level = max_diffs;
    
    check(diffs,times,level,limit);
    cout << over_limit_level;
    level = over_limit_level;
    while(true){
        long long total_time = 0;
        for(int i=0; i<diffs.size(); i++){
            if(diffs[i]<= level) total_time += times[i];
            else {
                total_time += (times[i]+times[i-1]) * (diffs[i]-level) + times[i];
            }
        }
        if(total_time <= limit) {
            return level;
        }
        level++;
    }
    
    return answer;
}
