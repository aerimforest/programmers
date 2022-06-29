// 구현, 문자열, 정렬
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for(int i = 0; i < phone_book.size() - 1; i++) {
        string s1 = phone_book[i];
        string s2 = phone_book[i+1];
        if(s1.size() <= s2.size()) {
            if(s2.substr(0, s1.size()) == s1) {
                return false;
            }
        }
    }
    return true;
}