//本题实际上是斐波那契数列
//即f[i + 2] = f[i] + f[i + 1]
//开一个二维数组f[5010][5010] 一维上存储每个台阶 二维上存储的是不同的走法
//因为题目N < 5000 是高精度 要用数组保存;
//初始化N == 1时 f = 1
//初始化N == 2时 f = 2
//开始递推算法
#include<bits/stdc++.h>
using namespace std;
int N;
int f[5010][5010];
int len = 1;
void hightplus(int k) {
    for (int i = 1; i <= len; i++) {//递推相加
        f[k][i] = f[k - 1][i] + f[k - 2][i];
    }
    for (int i = 1; i <= len; i++) {
        if (f[k][i] >= 10) {//高精度加法
            f[k][i + 1] += 1;
            f[k][i] %= 10;
            if (f[k][len + 1])len++;//判断是否最高位进位了
        }
    }
}
int main() {
    cin >> N;
    f[1][1] = 1; f[2][1] = 2;//初始化
    for (int i = 3; i <= N; i++)hightplus(i);//从N = 3开始进入递推
    for (int i = len; i >= 1; i--) {
        cout << f[N][i];
    }
    return 0;
}
