#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;

    string W, P;
    cin >> W >> P;

    unordered_map<char, int> info;
    unordered_map<char, int> cost;

    for (char word : W) {
        info[word] = -1;
        cost[word] = 0;
    }

    int L = P.size();
    for (int i = 0; i < L; i++) {
        char word = P[i];
        if (info[word] == -1) {
            info[word] = i;
            cost[word] += c;
            cost[word] += b;
            continue;
        }
        int dist = i - info[word] - 1;
        cost[word] += min(a * dist, c * 2);
        info[word] = i;
        cost[word] += b;
    }

    for (char word : W) {
        if (info[word] != -1) {
            cost[word] += c;
        }
        cout << cost[word] << endl;
    }

    return 0;
}
