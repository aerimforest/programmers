// 124 나라의 숫자
// 3진수와의 공통점과 차이점을 찾는게 중요(3으로 나누어 떨어지지 않는 수는 3진법과 124나라수가 동일)
// 구현, 수학, 문자열
#include <string>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    while(n > 0) {
        if(n % 3 != 0) {
            answer += (n%3+'0');
            n /= 3;
        }
        else {
            answer += '4';
            n /= 3;
            n--;
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}