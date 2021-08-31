#include <iostream>

using namespace std;

int main(){
    int N, len;
    cin >> N;

    string str_N = to_string(N);
    len = str_N.length();

    string str1 = str_N.substr(0,len/2);
    string str2 = str_N.substr(len/2);

    int num1 = 0;
    int num2 = 0;
    for(int i=0; i<str1.length(); i++){
        num1 += str1[i];
        num2 += str2[i];
    }

    if(num1 == num2)
        cout << "LUCKY";
    else    cout << "READY";
}