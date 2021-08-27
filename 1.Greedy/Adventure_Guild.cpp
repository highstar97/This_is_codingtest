#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> arr;

int main(){
    cin >> N;

    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        arr.emplace_back(x);
    }

    sort(arr.begin(),arr.end());

    int answer = 0;
    int count = 0;

    for(int i=0; i<N; i++){
        count++;
        if(count >= arr[i]){
            answer++;
            count = 0;
        }
    }
    cout << answer;
}