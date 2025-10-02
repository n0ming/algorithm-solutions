//"가장 작은 숫자들을 순서대로 배열에 담아" answer 부분 정렬 시키기 말것. 문제에 대한 이해 부족 
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    vector<vector<int>> boards(rows, vector<int>(columns, 0));
    // init
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            boards[i][j] = i*columns + j + 1;
        }
    }
    
    vector<int> v;
    for(auto query: queries){
        v.clear();
        int x1 = query[0]-1;
        int y1 = query[1]-1;
        int x2 = query[2]-1;
        int y2 = query[3]-1;
        
        int x_len = abs(x1-x2); 
        int y_len = abs(y1-y2); 
        
        int prev = boards[x1][y1];
        int tmp = 0;
        for(int ny=y1+1; ny<=y1+y_len; ny++){
            v.push_back(prev);
            tmp = boards[x1][ny];
            boards[x1][ny] = prev;
            prev = tmp;
        }
        
        for(int nx=x1+1; nx<=x1+x_len; nx++){
            v.push_back(prev);
            tmp = boards[nx][y1+y_len];
            boards[nx][y1+y_len] = prev;
            prev = tmp;
        }
        
        for(int ny=y2-1; ny>=y1; ny--){
            v.push_back(prev);
            tmp = boards[x1+x_len][ny];
            boards[x1+x_len][ny] = prev;
            prev = tmp;
        }
        
        for(int nx=x2-1; nx>=x1; nx--){
            v.push_back(prev);
            tmp = boards[nx][y1];
            boards[nx][y1] = prev;
            prev = tmp;
        }

        sort(v.begin(), v.end());
        answer.push_back(v[0]);
    }
    return answer;
}
