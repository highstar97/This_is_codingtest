#include <iostream>

using namespace std;

int d[30001];   
// ������ d[1] = 0�̹Ƿ� ����

int main(){
    int X;
    cin >> X;
    for(int i=2; i<=X; i++){
        // 1�� ����
        d[i] = d[i-1] + 1;
        // 2�� ������
        if(i%2 == 0)
            d[i] = min(d[i],d[i/2]+1);
        // 3���� ������
        if(i%3 == 0)
            d[i] = min(d[i],d[i/3]+1);
        // 5�� ������
        if(i%5 == 0)
            d[i] = min(d[i],d[i/5]+1);
    }
    cout << d[X];
}