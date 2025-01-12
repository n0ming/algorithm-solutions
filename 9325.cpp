#include <iostream>
using namespace std;

int main(){
    int case_num, s,n,q,p;
    cin >> case_num;
    int total[case_num] ={0};
    for(int i=0; i<case_num; i++){
        cin >> s;
        cin >> n;
        for(int j=0; j<n; j++){
            cin >> q >> p;
            total[i] += q*p;
        }
        total[i] += s;
    }
    for(int i=0; i<case_num; i++){
        cout << total[i]<<"\n";
    }
    
    
}
