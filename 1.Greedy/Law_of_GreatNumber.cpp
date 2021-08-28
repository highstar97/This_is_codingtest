#include <iostream>
#include <vector>
#include <algorithm>    // sort()

using namespace std;

bool cmp (int a, int b){
    return a > b;
}

int solution(int M, int K, vector<int> num){
    int answer = 0;

    // �������� ����    
    sort(num.begin(), num.end(), cmp);
    
    // ���� ū ��, �ι�° ū �� ����
    int first = num[0];
    int second = num[1];

    // ���� ū ���� �������� Ƚ��
    int count = (M/(K+1)*K) + (M%(K+1));

    answer += first * count;        // ���� ū �� ���ϱ�
    answer += second * (M-count);   // �ι�° ū �� ���ϱ�

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