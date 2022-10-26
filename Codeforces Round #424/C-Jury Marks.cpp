#include <bits/stdc++.h>
using namespace std;

//My initial method was correct, but to reduce time I have to use only 1 value
//First value or any 1 value of score can be used as using this should lead to other values of score
//If not it is an invalid answer

int n, m;
set<int> need;
bool check(int ini, vector<int> &jury){
    set<int> appear;
    int temp = 0;
    for(int ch: jury){
        ini += ch;
        if(appear.count(ini) == 0 && need.count(ini) != 0){
            appear.insert(ini);
            temp++;
        }
    }
    if(temp == m) return true;
    return false;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;

    vector<int> jury(n);
    vector<int> score(m);
    vector<int> s(n);

    for(int i = 0; i < n; i++){
        cin >> jury[i];
        if(i == 0) s[i] = jury[i];
        else s[i] = s[i-1] + jury[i];
    }
    for(int i = 0; i < m; i++){
        cin >> score[i];
        need.insert(score[i]);
    }

    set<int> cnt;
    for(auto sum_:s){
        cnt.insert(score[0]-sum_);
    }

    int ans = 0;
    for(auto ch: cnt){
        if(check(ch, jury)) ans++;
    }
    cout << ans;

}
