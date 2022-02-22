// 2022 KAKAO BLIND RECRUITMENT
// 완전탐색, dfs, 구현

#include <string>
#include <vector>
using namespace std;

int maxDiff;
vector<int> answer(1, -1);
vector<int> ryan(11, 0);

bool isBetterAns() {
    for(int i = 10; i >= 0; i--) {
        if(ryan[i] > answer[i]) return true;
        else if(ryan[i] < answer[i]) return false;
    }   
}

void cmpScore(vector<int>& apeach) {
    int ryanScore = 0, apeachScore = 0;
    for(int i = 0; i < 11; i++) {
        if(ryan[i] > apeach[i]) {
            ryanScore += (10 - i);
        }
        else if(apeach[i] > 0) {
            apeachScore += (10 - i);
        }
    }
    
    int diff = ryanScore - apeachScore;
    if(diff > maxDiff) {
        maxDiff = diff;
        answer = ryan;
    }
    else if(diff == maxDiff) {
        if(isBetterAns()) {
            answer = ryan;
        }
    }
}

void dfs(int targetNum, int leftArrows, vector<int>& apeach) {
    if(targetNum == 11) {
        ryan[10] += leftArrows; // 남은 화살은 모두 0점 과녁
        cmpScore(apeach);
        ryan[10] -= leftArrows;
        return;
    }
    if(leftArrows == 0) {
        cmpScore(apeach);
        return;
    }
    
    // 라이언이 점수를 얻는 경우
    if(apeach[targetNum] < leftArrows) {
        ryan[targetNum] += apeach[targetNum] + 1;
        dfs(targetNum + 1, leftArrows - apeach[targetNum] - 1, apeach);
        ryan[targetNum] -= apeach[targetNum] + 1;
    }
    
    // 라이언이 점수를 얻지 못하는 경우
    dfs(targetNum + 1, leftArrows, apeach);
}

vector<int> solution(int n, vector<int> info) {
    dfs(0, n, info);
    return answer;
}