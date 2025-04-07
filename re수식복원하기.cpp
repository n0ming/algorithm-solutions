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

string solveUnknown(string num1, string op, string num2, int base, int minBase) {
    int n1_size = num1.size()-1;        
    int n2_size = num2.size()-1;
    if(base == -1){
        while(n1_size>=0 || n2_size>=0){
            int n1 = (n1_size>=0)?num1[n1_size--]-'0':0;
            int n2 = (n2_size>=0)?num2[n2_size--]-'0':0;

            if(op=="+") {
                if(n1+n2>=minBase) return "?";
            } else if(op=="-"){
                if(n1-n2>=minBase || n1-n2<0) return "?";
            }
        }
        base = minBase;
    }
    
    n1_size = num1.size()-1;        
    n2_size = num2.size()-1;
    int total=0, pos = 0, carry =0;
    
    while(n1_size>=0 || n2_size>=0 || carry!=0){
        int n1= (n1_size>=0) ? num1[n1_size--]-'0':0;
        int n2= (n2_size>=0) ? num2[n2_size--]-'0':0;
        int sum =0;

        if(op=="+"){
            sum = n1 +n2+carry;
            carry = (sum>=base)?1:0;
            sum = (sum>=base)?sum-base:sum;
        } else if(op=="-"){
            sum = n1 - n2 + carry;
            carry = (sum<0)?-1:0;
            sum = (sum<0)?sum+base:sum;
        }

        total += sum * pow(10,pos++);
    }

    return to_string(total);
}

bool isValidExpression(string num1, string op, string num2, string num3, int base) {
    string result = solveUnknown(num1,op,num2,base,base);
    if(num3 == result) return true;
    else return false;
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    vector<string> unknown_expr, known_expr;
    
    for(auto expr: expressions){
        stringstream ss(expr);
        string num1, op, num2, equel, num3;
        ss >> num1 >> op >> num2 >> equel >> num3;
        
        if(num3 =="X") unknown_expr.push_back(expr);
        else known_expr.push_back(expr);
    }
    
    int minBase = 1;
    for(auto expr: expressions){
        stringstream ss(expr);
        string num1, op, num2, equel, num3;
        ss >> num1 >> op >> num2 >> equel >> num3;
        
        for (char c : num1) minBase = max(minBase, c - '0');
        for (char c : num2) minBase = max(minBase, c - '0');
        if (num3 != "X") for (char c : num3) minBase = max(minBase, c - '0');
    }

    minBase++;

    vector <int> possible_base;
    for(int base =minBase; base<10; base++){
        bool valid = true;
        for(auto expr: known_expr){
            stringstream ss(expr);
            string num1, op, num2, equel, num3;
            ss >> num1 >> op >> num2 >> equel >> num3;
            valid = isValidExpression(num1, op, num2, num3, base);
        }
        if(valid) possible_base.push_back(base);
    }
    
    for(auto expr: unknown_expr){
        stringstream ss(expr);
        string num1, op, num2, equel, num3;
        ss >> num1 >> op >> num2 >> equel >> num3;
        
        string ans;
        ans+= num1 +" " + op +" " + num2 +" " + equel +" ";
        
        if(possible_base.size()>1) ans += solveUnknown(num1, op, num2, -1, minBase);
        else ans += solveUnknown(num1, op, num2, possible_base[0], minBase);
        cout << possible_base.size() <<"::" << possible_base[0] <<"::"<<minBase <<endl;
        answer.push_back(ans);
    }
    return answer;
}
