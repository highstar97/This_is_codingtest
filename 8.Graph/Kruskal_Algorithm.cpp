#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Find_parent(vector<int> &parent, int x){
    if(parent[x] != x)
        parent[x] = Find_parent(parent,parent[x]);
    return parent[x];
}

void Union(vector<int> &parent, int a, int b){
    int x = Find_parent(parent,a);
    int y = Find_parent(parent,b);
    if(x < y)
        parent[y] = x;
    else
        parent[x] = y;
}

int main(){
    int V, E;
    int answer = 0;
    cin >> V >> E;
    // �θ� ���̺� �ʱ�ȭ
    vector<int> parent(V+1,0);
    for(int i=0; i<V+1; i++)
        parent[i] = i;
    // ���� ���� �Է� �ޱ� ( ���, a -> b )
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0; i<E; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        edges.emplace_back(make_pair(cost,make_pair(a,b)));
    }
    // ���� �������� ����
    sort(edges.begin(),edges.end());

    // Kruskal Algorithm
    for(int i=0; i<E; i++){
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        // Cycle�� �߻����� �ʴ� ��쿡�� ���տ� ����
        if(Find_parent(parent,a) != Find_parent(parent,b)){
            Union(parent,a,b);
            answer += edges[i].first;
        }
    }
    
    cout << answer << endl;
}