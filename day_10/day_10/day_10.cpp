/*
选择题

1.
32位系统中，定义**a[3][4],则变量占用内存空间为(B)
A 4
B 48
C 192
D 12
注：**a[3][4]表示的是一个3*4的二维数组，数组里面存放的数据，
是**类型的指针，然后每个指针是4个字节，那么12个指针就是48个字节。

2.
int I=1;
if(I<=0)
printf("****\n") ;
else
printf("%%%%\n");
A %%
B ****
C 有语法错，不能正确执行
D %%%%
注：%后才是字符%

3.
有如下C++代码：
struct A{
void foo(){printf("foo");}
virtual void bar(){printf("bar");}
A(){bar();}
};

struct B:A{
void foo(){printf("b_foo");}
void bar(){printf("b_bar");}
};
那么：
A *p=new B;
p->foo();
p->bar();

输出为(A)
A barfoob_bar
B foobarb_bar
C barfoob_foo
D foobarb_fpp
注：A *p=newB;// A类指针指向一个实例化对象B，
B类继承A类，先调用父类的无参构造函数，bar()输出bar，B类没有自己显示定义的构造函数。
p->foo();// 执行B类里的foo()函数，因为foo不是虚函数，所以直接调用父类的foo函数，输出foo
p->bar();// 执行B类的bar()函数, 该函数为虚函数，调用子类的实现，输出b_bar

4.
代码可以通过编译吗？如果不能应该如何修改()
template<class T> class Foo{
T tVar;
public:
Foo(T t) : tVar(t) { }
};
template<class T> class FooDerived:public Foo<T>
{ };
int main()
{
FooDerived<int> d(5);
return 0;
}

A 代码可以正确通过编译。
B 编译错误，FooDerived是一个继承模板类的非模板类，它的类型不能改变。
C 编译错误，tVal变量是一个不确定的类型。
D 编译错误，可以在FooDerived类中添加一个构造函数解决问题。

注：当基类构造函数需要外部传递参数才能进行初始化时，
派生类必须显式定义构造函数，为基类传递参数；
基类如果不需要传递或者可以不传递参数，派生类可以不用显式定义构造函数。
*/


/*
编程题

1.
链接：https://www.nowcoder.com/practice/e1bb714eb9924188a0d5a6df2216a3d1?tpId=8&&tqId=11055&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。
给定一个二维数组board，代表当前棋盘，其中元素为1的代表是当前玩家的棋子，
为0表示没有棋子，为-1代表是对方玩家的棋子。

测试样例：
[[1,0,1],[1,-1,-1],[1,-1,0]]
返回：true
*/

/*
思路1：判断行、列、对角线是否为1即可
*/
class Board {
public:
	bool checkWon(vector<vector<int>> board) {
		for (int i = 0; i < 3; i++)
		{
			if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == 1)
				return true; //行

			else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == 1)
				return true; //列

			else if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == 1)
				|| (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == 1))
				return true; //对角线
			else
				return false;
		}
	}
};

/*
思路2：
井字棋有四种情况表示当前玩家获胜，1代表当前玩家棋子 
1. 行全为1，即行的和为3 
2. 列全为1，列的和为3 
3. 主对角全为1，对角和为3 
4. 副对角全为1，对角和为3
5. 如果扩展为N*N的话，判断和是否等于N，
下面代码适用任何情况
*/

class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		int row = board.size();
		//检查每一行的和是是否等于row
		int i, j, sum;
		for (i = 0; i<row; i++)
		{
			sum = 0;
			for (j = 0; j<row; j++)
			{
				sum += board[i][j];
			} 
			if(sum == row)
				return true;
		} 
		// 检查每一列的和是是否等于row
		for (i = 0; i< row; i++)
		{
			sum = 0;
			for (j = 0; j<row; j++)
			{
				sum += board[j][i];
			} 
			if(sum == row)
				return true;
		} 
		// 检查主对角线的和是是否等于row
			sum = 0;
			for (i = 0; i<row; i++)
			{
				sum += board[i][i];
			} 
			if(sum == row)
				return true;
			//检查副对角线的和是是否等于row
			sum = 0;
			for (i = 0; i<row; i++)
			{
				sum += board[i][row - i - 1];
			} 
			if(sum == row)
				return true;
			return false;
	}
};


/*
2.
链接：https://www.nowcoder.com/practice/52d382c2a7164767bca2064c1c9d5361?tpId=37&&tqId=21310&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
密码按如下规则进行计分，并根据不同的得分为密码进行安全等级划分。
一、密码长度:
5分: 小于等于4个字符
10分: 5到7字符
25分: 大于等于8个字符

二、字母:
0分: 没有字母
10分: 全都是小（大）写字母
20分: 大小写混合字母

三、数字:
0分: 没有数字
10分: 1个数字
20分: 大于1个数字

四、符号:
0分: 没有符号
10分: 1个符号
25分: 大于1个符号

五、奖励:

2 分: 字母和数字
3 分: 字母、数字和符号
5 分: 大小写字母、数字和符号

最后的评分标准:
>= 90: 非常安全
>= 80: 安全（Secure）
>= 70: 非常强
>= 60: 强（Strong）
>= 50: 一般（Average）
>= 25: 弱（Weak）
>= 0:  非常弱


对应输出为：
VERY_SECURE
SECURE,
VERY_STRONG,
STRONG,
AVERAGE,
WEAK,
VERY_WEAK,

请根据输入的密码字符串，进行安全评定。

输入
38$@NoNoNo
输出
VERY_SECURE
*/


/*
思路：这里对于不同种类的字符得分不同，可以现对每一个维度进行单独判断，即对于长度，字母，数字，
符号单独判断，最后把所有的单项值根据题目要求相加，输出对应的安全级别
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	int score = 0;
	getline(cin, s);

	// 遍历密码，判断密码的字符组成
	int number = 0; // 数字
	int letter = 0, letters[2]; // 字母
	int symbol = 0; // 符号
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0'&& s[i] <= '9')
			number++;
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			letter = 1;
			letters[0] = 1;
		}
		else if (s[i] >= 'a' && s[i] <= 'z')
		{
			letter = 1;
			letters[1] = 1;
		}
		else
			symbol++;
	}

	// 密码长度
	if (s.size() <= 4)
		score += 5;
	else if (s.size() <= 7)
		score += 10;
	else
		score += 25;

	// 判断字母
	if (letter == 0)
		score += 0;
	else if (letters[0] == 1 && letters[1] == 1)
		score += 20;
	else
		score += 10;

	// 判断数字
	if (number == 0)
		score += 0;
	else if (number == 1)
		score += 10;
	else
		score += 20;

	// 判断符号
	if (symbol == 0)
		score += 0;
	else if (symbol == 1)
		score += 10;
	else
		score += 25;

	// 奖励分数
	if (number > 0 && letter > 0)
		score += 2;
	else if (number > 0 && letter > 0 && symbol > 0)
		score += 3;
	else if (number > 0 && letter > 0 && symbol > 0
		&& letters[0] == 1 && letters[1] == 1)
		score += 5;

	// 判断最终结果
	if (score >= 90)
		cout << "VERY_SECURE" << endl;
	else if (score >= 80)
		cout << "SECURE" << endl;
	else if (score >= 70)
		cout << "VERY_STRONG" << endl;
	else if (score >= 60)
		cout << "STRONG" << endl;
	else if (score >= 50)
		cout << "AVERAGE" << endl;
	else if (score >= 25)
		cout << "WEAK" << endl;
	else
		cout << "VERY_WEAK" << endl;
	return 0;
}