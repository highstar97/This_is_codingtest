#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void Topology_sort(vector<int> indegree, vector<vector<int>> graph){
    vector<int> answer;
    queue<int> q;
    // 진입 차수가 0인 노드 queue에 넣는다
    for(int i=1; i<indegree.size(); i++){
        if(indegree[i] == 0)
            q.emplace(i);
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        answer.emplace_back(now);
        // now와 연결된 노드들의 진입차수 1씩 감소
        for(int i=0; i<graph[now].size(); i++){
            indegree[graph[now][i]]--;
            if(indegree[graph[now][i]] == 0)
                q.emplace(graph[now][i]);
        }
    }

    // 위상 정렬 결과 출력
    for(auto data : answer)
        cout << data << " ";
}

int main(){
    int V, E;
    cin >> V >> E;
    vector<int> indegree(V+1,0);
    vector<vector<int>> graph(V+1);
    for(int i=0; i<E; i++){
        int x,y;
        cin >> x >> y;
        graph[x].emplace_back(y);
        indegree[y]++;
    }
    Topology_sort(indegree,graph);
}