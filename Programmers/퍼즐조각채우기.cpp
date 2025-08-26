#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int dx[] ={0,0,1,-1};
int dy[] = {1,-1,0,0};
int xSize;

struct Node{
    int x;
    int y;
    vector<pair<int,int>> savedBlock;
};

// 좌표를 (0,0) 기준으로 정규화
vector<pair<int,int>> normalize(vector<pair<int,int>> block) {
    int minX = 1e9, minY = 1e9;
    for (auto &p : block) {
        minX = min(minX, p.first);
        minY = min(minY, p.second);
    }
    for (auto &p : block) {
        p.first -= minX;
        p.second -= minY;
    }
    sort(block.begin(), block.end());
    return block;
}

// 블록 회전
vector<pair<int,int>> rotateBlock(const vector<pair<int,int>>& block) {
    vector<pair<int,int>> rotated;
    for (auto [x,y] : block) {
        rotated.push_back({xSize-y-1, x}); // 90도 회전
    }
    return normalize(rotated);
}

// 블록의 모든 회전 구하기
vector<vector<pair<int,int>>> getRotations(vector<pair<int,int>> block) {
    vector<vector<pair<int,int>>> rotations;
    block = normalize(block);
    rotations.push_back(block);
    for (int i=0; i<3; i++) {
        block = rotateBlock(block);
        rotations.push_back(block);
    }
    return rotations;
}

// 두 블록이 같은지 (회전 포함) 확인
bool isSameBlock(const vector<pair<int,int>>& a, const vector<pair<int,int>>& b) {
    auto rotations = getRotations(b);
    for (auto &r : rotations) {
        if (a == r) return true;
    }
    return false;
}

vector<vector<pair<int,int>>> bfs(vector<vector<int>> board, int check){
    int n = board.size();
    vector<vector<int>> visited(n, vector<int>(n,0));
    vector<vector<pair<int,int>>> blocks;

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (visited[i][j] || board[i][j]!=check) continue;

            queue<pair<int,int>> q;
            vector<pair<int,int>> tmp;
            visited[i][j]=1;
            q.push({i,j});
            tmp.push_back({i,j});

            while(!q.empty()){
                auto [x,y]=q.front(); q.pop();
                for (int d=0;d<4;d++){
                    int nx=x+dx[d], ny=y+dy[d];
                    if (nx<0||ny<0||nx>=n||ny>=n) continue;
                    if (visited[nx][ny] || board[nx][ny]!=check) continue;
                    visited[nx][ny]=1;
                    q.push({nx,ny});
                    tmp.push_back({nx,ny});
                }
            }
            blocks.push_back(normalize(tmp));
        }
    }
    return blocks;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    auto gameBlocks = bfs(game_board, 0); // 빈칸
    auto tableBlocks = bfs(table, 1);     // 블록
    
    vector<int> used(tableBlocks.size(), 0);

    for (auto &gb : gameBlocks) {
        for (int i=0; i<tableBlocks.size(); i++) {
            if (used[i]) continue;
            if (isSameBlock(gb, tableBlocks[i])) {
                answer += gb.size(); // 채운 칸 수 누적
                used[i] = 1;
                break;
            }
        }
    }
    return answer;
}
