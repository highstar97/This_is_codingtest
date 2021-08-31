#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    string S;
    cin >> S;

    int sum = 0;
    string answer;
    for(int i=0; i<S.length(); i++){
        if(isalpha(S[i]))
            answer += S[i];
        else{
            sum += S[i] - '0';
        }
    }
    sort(answer.begin(),answer.end());
    answer += to_string(sum);

    cout << answer;
}