#include <iostream>

int solution(std::string start_location)
{
    int answer = 0;
    int x = start_location[0] - 'a';
    int y = start_location[1] - '1';

    int dx[8] = {+1, +2, +2, +1, -1, -2, -2, -1};
    int dy[8] = {+2, +1, -1, -2, -2, -1, +1, +2};

    for(int i=0; i<8; ++i)
    {
        if(0 <= x+dx[i] && x+dx[i] <= 7 && 0 <= y+dy[i] && y+dy[i] <= 7)
        {
            ++answer;
        }
    }
    return answer;
}

int main()
{
    std::string start_location;
    std::cin >> start_location;

    std::cout << solution(start_location);
}