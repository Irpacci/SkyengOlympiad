#include <bits/stdc++.h>

using namespace std;

int score = 0;
string s = "AAAAAAAAAA";
int cntall = 4;
int sz = 10;

void make_plus() {
  int index = s.size() - 1;
  s[index]++;
  while (s[index] == 'E') {
    s[index] = 'A';
    index--;
    s[index]++;
  }
}
/*
нанести 6 если рядом две другие одинаковые
нанести 6, потом 5, так до 0
нанести 1 потом 2 потом 3
нанести 2 * кол-во другихразличных
//нанести 6 если рядом две различные и причем одна из них я
*/
void checkC() {
  for (int i = 1; i < sz - 1; i++) {
    if (s[i - 1] == s[i + 1] && s[i] == 'C' && s[i - 1] != 'C') {
      score += 8;
    }
  }
}

void checkB() {
  int real = 5;
  for (int i = 0; i < sz; i++) {
    if (s[i] == 'B') {
      score += real;
      if (real > 0) {
        real--;
      }
    }
  }
}

void checkA() {
  int real = 0;
  for (int i = 0; i < sz; i++) {
    if (s[i] == 'A') {
      score += real;
      real++;
    }
  }
}

void checkD() {

  int cnt[cntall];
  for (int i = 0; i < cntall; i++) {
    cnt[i] = 0;
  }
  for (int i = 0; i < sz; i++) {
    cnt[s[i] - 'A']++;
  }
  int promscore = 0;
  if (cnt[3]) {
    for (int i = 0; i < cntall; i++) {
      if (cnt[i] && i != 3) {
        promscore += 2;
      }
    }
    score += promscore * min(3, cnt[3]);
  }
}

void checkE() {
  for (int i = 1; i < sz - 1; i++) {
    if (s[i - 1] != s[i + 1] && (s[i] == s[i - 1] || s[i] == s[i + 1])) {
      score += 2;
    }
  }
}

void check() {
  score = 0;
  checkA();
  checkB();
  checkC();
  checkD();
  checkE();
}

int32_t main() {
  string max_string;
  int mx = 0;
  string maxs; /*
   do {
       check();
       if(score > mx) {
           mx = score;
           maxs = s;
       }
       if(score == 60) cout << "here " << s << endl;
       make_plus();
   } while(s != "DDDDDDDDDD");*/
  while (true) {
    cin >> s;
    check();
    cout << score;
  }
  cout << maxs << ' ' << mx;
}