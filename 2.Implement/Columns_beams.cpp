#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    vector<pair<int,int>> column;
    vector<pair<int,int>> beam;
    for(int i=0; i<build_frame.size(); i++){
        // ��ġ
        if(build_frame[i][3] == 1){
            // ���
            if(build_frame[i][2] == 0){
                // �ٴڿ� ��ġ
                if( build_frame[i][1] == 0){
                    vector<int> temp;
                    temp.emplace_back(build_frame[i][0]);
                    temp.emplace_back(build_frame[i][1]);
                    temp.emplace_back(build_frame[i][2]);
                    answer.emplace_back(temp);
                }
                else if()
            }
            // ��
            else{

            }
        }
        else{   // ����

        }
    }
    return answer;
}

int main(){
    int n = 5;
    vector<vector<int>> build_frame = {{1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1}};
    for(auto data : solution(n,build_frame)){
        cout << "{ " ;
        for(auto d : data){
            cout << d << " ";
        }
        cout << " }" << endl;
    }

}