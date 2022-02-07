#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer, infoVec;
    vector<pair<string, bool>> ansVec;
    map <string, string> info;
    
    for(int i = 0; i < record.size(); i++) {
        infoVec.clear();
        stringstream ss(record[i]);
        ss.str(record[i]);

        string word;
        while(ss >> word) {
            infoVec.push_back(word);
        }
        
        if(infoVec[0] == "Enter") {
            info[infoVec[1]] = infoVec[2];
            ansVec.push_back(make_pair(infoVec[1], true));
        }
        else if(infoVec[0] == "Leave") {
            ansVec.push_back(make_pair(infoVec[1], false));
        }
        else {
            info[infoVec[1]] = infoVec[2];
        }
    }
    
    for(int i = 0; i < ansVec.size(); i++) {
        string s = "";
        if(ansVec[i].second == true) {
            s = info[ansVec[i].first] + "님이 들어왔습니다.";
        }
        else {
            s = info[ansVec[i].first] + "님이 나갔습니다.";
        }
        answer.push_back(s);
    }
    return answer;
}