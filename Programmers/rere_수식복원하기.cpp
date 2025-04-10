//우리가 아는 2진수는 cba에 대해서 2^0*a + 2^1*b + 2^2*c..으로 값을 구한다.
//이거는 실제 5진수에서도 동일한 방식으로 10진수 변환이 가능하다


#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <math.h>
#include <set>

using namespace std;

int baseN_to_decimal(string num1, int base){
    int total =0,pos=num1.size()-1;
    for(char c: num1){
        total += pow(base,pos--)*(c-'0');
    }
    return total;
}

//45를 2진수로 바꿀때 나머지가 값이 되고 몫이 45다음 수가 됨.
string decimal_to_baseN(int num, int base){
    if(num==0) return "0";
    string result;
    while(num>0){
        result = to_string(num%base)+result;
        num /=base;
    }
    return result;
}

string solveUnknown(string num1, string num2, string op, int base){
    int x = baseN_to_decimal(num1,base);
    int y = baseN_to_decimal(num2,base);

    int result = (op=="+") ? x+y:x-y;
    return decimal_to_baseN(result, base);
}

// 주어진 수식이 해당 진법에서 성립하는지 확인
bool isValid(string a, string op, string b, string c, int base) {
    int x = baseN_to_decimal(a, base);
    int y = baseN_to_decimal(b, base);
    int z = baseN_to_decimal(c, base);

    if (op == "+") return x + y == z;
    if (op == "-") return x - y == z;
    return false;
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

    set<int> possible_base;
    for(int base =minBase; base<10; base++){
        bool valid = true;
        for(auto expr: known_expr){
            stringstream ss(expr);
            string num1, op, num2, equel, num3;
            ss >> num1 >> op >> num2 >> equel >> num3;
            if (!isValid(num1, op, num2, num3, base)){
                valid = false;
                break;
            }
        }
        if(valid) possible_base.insert(base);
    }

    for(auto expr: unknown_expr){
        set<string> results;
        stringstream ss(expr);
        string num1, op, num2, equel, num3;
        ss >> num1 >> op >> num2 >> equel >> num3;
        
        string ans;
        ans+= num1 +" " + op +" " + num2 +" " + equel +" ";
        
        for(auto base: possible_base){
            results.insert(solveUnknown(num1, num2, op, base));
        }
        
        if(results.size()==1) ans += *results.begin();
        else ans += "?";

        answer.push_back(ans);
    }
    
    return answer;
}
