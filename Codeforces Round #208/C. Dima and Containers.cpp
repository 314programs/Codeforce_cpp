//I actually thought of the concept correctly...
//Implementation was... off

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin >> n;
 
    vector<pair<ll, ll>> a[100000];
    vector<ll> c(n);
    int idx = 0;
    //I got it wrong the first time because I did not record index
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>> pq;
    
    //Between zeros(extractions) find 3 maximums
    //If its less then 3, just take the entire thing
    for(int i = 0; i < n; i++){
        ll num;
        cin >> num;
        c[i] = num;
        if(num == 0){
            for(int j = 0; j < 3; j++){
                if(pq.empty()) continue;
                a[idx].push_back(pq.top());
                pq.pop();
            }
            pq = priority_queue<pair<ll, ll>, vector<pair<ll, ll>>> ();
            idx++;
        }
        else{
            pq.push(make_pair(num, i));
        }
    }
 
    int cnt = 0;
    int fill = 0;
    for(int i = 0; i < n; i++){
        //If 0, print 0
        //If only 1, put in stack
        //If only 2, put in stack then in queue
        //If equal or above 3 put in stack, queue then finally bruh.
        if(c[i] == 0){
            if(a[cnt].size() == 0) cout << 0 << "\n";
            else if(a[cnt].size() == 1) cout << "1 popStack\n";
            else if(a[cnt].size() == 2) cout << "2 popStack popQueue\n";
            else cout << "3 popStack popQueue popFront\n";
            fill = 0;
            cnt++;
        }
        else{
            bool check = false;
            //If current element is maximum then change accordingly
            for(auto ch: a[cnt]){
                if(ch.second == i) check = true;
            }
            
            //If check, continue
            if(!check){
                //pushBack is used to 'remove' values that are not minimum
                //If the number of elements are below 3, this option would not be used
                cout << "pushBack\n";
                continue;
            }
            
            //Push accordingly
            if(fill == 0){
                cout << "pushStack\n";
                fill++;
            }
            else if(fill == 1){
                cout << "pushQueue\n";
                fill++;
            }
            else if(fill == 2){
                cout << "pushFront\n";
                fill++;
            }
            else{
                cout << "pushBack\n";
            }
 
        }
    }
    
 
}
