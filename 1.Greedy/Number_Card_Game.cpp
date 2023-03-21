#include <iostream>

int solution(int N, int M, int** num)
{
    int max = 0;
    for(int i=0; i<N; ++i)
    {
        int min = 10001;
        for(int j=0; j<M; ++j)
        {
            min = std::min(min,num[i][j]);
        }
        max = std::max(max,min);
    }
    return max;    
}

int main()
{
    int N, M;
    std::cin >> N >> M;
    
    int** num = new int*[N];
    for(int i=0; i<N; ++i)
    {
        num[i] = new int[M];
    }

    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {   
            int input;
            std::cin >> input;
            num[i][j] = input;
        }
    }

    std::cout << solution(N, M, num);

    for(int i=0; i<N; ++i)
    {
        delete[] num[i];
    }
    delete[] num;
}