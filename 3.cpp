#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;
using LL=long long;
using pii=pair<int, int>;

vector<vector<int>> e;
vector<vector<int>> vcount;
vector<pii> d;

int dfs1(int head, int pos){
    int sumcount = 1;
    for(int index=0; index<e[pos].size(); index++){
        int nextpos = e[pos][index];
        if(nextpos==head) vcount[pos].push_back(-1);
        else{
            int count = dfs1(pos, nextpos);
            vcount[pos].push_back(count);
            sumcount += count;
        }
    }
    vcount[pos].push_back(sumcount);
    return sumcount;
}

void dfs2(int head, int pos, int prevcount){
    d[pos].first = max(d[pos].first, prevcount);
    for(int index=0; index<e[pos].size(); index++){
        int nextpos = e[pos][index];
        if(nextpos==head) continue;
        d[pos].first = max(d[pos].first, vcount[pos][index]);
        dfs2(pos, nextpos, vcount[pos][vcount[pos].size()-1]-vcount[pos][index]+prevcount);
    }
    d[pos].second = pos;
    return ;
}


int main(void)
{
    int n;
    cin >> n;

    e.resize(n+1);
    vcount.resize(n+1);
    d.resize(n+1, {INT_MIN, -1});

    for(int index=0; index<n-1; index++){
        int a, b;
        cin >> a >> b;

        e[a].push_back(b);
        e[b].push_back(a);        
    }

    int totalsum = dfs1(-1, 1);
    
    dfs2(-1, 1, 0);
    d.erase(d.begin());
    
    /*
        假如对d[i]进行排序，时间复杂度为 O(nlogn)
        直接遍历，时间复杂度为 O(n)
    */


    int minVal = INT_MAX;
    for (int i = 1; i <= n; i++) minVal = min(minVal, d[i].first);

    for (int i = 1; i <= n; i++) if (d[i].first == minVal) cout << d[i].second << " ";
    cout << endl;


    // sort(d.begin(), d.end());
    // int num = 0;
    // while(num<n-1 && d[num].first==d[num+1].first) num += 1;

    // cout << num+1 << endl;
    // for(int index=0; index<num+1; index++) cout << d[index].second << " ";
    // cout << endl;

    return 0;
}