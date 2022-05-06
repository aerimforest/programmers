// 2021 카카오 채용연계형 인턴십
#include <string>
#include <vector>

using namespace std;
char map[5][5];
int dx1[4] = {-1, 0, 1, 0}, dy1[4] = {0, 1, 0, -1};
int dx2[4] = {-1, -1, 1, 1}, dy2[4] = {-1, 1, 1, -1};
int dx3[4] = {-2, 0, 2, 0}, dy3[4] = {0, 2, 0, -2};
int cdx2[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}, cdy2[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int cdx3[4] = {1, 0, -1, 0}, cdy3[4] = {0, -1, 0, 1};

bool check()
{
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(map[i][j] == 'P') {
                for(int k = 0; k < 4; k++) {
                    int nx = i + dx1[k];
                    int ny = j + dy1[k];
                    if(nx < 0 || nx > 4 || ny < 0 || ny > 4) continue;
                    if(map[nx][ny] == 'P') {
                        return false;
                    }
                }
            
                for(int k = 0; k < 4; k++) {
                    int nx = i + dx2[k];
                    int ny = j + dy2[k];
                    if(nx < 0 || nx > 4 || ny < 0 || ny > 4) continue;
                    if(map[nx][ny] == 'P') {
                        if(map[nx + cdx2[k][0]][ny + cdy2[k][0]] != 'X') {
                            return false;
                        }
                        else if(map[nx + cdx2[k][1]][ny + cdy2[k][1]] != 'X') {
                            return false;
                        }
                    }
                }
            
                for(int k = 0; k < 4; k++) {
                    int nx = i + dx3[k];
                    int ny = j + dy3[k];
                    if(nx < 0 || nx > 4 || ny < 0 || ny > 4) continue;
                    if(map[nx][ny] == 'P' && map[nx + cdx3[k]][ny + cdy3[k]] != 'X') {
                        return false;
                    }
                }   
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i = 0; i < places.size(); i++) {
        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) {
                map[j][k] = places[i][j][k];
            }
        }
      
        if(check() == false) {
            answer.push_back(0);
        }
        else {
            answer.push_back(1);
        }
    }
    
    return answer;
}