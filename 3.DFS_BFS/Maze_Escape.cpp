#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int N, int M, vector<vector<int>> map)
{
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    queue<pair<int, int>> queue;
    queue.emplace(make_pair(0, 0));
    while (!queue.empty())
    {
        int x = queue.front().first;
        int y = queue.front().second;
        queue.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            {
                continue;
            }

            if (map[nx][ny] == 1)
            {
                queue.emplace(make_pair(nx, ny));
                map[nx][ny] = map[x][y] + 1;
            }
        }
    }

    return map[N-1][M-1];
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> map(N, vector<int>(M, 0));

    for (int i = 0; i < N; ++i)
    {
        string input;
        cin >> input;
        for (int j = 0; j < M; ++j)
        {
            map[i][j] = input[j] - '0';
        }
    }

    cout << solution(N, M, map);
}