/*
ѡ����

������ͺ���������˵����ȷ��(A)
A sum���ر��ʽ�����������ܺͣ����ֻ�������������͵���
B Avg���ر��ʽ����������ƽ��ֵ���������������ͺ������͵���
C Max��Min���������ַ��͵���
D Count���������ַ��͵���

ע��
sum������������ֶ����ͱ�������ֵ�͵ģ������������������͵ģ������ַ������ڡ�
avg�������ֵ���� , ���� ���� ����
*/


/*
�����

1.
���ӣ�https://www.nowcoder.com/questionTerminal/aed1c7bbc2604e7c9661a2348b0541b8?pos=46&mutiTagIds=579&orderByHotValue=1

��C/C++ת��Java�ĳ���Ա��һ��ʼ�ϰ�ߵľ��Ǳ���������ʽ�ĸı䡣C���Է��ʹ���»��߷ָ�������ʣ�
���硰hello_world������Java�����һ�ֽ������������Ĺ��򣺳��׸��������⣬���е��ʵ�����ĸ��д�����硰helloWorld����
���������ĳ���Ա���Զ�ת����������

����
hello_world<br/>nice_to_meet_you
���
helloWorld<br/>niceToMeetYou
*/

/*
˼·��
����һ���ַ�һ���ַ��Ķ�ȡ����
1. ���� '_ '��ɾ��
2. �����һ���ַ��� _ ����һ���ַ�ת��д��ĸ
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			if (s[i] == '_')
			{
				s[i + 1] = toupper(s[i + 1]);
				s.erase(i,1);
			}
		}
		cout << s << endl;
	}
	return 0;
}


/*
2.
���ӣ�https://www.nowcoder.com/questionTerminal/81544a4989df4109b33c2d65037c5836

���ַ����е����е��ʽ��е��š�
˵����
1�����ɵ��ʵ��ַ�ֻ��26����д��СдӢ����ĸ��
2���ǹ��ɵ��ʵ��ַ�����Ϊ���ʼ������
3��Ҫ���ź�ĵ��ʼ������һ���ո��ʾ�����ԭ�ַ��������ڵ��ʼ��ж�������ʱ������ת����Ҳֻ�������һ���ո�������
4��ÿ�������20����ĸ��
*/

/*
��Ŀ������
��������ǰ������ַ������������� �з� �� �ϲ� ��Ȼ���� C ���Կ��Ͻ������Ƶ�����, �����������ı�
���ǶԵ��ʷָ����������, ֻҪ����ĸ, ����Ҫ���ɷָ��, ���ҷָ������Ŀ��������.
����˼·��
���������˼·��Ȼ��
1. ���з�(�з�ǰ�ȶԷָ��������, ͳһ�ָ��) , ��ʱ����ʹ�� stringstream �����з�
2. �ٺϲ�(���зֽ������ϲ�) ֱ���ַ���ƴ�Ӻϲ�����
*/


#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

void deal(vector<string>&res, string& str, char delim = ' ') 
{
	// ���ַ��������з�, ���� stringstream ���. Ĭ�Ϸָ��
	// stringstream ����������з�, ��������ַ���������֮
	stringstream ss;
	ss << str;
	string tmp;
	while (ss >> tmp) 
	{
		res.push_back(tmp);
	}
} 

int main()
{
	string str;
	while (getline(cin, str))
	{
		vector<string> res;
		for (int i = 0; i < str.size(); i++)
			// �ȶԷָ�����д���. ������ַָ��, ��ͳһ����
		if (!isalnum(str[i]))
			str[i] = ' ';
		// ���ַ��������з�
		deal(res, str);
		cout << res[res.size() - 1];
		for (int i = res.size() - 2; i >= 0; i--)
			cout << " " << res[i];
		cout << endl;
	}
	return 0;
}