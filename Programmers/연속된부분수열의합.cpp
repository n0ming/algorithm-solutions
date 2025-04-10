#include <string>
#include <vector>

//1, 2, 3, 4.. 개씩 차례대로 앞부분부터 총합의 결과를 구함
// 그 결과값이 k와 동일하면 result임
//500,000 * 1000,001 
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2,0);
//     int n_start = 0, idx=0, total=0;
//     for(int n=1; n<=sequence.size(); n++){
//         idx = sequence.size();
//         total = 0;
//         for(int j=0; j<n; j++) {//시작한 부분에서 n개만큼 부분수열 합 구함
//             idx--;
//             total += sequence[idx];
//         }
//         if(total >= k) {
//             n_start=n;
//             break;
//         }
//     }
    
//     for(int n=n_start; n<=sequence.size(); n++){ //몇개의 부분 수열할건지 n값 구하기
//         for(int i=0; i<=sequence.size()-n;i++){ //어디서부터 시작할지
//             idx = i;
//             total =0;
//             for(int j=0; j<n; j++) {//시작한 부분에서 n개만큼 부분수열 합 구함
//                 total += sequence[idx];
//                 idx++;
//             }
            
//             if(total==k) {
//                 answer[0]=i; 
//                 answer[1]=idx-1;
//                 return answer;
//             }
//         }
//     }
    
    int end =0,total=sequence[0],start=0, min_len=sequence.size()+1;
    while(end<sequence.size()){
        if(total<k){
            end++;
            total+=sequence[end];
        } else if(total>k){
            total-=sequence[start];
            start++;
        } else {
            int len = end - start+1;
            
            if(min_len>len) {
                answer[0] =start; 
                answer[1]=end;
                min_len = len;
            }
            else if(min_len == len && answer[0]>start) {
                answer[0] =start; 
                answer[1]=end;
            }
            total -= sequence[start];
            start++;
        }
    }
    
    return answer;
}
