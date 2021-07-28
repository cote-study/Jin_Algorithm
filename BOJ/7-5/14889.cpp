#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

int map[22][22];
int res = -1;

int main()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    vector<int> mask(n/2,0);
    for (int i = 0; i < n / 2; i++) {
        mask.push_back(1);
    }

    do {
        vector<int>s;
        vector<int>l;

        for (int i = 0; i < n; i++) {
            if (mask[i] == 0)s.push_back(i);
            else l.push_back(i);
        }

        int sres = 0;
        int lres = 0;

        for (int i = 0; i < s.size(); i++) {
            for (int j = i + 1; j < s.size(); j++) {
                sres += map[s[i]][s[j]];
                sres += map[s[j]][s[i]];
            }
        }

        for (int i = 0; i < l.size(); i++) {
            for (int j = i + 1; j < l.size(); j++) {
                lres += map[l[i]][l[j]];
                lres += map[l[j]][l[i]];
            }
        }

        if (res == -1 || res > abs(sres - lres)) {
            res = abs(sres - lres);
        }

    } while (next_permutation(mask.begin(), mask.end()));

    cout << res;
  
    return 0;
}
