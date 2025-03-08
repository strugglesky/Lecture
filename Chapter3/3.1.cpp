/*
* 题目名称：排序
* 题目来源：华中科技大学复试上机题
* 题目链接：http://t.cn/E9dLx5K
* 代码作者：杨泽邦(炉灰)

描述
    对输入的n个数进行排序并输出。
输入描述：
    输入的第一行包括一个整数n(1<=n<=100)。     接下来的一行包括n个整数。
输出描述：
    可能有多组测试数据，对于每组数据，将排序后的n个整数输出，每个数后面都有一个空格。     每组测试数据的结果占一行。
示例1
输入：
4
1 4 3 2

输出：
1 2 3 4 


*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

int arr[MAXN];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        sort(arr, arr + n);             //默认升序排序
        for (int i = 0; i < n; ++i) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}
