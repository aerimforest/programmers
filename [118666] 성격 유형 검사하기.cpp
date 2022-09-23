// [118666] 2022 KAKAO TECH INTERNSHIP 성격 유형 검사하기
#include <string>
#include <vector>
#include <map>
using namespace std;

map<char, int> m;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    for(int i = 0; i < survey.size(); i++) {
        if(1 <= choices[i] && choices[i] <= 3) m[survey[i][0]] += (4 - choices[i]);
        else if(5 <= choices[i] && choices[i] <= 7) m[survey[i][1]] += (choices[i] - 4);
    }
    answer += (m['R'] >= m['T'] ? 'R' : 'T');
    answer += (m['C'] >= m['F'] ? 'C' : 'F');
    answer += (m['J'] >= m['M'] ? 'J' : 'M');
    answer += (m['A'] >= m['N'] ? 'A' : 'N');
    return answer;
}