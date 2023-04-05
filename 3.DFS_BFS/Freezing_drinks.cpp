#include <iostream>
#include <vector>
#include <queue>

int solution(int N, int M, std::vector<std::vector<int>> ice)
{
    int answer = 0;
    std::vector<std::vector<int>> visited = ice;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (ice[i][j] == 0 && visited[i][j] == 0)
            {
                // BFS
                std::queue<std::pair<int, int>> queue;
                queue.emplace(std::make_pair(i, j));
                visited[i][j] = 1;
                while (!queue.empty())
                {
                    int x = queue.front().first;
                    int y = queue.front().second;
                    if (0 <= x - 1 && ice[x - 1][y] == 0 && visited[x - 1][y] == 0)
                    {
                        queue.emplace(std::make_pair(x - 1, y));
                        visited[x - 1][y] = 1;
                    }
                    if (x + 1 < N && ice[x + 1][y] == 0 && visited[x + 1][y] == 0)
                    {
                        queue.emplace(std::make_pair(x + 1, y));
                        visited[x + 1][y] = 1;
                    }
                    if (0 <= y - 1 && ice[x][y - 1] == 0 && visited[x][y - 1] == 0)
                    {
                        queue.emplace(std::make_pair(x, y - 1));
                        visited[x][y - 1] = 1;
                    }
                    if (y + 1 < M && ice[x][y + 1] == 0 && visited[x][y + 1] == 0)
                    {
                        queue.emplace(std::make_pair(x, y + 1));
                        visited[x][y + 1] = 1;
                    }
                    queue.pop();
                }
                ++answer;
            }
        }
    }

    return answer;
}

int main()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> ice(N, std::vector<int>(M, 0));

    for (int i = 0; i < N; ++i)
    {
        std::string input;
        std::cin >> input;
        for (int j = 0; j < M; ++j)
        {
            ice[i][j] = input[j] - '0';
        }
    }
    std::cout << solution(N, M, ice);
}