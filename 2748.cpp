// 2번째 수를 원한다면 반복문을 통해 0과 1서부터 계산을 시작한다. 
#include <iostream>
using namespace std;

int main()
{
    int k;
    cin >> k;
    
    long long a = 0, b = 1, result = 0;
    
    if(k ==0) {
        cout << a <<'\n';
        return 0;
    }
    else if(k==1) {
        cout << b <<'\n';
        return 0;
    }
    
    for(int i=2; i<=k; i++){
        result = a+b;
        a = b;
        b = result;
    }
    
    cout << result << '\n';

    return 0;
}
