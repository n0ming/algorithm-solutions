#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int solution(vector<vector<int>> scores) {
    int answer = scores.size();
    int wanghoScore = scores[0][0] + scores[0][1], wanghoRank =1;
    
    vector<vector<int>> tmpScores = scores;
    sort(scores.begin()+1, scores.end());
    for(int i=1; i<scores.size(); i++){ 
        if(scores[0][0]<scores[i][0] && scores[0][1]<scores[i][1]) return -1;
        
        if(wanghoScore>=scores[i][0]+scores[i][1]) {
            answer--;
            continue;
        }
        for(int j=i+1; j<scores.size(); j++) {
            if(scores[i][0]<scores[j][0] && scores[i][1]<scores[j][1]) {
                answer--;
                break;
            }
        }
    }
    return answer;
}

//잘못된 1차 코드 [시간초과]
/*#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int solution(vector<vector<int>> scores) {
    vector<int> deleteRank;
    for(int i=0; i<scores.size(); i++){ //최대 200,000
        for(int j=0; j<scores.size(); j++) {
            if(i==j) continue;
            if(scores[i][0]<scores[j][0] && scores[i][1]<scores[j][1]) {
                deleteRank.push_back(i);
                break;
            }
        }
    }
    
    for(auto e: deleteRank){ //왕호가 안되는 경우를 설정 안함
        if(e==0) return -1;
    }
    
    vector<int> scoreRank;
    for(auto score: scores){ //최대 100,000
        scoreRank.push_back(score[0]+score[1]);
    }
    
    sort(scoreRank.begin(), scoreRank.end());
    
    for(auto e: deleteRank){ //최대 100,000
        scoreRank.erase(find(scoreRank.begin(), scoreRank.end(), scores[e][0]+scores[e][1]));   
    }
    
    int wanghoScore = scores[0][0] + scores[0][1], wanghoRank =1;
    for(auto e: scoreRank){ 
        if(wanghoScore<e) wanghoRank++;
    }
    
    return wanghoRank;
}*/
