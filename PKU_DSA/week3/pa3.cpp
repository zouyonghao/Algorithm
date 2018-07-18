#include <iostream>
#include <stack>

using namespace std;

stack<char> op;
stack<char> num;


bool legal(char a)
{
    return (a >= 'a' && a <= 'z')
           || (a >= 'A' || a <= 'Z')
           || (a >= '0' || a <= '9')
           || a == '('
           || a == ')'
           || a == '+'
           || a == '-'
           || a == '*'
           || a == '/';
}

// 解析：
// 若两个表达式是相同的，
// 那么对于任意一个数 x ，
// 他们的运算结果是相同的。
// 那么，思路就确定了，选择 n 个不同的数
// （怎么选看自己，可以随机，也可以直接1 到 n，不过个人觉得随机兴许要好点吧），
// 然后将其值带入每个表达式，计算表达式的值，
// 只要有一个不相等，那么这两表达式就是不同的。

int main()
{
	int n;
	cin >> n;
	while (n-- > 0) {
		char i;
		cin >> i;
		while (i != '\n') {
			if (legal(i)) {

			}
			cin >> i;
		}
	}

}