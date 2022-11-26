//Old code and new code
//New code I wrote after seeing the solution, turns out I used similar concept
//Just that the code had bits that could be cut(binary search)

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long
 
map<char, int> cm;
 
bool check(int len, int odd, int even, int c){
    int cur_len = 0;
    int color = 0;
    bool odd_used = false;
 
    for(int i = 0; i < c; i++){
        if(len%2 == 0){
            if(even >= len/2){
                even -= len/2;
            }
            else return false;
        }
        else{
            if(odd > 0){
                odd--;
                if(even >= len/2){
                    even -= len/2;
                }
                else return false;
            }
            else{   
                if(even >= (len/2) + 1){
                    even -= (len/2) + 1;
                    odd++;
                }
                else return false;
            }
        }
    }
 
    return true;
}
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
 
    int tc;
    cin >> tc;
    while(tc--){
        int sl, r;
        cin >> sl >> r;
        string s;
        cin >> s;
        cm.clear();
        
        for(auto ch: s){
            cm[ch]++;
        }
        int odd = 0;
        int even = 0;
 
        for(auto ch: cm){
            if(ch.second%2 == 0){
                even += ch.second/2;
            }
            else{
                odd++;
                even += ch.second/2;
            }
        }
 
        int left = 1, right = (sl/r);
        int ans = -1;
 
        while(left <= right){
            int mid = (left+right)/2;
            if(check(mid, odd, even, r)){
                left = mid+1;
                ans = max(mid, ans);
            }
            else{
                right = mid-1;
            }
        }
 
        cout << max(ans, 1) << "\n";
 
    }
 
 
}


#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--){
        int sl, r;
        cin >> sl >> r;
        string s;
        cin >> s;

        map<char, int> cm;
        for(auto ch: s){
            cm[ch]++;
        }
        int odd = 0;
        int even = 0;

        for(auto ch: cm){
            even += ch.second/2;
            odd += ch.second%2;
        }

        int ans = 2*(even/r);
        odd += 2*(even%r);
        if(odd >= r){
            ans++;
        }

        cout << ans  << "\n";

    }


}
