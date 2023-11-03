#include <bits/stdc++.h>
#define f(a, s, d) for (int a = s; a < d; a++)

using namespace std;

const int sz = 12;
const int min_val = 6;
const int max_val = 18;

int ar[sz];

void gen() {
  f(i, 0, sz) { ar[i] = rand() % (max_val - min_val) + min_val; }
}

int32_t main() {
    srand(time(NULL));
  start:;
  gen();
  vector<pair<int, int>> answers;
  f(i, 0, sz) {
    f(j, i + 1, sz) {
      int sum1 = 0, sum2 = 0;
      for (int i2 = i + 1; i2 != j; i2 = (i2 + 1) % sz) {
        sum1 += ar[i2];
      }
      for (int i2 = j + 1; i2 != i; i2 = (i2 + 1) % sz) {
        sum2 += ar[i2];
      }
      if (sum1 == sum2) {
        answers.push_back({i, j});
      }
    }
  }
  if (answers.size() == 1) {
    f(i, 0, sz) {
        cout << ar[i] << ' ';
    }
    cout << endl;
    for (auto x : answers) {
      cout << x.first << ' ' << x.second << endl;
    }
  } else {
    goto start;
  }
}