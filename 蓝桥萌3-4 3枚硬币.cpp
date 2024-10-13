#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    int M = 0;
    int* p = new int[N + 3];
    int* r = new int[100000];
  
    fill(r, r + 100000, 0);//填充fill函数 用来赋值填充满数组r为0
  
    p[0] = 0;//三枚硬币可以是0 0 0 因此初始化三个0
    p[1] = 0;
    p[2] = 0;
  
    for (int i = 3; i < N + 3; i++) {//输入硬币面值
        cin >> p[i];
    }
//三层循环取三个硬币
    for (int j = 0; j < N + 3; j++) {//第一层循环 

        for (int k = 0; k < j; k++) {//第二层循环

            for (int l = 0; l < k; l++) {//第三层循环
                r[M] = p[j] + p[k] + p[l];//将三种任意排列组合结果存储在r数组中
                M++;
            }
        }
    }
    set<int>y(r, r + M);//重新创建y数组 存储 去重后的数组
    vector<int> x(y.size());//重新创建x数组 存储y来执行x.size的操作直接计算元素个数
    copy(y.begin(), y.end(), x.begin());
    cout << x.size();
    return 0;
}
