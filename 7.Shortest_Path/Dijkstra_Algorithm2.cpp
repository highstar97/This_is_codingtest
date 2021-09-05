#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

const int MAX = 10000;
int N, M, start;    // N : 노드 개수 , M : 간선 개수 , start : 시작 노드
int d[MAX+1];                           // 최단 거리 정보
vector<pair<int,int>> graph[MAX+1];     // 노드에 연결되어 있는 간선 정보

void Dijkstra2(int start){
    // Min_Heap <거리, 노드> 구현
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    // 시작 노드로 가긱 위한 최단 경로는 0
    pq.emplace(make_pair(0,start));
    d[start] = 0;
    while(!pq.empty()){
        // 최단 거리 노드 정보 꺼내기
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        // 현재 노드가 이미 처리된 적 있는 노드라면 무시
        if(d[now] < dist)
            continue;
        // 현재 노드와 연결된 다른 인접한 노드들 확인
        for(int i=0; i<graph[now].size(); i++){
            int cost = dist + graph[now][i].second;
            // 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 많은 경우
            if(cost < d[graph[now][i].first]){
                d[graph[now][i].first] = cost;
                pq.push(make_pair(cost,graph[now][i].first));
            }
        }
    }
}

int main(){
    cin >> N >> M >> start;
    // graph에 간선 정보 입력
    for(int i=0; i<M; i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].emplace_back(make_pair(b,c));
    }
    // 최단거리 INF로 초기화
    fill_n(d,MAX+1,INF);
    // 다익스트라2 실행
    Dijkstra2(start);
    // 최단 거리 출력
    for(int i=1; i<=N; i++){
        if(d[i] == INF)
            cout << start << " -> " << i << " : infinity" << endl;
        else
            cout << start << " -> " << i << " : " << d[i] << endl;
    }
}