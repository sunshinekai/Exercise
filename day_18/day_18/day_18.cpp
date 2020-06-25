/*
�����
1.
���ӣ�https://www.nowcoder.com/practice/1221ec77125d4370833fd3ad5ba72395?tpId=37&tags=&title=&diffculty=0&judgeStatus=0&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
��һֻ���ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�С���ӳ����������º�ÿ��������һֻ���ӣ��������Ӷ���������ÿ���µ���������Ϊ���٣�
����
9
���
34
*/

/*
˼·����n���µ�������������������ɣ�һ�������ϸ��µ�����f(n-1)����һ��������3���´�����ӣ�
����һֻ����f(n-2)�����Ե�n�������������� f(n) = f(n - 1) + f(n - 2)��
�������ڱ��࿼��쳲���������
*/

// �ݹ�
#include <iostream>
using namespace std;

int rabbits_count(int month)
{
	if (month < 3)
		return 1;
	return rabbits_count(month - 1) + rabbits_count(month - 2);
}

int main()
{
	int month;
	while (cin >> month)
	{
		int ret = rabbits_count(month);
		cout << ret << endl;
	}
	return 0;
}

// �ǵݹ�

#include <iostream>
using namespace std;
int main(){
	int month;
	while (cin >> month){
		int first = 1;
		int second = 1;
		int result;
		for (int i = 3; i <= month; ++i)
		{
			result = first + second;
			first = second;
			second = result;
		}
		cout << result << endl;
	} 
	return 0;
}


/*
2.
���ӣ�https://www.nowcoder.com/practice/43072d50a6eb44d2a6c816a283b02036?tpId=37&&tqId=21294&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
�����������ڼ�����У�ͨ���һ�������﷨���㷺Ӧ�����ļ����������ݿ⡢������ʽ������
��Ҫ��ʵ���ַ���ͨ������㷨��
Ҫ��
ʵ������2��ͨ�����
*��ƥ��0�������ϵ��ַ����ַ���Ӣ����ĸ������0-9��ɣ������ִ�Сд����ͬ��
����ƥ��1���ַ�

����
te?t*.*
txt12.xls
���
false
*/

/*
�������ͨ���ݹ���⡣��ǰ���һ��ƥ�䣬������ͬ�ַ���������ƶ�һ���ַ������ͨ���
����"?"������ƥ�䣬�Զ�����һ���ַ������ͨ�������"*"�������ƥ���������ַ�������
0������ʱ����������ѡ��1��ƥ��0����ͨ�������ƶ�һ���ַ����ַ���������2��ƥ��1
����ͨ������ַ���������ƶ�һ���ַ���3��ƥ������ͨ����������ַ�������ƶ�һ����
����
�ݹ����ֹ������ͨ��������ַ�������'\0'��������ͬʱ������
*/

#include <iostream>
#include <string>
using namespace std;

bool match(const char* pattern, const char *str)
{
	// ��ǰ�ַ�����������true
	if (*pattern == '\0' && *str == '\0')
		return true;
	// �����ַ�����һ���Ƚ������򷵻�false
	if (*pattern == '\0' || *str == '\0')
		return false;
	if (*pattern == '?')
		// ���� ? �ţ�ƥ��һ���ַ�������һ��λ��
		return match(pattern + 1, str + 1);

	else if (*pattern == '*')
		// ����*�ţ�ƥ��0��(str��Ų��)��1�������߶���ǰŲ��һ���ַ�������(str��ǰŲ��һ���ַ�)
		return match(pattern + 1, str) || match(pattern + 1, str + 1) || match(pattern, str + 1);
	
	else if (*pattern == *str)
		// �����ǰ�ַ���ȣ�ƥ����һ���ַ�
		return match(pattern + 1, str + 1);
	
	return false;
}

int main()
{
	string pattern, str;
	while (cin >> pattern >> str)
	{
		bool ret = match(pattern.c_str(), str.c_str());

		if (ret)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	} 
	return 0;
}