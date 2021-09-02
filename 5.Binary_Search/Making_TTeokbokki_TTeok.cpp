#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> tteok;

int main(){
    int max = 0;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        tteok.emplace_back(x);
        if(max < x)
            max = x;
    }

    int answer;
    int low = 0;
    int high = max;
    while(low <= high){
        int height = (low+high)/2;
        long long sum = 0;  // 10������� �� 4���� �������� int ����(21�� �Ѿ)
        for(int i=0; i<N; i++){
            if(tteok[i] > height)
                sum += (tteok[i] - height);
        }
        if(sum >= M){
            answer = height;
            low = height+1;
        }
        else if(sum < M){
            high = height-1;
        }
    }
    cout << answer;
}