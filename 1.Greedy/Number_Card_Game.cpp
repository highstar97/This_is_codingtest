#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int solution(vector<vector<int>> card){
    vector<int> v;
    for(int i=0; i<card.size(); i++){
        int small = card[i][0];
        for(int j=0; j<card[i].size(); j++){
            if(small > card[i][j])
                small = card[i][j];
        }
        v.emplace_back(small);
    }
    sort(v.begin(), v.end(), cmp);
    return v[0];
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> card;
    for(int i=0; i<N; i++){
        vector<int> v;
        for(int j=0; j<M; j++){
            int temp;
            cin >> temp;
            v.emplace_back(temp);
        }
        card.emplace_back(v);
    }
    cout << solution(card);
}