// 구현, 큐, 힙
#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    for(int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    
    while(!pq.empty()) {
        int top = pq.top();
        pq.pop();
        if(pq.empty() && top < K) {
            return -1;
        }
        if(top >= K) {
            break;
        }
        else {
            answer++;
            int second = pq.top();
            pq.pop();
            pq.push(top + 2* second);
        }
    }
    return answer;
}