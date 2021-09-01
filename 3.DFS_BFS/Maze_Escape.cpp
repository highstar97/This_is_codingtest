#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N , M;

int BFS(int a, int b, vector<vector<int>> maze, vector<vector<int>>& visited){
    queue<pair<int,int>> q;
    vector<vector<int>> len(N,vector<int>(M,0));
    q.emplace(make_pair(a,b));
    visited[a][b] = 1;  // 현재 노드 방문 했다고 표시
    len[a][b] = 1;      // 현재까지 지나간 칸을 표시

    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        int l = len[i][j];
        q.pop();
        // 인접 노드들이 방문한적이 없다면 q에 넣는다.
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
        if(j-1 >= 0 && maze[i][j-1] == 1 && visited[i][j-1] == 0){
            q.emplace(make_pair(i,j-1));
            visited[i][j-1] = 1;
            len[i][j-1] = l+1;
        }
        if(j+1 < M && maze[i][j+1] == 1 && visited[i][j+1] == 0){
            q.emplace(make_pair(i,j+1));
            visited[i][j+1] = 1;
            len[i][j+1] = l+1;
        }
    }
    return len[N-1][M-1]; 
}

int main(){
    cin >> N >> M;
    vector<vector<int>> maze(N,vector<int>(M,0));
    vector<vector<int>> visited = maze;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int x;
            cin >> x;
            maze[i][j] = x;
        }
    }

    cout << BFS(0,0,maze,visited);
}