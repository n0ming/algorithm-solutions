/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

int arr[3][3];
string goal ="123456780";
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

string arrayToString(int arr[3][3]){
    string result = "";
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++){
            result += to_string(arr[i][j]);
        }
    }
    return result;
}


void solve(int arr[3][3]){
    string start = arrayToString(arr);
    map<string, bool> visit;
    queue<pair<string, int>> q;
    
    visit[start] = true;
    q.push({start,0});
    
    while(!q.empty()){
        string cur = q.front().first;
        int time = q.front().second;
        
        q.pop();
        
        if(cur == goal) {
            cout << time <<endl;
            return;
        }
        
        //0확인
        int zero_pos = cur.find('0');
        int x = zero_pos/3;
        int y = zero_pos%3;
        
        for(int i=0; i<4; i++){
            if(x+dx[i]<0 || x+dx[i]>=3 || y+dy[i]<0 || y+dy[i]>=3) continue;;
            string next = cur;
            swap(next[x * 3 + y], next[(x+dx[i]) * 3 + y+dy[i]]);
            
            if(!visit[next]) {
                visit[next] = true;
                q.push({next, time+1});
            }
        }
    }
    
    cout << "-1" <<endl;
}
int main()
{
    for(int i=0; i<3; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    
    solve(arr);

    return 0;
}
