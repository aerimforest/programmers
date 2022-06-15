#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int remainClothes[n];
    for(int i = 0; i < n; i++) {
        remainClothes[i] = 1;
    }
    for(int i = 0; i < lost.size(); i++) {
        remainClothes[lost[i]-1]--;
    }
    for(int i = 0; i < reserve.size(); i++) {
        remainClothes[reserve[i]-1]++;
    }
    for(int i = 0; i < n; i++) {
        if(remainClothes[i] >= 1) {
            answer++;
        }
        else {
            if(remainClothes[i-1] == 2) {
                answer++;
            }
            else if(remainClothes[i+1] == 2) {
                answer++;
                remainClothes[i+1]--;
            }
        }
    }
    return answer;
}