/*
    The method come from EmberQR (https://github.com/IamMI/fdu-cs-coding/issues/1).
    Thanks for his/her suggestion!
*/
#include <iostream>
#include <vector>
using namespace std;

/*
    The method is Sakamoto algorithm. Here follows one link:
    - https://www.jianshu.com/p/9b4e2bdd18c1
*/

int dayOfTheWeek(int d, int m, int y) {
    y -= m < 3 ? 1 : 0;
    return (y + y / 4 - y / 100 + y / 400 +
                  "-bed=pen+mad."[m] + d) %
                 7;
}

int main(void)
{
    int n;
    cin >> n;
    vector<int> res;
    for(int index=0; index<n; index++){
        int Y, M, D;
        cin >> Y >> M >> D;

        res.push_back(dayOfTheWeek(D, M, Y));
    }
    for(auto ans:res) cout << ans << " ";
    cout << endl;

    return 0;
}