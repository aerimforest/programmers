// 2021 KAKAO BLIND RECRUITMENT

#include <string>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    for(int i = 0 ; i < new_id.size() ; i++) {
        // 1단계
        if('A' <= new_id[i] && new_id[i] <= 'Z') {
            new_id[i] = tolower(new_id[i]);
            continue;
        }
    }
        
    for(int i = 0 ; i < new_id.size() ; i++) {
        // 2단계
        if(('a' <= new_id[i] && new_id[i] <= 'z') || ('0' <= new_id[i] && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') ;
        else {
            new_id.erase(i, 1); i--;
        }
    }
        
    for(int i = 0 ; i < new_id.size() ; i++) {
        // 3단계
        if(new_id[i] == '.' && new_id[i+1] == '.') {
            new_id.erase(i, 1); i--;
        }
    }

    // 4단계
    if(new_id[0] == '.') {
        new_id.erase(0, 1);
    } 
    if(new_id[new_id.size() - 1] == '.') {
        new_id.erase(new_id.size() - 1, 1);
    }
        
    // 5단계
    if(new_id.size() == 0) {
        new_id.push_back('a');
    }
        
    // 6단계
    if(new_id.size() >= 16) {
        new_id.erase(15, new_id.size() - 15);
    }
    if(new_id[14] == '.') {
        new_id.erase(14, 1);
    }
        
    // 7단계
    if(new_id.size() == 1) {
        new_id.push_back(new_id[0]);
        new_id.push_back(new_id[0]);
    }
    else if(new_id.size() == 2) {
        new_id.push_back(new_id[1]);
    }

    return new_id;
}

int main(void)
{
    string s;
    cin >> s;
    cout << solution(s) << '\n';
}