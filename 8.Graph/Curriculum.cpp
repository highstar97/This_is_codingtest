#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void Topology_sort(vector<int> indegree, vector<vector<int>> graph, vector<int> times){
    queue<int> q;
    vector<int> result = times;
    for(int i=1; i<=indegree.size(); i++){
        if(indegree[i] == 0){
            q.emplace(i);
        }
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0; i<graph[now].size(); i++){
            result[graph[now][i]] = max(result[i],result[now]+times[graph[now][i]]);
            indegree[graph[now][i]]--;
            if(indegree[graph[now][i]] == 0)
                q.emplace(graph[now][i]);
        }
    }

    for(int i=1; i<result.size(); i++)
        cout << result[i] << endl;
}

int main(){
    int N;
    cin >> N;
    vector<int> indegree(N+1,0);
    vector<int> times(N+1,0);
    vector<vector<int>> graph(N+1);
    for(int i=1; i<=N; i++){
        int x;
        cin >> x;
        times[i] = x;
        while(true){
            cin >> x;
            if(x == -1) break;
            graph[x].emplace_back(i);
            indegree[i]++;
        }
    }
    Topology_sort(indegree,graph,times);
}