#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<double, int> A, pair<double, int> B) {
    if(A.first >= B.first) {
        if(A.first == B.first) { // 실패율 같은 경우
            if(A.second < B.second) { // 스테이지가 작은 번호부터 출력되도록
                return true;
            }
            return false;
        }
        return true; // A의 실패율이 더 큰 경우
    }
    return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int> > failureRates;
    int passUsers[501] = {0, };
    
    for(int i = 0; i < stages.size(); i++) {
        for(int j = 1; j < stages[i]; j++) {
            passUsers[j]++;
        }
    }
    
    passUsers[0] = stages.size();
    for(int i = 1; i <= N; i++) {
        double failureRate = 0;
        if(passUsers[i-1] != 0) {
            failureRate = (double)(passUsers[i-1] - passUsers[i]) / passUsers[i-1];
        }
        failureRates.push_back(make_pair(failureRate, i));
    }
    
    sort(failureRates.begin(), failureRates.end(), cmp);
    
    for(int i = 0; i < failureRates.size(); i++) {
        answer.push_back(failureRates[i].second);
    }
    
    return answer;
}