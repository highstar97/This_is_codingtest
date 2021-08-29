#include <iostream>
#include <vector>

using namespace std;

int answer = 1;
int N, M;
int x, y, d;
vector<pair<int,int>> _move = {{-1,0},{0,1},{1,0},{0,-1}};
vector<pair<int,int>> _back = {{1,0},{0,-1},{-1,0},{0,1}};

int main(){
    cin >> N >> M;
    cin >> x >> y >> d;
    vector<vector<char>> map(N,vector<char>(M,'0'));
    vector<vector<int>> visited(N,vector<int>(M,0));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char c;
            cin >> c;
            map[i][j] = c;
        }
    }

    // 계획대로 움직이기
    bool finish = false;
    while (finish == false){
        int start_d = d;
        int next_d = d;
        visited[x][y] = 1;  // 현재 위치는 방문한 것으로 표시
        while (true){
            if(next_d==0)
                next_d = next_d+3;
            else 
                next_d = --next_d;
            int nx = x + _move[next_d].first;
            int ny = y + _move[next_d].second;
            // 이동 좌표가 맵 범위 내 일때만 실행
            if (0 <= nx && nx < N && 0 <= ny && ny < M){
                if (map[nx][ny] == '0' && visited[nx][ny] == 0){
                    x = nx;
                    y = ny;
                    d = next_d;
                    answer++; // 이동에 성공
                    break;
                }
            }
            // 만약 제자리에서 360도 돌았다면
            if(next_d == start_d){
                // 뒤로 이동 준비
                nx = x + _back[start_d].first;
                ny = y + _back[start_d].second;
                if (0 <= nx && nx < N && 0 <= ny && ny < M){
                    // 뒤가 바다라면 움직임을 종료
                    if(map[nx][ny] == '1'){
                        finish = true;
                    }
                    // 돌아갈 육지가 있으면 뒤로 이동, 방문 아님
                    else{
                        x = nx;
                        y = ny;
                    }
                }
                break;
            }
        }
    }

    cout << answer;
}