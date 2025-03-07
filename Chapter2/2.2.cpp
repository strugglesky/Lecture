/*
* 题目名称：反序数
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/E9WBrut
* 代码作者：杨泽邦(炉灰)
*/

/*
描述
设N是一个四位数，它的9倍恰好是其反序数（例如：1234的反序数是4321）
求N的值
输入描述：
程序无任何输入数据。
输出描述：
输出题目要求的四位数，如果结果有多组，则每组结果之间以回车隔开。
*/

#include <iostream>
#include <cstdio>

using namespace std;

int Reverse(int number) {    //求反序数
    int reverseNumber = 0;
    while (number != 0) {
        reverseNumber *= 10;
        reverseNumber += number % 10;
        number /= 10;
    }
    return reverseNumber;
}

int main() {
    for (int i = 1000; i <= 9999; ++i) {
        if (i * 9 == Reverse(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}
