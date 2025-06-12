#include <string>
#include <vector>
#include <queue>
using namespace std;

string str = "dlru";
int dx[]={1, 0, 0, -1};
int dy[]={0, -1, 1, 0};

class Node{
    public:
    int count;
    int x;
    int y;
    string s;
    
    Node(int x,int y, int count, string s) {
        this->x = x;
        this->y = y;
        this->count = count;
        this->s = s;
    }
};

void dfs(int n, int m, int x, int y, int r, int c, int k, Node& node, string &ans, bool &check){
    if(check) return;
    
    if (k - node.count < abs(node.x-r+1) + abs(node.y-c+1)){
        return;
    }
    
    if((node.x==r-1&&node.y==c-1)&&node.count==k) {
        check = true;
        ans = node.s;
        return;
    }

    for(int i=0; i<4;i++){
        int nx = node.x+dx[i];
        int ny = node.y+dy[i];

        if(nx>=n||nx<0||ny>=m||ny<0) continue; //4 //3
        Node nnode(nx,ny,node.count+1,node.s+str[i]);
        dfs(n,m,x,y,r,c,k,nnode,ans, check);
    }
    
    return;
}
string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "impossible";
    bool check = false;
    Node node(x-1,y-1,0,"");
    
    int remain = abs(x-r) + abs(y-c);
    if ((k - remain) % 2 != 0 || remain > k) {
        answer = "impossible";
    }
    else {
        dfs(n,m,x,y,r,c,k,node,answer,check);
    }
    
    return answer;
}
