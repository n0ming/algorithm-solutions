#include <string>
#include <vector>
#include <bitset>
#include <iostream>
#include <algorithm>

using namespace std;

vector<long long> changeBit(long long num) {
    vector<long long> bit;
    while (num > 0) {
        bit.push_back(num % 2);
        num /= 2;
    }
    reverse(bit.begin(), bit.end());
    
    // 포화 이진트리 크기로 패딩
    long long len = bit.size();
    long long h = 0;
    while ((1 << h) - 1 < len) h++;
    long long full_len = (1 << h) - 1;
    bit.insert(bit.begin(), full_len - len, 0);
    return bit;
}

bool checkRoot(vector<long long> bit){
    if(bit.size() == 1) return true;
    
    int mid = bit.size()/2;
    if (bit[mid] == 0) {
        vector<long long> left(bit.begin(), bit.begin() + mid);
        vector<long long> right(bit.begin() + mid + 1, bit.end());
        
        // 왼쪽/오른쪽 서브트리에 1이 있으면 안 됨
        for (long long b : left) if (b == 1) return false;
        for (long long b : right) if (b == 1) return false;
    }
    
    vector<long long> left(bit.begin(), bit.begin() + mid);
    vector<long long> right(bit.begin() + mid + 1, bit.end());
    
    return checkRoot(left) && checkRoot(right);
}
vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(auto number: numbers){
        vector<long long> bit = changeBit(number);
        
        if(!checkRoot(bit)) answer.push_back(0);
        else answer.push_back(1);
    }
    return answer;
}
