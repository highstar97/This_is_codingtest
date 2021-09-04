#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> v ={0,1,3};

    if(N <3){
        cout << v[N] << endl;
        return 1;
    }
    else{
        for(int i=3; i<=N; i++){
            v[i] = (v[i-1] + v[i-2] + v[i-2])%796796;
        }
        cout << v[N] << endl;
        return 1;
    }
}