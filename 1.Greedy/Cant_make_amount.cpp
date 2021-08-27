#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    vector<int> arr;

    cin >> N;
    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        arr.emplace_back(x);
    }

    sort(arr.begin(), arr.end());

    int target = 1;
    for(int i=0; i<N; i++){
        if(target < arr[i])
            break;
        target += arr[i];
    }

    cout << target;
}