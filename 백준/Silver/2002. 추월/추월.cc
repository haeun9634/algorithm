#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#define V_SIZE 100005

using namespace std;
using ll = long long int;
string s;
int arr[V_SIZE];
map <string, int> p;
queue <string> in;
queue <string> out;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, cnt=0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        p[s] = 1;
        in.push(s);
    }
    for (int i = 0; i < n; i++) {
        cin >> s;
        out.push(s);
    }

    for (int i = 0; i < n; i++) {
        string incar = in.front();
        string outcar = out.front();
        if (p[incar] == 0) {
            in.pop();
            incar = in.front();
            while (p[incar] == 0) {
                in.pop();
                incar = in.front();
            }
        }
        p[outcar] = 0;
        if (incar==outcar) {
            in.pop();
            out.pop();
        }
        else {
            if(p[incar]!=0)
                cnt++;
            out.pop();
        }

    }

    cout << cnt << " ";

    return 0;

  
}
