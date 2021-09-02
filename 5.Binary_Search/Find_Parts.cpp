#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> have;
vector<int> target;

int binary_search(vector<int> have, int target, int start, int end){
    while(start <= end){
        int mid = (start+end)/2;
        if(have[mid] == target){
            return mid;
        }
        else if(have[mid] < target){
            start = mid+1;
        }
        else if(have[mid] > target){
            end = mid-1;
        }
    }
    return -1;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        have.emplace_back(x);
    }
    cin >> M;
    for(int i=0; i<M; i++){
        int x;
        cin >> x;
        target.emplace_back(x);
    }

    sort(have.begin(),have.end());

    for(int i=0; i<M; i++){
        if(binary_search(have,target[i],0,N-1) == -1)
            cout << "no ";
        else
            cout << "yes ";
    }
}