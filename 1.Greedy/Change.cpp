#include <iostream>

int solution(int money)
{
    int answer = 0;
    int coin[4] = {500, 100, 50, 10};
    for(int i=0; i<4; ++i)
    {
        answer += money / coin[i];
        money = money % coin[i];
    }

    return answer;
}

int main()
{
    int input;
    std::cin >> input;

    std::cout << solution(input);
}