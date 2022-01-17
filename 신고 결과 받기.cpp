#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    map<string, set<string> > reportInfo;
    map<string, int> reportedNum;
    set<string> stopUser;
    
    for(string s: report) {
        string reporter, poorUser;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                reporter = s.substr(0, i);
                poorUser = s.substr(i+1);
                break;
            }
        }
        if(reportInfo[reporter].count(poorUser) == 0) {
            reportInfo[reporter].insert(poorUser);
            reportedNum[poorUser]++;   
        }
    }
    
    for(int i = 0; i < id_list.size(); i++) {
        if(reportedNum[id_list[i]] >= k) { // 계정 정지될 유저라면
            stopUser.insert(id_list[i]); // 계정 정지 대상자 목록에 추가
        }
    }
    
    for(int i = 0; i < id_list.size(); i++) {
        for(auto user: reportInfo[id_list[i]]) {
            if(stopUser.find(user) != stopUser.end()) {
                answer[i]++;
            }
        }
    }
    
    return answer;
}