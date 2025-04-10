#include <string>
#include <vector>

using namespace std;
//360도 60초 -> 1초 6도
//360도 60분 3600초 -> 1분 6도 1초 0.1도
//30도 1시간 60분 3600초 -> 1시간 30도 | 1분 0.5도 | 1초 1/120도
class Time {
public:
    int h, m, s;
    
    Time(int second){
        this->h = second/3600;
        this->m = (second%3600)/60;
        this->s = (second%3600)%60;
    }
    
    vector<double> getDegree(){
        double sDegree = s*6.0;
        double mDegree = m*6.0+ s*0.1;
        double hDegree = (h%12)*30 + m*0.5 + s*(1/120.0);
        return vector<double> {hDegree, mDegree, sDegree};
    }
};

bool minuteMatch(vector<double> now, vector<double> next){
    if(now[1]>now[2]&&next[1]<=next[2]) return true;
    
    if(now[2]==354&&now[1]>354) return true;
    
    return false;
}

bool hourMatch(vector<double> now, vector<double> next){
    if(now[0]>now[2]&&next[0]<=next[2]) return true;
    
    if(now[2]==354&&now[0]>354) return true;
    
    return false;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    
    int start = h1*3600+m1*60+s1;
    int end = h2*3600+m2*60+s2;
    
    
    for(int i=start; i<end; i++){
        vector<double> now = Time(i).getDegree();
        vector<double> next = Time(i+1).getDegree();
        
        bool hMatch = hourMatch(now,next);
        bool mMatch = minuteMatch(now,next);
        
        if(hMatch&&mMatch) {
            if(next[0]==next[1]) answer++;
            else answer+=2;
        }
        
        else if(hMatch||mMatch) answer++;
    }
    if(start == 0 || start == 43200) answer++;
    
    return answer;
}
