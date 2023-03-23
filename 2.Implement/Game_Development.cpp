#include <iostream>

int solution(int N, int M, int A, int B, int d, int **map)
{
    int answer = 1;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};

    while (true)
    {
        bool can_move = false;
        for (int i = 0; i < 4; ++i)
        {
            int index = abs(d + i - 3);
            if (!(0 <= A + dx[index] && A + dx[index] < M && 0 <= B + dy[index] && B + dy[index] < N))
            {
                continue;
            }
            if (map[A + dx[index]][B + dy[index]] == 0)
            {
                ++answer;
                map[A][B] = 2;
                A += dx[index];
                B += dy[index];
                d = index;
                can_move = true;
                break;
            }
        }
        if (can_move == false)
        {
            int index = (d + 2) % 4;
            if (!(0 <= A + dx[index] && A + dx[index] < M && 0 <= B + dy[index] && B + dy[index] < N))
            {
                break;
            }
            if (map[A + dx[index]][B + dy[index]] == 2)
            {
                map[A][B] = 2;
                A += dx[index];
                B += dy[index];
            }
            else
            {
                break;
            }
        }
    }
    return answer;
}

int main()
{
    int N, M, A, B, d;
    std::cin >> N >> M;
    std::cin >> A >> B >> d;

    int **map = new int *[N];
    for (int i = 0; i < N; ++i)
    {
        map[i] = new int[M];
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            int input;
            std::cin >> input;
            map[i][j] = input;
        }
    }

    std::cout << solution(N, M, A, B, d, map);

    for (int i = 0; i < N; ++i)
    {
        delete[] map[i];
    }
    delete[] map;
}