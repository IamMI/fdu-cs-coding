#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
using LL=long long;
using pii=pair<int, int>;

int main(void)
{
    int n,m;
    cin >> n >> m;

    unordered_map<int, int> mp;
    queue<int> que;
    set<int> st;

    /*
        我们可以管理一个set，从而避免每次都从map中提取出vector并排序，将总体的时间复杂度变为
        set+map: O((n+m-1)*m)
        vector+map: O((n+m-1)*mlgm)
    */

    vector<string> ans;
    for(int index=0; index<n; index++){
        int pushval;
        cin >> pushval;
        que.push(pushval);
        if(mp.find(pushval)==mp.end()) mp[pushval] = 1;
        else mp[pushval] += 1;

        if(mp[pushval]==1) st.insert(pushval);
        if(mp[pushval]>1) st.erase(pushval);

        if(que.size()>m){
            int popval = que.front();
            que.pop();
            if(mp[popval]==1) mp.erase(popval);
            else mp[popval] -= 1;

            if(mp.find(popval)!=mp.end() && mp[popval]==1) st.insert(popval);
            if(mp.find(popval)==mp.end()) st.erase(popval);
        }

        if(que.size()==m){
            int l = st.size();
            if(l==0) ans.push_back("No");
            else{
                auto it = st.begin();
                advance(it, (l+1)/2-1); 
                ans.push_back(to_string(*it));
            }


            // vector<int> sorvec;
            // for(auto item:mp){
            //     if(item.second==1) sorvec.push_back(item.first);
            // }
            // int l=sorvec.size();        
    
            // if(sorvec.size()==0){
            //     ans.push_back("No");
            // }
            // else{
            //     sort(sorvec.begin(), sorvec.end());
            //     ans.push_back(to_string(sorvec[(l+1)/2-1]));
            // }
        }
    }

    for(auto str:ans) cout << str << " " << endl;


    return 0;
}