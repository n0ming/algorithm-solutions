#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
//반복개수 + 값
//반복x 1개값은 생략
//1개 단위가 아닌 2개 단위로 잘라서 압축하여 표현함

//구현 방법
//1000 이하의 문자열이기 때문에 1000번 반복해도 충분함
using namespace std;
int solution(string s) {
    size_t answer = 1000;
    set <string> aph;
    map<string,int> m;
    
    if (s.size() == 1) return 1; // 예외처리는 필수임!!
    
    for(int cut=1; cut<s.size(); cut++){
        string final_str;
        int cnt = 0;
        string pre_str = "";
        for(int i=0; i<s.size(); i+=cut){
            string m_str = s.substr(i,cut);
            if(pre_str =="" || m_str == pre_str) {
                cnt ++; //m_str처음 등장
            }
            else {
                if(cnt !=1) final_str += pre_str + to_string(cnt); //pre_str 연속 등장 끝
                else final_str += pre_str;
                cnt = 1;
            }
            pre_str = m_str;
        }
        if(cnt !=1) final_str += pre_str + to_string(cnt); 
        else final_str += pre_str;
        answer = min(answer,final_str.size());
        
    }
    return answer;
}
