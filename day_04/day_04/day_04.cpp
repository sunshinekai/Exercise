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

#include <iostream>

using namespace std;
int main()
{
	//int m, n, x, y;
	//while (cin >> m >> n >> x >> y)
	//{
	//	int A = (m + x) / 2;
	//	int B = (n + y) / 2;
	//	int C = (y - n) / 2;
	//	cout << A << ' ' << B << ' ' << C << endl;
	//}

	int a[5] = { 1, 3, 5, 7, 9 };
	int *p = (int*)(&a + 1);
	printf("%d,%d", *(a + 1), *(p - 1));
	return 0;

}

/*#include <iostream>
#include <vector>
#include <string>

using namespace std;
#include<iostream>
using namespace std;

void calculate(int n, int k)
{
	char num[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	int temp;
	temp = n % k;
	n /= k;
	if (n != 0)
		calculate(n, k);
	cout << num[temp];
}
int main()
{
	int M, N;
	while (cin >> M >> N)
	{
		calculate(M, N);
		cout << endl;
	}
	return 0;
}
*/