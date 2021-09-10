#include <iostream>
#include <vector>

using namespace std;

int V , E;      // V : 노드 개수, E : 간선 개수

int Find_parent(vector<int> &parent, int x){
    if(x != parent[x])
        parent[x] = Find_parent(parent, parent[x]);
    return parent[x];
}

void Union_Parent(vector<int> &parent, int a, int b){
    int x = Find_parent(parent,a);
    int y = Find_parent(parent,b);
    if(x < y)
        parent[y] = x;
    else
        parent[x] = y;
}

int main(){
    cin >> V >> E;
    // 부모 테이블 초기화
    vector<int> parent(V+1,0);
    for(int i=1; i<=V; i++){
        parent[i] = i;
    }
    // 간선 정보 입력 && Union
    for(int i=0; i<E; i++){
        int a,b;
        cin >> a >> b;
        Union_Parent(parent,a,b);
    }

    cout << "각 원소가 속한 집합 : ";
    for(int i=1; i<=V; i++)
        cout << Find_parent(parent,i) << " ";
    
    cout << endl;

    cout << "부모 테이블 : ";
    for(int i=1; i<=V; i++)
        cout << parent[i] << " ";
}