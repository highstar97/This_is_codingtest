#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

const int MAX = 30000;
int N, M, C;
int d[MAX];
vector<vector<pair<int,int>>> graph(MAX);

void dijkstra(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    fill_n(d,N+1,INF);

    d[start] = 0;
    pq.emplace(make_pair(0,start));
    while(!pq.empty()){
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(d[now] < dist)   continue;
        for(int i=0; i<graph[now].size(); i++){
            int cost = dist + graph[now][i].second;
            if(cost < d[graph[now][i].first]){
                d[graph[now][i].first] = cost;
                pq.emplace(make_pair(cost,graph[now][i].first));
            }
        }
    }
}

int main(){
    // data �Է� �ޱ�
    cin >> N >> M >> C;
    for(int i=0; i<M; i++){
        int x,y,z;
        cin >> x >> y >> z;
        graph[x].emplace_back(make_pair(y,z));
    }

    dijkstra(C);

    int num = 0;        // ������ ���� �� �ִ� ���� ����
    int time = 0;       // ������ �޴µ� �ɸ��� ���� �� �ð�
    for(int i=1; i<=N; i++){
        // ��ߵ���, ���޸��ϴ� ���� ����
        if(d[i] != INF && d[i] != 0){
            num++;
            if(time < d[i])
                time = d[i];
        }
    }
    cout << num << " " << time << endl;
}