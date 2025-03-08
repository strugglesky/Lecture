/*
* 题目名称：成绩排序
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/E9d3ysv
* 代码作者：杨泽邦(炉灰)

描述
用一维数组存储学号和成绩，然后，按成绩排序输出。
输入描述：
输入第一行包括一个整数N(1<=N<=100)，代表学生的个数。 接下来的N行每行包括两个整数p和q，分别代表每个学生的学号和成绩。
输出描述：
按照学生的成绩从小到大进行排序，并将排序后的学生信息打印出来。 如果学生的成绩相同，则按照学号的大小进行从小到大排序。
示例1
输入：
3
1 90
2 87
3 92

输出：
2 87
1 90
3 92


*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

struct Student {
    int number;                                     //学号
    int score;                                      //成绩
};

Student arr[MAXN];

bool Compare(Student x, Student y) {                //比较函数
    if (x.score == y.score) {                       //成绩相等比较学号
        return x.number < y.number;
    } else {                                        //成绩不等比较成绩
        return x.score < y.score;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &arr[i].number, &arr[i].score);
    }
    sort(arr, arr + n, Compare);                    //按照比较函数排序
    for (int i = 0; i < n; ++i) {
        printf("%d %d\n", arr[i].number, arr[i].score);
    }
    return 0;
}
