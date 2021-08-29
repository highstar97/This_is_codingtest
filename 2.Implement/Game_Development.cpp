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

    // ��ȹ��� �����̱�
    bool finish = false;
    while (finish == false){
        int start_d = d;
        int next_d = d;
        visited[x][y] = 1;  // ���� ��ġ�� �湮�� ������ ǥ��
        while (true){
            if(next_d==0)
                next_d = next_d+3;
            else 
                next_d = --next_d;
            int nx = x + _move[next_d].first;
            int ny = y + _move[next_d].second;
            // �̵� ��ǥ�� �� ���� �� �϶��� ����
            if (0 <= nx && nx < N && 0 <= ny && ny < M){
                if (map[nx][ny] == '0' && visited[nx][ny] == 0){
                    x = nx;
                    y = ny;
                    d = next_d;
                    answer++; // �̵��� ����
                    break;
                }
            }
            // ���� ���ڸ����� 360�� ���Ҵٸ�
            if(next_d == start_d){
                // �ڷ� �̵� �غ�
                nx = x + _back[start_d].first;
                ny = y + _back[start_d].second;
                if (0 <= nx && nx < N && 0 <= ny && ny < M){
                    // �ڰ� �ٴٶ�� �������� ����
                    if(map[nx][ny] == '1'){
                        finish = true;
                    }
                    // ���ư� ������ ������ �ڷ� �̵�, �湮 �ƴ�
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