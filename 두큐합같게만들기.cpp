//이건 블로그 참고함..
#include <string>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    queue<int> q1 {{begin(queue1), end(queue1)}};
    queue<int> q2 {{begin(queue2), end(queue2)}};
    long long sum1 = accumulate(begin(queue1), end(queue1), 0ll);
    long long sum2 = accumulate(begin(queue2), end(queue2), 0ll);
    if((sum1 + sum2) % 2 != 0) return -1;
    size_t s1 = q1.size(), s2 = q2.size();
    int cnt = 0;
    while(sum1 != sum2) {
        if(cnt > s1 + s2 + 2) return -1;
        if(sum1 < sum2) {
            q1.push(q2.front());
            sum1 += q2.front();
            sum2 -= q2.front();
            q2.pop();
        }
        else {
            q2.push(q1.front());
            sum2 += q1.front();
            sum1 -= q1.front();
            q1.pop();
        }
        ++cnt;
    }
    return cnt;
}
