#include <bits/stdc++.h>
using namespace std;
int main()
{
    long N;
    cin >> N;
    long r = 1;
    long* p = new long[N];//创建动态数组p

    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }

    set<long>b(p, p + N); //set函数实现去重，排序
    long len = b.size(); //计算set后的数组大小
    long * arr = new long[len];//copy函数复制set后的元素进入数组 以进行binary_search
    copy(b.begin(), b.end(),arr);

    for (int j = 0; j <= len; j++) {
        if (binary_search(arr, arr + len, r) == 1) {//binary_search来查找r
            r++;//binary_search == 1 表明存在元素 则r++
        }
        else {
            cout << r;
            return 0;
        }
    }
    return 0;
}
