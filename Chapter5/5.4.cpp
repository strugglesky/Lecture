/*
* 题目名称：Zero-complexity Transposition
* 题目来源：上海交通大学复试上机题
* 题目链接：http://t.cn/AiKa20bt
* 代码作者：杨泽邦(炉灰)
描述
You are given a sequence of integer numbers. Zero-complexity transposition of the sequence is the reverse of this sequence. Your task is to write a program that prints zero-complexity transposition of the given sequence.
给定一个整数序列。该序列的零复杂度转置是该序列的逆序列。您的任务是编写一个程序，打印给定序列的零复杂度转置。
输入描述：
For each case, the first line of the input file contains one integer n-length of the sequence (0 ＜ n ≤ 10 000). The second line contains n integers numbers-a1, a2, …, an (-1 000 000 000 000 000 ≤ ai ≤ 1 000 000 000 000 000).
对于每种情况，输入文件的第一行包含一个整数 n - 序列的长度（0 ＜ n ≤ 10 000）。第二行包含 n 个整数-a1，a2，...，an（-1 000 000 000 000 000 ≤ ai ≤ 1 000 000 000 000 000）。
输出描述：
For each case, on the first line of the output file print the sequence in the reverse order.
对于每种情况，在输出文件的第一行以相反的顺序打印序列。
示例1
输入：
5
-3 4 6 -8 9

输出：
9 -8 6 4 -3



*/

#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

stack<long long> sequence;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        while (n--) {
            long long number;
            scanf("%lld", &number);
            sequence.push(number);
        }
        while (!sequence.empty()) {
            printf("%lld ", sequence.top());
            sequence.pop();
        }
        printf("\n");
    }
    return 0;
}
