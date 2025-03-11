/*
* 题目名称：猫狗收容所
* 题目来源：程序员面试金典
* 题目链接：无
* 代码作者：杨泽邦(炉灰)

题目描述
动物收容所。有家动物收容所只收容狗与猫，且严格遵守“先进先出”的原则。在收养该收容所的动物时，收养人只能收养所有动物中“最老”（由其进入收容所的时间长短而定）的动物，或者可以挑选猫或狗（同时必须收养此类动物中“最老”的）。换言之，收养人不能自由挑选想收养的对象。请创建适用于这个系统的数据结构，实现各种操作方法，比如 enqueue、dequeueAny、dequeueDog 和 dequeueCat。允许使用 Java 内置的 LinkedList 数据结构。

enqueue 方法有一个 animal 参数，animal[0]代表动物编号，animal[1]代表动物种类，其中 0 代表猫，1 代表狗。

dequeue 方法返回一个列表[动物编号, 动物种类]，若没有可以收养的动物，则返回[-1,-1]。

示例 1:
输入：
["AnimalShelf", "enqueue", "enqueue", "dequeueCat", "dequeueDog", "dequeueAny"]
[[], [[0, 0]], [[1, 0]], [], [], []]
输出：
[null,null,null,[0,0],[-1,-1],[1,0]]
示例 2:
输入：
["AnimalShelf", "enqueue", "enqueue", "enqueue", "dequeueDog", "dequeueCat", "dequeueAny"]
[[], [[0, 0]], [[1, 0]], [[2, 1]], [], [], []]
输出：
[null,null,null,null,[2,1],[0,0],[1,0]]
说明:
收纳所的最大容量为 20000
题目思考
需要哪些数据结构?
解决方案
思路
由于需要可以单独挑选猫或狗, 所以需要两个双端队列来存对应的编号
另外又有需求来挑选猫或狗中最老的, 所以我们还要额外维护动物加入队列的时间, 也要将这一信息和编号一起入队, 入队后再将时间+1
这样出队最老的动物时, 只需要比较两个队列开头的时间, 然后选择更老的那只动物即可
复杂度
时间复杂度 O(1): 显然每种操作都只需要常数时间
空间复杂度 O(N): 使用了两个双端队列存 N 个元素

作者：随便发挥
链接：https://www.nowcoder.com/discuss/353148656217956352
来源：牛客网

*/

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct animal {
    int number;                                     //动物编号
    int order;                                      //收容次序
    animal(int n, int o): number(n), order(o) {}
};

queue<animal> cats;
queue<animal> dogs;

int main() {
    int n;
    scanf("%d", &n);
    int order = 0;
    for (int i = 0; i < n; ++i) {
        int event;
        scanf("%d", &event);
        if (event == 1) {
            int number;                             //动物编号
            scanf("%d", &number);
            if (0 < number) {
                dogs.push(animal(number, order++));
            } else {
                cats.push(animal(number, order++));
            }
        } else {
            int type;                               //收养方式
            scanf("%d", &type);
            if (type == 0 && !dogs.empty() && !cats.empty()) {
                if (dogs.front().order < cats.front().order) {
                    printf("%d ", dogs.front().number);
                    dogs.pop();
                } else {
                    printf("%d ", cats.front().number);
                    cats.pop();
                }
            } else if (type == 0 && dogs.empty() && !cats.empty()) {
                printf("%d ", cats.front().number);
                cats.pop();
            } else if (type == 0 && !dogs.empty() && cats.empty()) {
                printf("%d ", dogs.front().number);
                dogs.pop();
            } else if (type == 1 && !dogs.empty()) {
                printf("%d ", dogs.front().number);
                dogs.pop();
            } else if (type == -1 && !cats.empty()) {
                printf("%d ", cats.front().number);
                cats.pop();
            }
        }
    }
    printf("\n");
    return 0;
}
