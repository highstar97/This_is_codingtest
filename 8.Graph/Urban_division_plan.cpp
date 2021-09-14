#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Find_parent(vector<int> &parent, int x){
    if(parent[x] != x)
        parent[x] = Find_parent(parent,parent[x]);
    return parent[x];
}

void Union(vector<int>& parent, int x ,int y){
    int a = Find_parent(parent,x);
    int b = Find_parent(parent,y);
    if(a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main(){
    int N, M;
    int last_cost = 0;  // 맨 마지막에 Union하는 간선이 가장 큰 cost 간선
    int answer = 0;     // 최소 유지비
    cin >> N >> M;
    
    vector<int> parent(N+1);
    for(int i=0; i<N+1; i++){
        parent[i] = i;
    }

    vector<pair<int,pair<int,int>>> edges;
    for(int i=0; i<M; i++){
        int a,b,c;
        cin >> a >> b >> c;
        edges.emplace_back(make_pair(c,make_pair(a,b)));
    }

    sort(edges.begin(),edges.end());

    for(int i=0; i<M; i++){
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if(Find_parent(parent,a) != Find_parent(parent,b)){
            answer += edges[i].first;
            last_cost = edges[i].first;
            Union(parent,a,b);
        }
    }

    cout << answer - last_cost;
}