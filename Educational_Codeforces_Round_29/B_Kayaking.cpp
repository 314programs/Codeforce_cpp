#include <bits/stdc++.h>
using namespace std;

int n;
int solve(vector<int> &ppl){
    int idx = 0;
    int prev = -1;
    int res = 0;
    while(idx < n*2){
        if(ppl[idx] != -1 && prev == -1){
            prev = ppl[idx];
        }
        else if(ppl[idx] != -1 && prev != -1){
            res += ppl[idx] - prev;
            prev = -1;
        }
        idx++;
    }
    return res;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> n;

    vector<int> ppl(n*2);
    for(int i = 0; i < n*2; i++){
        cin >> ppl[i];
    }


    sort(ppl.begin(), ppl.end());
    int ans = 2e9;
    
    //Decide two single kayaks then calculate the difference for others
    for(int i = 0; i < n*2 - 1; i++){
        for(int j = i+1; j < n*2; j++){
            int tempi = ppl[i];
            int tempj = ppl[j];
            ppl[i] = -1;
            ppl[j] = -1;
            ans = min(solve(ppl), ans);
            ppl[i] = tempi;
            ppl[j] = tempj;
        }
    }

    cout << ans;

}
