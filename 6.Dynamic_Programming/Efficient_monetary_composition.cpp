#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> answer(M+1,10001);
    vector<int> coin;
    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        coin.emplace_back(x);
    }

    answer[0] = 0;
    for(int i=0; i<N; i++){
        for(int j=coin[i]; j<=M; j++){
            if(answer[j-coin[i]] != 10001)
                answer[j] = min(answer[j],answer[j-coin[i]]+1);
        }
        for(auto data : answer){
            cout << data <<  " ";
        }
        cout << endl;
    }
    if(answer[M] == 10001)
        cout << -1;
    else
        cout << answer[M];
}