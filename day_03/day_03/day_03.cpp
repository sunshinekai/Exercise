/*
ѡ���⣺

1.�ܰѺ����������Ķ������ݷ��ظ�����������������ķ����в���ȷ���ǣ�A��
A return�������
B �β�������
C �β��ö���ָ��
D �ö���ȫ�ֱ���
ע��returnֻ�ܷ���һ�����Ϸ������͵�ֵ�����ܷ��ض��

2.����main()����ִ�к�Ľ��Ϊ(B)
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
ע������Ϊj = 0;������j == 0

3.��һ���������������ڽ����󣬹��ڵ�������������������ȷ����:��C��
A ���������û�ж���������������ֻ���û������������
B �������û�ж���������������ֻ�������������������
C �ȵ������������������������û������������
D �ȵ��û����������������������������������
ע��û�ж���������������Ĭ����������
���������빹������෴����������ȵ��û��๹�캯����
�ٵ��������๹�캯���������ͷ��������ȵ��������������������ٵ��û�����������

4.�������һ����ľ�̬��Ա������,����ȷ����(C)
A ��̬��Ա�����ɱ���������з�������
B ����ľ�̬����ֻ�ܷ��ʸ���ľ�̬��Ա����
C ����ľ�̬���ݳ�Ա������ֵ�����޸�
D ������Է��ʸ���ľ�̬��Ա
E ��̬��Ա�޶�̬����
ע����̬�������������࣬�ڶ��󴴽�֮ǰ���Ѿ�����ռ䣬
��ķǾ�̬��ԱҪ�ڶ��󴴽�������ڴ棬���о�̬����ֻ�ܷ��ʾ�̬��Ա�����ܷ��ʷǾ�̬��Ա��
��̬��Ա���Ա���һ�����޸ģ��޸ĺ��ֵ���Ա����ж�����

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

������������������(C)
A 100 300 300 300 300 500
B 100 300 300 300 500
C 100 300 300 500
D 100 300 500
E 100 500
F �������
*/


/*
1.
����һ���ַ���str������ַ���str�е�����������ִ�
���ӣ�https://www.nowcoder.com/practice/bd891093881d4ddf9e56e7cc8416562d?tpId=85&&tqId=29864&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

ʾ����
����
abcd12345ed125ss123456789
���
123456789

�����������ַ�����ʹ��curȥ��¼���������ִ�������������������ַ������ʾһ�����������ִ������ˣ���
���ִ���֮ǰ�����ִ��Ƚϣ��������������¸��������ִ����µ�res
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
		// ����+=��cur
		if (str[i] >= '0' & str[i] <= '9')
		{
			cur += str[i];
		}
		else
		{
			// �ҳ��������ַ�����������ַ���
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
���ӣ�https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&tqId=11181&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2��
��������������0��
*/

/*
�ⷨ1��
���������������������������ڣ���һ���������м��Ǹ�����
���ַ�����Ȼ������⣬�������漰������sort����ʱ�临�Ӷ�ΪO(NlogN)�������ţ�
*/

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		// ��Ϊ�õ���sort��ʱ�临�Ӷ�O(NlogN)����������
		if (numbers.empty()) 
				return 0;
		std::sort(numbers.begin(), numbers.end()); // ����ȡ�����м��Ǹ���
		int middle = numbers[numbers.size() / 2];
		int count = 0; // ���ִ���
		for (int i = 0; i<numbers.size(); ++i)
		{
			if (numbers[i] == middle) 
				++count;
		} 
		return(count>numbers.size() / 2) ? middle : 0;
	}
};

/*
�ⷨ2��
����з������������֣��������ֵĴ����������������ֳ��ֵĴ����ͻ�Ҫ�ࡣ�ڱ�������ʱ��������ֵ��
һ��������һ�����֣�һ�Ǵ�����������һ������ʱ��������֮ǰ�����������ͬ���������1�����������
1��������Ϊ0���򱣴���һ�����֣�����������Ϊ1����������������������ּ�Ϊ����Ȼ�����ж���
�Ƿ�����������ɡ���ʱʱ�临�Ӷ�ΪO(N)
*/

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		if (numbers.empty()) return 0;
		// ����ÿ��Ԫ�أ�����¼����������ǰһ��Ԫ����ͬ���������1�����������1
		int result = numbers[0];
		int times = 1; // ����
		for (int i = 1; i<numbers.size(); ++i)
		{
			if (times == 0)
			{
				// ����result��ֵΪ��ǰԪ�أ����ô���Ϊ1
				result = numbers[i];
				times = 1;
			} 
			else if (numbers[i] == result)
			{
				++times; // ��ͬ���1
			} 
			else
			{
				--times; // ��ͬ���1
			}
		} 
		// �ж�result�Ƿ���������������ִ����������鳤�ȵ�һ��
		times = 0;
		for (int i = 0; i<numbers.size(); ++i)
		{
			if (numbers[i] == result)
				++times;
		} 
		return(times > numbers.size() / 2) ? result : 0;
	}
};