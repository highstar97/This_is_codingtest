#include <iostream>
#include <map>

using namespace std;

int main(){
    int N, M;
    int answer = 0;
    map<int,int> mymap;

    cin >> N >> M;
    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        mymap[x]++;
    }
    // 1~M(볼링공 무게 마다) 공 선택
    for(int i=1; i<=M; i++){
        int sum = 0;
        // 선택된 공의 무게보다 무거운 공의 개수의 합
        for(int j=i+1; j<=M; j++){
            sum += mymap[j];
        }
        // 선택된 공의 개수만큼 더하기
        answer += (sum * mymap[i]);
    }

    cout << answer;
}