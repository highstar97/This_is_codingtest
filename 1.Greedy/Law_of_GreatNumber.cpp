#include <iostream>
#include <algorithm>

int solution(int N, int M, int K, int* num)
{
    int answer = 0;
    std::sort(num, num + N, [](int a, int b)
    {
        return a > b;
    });
    
    for(int i=1; i<=M; ++i)
    {
        if(i % (K+1) == 0)
        {
            answer += num[1];
        }
        else
        {
            answer += num[0];
        }
    }

    return answer;
}

int main()
{
    int N, M, K;
    std::cin >> N >> M >> K;
    
    int* num = new int[N];
    for(int i=0; i<N; ++i)
    {
        int input;
        std::cin >> input;
        num[i] = input;
    }

    std::cout << solution(N, M, K, num);

    delete[] num;
}