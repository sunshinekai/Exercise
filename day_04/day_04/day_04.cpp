/*
ѡ����

1.
print()������һ����ĳ���Ա���������޷���ֵ�����б�ʾ����ȷ����(C)
A const void print();
B void const print();
C void print() const;
D void print(const);
ע��const void print(const int num)const ��һ��const���η�������
�ڶ���const���β��� ������const���ε��ö���

2.
�����й�thisָ��ʹ�÷�����������ȷ���ǣ���
A ��֤���ౣ����Ա�������п��Ա�����
B ��֤����˽�г�Ա�������п��Ա�����
C ��֤���๲�г�Ա�������п��Ա�����
D ��֤ÿ������ӵ���Լ������ݳ�Ա������������Щ���ݵĴ���
ע��this��ָ��ʵ����������ʱ���һ��ָ�룬����洢���Ƕ�����ĵ�ַ��
ͨ���õ�ַ���Է����ڲ��ĳ�Ա�����ͳ�Ա������ Ϊʲô��Ҫthis��
��Ϊthis��������������ڲ����Լ�����һ�����ʱ�򣬻���֪��ʵ������������֣�
������this��ʹ�ö������������

3.
���������������ʲô? (A)
#include<iostream>
using namespace std;

class A
{
public:
	A(char *s)
	{
		cout << s << endl;
	} 
	~A(){}
};

class B : virtual public A
{
public :
	B(char *s1, char*s2) : A(s1)
	{
		cout << s2 << endl;
	}
};

class C : virtual public A
{
public:
	C(char *s1, char*s2) : A(s1)
	{
		cout << s2 << endl;
	}
};

A class A class B class C class D
B class D class B class C class A
C class D class C class B class A
D class A class C class B class D
ע�����ڹ��캯������˳�򣺻��๹�캯��->�����Ա�������캯��->���๹�캯�� 
����������������˳��������������->�����Ա������������->������������ 
*/


/*
�����

1.
���ӣ�https://www.nowcoder.com/practice/02d8d42b197646a5bbd0a98785bb3a34?tpId=85&&tqId=29857&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
A, B, C�������Ǻ�����, ÿ�������ﶼ��һЩ�ǹ�, ���ǲ�֪������ÿ�������Ͼ����ж��ٸ��ǹ�, ��������֪�����µ���Ϣ��
A - B, B - C, A + B, B + C.���ĸ���ֵ.ÿ����ĸ����ÿ������ӵ�е��ǹ���.
������Ҫͨ�����ĸ���ֵ�����ÿ���������ж��ٸ��ǹ�, ��A, B, C�����ﱣ֤���ֻ��һ������A, B, C������������������
�������� :
����Ϊһ�У�һ��4���������ֱ�ΪA - B��B - C��A + B��B + C���ÿո������ ��Χ���� - 30��30֮��(������)��
������� :
���Ϊһ�У�����������������A��B��C��˳�����A��B��C���ÿո��������ĩ�޿ո� �������������������A��B��C�������No
ʾ����
����
1 - 2 3 4
���
2 1 3
*/


#include <iostream>
using namespace std;
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A = (a + c) / 2;
	int C = (d - b) / 2;
	int B1 = (c - a) / 2;
	int B2 = (b + d) / 2;
	if (B1 != B2)
		cout << "No";
	else
		cout << A << " " << B1 << " " << C;
	return 0;
}


/*
2.
����һ��ʮ������M���Լ���Ҫת���Ľ�����N����ʮ������Mת��ΪN������
ʾ����
����
7 2
����
111
*/


#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s, table = "0123456789ABCDEF";
	int M, N;
	cin >> M >> N;
	bool flag = false;
	// ����Ǹ�������ת�������������һ��
	if (M < 0)
	{
		M = 0 - M;
		flag = true;
	}
	// �����ƻ���ɶ�Ӧ���ַ���ӵ�s
	while (M)
	{
		s += table[M % N];
		M /= N;
	}
	if(flag)
		s += '-';
	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}