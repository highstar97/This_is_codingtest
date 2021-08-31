#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,K,L;
vector<pair<int,char>> m;
//          ���ƿ���
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void rotate_dir(int& dir, char d){
    // �������� 90�� ȸ��
    if(d == 'L'){
        if(dir == 0)
            dir = 3;
        else    dir--;
    }
    // ���������� 90�� ȸ��
    else{
        if(dir == 3)
            dir = 0;
        else    dir ++;
    }
}

bool IsOkay(int nx, int ny, queue<pair<int,int>> snake){
    // ���� �ε����°�?
    if(nx == N || ny == N)
        return false;
    // �Ӹ��� ���� �Ծ��°�?
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
    // map : 0 �� ��ǥ, 1 : ��� -1 : ��
    vector<vector<int>> map = input();
    
    cout << "----map----" << endl;
    for(auto a : map){
        for(auto b : a)
            cout << b << " ";
        cout << endl;
    }

    // �� ����
    queue<pair<int,int>> snake;
    snake.emplace(make_pair(0,0)); // �� ���� ��ġ 1�� 1��

    int dir = 0;  // ���� = ������ (0:����, 1:�Ʒ�, 2:��, 3:��)
    
    // �� �̵�
    int x = 0;
    int y = 0;
    for(int i=0; i<m.size(); i++){
        // m[i].first�� ��ŭ ������ �̵�
        for(int j=0; j<m[i].first; j++){
            answer++;
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            
            // �Ӹ��� ������ �����°�?, �Ӹ��� ���� ����ߴ°�?
            if(IsOkay(nx,ny,snake) == false){
                cout << answer << endl;
                return answer;
            }

            snake.emplace(make_pair(nx,ny));    // �Ӹ� ����
            x = nx;
            y = ny;

            // ����� ���ٸ�
            if(map[ny][nx] != 1){
                snake.pop();    // ���� ����
            }
            else{
                map[nx][ny] == 0;
            }
            print_s(snake);
        }
        // m[i].second�� ȸ��
        rotate_dir(dir,m[i].second);
    }

    cout << answer << endl;
    return answer;
}