/*
* 题目名称：质因子的个数
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/Aip7J0Oo
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cmath>
using namespace std;

int countPrimeFactors(int n) {
    int count = 0;
    // 处理因数2
    while (n % 2 == 0) {
        count++;
        n /= 2;
    }
    // 处理奇数因数
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            count++;
            n /= i;
        }
    }
    // 如果n大于1，说明n本身是一个质数
    if (n > 1) {
        count++;
    }
    return count;
}

int main() {
    int n;
    while (cin >> n) {
        cout << countPrimeFactors(n) << endl;
    }
    return 0;
}
