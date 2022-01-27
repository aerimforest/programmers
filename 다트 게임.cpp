#include <string>
#include <vector>
using namespace std;

int solution(string dartResult) {
    int answer = 0, num = 0;
    vector <int> result;
    
    for(int i = 0; i < dartResult.size(); i++) {
        if('0' <= dartResult[i] && dartResult[i] <= '9') {
            num = num*10 + (dartResult[i] - '0');
        }
        else if(dartResult[i] == 'S') {
            result.push_back(num);
            num = 0;
        }
        else if(dartResult[i] == 'D') {
            result.push_back(num*num);
            num = 0;
        }
        else if(dartResult[i] == 'T') {
            result.push_back(num*num*num);
            num = 0;
        }
        else if(dartResult[i] == '*') {
            result[result.size()-1] *= 2;
            result[result.size()-2] *= 2;
            num = 0;
        }
        else if(dartResult[i] == '#') {
            result[result.size()-1] *= -1;
        }
    }
    for(int i = 0; i < result.size(); i++) {
        answer += result[i];
    }
    
    return answer;
}