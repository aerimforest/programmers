// 2020 카카오 인턴십
// 키패드 누르기

#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int leftX = 3, leftY = 0, rightX = 3, rightY = 2, leftD, rightD;
    
    for(int i = 0 ; i < numbers.size() ; i++) {
        if(numbers[i] == 0) numbers[i] = 11;
        
        if(numbers[i] % 3 == 1) { // 왼쪽 열
            answer.push_back('L');
            leftX = numbers[i]/3; leftY = 0;
        }
        else if(numbers[i] % 3 == 0) { // 오른쪽 열
            answer.push_back('R');
            rightX = numbers[i]/3-1; rightY = 2;
        }
        else { // 가운데 열
            leftD = abs(leftX-numbers[i]/3) + abs(leftY-1);
            rightD = abs(rightX-numbers[i]/3) + abs(rightY-1);
            
            // 왼쪽 엄지가 더 가까운 경우
            if(leftD < rightD) {
                leftX = numbers[i]/3; leftY = 1;
                answer.push_back('L');
            }
            // 오른쪽 엄지가 더 가까운 경우
            else if(leftD > rightD){
                rightX = numbers[i]/3; rightY = 1;
                answer.push_back('R');
            }
            // 왼쪽, 오른쪽 엄지와의 거리 같은 경우
            else {
                if(hand.compare("left") == 0) { // 왼손잡이
                    leftX = numbers[i]/3; leftY = 1;
                    answer.push_back('L');
                }
                else { // 오른손잡이
                    rightX = numbers[i]/3; rightY = 1;
                    answer.push_back('R');
                }
            }
        }
    }
    return answer;
}