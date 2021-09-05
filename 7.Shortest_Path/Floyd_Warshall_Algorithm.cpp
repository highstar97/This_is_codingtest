#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;

const int MAX = 500;
int N,M;                    // N : 노드 개수 , M : 간선 개수
int graph[MAX+1][MAX+1];    // 최단거리 저장 테이블

int main(){
    cin >> N >> M;
    // 최단거리 테이블 INF로 초기화
    for(int i=0; i<MAX+1; i++){
        fill(graph[i],graph[i]+MAX+1,INF);
    }
    // 자신 -> 자신 => 0
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++)
            if(i==j) graph[i][j] = 0;
    }
    // 간선 정보 입력 받기
    for(int i=0; i<M; i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }
    // 플로이드 워셜 수행
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            for(int k=1; k<=N; k++){
                graph[j][k] = min(graph[j][k],graph[j][i]+graph[i][k]);
            }
        }
    }
    // 결과 출력
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