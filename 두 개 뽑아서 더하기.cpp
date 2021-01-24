#include <string> // erase
#include <vector>
#include <algorithm> // sort, unique

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(int i = 0 ; i < numbers.size()-1 ; i++) {
        for(int j = i+1 ; j < numbers.size() ; j++) {
            answer.push_back(numbers[i] + numbers[j]);
        }
    }
    sort(answer.begin(), answer.end()); // 오름차순 정렬
    answer.erase(unique(answer.begin(), answer.end()), answer.end()); // 중복 제거
    return answer;
}