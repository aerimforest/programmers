#include <cmath>
#include <stack>

using namespace std;
stack <int> num;

void nTok(int n, int k)
{
    while(n != 0) {
        num.push(n % k);
        n /= k;
    }
}

bool isPrime(long long num, int k)
{   
    if(num == 1) {
        return false;
    }
    
    for(int i = 2; i <= (int)sqrt(num); i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0, top;
    long long primeNum = 0;
    nTok(n, k);
    
    while(!num.empty()) {
        top = num.top();
        num.pop();
        if(top != 0) {
            primeNum  = primeNum*10 + (long long)top;
        }
        else {
            if(primeNum == 0) {
                continue;
            }
            else {
                if(isPrime(primeNum, k) == true) {
                    answer++;
                }
                primeNum = 0;
            }
        }
    }
    if(primeNum > 0) {
        if(isPrime(primeNum, k) == true) {
            answer++;
        }
    }
    return answer;
}