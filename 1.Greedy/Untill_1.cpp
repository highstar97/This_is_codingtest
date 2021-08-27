#include <iostream>

using namespace std;

int solution(int N, int K){
    int answer = 0;
    while(N != 1){
        if(N%K != 0){
            answer += N%K;
            N -= N%K;
        }
        else{
            N = N/K;
            answer++;
        }
    }
    return answer;
}
int main(){
    int N, K;
    cin >> N >> K;
    cout << solution(N,K);
}