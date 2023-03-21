#include <iostream>

int solution(int N, int K)
{
    int answer = 0;

    while(true)
    {
        if(N < K)
        {
            break;
        }
        
        if(N % K != 0)
        {
            answer += N % K;
            N -= N % K;
        }
        else
        {
            ++answer;
            N /= K;
        }
    }

    answer += N-1;

    return answer;
}

int main()
{
    int N, K;
    std::cin >> N >> K;

    std::cout << solution(N,K);
}