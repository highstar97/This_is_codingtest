#include <iostream>
#include <vector>

using namespace std;

int N;
string plan;

int main(){
    cin >> N;
    cin.ignore();   // buffer에서 \n을 지워야 함.
    getline(cin,plan);
    int i = 1, j = 1;
    for(int k=0; k<plan.size(); k++){
        if(plan[k]=='U'){
            if(i > 1)
                i--;
        }
        else if(plan[k]=='D'){
            if(i < N)
                i++;
        }
        else if(plan[k]=='L'){
            if(j > 1)
                j--;
        }
        else if(plan[k]=='R'){
            if(j < N)
                j++;
        }
    }
    cout << i << " " << j;
}