//블로그 확인함
//안에 가능한 모든 수를 구하고 뺄려고했는데 그부분이 잘못되었음.
//기본적으로 int형을 반환하기에 longlong을 넣어야함
#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    //x^2 + y^2 = c^2
    //y^2 = c^2-x^2
    
    for(int i=1; i<=r2; i++){
        long long maxY = sqrt((long long)r2*r2 - (long long)i*i);
        long long minY = ceil(sqrt((long long)r1*r1 - (long long)i*i));
        if(r1<i) minY =0;
        answer += (maxY-minY+1);
    }
    //cout << answer;
    answer *=4;
    //answer += (r2-r1+1)*4;
    return answer;
}
