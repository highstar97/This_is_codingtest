#include <iostream>

void solution(int N, std::string plan)
{
    int x = 1, y = 1;
    for(int i=0; i<plan.size(); ++i)
    {
        if(plan[i] == ' ')
        {
            continue;
        }
        else if(plan[i] == 'U' && x > 1)
        {
            --x;
        }
        else if(plan[i] == 'D' && x < N)
        {
            ++x;
        }
        else if(plan[i] == 'L' && y > 1)
        {
            --y;
        }
        else if(plan[i] == 'R' && y < N)
        {
            ++y;
        }
    }
    std::cout << x << " " << y;
}

int main()
{
    int N;
    std::string plan;

    std::cin >> N;
    std::cin.ignore();
    getline(std::cin, plan);

    solution(N,plan);
}