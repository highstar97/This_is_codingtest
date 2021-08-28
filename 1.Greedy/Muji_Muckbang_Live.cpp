#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> food_times, long long k) {
    priority_queue<int,vector<int>, greater<int>> pq;
    for(int data : food_times){
        pq.emplace(data);
    }

    for(int i=0; i<food_times.size(); i++){
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}

int main(){
    vector<int> food_times ={3,1,2};
    long long k = 5;
    cout << solution(food_times, k);
}