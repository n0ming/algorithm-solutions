#include <string>
#include <vector>
#include <sstream>
#include<algorithm>

using namespace std;
vector <int> v;

bool compare(const int& a, const int& b){
    return a> b;
}
void insert(string op){
    stringstream str(op);
    
    string cmd;
    int num;
    str >> cmd >> num;

    v.push_back(num);
}
void printMin(){
    if (v.empty()) return;
    sort(v.begin(), v. end());
    v.erase(v.begin());
}
void printMax(){
    if (v.empty()) return;
    sort(v.begin(), v. end(), compare);
    v.erase(v.begin());
}
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    for(auto op: operations){
        if(op.substr(0,1)=="I") insert(op);
        else if (op=="D -1") printMin();
        else if (op=="D 1") printMax();
    }
    
    if (v.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        sort(v.begin(), v.end());
        answer.push_back(v.back());  
        answer.push_back(v.front()); 
    }
    return answer;
}
