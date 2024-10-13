#include <bits/stdc++.h>
using namespace std;
  int main(){
      int N;
      int * p = new int[10000];
      int count = 0;
      cin >> N;
     /* for (int k = 0; k < 10000; k++) {
          p[k] = 0;
      }
    */
      //使用fill()函数优化
    fill(p,p + 10000,0);
      for (int i = 0; i < N; i++) {
          string b;
          cin >> b;
          int len = b.size();

          for (int j = 0; j < len; j++) {
              if (b[0] == b[j]) {
                  p[i]++;
              }
          }
        
          if (p[i] == len) {
              count++;
          }
        
      }

  cout << count;
  return 0;
}
