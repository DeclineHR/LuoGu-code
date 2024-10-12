#include <bits/stdc++.h>
using namespace std;

 void creat_hash(int a[], int n, int table[]) { //分别传入 初始数组，初始数组的元素个数n，哈希表载体talbe
        //使用i，遍历数组中的全部n个元素
        for (int i = 0; i < n; i++) {
            //通过table[a[i]]++
            //利用table数组下标
            //即可记录数字a[i]出现的次数 
            table[a[i]]++;
        }
    }
 int main()
 {
     int testarr[] = { 1,2,3,4,5,6,7,8,9,9 };
     //在使用哈希表前，需要先创建哈希表
     //可以任意设置一个长度为100的数组table
     //初始化其中元素为0
     int table[100] = { 0 };//table为哈希表载体
     //使用函数creat_hash创建哈希表
     creat_hash(testarr, 10, table);
    
   //遍历哈希表,实现元素次数分类功能
     for (int j = 0; j < 100; j++) {
         if (table[j] > 0) {
             cout << "数字" << j << "出现了" 
                 << abc[j] << "次" << endl;
         }
     }
     system("pause");
    return 0;
}
