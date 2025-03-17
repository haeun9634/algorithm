#include <iostream>
#include <queue>
#include <string>

using namespace std;

const int MAX = 10005;
int n, m;
char arr[25][25];
priority_queue <string,vector<string>, greater<string>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        string temp;
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != '#')
                temp += arr[i][j];
            else {
                if(temp.size()>1)
                    pq.push(temp);
                temp = "";
            }
           
        }

        if (temp.size() > 1)
        pq.push(temp);
    }

    for (int i = 0; i < m; i++) {
        string temp2;
        for (int j = 0; j < n; j++) {
            if (arr[j][i] != '#')
                temp2 += arr[j][i];
            else {
                if (temp2.size() > 1)
                pq.push(temp2);
                temp2 = "";
            }
        }
        if (temp2.size() > 1)
            pq.push(temp2);
    }

    cout << pq.top();
   
   
    

    return 0;
}
