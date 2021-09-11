#include <iostream>
#include <vector>

using namespace std;

int Find_parent(vector<int> &parent, int x){
    if(parent[x] != x)
        parent[x] = Find_parent(parent,parent[x]);
    return parent[x];
}

void Union(vector<int> &parent, int x, int y){
    int a = Find_parent(parent,x);
    int b = Find_parent(parent,y);
    if(a < b)
        parent[b] = a;
    else 
        parent[a] = b;
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<int> parent(N+1);
    for(int i=0; i<N+1; i++)
        parent[i] = i;

    for(int i=0; i<M; i++){
        int x,y,z;
        cin >> x >> y >> z;
        if(x == 0){
            Union(parent,y,z);
        }
        else{   // x == 1
            if(Find_parent(parent,y) == Find_parent(parent,z)){
                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
    }
}