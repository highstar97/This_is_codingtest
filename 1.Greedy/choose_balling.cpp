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
    // 1~M(������ ���� ����) �� ����
    for(int i=1; i<=M; i++){
        int sum = 0;
        // ���õ� ���� ���Ժ��� ���ſ� ���� ������ ��
        for(int j=i+1; j<=M; j++){
            sum += mymap[j];
        }
        // ���õ� ���� ������ŭ ���ϱ�
        answer += (sum * mymap[i]);
    }

    cout << answer;
}