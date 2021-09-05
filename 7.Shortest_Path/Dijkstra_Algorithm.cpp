#include <iostream>
#include <vector>
#define INF 10e8

using namespace std;

const int MAX = 10000;
int N, M, start;    // N : ��� ���� , M : ���� ���� , start : ���� ���
int d[MAX+1];                           // �ִ� �Ÿ� ����
bool visited[MAX+1];                    // �湮 ����
vector<pair<int,int>> graph[MAX+1];     // ��忡 ����Ǿ� �ִ� ���� ����

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
    // ���� ��忡 ���ؼ� �ʱ�ȭ
    d[start] = 0;
    visited[start] = true;
    for(int i=0; i<graph[start].size(); i++){
        d[graph[start][i].first] = graph[start][i].second;
    }

    // ���� ��带 ������ ��ü N-1���� ��忡 ���� �ݺ�
    for(int i=0; i<N-1; i++){    
        // ���� �ִ� �Ÿ��� ���� ª�� ��带 ������, �湮 ó��
        int now = getSmallestNode();
        visited[now] = true;
        // ���� ���� ����� �ٸ� ���� Ȯ��
        for(int j=0; j<graph[now].size(); j++){
            int cost = d[now] + graph[now][j].second;
            // ���� ��带 ���ļ� �ٸ� ���� �̵��ϴ� �Ÿ��� �� ª�� ���
            if(cost < d[graph[now][j].first])
                d[graph[now][j].first] = cost;
        }
    }
}

int main(){
    cin >> N >> M >> start;
    // graph ���� �Է�
    for(int i=0; i<M; i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].emplace_back(make_pair(b,c));
    }   
    // �ִ� �Ÿ� INF�� �ʱ�ȭ
    fill_n(d,MAX+1,INF);
    // ���ͽ�Ʈ�� ����
    Dijkstra(start);
    // ���
    cout << "Result" << endl;
    for(int i=1; i<=N; i++){
        if(d[i] == INF)
            cout << start << " -> " << i << " : infinity" << endl;
        else
            cout << start << " -> " << i << " : " << d[i] << endl;
    }
}