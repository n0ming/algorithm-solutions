//소수점 반올림이 안되는 상태
#include <iostream>

using namespace std;

int main(){
    int T, N, C, total_C;
    double  G, total_score;
    
    cin >> T;
    double Score[T]; // 소수접 가능 int Score[T];
    int tC[T];
    for (int n=0; n<T; n++){
        total_score=0;
        total_C = 0;
        cin >> N;
        for(int j=0; j<N; j++){
            cin >> C >> G;
            total_C += C;
            total_score += C*G;
        }
        if(total_score==0){
            Score[n]=0;
        }
        else{
            Score[n] = (total_score)/total_C;
        }
        tC[n] = total_C;
    }
    cout.precision(1);
    cout << fixed;
    for(int i=0; i<T; i++){
        cout << tC[i] << " " << Score[i] << "\n";
    }
}

/*
입력
2
4
3 4.3
2 2.0
4 0.0
2 4.0
3
4 0.0
4 0.0
3 0.0

결과
11 2.3
11 0.0
*/
