#include <iostream>
#include <vector>
#include <algorithm>    // sort()

using namespace std;

bool cmp (int a, int b){
    return a > b;
}

int solution(int M, int K, vector<int> num){
    int answer = 0;

    // 내림차순 정렬    
    sort(num.begin(), num.end(), cmp);
    
    // 가장 큰 수, 두번째 큰 수 저장
    int first = num[0];
    int second = num[1];

    // 가장 큰 수가 더해지는 횟수
    int count = (M/(K+1)*K) + (M%(K+1));

    answer += first * count;        // 가장 큰 수 더하기
    answer += second * (M-count);   // 두번째 큰 수 더하기

    return answer;
}

int main(){
    int N, M, K, temp;
    vector<int> num;
    cin >> N >> M >> K;
    for(int i=0; i<N; i++){
        cin >> temp;
        num.emplace_back(temp);
    }
    cout << solution(M,K,num);
}