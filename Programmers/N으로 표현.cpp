#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    
    vector<unordered_set<int>> s(8);
    int S = 0;
    for(int i=0; i<8; i++){
        S = S*10 + N;
        s[i].insert(S);
        
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++) {
                if(k+j+1!=i) continue;
                
                for(auto one: s[j]) {
                    for(auto two : s[k]){
                        s[i].insert(one+two);
                        s[i].insert(one*two);
                        
                        if(one-two>0) s[i].insert(one-two);
                        if(one/two>0) s[i].insert(one/two);
                    }
                }
            }
        }
        if(s[i].find(number)!=s[i].end()) return i+1;
    }
    return -1;
}