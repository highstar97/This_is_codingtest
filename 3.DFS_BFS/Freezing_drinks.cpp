#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, answer;

void BFS(int a, int b, vector<vector<int>> ice, vector<vector<int>>& visited){
    queue<pair<int,int>> q;

    q.emplace(make_pair(a,b));
    visited[a][b] = 1;  // ���� ��� �湮 �ߴٰ� ǥ��

    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        // ���� ������ �湮������ ���ٸ� q�� �ִ´�.
        if(i-1 >= 0 && ice[i-1][j] == 0 && visited[i-1][j] == 0){
            q.emplace(make_pair(i-1,j));
            visited[i-1][j] = 1;
        }
        if(i+1 < N && ice[i+1][j] == 0 && visited[i+1][j] == 0){
            q.emplace(make_pair(i+1,j));
            visited[i+1][j] = 1;
        }
        if(j-1 >= 0 && ice[i][j-1] == 0 && visited[i][j-1] == 0){
            q.emplace(make_pair(i,j-1));
            visited[i][j-1] = 1;
        }
        if(j+1 < M && ice[i][j+1] == 0 && visited[i][j+1] == 0){
            q.emplace(make_pair(i,j+1));
            visited[i][j+1] = 1;
        }
    }
}

int main(){
    cin >> N >> M;
    vector<vector<int>> ice(N,vector<int>(M,0));
    vector<vector<int>> visited = ice;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int x;
            cin >> x;
            ice[i][j] = x;
        }
    }

    for(int i=0; i<visited.size(); i++){
        for(int j=0; j<visited[i].size(); j++){
            // ������ �� ��ġ && �湮���� ���� ���̶�� �湮
            if(ice[i][j] == 0 && visited[i][j] == 0){
                BFS(i, j, ice, visited);
                answer++;
            }
        }
    }

    cout << answer;
}