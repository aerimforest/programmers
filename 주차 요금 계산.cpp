#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

int getParkingTime(string in, string out) {
    int h1 = stoi(in.substr(0, 2));
    int m1 = stoi(in.substr(3, 2));
    int h2 = stoi(out.substr(0, 2));
    int m2 = stoi(out.substr(3, 2));
    int time = (h2 - h1) * 60 + (m2 - m1);
    
    return time;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<string>> parkInfo;
    
    stringstream ss;
    for(auto record: records) {
        string time, number, status; 
        ss.str(record);
        ss >> time >> number >> status;
        
        parkInfo[number].push_back(time);
        ss.clear();
    }
    
    for(auto it: parkInfo) {
        if(it.second.size() % 2 == 1) 
            it.second.push_back("23:59");
        
        vector<string> timeInfo = it.second;
        int total = 0;
        for(int i = 0; i < timeInfo.size()-1; i += 2) {
            total += getParkingTime(timeInfo[i], timeInfo[i + 1]);
        }
        
        int price = fees[1];
        if(total > fees[0]) {
            price += ceil((total-fees[0]) / (double)fees[2]) * fees[3];
        }
        
        answer.push_back(price);
    }
    
    return answer;
}