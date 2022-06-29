// 구현, 해시, 맵
#include <string>
#include <vector>
#include <map>
using namespace std;

bool solution(vector<string> phone_book) {
    map<string, bool> m;
    for(int i = 0; i < phone_book.size(); i++) {
        m[phone_book[i]] = true;
    }
    for(int i = 0; i < phone_book.size(); i++) {
        string num = "";
        for(int j = 0; j < phone_book[i].size() - 1; j++) {
            num += phone_book[i][j];
            if(m[num] == true) return false;
        }
    }
    return true;
}