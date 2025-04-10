#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <math.h>
//X가 아닌 것들을 추리기
//전부다 노출된 값들에 대해서 op와 숫자를 추출하기
//최대 숫자값을 구하기 -> 그값 +1이 n진수시작값임
//맨 뒷자리수만 계산해서 n진수인지 확인
//만약 다 되면 ?로 지정
//특정 n진수만 되면 그걸로 X값 도출
using namespace std;

vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    
    vector<string> unknown_expr;
    vector<string> known_expr;
    for(auto expr: expressions){
        stringstream ss(expr);
        string num1, op, num2, equel, num3;
        ss >> num1 >> op >> num2 >> equel >> num3;
        
        if(num3 =="X") unknown_expr.push_back(expr);
        else known_expr.push_back(expr);
    }
    
    int minBase = 0;
    for(auto expr: expressions){
        stringstream ss(expr);
        string num1, op, num2, equel, num3;
        ss >> num1 >> op >> num2 >> equel >> num3;
        
        minBase = max(minBase, num1.back()-'0'); //stoi()함수는 string을 가져와야하는데 num1.back()은 char이여서 안됨
        minBase = max(minBase, num2.back()-'0');
        if(num3 != "X") minBase = max(minBase, num3.back()-'0');
    }
    cout << minBase <<endl;
    
    bool all_possible = true;
    bool pass = true;
    int result_base = -1;
    for(auto expr: known_expr){
        stringstream ss(expr);
        string num1, op, num2, equel, num3;
        ss >> num1 >> op >> num2 >> equel >> num3;
        
        //minBase부터 9진수 까지 확인해보기
        for(int base =minBase+1; base<10; base++){
            int n1_size = num1.size()-1;
            int n2_size = num2.size()-1;
            int n3_size = num3.size()-1;
            
            bool plus=false, minus=false;
            int result=0;
            pass = true;
            
            for(int i=n3_size; i>=0; i--){
                if(n1_size<0 || n2_size<0) {
                    int n3 = num3[i]-'0';
                    if(plus) {
                        result = 1;
                        if(result == n3) all_possible = false;
                        else result_base = base;
                    }
                    break;
                }
                int n1 = num1[n1_size]-'0';
                int n2 = num2[n2_size]-'0';
                int n3 = num3[i]-'0';
                
                if(plus) n2++;
                else if(minus) n2--;
                
                plus = false, minus = false;
                result=0;
                
                if(op =="-"){
                    if(n1 < n2) {
                        result = n1+base-n2;
                        minus = true;
                    } else {
                        if(n2 !=-1) result = n1 - n2;
                        else result = n1-1;
                    }
                    
                    if(n1<0) {
                        minus = true;
                        result = base-1;
                    }
                    
                    if(result != n3) all_possible = false;
                    else  result_base = base;
                    
                } else if(op =="+") {
                    if(n1+n2 >= base) {
                        result = n1+n2-base;
                        plus = true;
                    } else { 
                        result = n1+n2;
                    }
                    
                    cout << result << "vs" << n3 <<endl;
                    if(result != n3) {
                        all_possible = false; //모두 가능말고 2개 이상 가능일수도 있지 않나?
                        pass =false;
                    }
                }
                
                n1_size--;
                n2_size--;
            }
            if(pass) {
                result_base = base;
            }
        }
    }
    
    if(all_possible) cout << "전부다 가능" <<endl;
    cout << result_base <<endl;
    
    for(auto expr: unknown_expr){
        stringstream ss(expr);
        string num1, op, num2, equel, num3;
        ss >> num1 >> op >> num2 >> equel >> num3;
        
        string ans;
        ans+= num1 +" " + op +" " + num2 +" " + equel +" ";
        
        int n1_size = num1.size()-1;
        int n2_size = num2.size()-1;

        int max_size = max(n1_size, n2_size);

        bool plus=false, minus=false;
        int result=0, ten = 0;
        pass = true;
        
        for(int i=max_size; i>=0; i--){
            if(n1_size<0 || n2_size<0) {
                if(plus) {
                    result += 1*pow(10,ten);
                }
                break;
            }
            
            int n1 = num1[n1_size]-'0';
            int n2 = num2[n2_size]-'0';
            if(plus) n2++;
            else if(minus) n2--;

            plus = false, minus = false;
            result=0;

            if(op =="-"){
                if(n1 < n2) {
                    // if(all_possible){
                    //     ans+="?";
                    //     break;
                    // }
                    result = n1+result_base-n2;
                    minus = true;
                } else {
                    if(n2 !=-1) result = n1 - n2;
                    else result = n1-1;
                }

                if(n1<0) {
                    minus = true;
                    result = (result_base-1);
                }

                result += result*pow(10,ten);
                ten++;

            } else if(op =="+") {
                // if(n1+n2>=minBase) {
                //     ans+="?";
                //     break;
                // }
                if(n1+n2 >= result_base) {
                    result = n1+n2-result_base;
                    plus = true;
                } else { 
                    result = n1+n2;
                }

                result += result*pow(10,ten);
                ten++;
            }

            n1_size--;
            n2_size--;
        }
        cout << result;
    }
    return answer;
}
