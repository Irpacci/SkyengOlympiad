#include <bits/stdc++.h>
#define f(a, s, d) for (int a = s; a < d; a++)

using namespace std;

string s;
int k;

void shift() {
    f(i, 0, s.size()) {
        if(isdigit(s[i])) {
            int nx = s[i] - '0';
            nx = (nx + k) % 10;
            s[i] = nx + '0';
        }
    }
}

int32_t main() {
    cin >> s >> k;
    shift();
    cout << s;
}