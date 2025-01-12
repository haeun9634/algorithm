#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#define V_SIZE 100005

using namespace std;
using ll = long long int;
string s;
int arr[V_SIZE];
stack <char> st;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    int result = 0;
    int temp = 1;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push('(');
            temp *= 2; 
        }
        else if (s[i] == '[') {
            st.push('[');
            temp *= 3; 
        }
        else if (s[i] == ')') {
            if (st.empty() || st.top() != '(') {
                result = 0; 
                break;
            }
            if (s[i - 1] == '(') result += temp; // 바로 직전 괄호가 '('일 때만 더함
            st.pop();  
            temp /= 2; // '('에 대한 값 감소
        }
        else if (s[i] == ']') {
            if (st.empty() || st.top() != '[') {
                result = 0; 
                break;
            }
            if (s[i - 1] == '[') result += temp; // 바로 직전 괄호가 '['일 때만 더함
            st.pop();  
            temp /= 3; 
        }

    }

    if (!st.empty()) result = 0;

    cout << result << endl;

    return 0;

  
}
