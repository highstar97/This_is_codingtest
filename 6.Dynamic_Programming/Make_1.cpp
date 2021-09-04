#include <iostream>

using namespace std;

int d[30001];   
// 어차피 d[1] = 0이므로 생략

int main(){
    int X;
    cin >> X;
    for(int i=2; i<=X; i++){
        // 1로 빼기
        d[i] = d[i-1] + 1;
        // 2로 나누기
        if(i%2 == 0)
            d[i] = min(d[i],d[i/2]+1);
        // 3으로 나누기
        if(i%3 == 0)
            d[i] = min(d[i],d[i/3]+1);
        // 5로 나누기
        if(i%5 == 0)
            d[i] = min(d[i],d[i/5]+1);
    }
    cout << d[X];
}