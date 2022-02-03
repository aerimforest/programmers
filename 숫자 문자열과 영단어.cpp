#include <string>
#include <vector>

using namespace std;

int check(string word) {
    if(word == "zero") {
        return 0;
    } else if(word == "one") {
        return 1;
    } else if(word == "two") {
        return 2;
    } else if(word == "three") {
        return 3;
    } else if(word == "four") {
        return 4;
    } else if(word == "five") {
        return 5;
    } else if(word == "six") {
        return 6;
    } else if(word == "seven") {
        return 7;
    } else if(word == "eight") {
        return 8;
    } else if(word == "nine") {
        return 9;
    } else {
        return -1;
    }
}

int solution(string s) {
    string ans = "", word = "";
    for(int i = 0; i < s.size(); i++) {
        if('0' <= s[i] && s[i] <= '9') {
            ans += s[i];
        }
        else {
            word += s[i];
            if(word.size() >= 3) {
                int idx = check(word);
                if(idx != -1) {
                    word = "";
                    ans += (char)(idx + 48);
                }
            }
        }
    }
    return stoi(ans);
}