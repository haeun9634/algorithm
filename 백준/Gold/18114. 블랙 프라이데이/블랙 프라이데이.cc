#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    bool check[100000001];
    int answer = 0;
    memset(check, false, sizeof(check));
    int N, M; cin>>N>>M;
    int list[N];
    for(int i=0; i<N; i++) {
        int d; cin>>d;
        list[i] = d;
        check[d] = true;
    }
    sort(list, list+N);
    for(int i=0; i<N; i++) {
        if (answer) { break;}
        if (list[i] == M) { answer = 1; break ;}
        for(int j=i+1; j<N; j++) {
            if (answer) { break;}
            int sum = list[i]+list[j];
            if (sum==M) { answer = 1; break;}
            else if (sum<=M && list[i] != M-sum && list[j] != M-sum) {
                if (check[M-sum]) { answer = 1 ; break ; }
            }
        }
    }
    cout<<answer;
}
