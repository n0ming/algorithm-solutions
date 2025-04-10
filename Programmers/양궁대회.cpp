#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> answer(11, 0);
vector<int> lion(11, 0); // 10점이 0번째 배열임
vector<int> global_info;
int score = 0;
// 점수 계산 함수
vector<int> compare_low(vector<int> answer, vector<int> lion) {
    for (int i = 10; i >= 0; i--) {
        if (lion[i] > answer[i]) return lion;  // 더 큰 점수 차이를 기록
        else if(lion[i] < answer[i]) return answer; // 점수가 같지 않으면 answer 반환
    }
    return answer;  // 모두 같으면 현재 answer 반환
}

void back(int i, int n, vector<int> lion, int total) {
    if (i == 11) { // 11번째까지 다 진행했으면
        if (total == n) { // 총 점수가 정확히 n점일 때만 점수 계산
            int peach_score = 0;
            int lion_score = 0;
            for (int i = 0; i < 11; i++) {
                if (global_info[i] != 0 && global_info[i] >= lion[i]) peach_score += 10 - i; // peach가 더 많은 점수를 받으면 peach_score 증가
                 else if (global_info[i] < lion[i]) lion_score += 10 - i; // lion이 더 많은 점수를 받으면 lion_score 증가
            }

            if (lion_score > peach_score) {
                if(lion_score > score) {
                    answer = lion;
                    score = lion_score;
                } else if (lion_score == score) {
                    compare_low(answer, lion);
                    score = lion_score;
                }
            }
        }
        return;
    }

    // 가능한 점수 차이만큼 점수 할당
    for (int k = 0; k <= n - total; k++) {
        lion[i] = k;
        back(i + 1, n, lion, total + k); // i+1로 넘어가며 점수 추가
    }
}

vector<int> solution(int n, vector<int> info) {
    global_info = info;
    back(0, n, lion, 0); // 백트래킹 시작
    
    for(int i=0; i<11; i++){
        if(answer[i]!=0) return answer;
    }
    
    vector<int> answer(1,-1);
    return answer;
}
