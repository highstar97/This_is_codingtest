#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N = 0;      // �Ž��� ���� ��
    int answer = 0;
    vector<int> coin = {500, 100, 50, 10};  // ������ ����
    
    cout << "�Ž��� ���� �� N : "; cin >> N;
    // Greedy Alogrithm
    for(int i=0; i<coin.size(); i++){
        answer += N/coin[i];
        N %= coin[i];
    }

    cout << answer << endl;
}