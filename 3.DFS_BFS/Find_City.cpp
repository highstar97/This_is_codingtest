#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N,M,K,X;
    cin >> N >> M >> K >> X;
    vector<pair<int,pair<int,int>>> graph;
    for(int i=0; i<M; i++){
        int x, y;
        cin >> x >> y;
        graph.empalce_back(make_pair(1,make_pair(x,y)));
    }

    ////////////////
    queue<pair<int,int>> q;
    vector<vector<int>> len(N,vector<int>(M,0));
    q.emplace(make_pair(a,b));
    visited[a][b] = 1;  // ���� ��� �湮 �ߴٰ� ǥ��
    len[a][b] = 1;      // ������� ������ ĭ�� ǥ��

    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        int l = len[i][j];
        q.pop();
        // ���� ������ �湮������ ���ٸ� q�� �ִ´�.
        if(i-1 >= 0 && maze[i-1][j] == 1 && visited[i-1][j] == 0){
            q.emplace(make_pair(i-1,j));
            visited[i-1][j] = 1;
            len[i-1][j] = l+1;
        }
        if(i+1 < N && maze[i+1][j] == 1 && visited[i+1][j] == 0){
            q.emplace(make_pair(i+1,j));
            visited[i+1][j] = 1;
            len[i+1][j] = l+1;
    }
}

