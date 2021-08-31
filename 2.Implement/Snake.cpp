#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,K,L;
vector<pair<int,char>> m;
//          오아왼위
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void rotate_dir(int& dir, char d){
    // 왼쪽으로 90도 회전
    if(d == 'L'){
        if(dir == 0)
            dir = 3;
        else    dir--;
    }
    // 오른쪽으로 90도 회전
    else{
        if(dir == 3)
            dir = 0;
        else    dir ++;
    }
}

bool IsOkay(int nx, int ny, queue<pair<int,int>> snake){
    // 벽에 부딪혔는가?
    if(nx == N || ny == N)
        return false;
    // 머리가 몸을 먹었는가?
    queue<pair<int,int>> temp = snake;
    for(int i=0; i<temp.size(); i++){
        int x = temp.front().first;
        int y = temp.front().second;
        if(nx == x && ny == y)
            return false;
        temp.pop();
    }
    return true;
}

vector<vector<int>> input(){
    cin >> N;
    cin >> K;
    vector<vector<int>> temp(N,vector<int>(N,0));
    for(int i=0; i<K; i++){
        int x, y;
        cin >> x >> y;
        temp[x-1][y-1] = 1;
    }
    cin >> L;
    for(int i=0; i<L; i++){
        int x;
        char c;
        cin >> x >> c;
        m.emplace_back(make_pair(x,c));
    }

    return temp;
}

void print_s(queue<pair<int,int>> snake){
    cout << " now snake " << endl;
    while(!snake.empty()){
        cout << snake.front().second << "," << snake.front().first << endl;
        snake.pop();
    }
}

int main(){
    int answer = 0;
    // map : 0 빈 좌표, 1 : 사과 -1 : 뱀
    vector<vector<int>> map = input();
    
    cout << "----map----" << endl;
    for(auto a : map){
        for(auto b : a)
            cout << b << " ";
        cout << endl;
    }

    // 뱀 정보
    queue<pair<int,int>> snake;
    snake.emplace(make_pair(0,0)); // 뱀 시작 위치 1행 1열

    int dir = 0;  // 방향 = 오른쪽 (0:오른, 1:아래, 2:왼, 3:위)
    
    // 뱀 이동
    int x = 0;
    int y = 0;
    for(int i=0; i<m.size(); i++){
        // m[i].first초 만큼 앞으로 이동
        for(int j=0; j<m[i].first; j++){
            answer++;
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            
            // 머리가 몸통을 물었는가?, 머리가 벽을 통과했는가?
            if(IsOkay(nx,ny,snake) == false){
                cout << answer << endl;
                return answer;
            }

            snake.emplace(make_pair(nx,ny));    // 머리 생성
            x = nx;
            y = ny;

            // 사과가 없다면
            if(map[ny][nx] != 1){
                snake.pop();    // 꼬리 제거
            }
            else{
                map[nx][ny] == 0;
            }
            print_s(snake);
        }
        // m[i].second로 회전
        rotate_dir(dir,m[i].second);
    }

    cout << answer << endl;
    return answer;
}