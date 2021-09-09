#include <iostream>
#include <vector>

using namespace std;

int Find_parent(vector<int> &parent, int x){
    if(parent[x] != x)
        parent[x] = Find_parent(parent,parent[x]);
    return parent[x];
}

void Union_parent(vector<int> &parent, int x, int y){
    int a = Find_parent(parent, x);
    int b = Find_parent(parent, y);
    if(a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main(){
    int V, E;
    cin >> V >> E;
    // 부모 테이블 초기화
    vector<int> parent(V+1,0);
    for(int i=0; i<V+1; i++)
        parent[i] = i;
    // Union_Find
    for(int i=0; i<E; i++){
        int x,y;
        cin >> x >> y;
        if(Find_parent(parent,x) == Find_parent(parent,y)){
            cout << "Cycle" << endl;
            return 0;
        }
        else
            Union_parent(parent,x,y);
    }
    cout << "NO Cycle" << endl;
}