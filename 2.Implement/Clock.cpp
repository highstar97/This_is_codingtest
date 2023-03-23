#include <iostream>

int solution(int N)
{
    int answer = 0;
    for (int hour = 0; hour <= N; ++hour)
    {
        for (int minute = 0; minute < 60; ++minute)
        {
            for (int second = 0; second < 60; ++second)
            {
                std::string time = std::to_string(hour);
                time += std::to_string(minute);
                time += std::to_string(second);
                if (time.find('3') != std::string::npos)
                {
                    ++answer;
                }
            }
        }
    }
    return answer;
}

int main()
{
    int N;
    std::cin >> N;

    std::cout << solution(N);
}