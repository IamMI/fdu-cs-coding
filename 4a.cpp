#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>

using namespace std;
using LL=long long;
using pii=pair<int, int>;

int cy = 2025;
int cm = 8;
int cd = 26;

int monthList[13] = {0,0,31,59,90,120,151,181,212,243,273,304,334};

bool isLeap(int y){
    return (y%4==0 && y%100!=0) || (y%400==0);
}

LL gapYear(int Y){
    auto leap = [](int y){ return y/4 - y/100 + y/400; };
    LL days = 0;
    if(Y >= 2025){
        LL leapY = leap(Y-1) - leap(2024);  
        LL totalYears = Y - 2025;
        days = totalYears*365 + leapY;
    } else {
        LL leapY = leap(2024) - leap(Y-1);
        LL totalYears = 2025 - Y;
        days = -(totalYears*365 + leapY);
    }
    return days;
}

LL monthDay(int Y, int M, int D){
    LL days = monthList[M] + D;
    if(isLeap(Y) && M > 2) days += 1;
    return days;
}

int compute(int Y, int M, int D){
    LL gap = gapYear(Y);
    LL currDay = monthDay(Y,M,D);
    LL baseDay = monthDay(cy,cm,cd);

    if(Y > cy || (Y==cy && (M>cm || (M==cm && D>cd)))){
        gap += currDay - baseDay;
        return (2 + gap % 7 + 7) % 7; 
    } else {
        gap += currDay - baseDay;
        return (2 + gap % 7 + 7) % 7;
    }
}


int main(void)
{
    int n;
    cin >> n;
    vector<int> res;
    for(int index=0; index<n; index++){
        int Y, M, D;
        cin >> Y >> M >> D;

        res.push_back(compute(Y, M, D));
    }
    for(auto ans:res) cout << ans << " ";
    cout << endl;


    return 0;
}