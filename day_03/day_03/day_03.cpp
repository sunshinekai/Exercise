/*
选择题：

1.能把函数处理结果的二个数据返回给主调函数，在下面的方法中不正确的是（A）
A return这二个数
B 形参用数组
C 形参用二个指针
D 用二个全局变量
注：return只能返回一个符合返回类型的值，不能返回多个

2.下列main()函数执行后的结果为(B)
int func()
{
	int i,j,k=0;
	for(i=0,j=-1;j=0;i++,j++)
	{
		k++;
	}
	return k;
}
int main()
{
	cout<<(func());
}
A -1
B 0
C 1
D 2
注：上面为j = 0;而不是j == 0

3.当一个类对象的生命周期结束后，关于调用析构函数的描述正确的是:（C）
A 如果派生类没有定义析构函数，则只调用基类的析构函数
B 如果基类没有定义析构函数，则只调用派生类的析构函数
C 先调用派生类的析构函数，后调用基类的析构函数
D 先调用基类的析构函数，后调用派生类的析构函数
注：没有定义析构函数会有默认析构函数
析构过程与构造过程相反，构造过程先调用基类构造函数，
再调用派生类构造函数。析构就反过来，先调用派生类析构函数，再调用基类析构函数

4.下面关于一个类的静态成员描述中,不正确的是(C)
A 静态成员变量可被该类的所有方法访问
B 该类的静态方法只能访问该类的静态成员函数
C 该类的静态数据成员变量的值不可修改
D 子类可以访问父类的静态成员
E 静态成员无多态特性
注：静态方法属于整个类，在对象创建之前就已经分配空间，
类的非静态成员要在对象创建后才有内存，所有静态方法只能访问静态成员，不能访问非静态成员；
静态成员可以被任一对象修改，修改后的值可以被所有对象共享。

5.
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	vector<int>array;
	array.push_back(100);
	array.push_back(300);
	array.push_back(300);
	array.push_back(300);
	array.push_back(300);
	array.push_back(500);

	vector<int>::iterator itor;

	for(itor=array.begin();itor!=array.end();itor++)
	{
		if(*itor==300)
			itor=array.erase(itor);
	}

	for(itor=array.begin();itor!=array.end();itor++)
	{
		cout<<*itor<<"";
	}
	return 0;
}

下面这个代码输出的是(C)
A 100 300 300 300 300 500
B 100 300 300 300 500
C 100 300 300 500
D 100 300 500
E 100 500
F 程序错误
*/


/*
1.
读入一个字符串str，输出字符串str中的连续最长的数字串
链接：https://www.nowcoder.com/practice/bd891093881d4ddf9e56e7cc8416562d?tpId=85&&tqId=29864&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

示例：
输入
abcd12345ed125ss123456789
输出
123456789

分析：遍历字符串，使用cur去记录连续的数字串，如果遇到不是数字字符，则表示一个连续的数字串结束了，则将
数字串跟之前的数字串比较，如果更长，则更新更长的数字串更新到res
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str, res, cur;
	cin >> str;
	for (size_t i = 0; i <= str.size();i++)
	{
		// 数字+=到cur
		if (str[i] >= '0' & str[i] <= '9')
		{
			cur += str[i];
		}
		else
		{
			// 找出更长的字符串，则更新字符串
			if (res.size() < cur.size())
				res = cur;
			else
				cur.clear();
		}
	}
	cout << res << endl;
	return 0;
}


/*
2.
链接：https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&tqId=11181&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
如果不存在则输出0。
*/

/*
解法1：
数组排序后，如果符合条件的数存在，则一定是数组中间那个数。
这种方法虽然容易理解，但由于涉及到快排sort，其时间复杂度为O(NlogN)并非最优；
*/

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		// 因为用到了sort，时间复杂度O(NlogN)，并非最优
		if (numbers.empty()) 
				return 0;
		std::sort(numbers.begin(), numbers.end()); // 排序，取数组中间那个数
		int middle = numbers[numbers.size() / 2];
		int count = 0; // 出现次数
		for (int i = 0; i<numbers.size(); ++i)
		{
			if (numbers[i] == middle) 
				++count;
		} 
		return(count>numbers.size() / 2) ? middle : 0;
	}
};

/*
解法2：
如果有符合条件的数字，则它出现的次数比其他所有数字出现的次数和还要多。在遍历数组时保存两个值：
一是数组中一个数字，一是次数。遍历下一个数字时，若它与之前保存的数字相同，则次数加1，否则次数减
1；若次数为0，则保存下一个数字，并将次数置为1。遍历结束后，所保存的数字即为所求。然后再判断它
是否符合条件即可。这时时间复杂度为O(N)
*/

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		if (numbers.empty()) return 0;
		// 遍历每个元素，并记录次数；若与前一个元素相同，则次数加1，否则次数减1
		int result = numbers[0];
		int times = 1; // 次数
		for (int i = 1; i<numbers.size(); ++i)
		{
			if (times == 0)
			{
				// 更新result的值为当前元素，并置次数为1
				result = numbers[i];
				times = 1;
			} 
			else if (numbers[i] == result)
			{
				++times; // 相同则加1
			} 
			else
			{
				--times; // 不同则减1
			}
		} 
		// 判断result是否符合条件，即出现次数大于数组长度的一半
		times = 0;
		for (int i = 0; i<numbers.size(); ++i)
		{
			if (numbers[i] == result)
				++times;
		} 
		return(times > numbers.size() / 2) ? result : 0;
	}
};