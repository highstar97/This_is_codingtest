#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

const int MAX = 10000;
int N, M, start;    // N : ��� ���� , M : ���� ���� , start : ���� ���
int d[MAX+1];                           // �ִ� �Ÿ� ����
vector<pair<int,int>> graph[MAX+1];     // ��忡 ����Ǿ� �ִ� ���� ����

void Dijkstra2(int start){
    // Min_Heap <�Ÿ�, ���> ����
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    // ���� ���� ���� ���� �ִ� ��δ� 0
    pq.emplace(make_pair(0,start));
    d[start] = 0;
    while(!pq.empty()){
        // �ִ� �Ÿ� ��� ���� ������
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        // ���� ��尡 �̹� ó���� �� �ִ� ����� ����
        if(d[now] < dist)
            continue;
        // ���� ���� ����� �ٸ� ������ ���� Ȯ��
        for(int i=0; i<graph[now].size(); i++){
            int cost = dist + graph[now][i].second;
            // ���� ��带 ���ļ�, �ٸ� ���� �̵��ϴ� �Ÿ��� �� ���� ���
            if(cost < d[graph[now][i].first]){
                d[graph[now][i].first] = cost;
                pq.push(make_pair(cost,graph[now][i].first));
            }
        }
    }
}

int main(){
    cin >> N >> M >> start;
    // graph�� ���� ���� �Է�
    for(int i=0; i<M; i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].emplace_back(make_pair(b,c));
    }
    // �ִܰŸ� INF�� �ʱ�ȭ
    fill_n(d,MAX+1,INF);
    // ���ͽ�Ʈ��2 ����
    Dijkstra2(start);
    // �ִ� �Ÿ� ���
    for(int i=1; i<=N; i++){
        if(d[i] == INF)
            cout << start << " -> " << i << " : infinity" << endl;
        else
            cout << start << " -> " << i << " : " << d[i] << endl;
    }
}