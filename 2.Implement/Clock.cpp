#include <iostream>

using namespace std;

int main(){
    int N;
    int answer = 0;
    cin >> N;
    for(int i=0; i<=N; i++){
        if( i%10 == 3 ){
            answer += 60*60;
        }
        else
            answer += ((45*15)+(15*60));
    }
    cout << answer;
}