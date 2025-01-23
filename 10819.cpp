#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> arr;
vector<int> v;
int visit[8];
int result; 

void solve(){
    if(v.size() == N){
        int result_temp = 0;
        for(int i=0; i<N-1; i++){
            result_temp += abs(v[i] - v[i+1]);
        }
        result = max(result, result_temp);
        return;
    } else {
        for(int i=0; i<N; i++){
            if(!visit[i]) {
                visit[i] = 1;
                v.push_back(arr[i]);
                
                solve();
                
                v.pop_back();
                visit[i]=0;
            }
        }
    }
}
int main(){
    int temp;
    
    cin >> N;
    
    for(int i = 0; i<N; i++){
        cin >> temp;
        arr.push_back(temp);
    }
    
    solve();
    cout << result << endl;
    
    return 0;
}
