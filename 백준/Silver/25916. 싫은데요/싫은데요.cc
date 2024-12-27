#include <iostream>
#include <algorithm>
#include <vector>
#define V_SIZE 500005
using ll = long long int;
using namespace std; \

int n, m;
int hole[V_SIZE];
int sum;
vector <int> idx;
int answer = 0;

int main() {
    cin.tie(0);
    cout.tie(0);
    idx.push_back(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> hole[i];
    }

    int st = 0, end = 0;

    while (end <= n) {
        if (sum > m) {
            sum -= hole[st];
            st++;
        }
        else if (sum <= m) {
            answer = max(answer, sum);
            sum += hole[end];
            end++;
        }
    }

    cout << answer << "\n";


    return 0;
}
