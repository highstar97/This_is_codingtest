#include <iostream>
#include <vector>

using namespace std;

int N;

int main(){
    cin >> N;
    vector<int> storage(N,0);
    vector<int> K;
    
    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        K.emplace_back(x);
    }

    storage[1] = K[0];

    for(int i=2; i<=N; i++){
        storage[i] = max(storage[i-1],storage[i-2]+K[i-1]); 
    }
    
    cout << storage[N];
    return 0;
}