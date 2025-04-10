#include <iostream>
using namespace std;
int main()
{
    int E, S, M ;
    int e =1, s=1, m = 1;
    cin >> E >> S >> M;
    
    int result = 1;
    while(true){
        if (E==e && S==s && M==m) break;
        if(++e > 15) e -= 15;
        if(++s > 28) s -= 28;
        if(++m > 19) m -= 19;
        result++;
    }
    
    cout << result << "\n";
    return 0;
}
