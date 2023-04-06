#include <iostream>
#include <algorithm>

using namespace std;

void solution(int N, int *arr)
{
    sort(arr, arr + N, std::greater<int>());

    for (int i = 0; i < N; ++i)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int N;
    cin >> N;
    int *arr = new int[N];

    for (int i = 0; i < N; ++i)
    {
        int input;
        cin >> input;
        arr[i] = input;
    }

    solution(N, arr);

    delete[] arr;
}