#include <string>
#include <vector>

using namespace std;

char map[17][17];

void fillMap(int line, int num, int n)
{
    int idx = n-1;
    while(num != 0) {
        if(num % 2 == 1) {
            map[line][idx] = '#';
        }
        idx--; 
        num /= 2;
    }
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            map[i][j] = ' ';
        }
        fillMap(i, arr1[i], n);
        fillMap(i, arr2[i], n);
    }
    
    for(int i = 0; i < n; i++) {
        string s;
        for(int j = 0; j < n; j++) {
            s += map[i][j];
        }
        answer.push_back(s);
    }
    return answer;
}