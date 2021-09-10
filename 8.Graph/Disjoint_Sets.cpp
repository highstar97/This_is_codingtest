#include <iostream>
#include <vector>

using namespace std;

int V , E;      // V : ��� ����, E : ���� ����

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
    // �θ� ���̺� �ʱ�ȭ
    vector<int> parent(V+1,0);
    for(int i=1; i<=V; i++){
        parent[i] = i;
    }
    // ���� ���� �Է� && Union
    for(int i=0; i<E; i++){
        int a,b;
        cin >> a >> b;
        Union_Parent(parent,a,b);
    }

    cout << "�� ���Ұ� ���� ���� : ";
    for(int i=1; i<=V; i++)
        cout << Find_parent(parent,i) << " ";
    
    cout << endl;

    cout << "�θ� ���̺� : ";
    for(int i=1; i<=V; i++)
        cout << parent[i] << " ";
}