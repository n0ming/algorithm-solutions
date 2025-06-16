#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<long long> nums;
    while(N--){
        long long num;
        cin>>num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());

    cin >> N;
    while(N--){
        long long num;
        cin>>num;

        cout << binary_search(nums.begin(), nums.end(), num) << "\n";

    }

    return 0;
}
