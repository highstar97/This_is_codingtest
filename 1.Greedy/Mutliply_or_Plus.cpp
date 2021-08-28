#include <iostream>
#include <string>

using namespace std;

int main(){
    long long answer = 0;
    string str;

    cin >> str;

    answer = str[0] - '0';

    for(int i=1; i<str.length(); i++){
        int num = str[i] - '0';
        if(answer <= 1 || num <= 1)
            answer += num;
        else
            answer *= num;
    }

    cout << answer;
}