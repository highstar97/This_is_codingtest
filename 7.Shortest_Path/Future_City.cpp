#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

int N, M, X, K;

int dijkstra(int start, int dest, vector<vector<int>> graph){
    int d[N+1];
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    // �ִܰŸ� ���� �ʱ�ȭ
    fill_n(d,N+1,INF);
    // �ʱ����� ����
    d[start] = 0;
    pq.emplace(make_pair(0,start));
    while(!pq.empty()){
        // �ִܰŸ� ��� ���� ������
        int dist = pq.top().first;
        
        int now = pq.top().second;
        pq.pop();
        if(d[now] < dist) continue;
        // now�� ����� ������ �Ÿ� ������Ʈ
        for(int i=0; i<graph[now].size(); i++){
            int cost = dist + 1;
            if(cost < d[graph[now][i]]){
                d[graph[now][i]] = cost;
                pq.emplace(cost,graph[now][i]);
            }
        }
    }
    if(d[dest] != INF)
        return d[dest];
    else{
        return -1;
    }
}

int solution(vector<vector<int>> graph){
    int answer = 0;
    // 1 -> K
    int temp = dijkstra(1,K,graph);
    if(temp == -1)
        return -1;
    answer += temp;
    // K -> X
    temp = dijkstra(K,X,graph);
    if(temp == -1)
        return -1;
    answer += temp;
    return answer;
}

int main(){
    // data �Է¹ޱ�
    cin >> N >> M;
    vector<vector<int>> graph(N+1);
    for(int i=0; i<M; i++){
        int x, y;
        cin >> x >> y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }
    cin >> X >> K;
    // solution()
    cout << solution(graph);
}