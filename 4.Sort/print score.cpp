#include <iostream>
#include <algorithm>

using namespace std;

struct Score
{
    string name;
    int score;
};

void solution(int N, Score *arr)
{
    sort(arr, arr + N, [](const Score &rv, const Score &lv)
         {
        if(lv.score > rv.score)
        {
            return true;
        }
        else return false; });

    for (int i = 0; i < N; ++i)
    {
        cout << arr[i].name << " ";
    }
}

int main()
{
    int N;
    cin >> N;
    Score *arr = new Score[N];

    for (int i = 0; i < N; ++i)
    {
        string input_name;
        int input_score;
        cin >> input_name >> input_score;
        arr[i].name = input_name;
        arr[i].score = input_score;
    }

    solution(N, arr);

    delete[] arr;
}