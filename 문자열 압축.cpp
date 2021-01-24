#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();
    for(int i = 1 ; i <= s.length() / 2 ; i++) {
        string compress = "";
        int count = 1;
        string temp = s.substr(0,i);
        for(int j = i ; j <= s.length() ; j += i) {
            // 같음
            if(temp.compare(s.substr(j,i)) == 0)  
                count++;
            
            // 다름
            else {
                if(count == 1) 
                    compress += temp;
                else {
                    compress += (to_string(count) + temp);
                }
                count = 1; // initialization
                temp = s.substr(j,i);
            }
        }
        if(s.length()/i != 0)
            compress += s.substr((s.length()/i) * i);
        if(answer > compress.length()) // 길이가 더 짧아진다면 업데이트
            answer = compress.length();
    }
    return answer;
}