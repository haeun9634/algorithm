#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#define V_SIZE 1005
using namespace std;
using ll = long long int;
using pi = pair<int, int>;
int d;
string s;
map <char, int> club;
bool wmdifference(int a, int b) {
    int temp;
    if (a > b) temp = a - b;
    else temp = b - a;
    
    if (temp <= d) return false;
    else return true;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> d;
    cin >> s;
    club.insert({ 'W',0 });
    club.insert({ 'M',0 });

    for (int i = 0; i < s.size(); i++) {

        club[s[i]]++;
        if (wmdifference(club['W'], club['M']))//남여 차이가 d보다 크다면
        {
            club[s[i]]--;
            if (s[i + 1] != s[i] && i+1 < s.size()) {
                club[s[i + 1]]++;//두번째 사람 넣기 
                if (wmdifference(club['W'], club['M'])) {
                    club[s[i + 1]]--;
                    break;
                }
                else {
                    club[s[i]]++;
                }
                i++;
            }
            else
                break;
        }
       //cout << i << " " << club['W'] << " " << club['M'] << "\n";
        
    }

    cout << club['W'] + club['M'] << "\n";

    return 0;
}
