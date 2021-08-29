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
    // map �׸���
    int map_size = lock.size()+(2*key.size())-2;
    vector<vector<int>> map(map_size,vector<int>(map_size,0));
    for(int i=0; i<lock.size(); i++){
        for(int j=0; j<lock.size(); j++){
            map[i+key.size()-1][j+key.size()-1] = lock[i][j];
        }
    }

    for (int r = 0; r < 4; r++){
        // rotation ��Ű��
        vector<vector<int>> r_key(key.size(),vector<int>(key.size(),0));
        r_key = rotation(r,key);
        // key ���� temp�� �־��
        int sx = 0;
        int sy = 0;
        int max_sxy = key.size() + lock.size() - 1; // sx|sy�� �� ���� �Ǹ� map�� �Ѿ����
        bool crash = false;
        while (true){
            // ���� ����
            if(sx == max_sxy && sy == max_sxy-1)
                break;
            // sx�� map�� �Ѿ������ �����ٷ� �̵�
            if (sx == key.size() + lock.size() - 1){
                sx = 0;
                sy++;
            }
            crash = false; // crash �ʱ�ȭ
            vector<vector<int>> temp = map;
            for (int i = 0; i < key.size(); i++){
                for (int j = 0; j < key.size(); j++){
                    if (r_key[i][j] == 1){
                        // �浹X
                        if (temp[i + sy][j + sx] == 0)
                            temp[i + sy][j + sx] = 1;
                        // �浹O
                        else{
                        crash = true;
                        break;
                        }
                    }
                }
                // �浹�� �־��� ��� �ٷ� ���� ����� ����
                if(crash == true)
                    break;
            }
            // �浹 ���ٸ�
            if(crash == true){
                sx++;
            }
            // �浹�� ���� �ʾҴٸ� �ڹ��谡 Ǯ�ȴ��� Ȯ��
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
                // �ڹ��谡 Ǯ�ȴٸ� ���� ����
                if(unlock == true){
                    return true;
                }
                // Ǯ���� �ʾҴٸ� ���� ����� ����
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