#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    int max = prices[0];
    for(int i = 0 ; i < prices.size()-1 ; i++) {
        for(int j = i+1 ; j < prices.size() ; j++) {
            if(prices[j] >= prices[i]) {
                answer[i]++;
                max = prices[j];
            }
            else {
                answer[i]++;
                break;
            }
        }
    }
    return answer;
}