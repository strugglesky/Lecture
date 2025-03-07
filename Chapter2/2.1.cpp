/*
* 题目名称：abc
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/E9WMRTE
* 代码作者：杨泽邦(炉灰)
*/

/*
描述
设a、b、c均是0到9之间的数字，abc、bcc是两个三位数，且有：abc+bcc=532。求满足条件的所有a、b、c的值。
输入描述：
题目没有任何输入。
输出描述：
请输出所有满足题目条件的a、b、c的值。 a、b、c之间用空格隔开。 每个输出占一行。
*/    
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    for (int a = 0; a <= 9; ++a) {
        for (int b = 0; b <= 9; ++b) {
            for (int c = 0; c <= 9; ++c) {
                if (a * 100 + b * 110 + c * 12 == 532) {
                    printf("%d %d %d\n", a, b, c);
                }
            }
        }
    }
    return 0;
}
