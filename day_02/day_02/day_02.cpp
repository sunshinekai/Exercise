/*
ѡ���⣺
�뽫���й��캯������������ʹ�ó�������н����5(B)

#include<iostream>
using namespace std;
class Sample
{
public:
	Sample(int x)
	{
		_________
	} 
	~Sample()
	{
		if(p)
		delete p;
	}
	int show()
	{
		return *p;
}
private:
	int*p;
};

int main()
{
	Sample S(5);
	cout << S.show() << endl;
	return 0;
}
A *p=x;
B p=new int(x);
C *p=new int(x);
D p=&x;

A��*p = x����x��ֵ��ֵ��ָ��pָ����ڴ�ռ䣬����p֮ǰû��ָ���κ�һ���ڴ�ռ䣬������������Ƿ�
B��p = new int(x)��������һ���ڴ�ռ䣬�ڴ�ռ��е�ֵ��x�����Ұ�����ڴ�ռ丳ֵ��p��pҲ��ָ��������ڴ�ռ䡣���ҳ��������Ҳ���ͷ�����ڴ�ռ䡣
C��*p = new int(x)������p֮ǰû��ָ���κ�һ���ڴ�ռ䣬����ֱ�Ӹ�*p��ֵ�Ǵ���ġ���*p��ʾpָ����ڴ�ռ䡣��
D��p = &x����ʾ��x�ĵ�ַ��ֵ��p�����������x ���βΣ��������ý�����x�ͱ��ͷ��ˣ�����*p���Ҳ���x��
*/


/*
����⣺

1.
���ӣ�https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471?orderByHotValue=1&page=1&onlyReference=false

ţţ��������������Ϊһ��������һ��������������,��������������Ƿǵ������߷ǵݼ�����ġ�
ţţ��һ������Ϊn����������A,��������һ�������ǰ�����A��Ϊ���ɶ�����������,ţţ��֪�������ٿ��԰���������Ϊ��������������.
��������ʾ,ţţ���԰�����A����Ϊ[1,2,3]��[2,2,1]��������������,������Ҫ����Ϊ2������������,�������2

��������:
����ĵ�һ��Ϊһ��������n(1 �� n �� 10^5)
�ڶ��а���n������A_i(1 �� A_i �� 10^9),��ʾ����A��ÿ�����֡�

�������:
���һ��������ʾţţ���Խ�A���ٻ���Ϊ���ٶ�����������
ʾ��1
����
6
1 2 3 2 2 1
���
2
*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a;
	a.resize(n + 1);
	a[n] = 0;
	// ��������
	int i = 0;
	for (; i < n; ++i)
		cin >> a[i];
	i = 0;
	int count = 0;
	while (i < n)
	{
		// �ǵݼ�������
		if (a[i] < a[i + 1])
		{
			while (i < n && a[i] <= a[i + 1])
				i++;
			count++;
			i++;
		} 
		else if (a[i] == a[i + 1])
		{
			i++;
		}
		else // �ǵ���������
		{
			while (i < n && a[i] >= a[i + 1])
				i++;
			count++;
			i++;
		}
	}
	cout << count << endl;
	return 0;
}



/*
2.
���ӣ�https://www.nowcoder.com/practice/ee5de2e7c45a46a090c1ced2fdc62355?tpId=85&&tqId=29867&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

��һ�仰�ĵ��ʽ��е��ã���㲻���á�
���� I like beijing. �����������Ϊ��beijing. like I
��������:
ÿ�������������1������������ I like beijing. �����������Ȳ�����100.
�������:
�����������֮����ַ���,�Կո�ָ�.
ʾ��:
����
I like beijing.
���
beijing. like I
*/


// �ⷨ1
/*
˼·����rfind�ҵ���1���ո������һ���ո񣬼�¼λ��
��һ�����ַ����������һ�����ʣ�Ȼ��ɾ�����һ������(�����ո�)
ֱ�������rpos�Ҳ����ո�Ϊֹ.
*/
#include <iostream>
#include <string>

using namespace std;
int main()
{
	string s, s1, s2;
	getline(cin, s1);
	int pos = s1.find(' ');
	int rpos = s1.rfind(' ');
	s2 = s1.substr(0, pos);
	while (rpos >= 0)
	{
		s += s1.substr(rpos + 1) + ' ';
		s1.erase(rpos);
		rpos = s1.rfind(' ');
	}
	s += s2;
	cout << s << endl;
	return 0;
}


// �ⷨ2
/*
�Ƚ������ַ������ù������ٱ����ַ������ҳ�ÿ�����ʣ��Ե������á���������ʹ����stl�㷨�е�
reverse����������ʹ�õ���������string
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	// ��ת��������
	reverse(s.begin(), s.end());

	// ��ת����
	string::iterator start = s.begin();
	while (start != s.end())
	{
		auto end = start;
		while (end != s.end() && *end != ' ')
			end++;
		reverse(start, end);

		if (end != s.end())
			start = end + 1;
		else
			start = end;
	}

	cout << s << endl;
	return 0;
}


// �ⷨ3
/*
����һ���Ƚ����ɵ�˼·��ֱ������cin>>s�������룬�����ո�ͽ����ˣ���Ȼ�ͷָ��ÿ����
�ʣ���ν�ÿ�ν��յ��ĵ���ƴ�ӵ�֮ǰ����ǰ������ù����ˡ�
*/

#include <iostream>
#include <string>
using namespace std;
// cin��ȡstringʱ�Զ��ᱻ�ո�ָ���������һ���ַ����洢�����������
int main()
{
	string s1, s2;
	cin >> s2;
	while (cin >> s1)
		s2 = s1 + ' ' + s2;
	cout << s2 << endl;
	return 0;
}