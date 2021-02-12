#include <string>
#include <vector>
#include <algorithm> // max
#include <iostream>

using namespace std;

int person1[5] = {1, 2, 3, 4, 5};
int person2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int person3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> tester(3);
    int maxScore = 0;
    
    for(int i = 0 ; i < answers.size() ; i++) {
        if(answers[i] == person1[i % 5]) tester[0]++;
        if(answers[i] == person2[i % 8]) tester[1]++;
        if(answers[i] == person3[i % 10]) tester[2]++;
    }
    maxScore = max(max(tester[0], tester[1]), tester[2]);
    
    // 1번 수포자부터 탐색 -> 자동 오름차순
    for(int i = 0 ; i < 3 ; i++) {
        if(tester[i] == maxScore) {
            answer.push_back(i+1);
        }
    }
    return answer;
}