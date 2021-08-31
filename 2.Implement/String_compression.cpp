#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int len = s.length();
    int min = len;  // min�� �׻� len���� �۴�.
    
    // �ڸ��� ũ�� i �� ���ڿ� s�� ���ݱ����� Ȯ���ϸ� ��
    for(int i=1; i<=len/2; i++){
        int base = 0;
        string str;
        while(true){
            // str1�� i�� ��ŭ ������ Ȯ�� �ʿ���� �� ������ �κ��̶�� ��
            if(base + i >= len){
                str += s.substr(base);
                break;
            }
            string str1 = s.substr(base,i);
            int count = 1;
            int next = base + i;
            // ���� ũ�⸸ŭ �������� ���ӵǸ�
            while(str1 == s.substr(next,i)){
                next += i;
                count++;
            }
            if(count == 1){
                str += str1;    // ���� 1�� ����
            }
            else
                str = str + to_string(count) + str1;
            base += i*count;
        }
        if(min > str.length())
            min = str.length();
    }
    return min;
}

int main(){
    string s = "abrabcabcadqabcabc";
    cout << solution(s);
}