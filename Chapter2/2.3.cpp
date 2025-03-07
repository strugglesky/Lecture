/*
* 题目名称：对称平方数1
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/E9lUYRn
* 代码作者：杨泽邦(炉灰)
*/

/*
描述
打印所有不超过256，其平方具有对称性质的数。如2，11就是这样的数，因为2*2=4，11*11=121。
输入描述：
无任何输入数据
输出描述：
输出具有题目要求的性质的数。如果输出数据不止一组，各组数据之间以回车隔开。
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
    for (int i = 0; i <= 256; ++i) {
        if (i * i == Reverse(i * i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}
