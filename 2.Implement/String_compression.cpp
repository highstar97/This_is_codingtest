#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int len = s.length();
    int min = len;  // min은 항상 len보다 작다.
    
    // 자르는 크기 i 는 문자열 s의 절반까지만 확인하면 됨
    for(int i=1; i<=len/2; i++){
        int base = 0;
        string str;
        while(true){
            // str1이 i개 만큼 없으면 확인 필요없는 맨 마지막 부분이라는 뜻
            if(base + i >= len){
                str += s.substr(base);
                break;
            }
            string str1 = s.substr(base,i);
            int count = 1;
            int next = base + i;
            // 같은 크기만큼 비교했을때 연속되면
            while(str1 == s.substr(next,i)){
                next += i;
                count++;
            }
            if(count == 1){
                str += str1;    // 숫자 1은 생략
            }
            else
                str = str + to_string(count) + str1;
            base += i*count;
        }
        if(min > str.length())
            min = str.length();
    }
    return min;
}

int main(){
    string s = "abrabcabcadqabcabc";
    cout << solution(s);
}