#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;

const int MAX = 500;
int N,M;                    // N : ��� ���� , M : ���� ����
int graph[MAX+1][MAX+1];    // �ִܰŸ� ���� ���̺�

int main(){
    cin >> N >> M;
    // �ִܰŸ� ���̺� INF�� �ʱ�ȭ
    for(int i=0; i<MAX+1; i++){
        fill(graph[i],graph[i]+MAX+1,INF);
    }
    // �ڽ� -> �ڽ� => 0
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++)
            if(i==j) graph[i][j] = 0;
    }
    // ���� ���� �Է� �ޱ�
    for(int i=0; i<M; i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }
    // �÷��̵� ���� ����
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            for(int k=1; k<=N; k++){
                graph[j][k] = min(graph[j][k],graph[j][i]+graph[i][k]);
            }
        }
    }
    // ��� ���
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(graph[i][j] == INF)
                cout << "INF" << " ";
            else
                cout << graph[i][j] << " ";
        }
        cout << endl;
    }   
}