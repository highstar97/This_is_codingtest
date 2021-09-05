#include <iostream>
#include <vector>
#define INF 10e8

using namespace std;

const int MAX = 10000;
int N, M, start;    // N : 노드 개수 , M : 간선 개수 , start : 시작 노드
int d[MAX+1];                           // 최단 거리 정보
bool visited[MAX+1];                    // 방문 정보
vector<pair<int,int>> graph[MAX+1];     // 노드에 연결되어 있는 간선 정보

int getSmallestNode(){
    int min_value = INF;
    int index = 0;
    for(int i=1; i<=N; i++){
        if(d[i] < min_value && !visited[i]){
            min_value = d[i];
            index = i;
        }
    }
    return index;
}

void Dijkstra(int start){
    // 시작 노드에 대해서 초기화
    d[start] = 0;
    visited[start] = true;
    for(int i=0; i<graph[start].size(); i++){
        d[graph[start][i].first] = graph[start][i].second;
    }

    // 시작 노드를 제외한 전체 N-1개의 노드에 대해 반복
    for(int i=0; i<N-1; i++){    
        // 현재 최단 거리가 가장 짧은 노드를 꺼내서, 방문 처리
        int now = getSmallestNode();
        visited[now] = true;
        // 현재 노드와 연결된 다른 노드들 확인
        for(int j=0; j<graph[now].size(); j++){
            int cost = d[now] + graph[now][j].second;
            // 현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
            if(cost < d[graph[now][j].first])
                d[graph[now][j].first] = cost;
        }
    }
}

int main(){
    cin >> N >> M >> start;
    // graph 정보 입력
    for(int i=0; i<M; i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].emplace_back(make_pair(b,c));
    }   
    // 최단 거리 INF로 초기화
    fill_n(d,MAX+1,INF);
    // 다익스트라 실행
    Dijkstra(start);
    // 출력
    cout << "Result" << endl;
    for(int i=1; i<=N; i++){
        if(d[i] == INF)
            cout << start << " -> " << i << " : infinity" << endl;
        else
            cout << start << " -> " << i << " : " << d[i] << endl;
    }
}