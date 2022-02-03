#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0, length = board[0].size();
    vector <int> bucket;
    bool visited[31][31];
    
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            visited[i][j] = false;
            if(board[i][j] == 0) {
                visited[i][j] = true;
            }
        }
    }
    
    for(int i = 0; i < moves.size(); i++) {
        for(int j = 0; j < length; j++) {
            if(visited[j][moves[i]-1] == false) {
                visited[j][moves[i]-1] = true;
                bucket.push_back(board[j][moves[i]-1]);
                if(bucket[bucket.size()-1] == bucket[bucket.size()-2]) {
                    bucket.erase(bucket.begin() + bucket.size()-1);
                    bucket.erase(bucket.begin() + bucket.size()-1);
                    answer += 2;
                }
                break;
            }
        }
    }
    
    return answer;
}