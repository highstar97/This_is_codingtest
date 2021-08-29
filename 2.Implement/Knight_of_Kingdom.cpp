#include <iostream>
#include <vector>

using namespace std;

int main(){
    int answer = 8;
    string start;
    vector<pair<int,int>> location;

    cin >> start;
    int i = start[0] - 'a';
    int j = start[1] - '1';
    location.emplace_back(make_pair(i-2,j-1));
    location.emplace_back(make_pair(i-2,j+1));
    location.emplace_back(make_pair(i-1,j-2));
    location.emplace_back(make_pair(i-1,j+2));
    location.emplace_back(make_pair(i+1,j-2));
    location.emplace_back(make_pair(i+1,j+2));
    location.emplace_back(make_pair(i+2,j-1));
    location.emplace_back(make_pair(i+2,j+1));

    for(auto data : location){
        if(data.first < 0 || data.first > 7 || data.second < 0 || data.second > 7)
            answer--;
    }

    cout << answer;
}