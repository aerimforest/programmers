// 구현, 큐
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<double> day;
    
    for(int i = 0; i < progresses.size(); i++) {
        day.push(ceil((100 - progresses[i]) / (double)speeds[i]));
    }
    
    int cnt = 1;
    double maxDay = day.front();
    day.pop();
    while(!day.empty()) {
        double top = day.front();
        day.pop();
        if(top <= maxDay) {
            cnt++;
        }
        else {
            maxDay = top;
            answer.push_back(cnt);
            cnt = 1;
        }
    }
    answer.push_back(cnt);
    return answer;
}