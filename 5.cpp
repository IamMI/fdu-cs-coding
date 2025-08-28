#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using LL=long long;
using pii=pair<int, int>;

int main(void)
{
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;


    LL res=1;
    while(n>0){
        int order;
        if(x/int(pow(2, n-1))==0 && y/int(pow(2, n-1))==0) order = 0;
        else if(x/int(pow(2, n-1))==0 && y/int(pow(2, n-1))==1) order = 1;
        else if(x/int(pow(2, n-1))==1 && y/int(pow(2, n-1))==0) order = 2;
        else order = 3;
        
        res +=  order * pow(2, n-1) * pow(2, n-1);

        x = x%int(pow(2, n-1));
        y = y%int(pow(2, n-1));
        n -= 1;
    }

    cout << res << endl;

    return 0;
}