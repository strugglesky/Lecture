/*
* 题目名称：最小公倍数
* 题目来源：HDU 1108
* 题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=1108
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

int getGCD(int x,int y){//最大公约数 
	int n = min(x,y);
	int ans = 1;
	for(int i = 1; i <= n; i++){
		if(x % i == 0 && y % i == 0){
			ans = max(ans,i);
		}
	}
	return ans;
}
int getLCM(int a,int b){//最小公倍数 
	return (a * b) / getGCD(a,b);
}
int main(){
	int a,b;
	while(cin >> a >>b){
		cout << getLCM(a,b) << endl;
	}
	return 0;
}
