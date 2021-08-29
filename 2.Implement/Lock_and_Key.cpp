#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotation(int r, vector<vector<int>> key){
    vector<vector<int>> temp(key.size(),vector<int>(key.size(),0));
    if(r==0){
        for(int i=0; i<key.size(); i++){
            for(int j=0; j<key.size(); j++){
                if(key[i][j] == 1){
                    temp[i][j] = 1;
                }
            }
        }
    }
    else if(r==1){
        for(int i=0; i<key.size(); i++){
            for(int j=0; j<key.size(); j++){
                if(key[i][j] == 1){
                    temp[j][key.size()-1-i] = 1;
                }
            }
        }
    }
    else if(r==2){
        for(int i=0; i<key.size(); i++){
            for(int j=0; j<key.size(); j++){
                if(key[i][j] == 1){
                    temp[key.size()-1-i][key.size()-1-j] = 1;
                }
            }
        }
    }
    else if(r==3){
        for(int i=0; i<key.size(); i++){
            for(int j=0; j<key.size(); j++){
                if(key[i][j] == 1){
                    temp[key.size()-1-j][i] = 1;
                }
            }
        }
    }
    return temp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    // map 그리기
    int map_size = lock.size()+(2*key.size())-2;
    vector<vector<int>> map(map_size,vector<int>(map_size,0));
    for(int i=0; i<lock.size(); i++){
        for(int j=0; j<lock.size(); j++){
            map[i+key.size()-1][j+key.size()-1] = lock[i][j];
        }
    }

    for (int r = 0; r < 4; r++){
        // rotation 시키기
        vector<vector<int>> r_key(key.size(),vector<int>(key.size(),0));
        r_key = rotation(r,key);
        // key 정보 temp에 넣어보기
        int sx = 0;
        int sy = 0;
        int max_sxy = key.size() + lock.size() - 1; // sx|sy가 이 값이 되면 map을 넘어가버림
        bool crash = false;
        while (true){
            // 종료 조건
            if(sx == max_sxy && sy == max_sxy-1)
                break;
            // sx가 map을 넘어가버리면 다음줄로 이동
            if (sx == key.size() + lock.size() - 1){
                sx = 0;
                sy++;
            }
            crash = false; // crash 초기화
            vector<vector<int>> temp = map;
            for (int i = 0; i < key.size(); i++){
                for (int j = 0; j < key.size(); j++){
                    if (r_key[i][j] == 1){
                        // 충돌X
                        if (temp[i + sy][j + sx] == 0)
                            temp[i + sy][j + sx] = 1;
                        // 충돌O
                        else{
                        crash = true;
                        break;
                        }
                    }
                }
                // 충돌이 있었을 경우 바로 다음 경우의 수로
                if(crash == true)
                    break;
            }
            // 충돌 났다면
            if(crash == true){
                sx++;
            }
            // 충돌이 나지 않았다면 자물쇠가 풀렸는지 확인
            else{
                bool unlock = true;
                for(int i=0; i<lock.size(); i++){
                    for(int j=0; j<lock.size(); j++){
                        if(temp[i+key.size()-1][j+key.size()-1] != 1)
                            unlock = false;
                    }
                    if(unlock == false)
                        break;
                }
                // 자물쇠가 풀렸다면 정답 선언
                if(unlock == true){
                    return true;
                }
                // 풀리지 않았다면 다음 경우의 수로
                else{
                    sx++;
                }
            }
        }  
    }
    return answer;
}

int main(){
    cout << boolalpha << solution({{0,0,0},{1,0,0},{0,1,1}},{{1,1,1},{1,1,0},{1,0,1}});
}