#include <string>
#include <vector>
#include <cstring>

using namespace std;
char map[5][5];
bool flag = true, visited[5][5];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int depth)
{
    visited[x][y] = true;
    if(depth == 2) return;
    
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx > 4 || ny < 0 || ny > 4) {
            continue;
        }
        else if(visited[nx][ny] == true || map[nx][ny] == 'X') {
            continue;
        }
        else if(map[nx][ny] == 'P') {
            flag = false;
            return;
        }
        dfs(nx, ny, depth + 1);
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i = 0; i < places.size(); i++) {
        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) {
                map[j][k] = places[i][j][k];
            }
        }
        
        flag = true;
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(map[i][j] == 'P') {
                    dfs(i, j, 0);  
                    if(flag == false) {
                        break;
                    }
                } 
            }
            if(flag == false) {
                break;
            }
        }
        if(flag == false) {
            answer.push_back(0);
        }
        else {
            answer.push_back(1);
        }
    }
    return answer;
}