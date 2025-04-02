#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

map<char, int> aph;
map<int, char> int_aph;
vector<long long> bans_location;

long long fastPow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}

string solution(long long n, vector<string> bans) {
    string answer = "";
    
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < alphabet.size(); i++) {
        aph[alphabet[i]] = i + 1;
        int_aph[i + 1] = alphabet[i];
    }

    for (int i = 0; i < bans.size(); i++) {
        int len = bans[i].size() - 1;
        
        long long num1 = 0;
        while (len > 0) {
            num1 += fastPow(26, len);
            len--;
        }
        
        long long num2 = 0;
        long long tmp = bans[i].size();
        for (int j = 0; j < bans[i].size() - 1; j++) {
            num2 += fastPow(26, tmp - 1) * (aph[bans[i][j]] - 1);
            tmp--;
        }
        num2 += aph[bans[i][bans[i].size() - 1]];
        
        bans_location.push_back(num1 + num2);
    }

    // 중복 제거 후 정렬
    set<long long> bans_set(bans_location.begin(), bans_location.end());
    bans_location.assign(bans_set.begin(), bans_set.end());
    sort(bans_location.begin(), bans_location.end());

    // n 값 업데이트 (삭제된 주문 고려)
    for (auto e : bans_location) {
        if (e > n) break;
        n++;
    }

    // n 번째 주문의 길이 구하기
    long long total = 0, len = 0;
    while (total <= n) {
        len++;
        if (total > LLONG_MAX - fastPow(26, len)) break;  // 오버플로우 방지
        total += fastPow(26, len);
    }
    total -= fastPow(26, len);
    n -= total;

    // n 번째 주문 구하기
    while (len > 0) {
        long long k = max(1LL, min(26LL, n / fastPow(26, len - 1) + 1));
        if (len == 1) k--;
        answer += int_aph[k];
        n -= (k - 1) * fastPow(26, len - 1);
        len--;
    }

    return answer;
}
