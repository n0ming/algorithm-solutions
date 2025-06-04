#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <iostream>
#include <tuple> 
using namespace std;

//vector<vector<Node>> node(51, vector<Node>(51));
string value[51][51];
pair<int,int> parent[51][51];
vector<pair<int,int>> group[51][51];

pair<int,int> find(int x, int y){
    if(parent[x][y]==make_pair(x,y)) return {x,y};
    return parent[x][y] = find(parent[x][y].first, parent[x][y].second);
}

void updateCell(int x, int y, string val){
    auto p = find(x,y);
    value[p.first][p.second] = val;
}

void updateValue(string value1, string value2){
    for(int i=1;i<51;i++){
        for(int j=1;j<51;j++){
            auto p = find(i,j);
            if(value[p.first][p.second]==value1) 
                value[p.first][p.second] = value2;
        }
    }
}

string printValue(int x, int y){
    auto p = find(x,y);
    return value[p.first][p.second];
}

void unmerge(int x, int y){
    auto p=find(x,y);
    string keep = value[p.first][p.second];
    
    vector<pair<int, int>> members = group[p.first][p.second];
    members.push_back(p); // 대표 포함

    for (auto m : members) {
        parent[m.first][m.second] = m;
        value[m.first][m.second] = "";
        group[m.first][m.second].clear();
    }
    
    value[x][y] = keep;
}

void merge(int x1, int y1, int x2, int y2){
    auto p1 = find(x1,y1);
    auto p2 = find(x2,y2);
    if(p1==p2) return;
    
    //부모 병합
    parent[p2.first][p2.second] = p1;
    
    //값 병합
    if(value[p1.first][p1.second].empty()) 
        value[p1.first][p1.second]=value[p2.first][p2.second];
    
    group[p1.first][p1.second].push_back(p2);
    for(auto g:group[p2.first][p2.second]){
        group[p1.first][p1.second].push_back(g);
    }

    group[p2.first][p2.second].clear();
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    for(int i=1;i<51;i++){
        for(int j=1;j<51;j++){
            parent[i][j]={i,j};
        }
    }
    
    vector<vector<string>> graph(51,vector<string>(51,""));
    
    for(auto c: commands){
        stringstream ss(c);
        
        string command, value1, value2;
        int r1,c1,r2,c2;
        
        ss >> command;
        if(command == "MERGE") {
            stringstream ss(c);
            ss >> command >> r1 >> c1 >> r2 >> c2;
            merge(r1,c1,r2,c2);
            
            
        } else if(command == "UNMERGE") {
            stringstream ss(c);
            ss >> command >> r1 >> c1;
            unmerge(r1, c1);
    
        } else if(command == "PRINT") {
            stringstream ss(c);
            ss >> command >> r1 >> c1;
            
            string str = printValue(r1, c1);
            if(str == "")answer.push_back("EMPTY");
            else answer.push_back(str);
            
        } else if(command == "UPDATE") {
            string token;
            int count =1;
            
            while(ss>>token) count++;
            
            if(count==4) {
                stringstream ss(c);
                ss >> command >> r1 >> c1 >> value1;
                updateCell(r1, c1, value1);
            }
            else if(count==3) {
                stringstream ss(c);
                ss >> command >> value1 >> value2;
                updateValue(value1, value2);
            }
        }
    }

    return answer;
}
