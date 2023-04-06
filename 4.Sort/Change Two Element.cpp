#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int N, int K, vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end(), less<int>());
    sort(B.begin(), B.end(), greater<int>());

    for (int i = 0; i < K; ++i)
    {
        if (A[i] < B[i])
        {
            int temp = A[i];
            A[i] = B[i];
            B[i] = temp;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        answer += A[i];
    }

    return answer;
}

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> A, B;
    for (int i = 0; i < 2 * N; ++i)
    {
        int input;
        cin >> input;
        i < N ? A.emplace_back(input) : B.emplace_back(input);
    }

    cout << solution(N, K, A, B);
}