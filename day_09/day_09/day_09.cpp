/*
ѡ����

1.
ĳ�����������£�
void Func(int &nVal1);
��int a,����ʹ����ȷ��Ϊ��(A)
A Func(a)
B Func(&a)
C Func(*a)
D Func(&(*a))

ע������&����ʾ���ã�Ҳ���Ǳ�������һ��������
&(����)==>�����ڱ������������λ�ڱ������ʱ,��ʾ������������.
&(ȡ��ַ�����)==>�ڸ���������ֵʱ�����ڵȺ��ұ߻���ִ�������
��ΪһԪ���������ʱ��ʾȡ����ĵ�ַ.

2.
��һ�����ĳ��������˵��Ϊvirtual�����ڸ���������������е�ͬԭ�ͺ���(D)
A ֻ�� ������˵��ʱ��ʶ�麯��
B ֻ�б�����˵��Ϊvirtualʱ�����麯��
C �������麯��
D �����麯��
ע����������������У�ͬ�����������麯����

3.
�����³���
����ʱ����������(B)
void Func(int &nVal1);
#include<iostream>
using namespace std;
class MyClass{
public:
	MyClass(int i=0){cout<<1;}
	MyClass(const MyClass&x){cout<<2;}
	MyClass& operator=(const MyClass&x){cout<<3; return*this;}
	~MyClass(){cout<<4;}
};
int main(){
	MyClass obj1(1),obj2(2),obj3(obj1);
	return 0;
}
A 121,444
B 112,444
C 11,114,444
D 11,314,445
E 11,314,444
C MyClass obj3 = obj1;

ע��obj3�������ڣ����Ե��ÿ������캯�����2��
���obj3���ڣ�obj3 = obj������ø�����������غ��������3

4.
����ִ�к�a��b��ֵ�ֱ�Ϊ(A)
class Test{
public:
	int a;
	int b;
	virtual void fun() {}
	Test(int temp1 = 0, int temp2 = 0)
	{
		a = temp1;
		b = temp2;
	}
	int getA()
	{
		return a;
	}
	int getB()
	{
		return b;
	}
};
int main()
{
	Test obj(5, 10);
	// Changing a and b
	int* pInt = (int*)&obj;
	*(pInt + 0) = 100;
	*(pInt + 1) = 200;
	cout << "a = " << obj.getA() << endl;
	cout << "b = " << obj.getB() << endl;
	return 0;
}

A 200 10
B 5 10
C 100 200
D 100 10
ע����Ҫ�����麯����ָ���麯�����ָ����32λϵͳ��ռ��4���ֽڣ�
���ַ�ֲ����������Ա�����ĵ�ַ���ײ������������Ǳ���a�ĵ�ַ��b�ĵ�ַ��
����test����obj����ָ�����͵�pInt��ָ��pIntָ���˵�ַ���ײ�Ҳ�����麯����ָ�룬
����*��pInt+0��=100�ı�����麯�����ֵ��������*��pInt+1��=200�ı���Ǳ���a��ֵ������bû�б任��
*/



/*
�����

1.
���ӣ�https://www.nowcoder.com/practice/e7e0d226f1e84ba7ab8b28efc6e1aebc?tpId=8&&tqId=11065&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
���дһ��������������������ӡ�����ʹ��+�����������������
��������int A��B���뷵��A��B��ֵ

����������
1,2
���أ�3
*/

/*
˼·��A&B��A��B��ͬ��λ��A^B��ȡA��B��ͬ��λ����ͬλ*2 + ��ͬλ��Ϊ�ӷ�����
(A & B) << 1 + (A & B),���ѭ��ֱ����λ֮��Ľ��Ϊ0ʱ����ӽ���
*/

class UnusualAdd {
public:
	int addAB(int A, int B) {
		int x = A ^ B; // A��B��ͬ��λ
		int y = A & B; // A��B��ͬ��λ
		while (y != 0)
		{
			y = y << 1; // ��ͬλ*2
			int tmp = x;
			x = x ^ y;
			y = tmp & y;
		}
		return x;
	}
};

/*
2.
���ӣ�https://www.nowcoder.com/practice/e2a22f0305eb4f2f9846e7d644dba09b?tpId=37&&tqId=21314&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
���дһ�����������������Ӻ�����������n x m�����̸��ӣ�nΪ����ĸ�������mΪ����ĸ�������
���Ÿ��Ա�Ե�ߴ����Ͻ��ߵ����½ǣ��ܹ��ж������߷���Ҫ�����߻�ͷ·��
����ֻ�����Һ������ߣ���������������ߡ�
ʾ����
����
2
2
���
6
*/

/*
˼·������Ϊ��ȡ·����������Ŀ��һ�����ͨ���ݹ���⣬���ڸ��ӵ����⣬����ͨ����̬�滮��⡣
| 1 | 2 | 3 |
-------------
| 4 | 5 | 6 |
-------------
| 7 | 8 | 9 |
-------------
1. ���������n*m(3*3)�ĸ��ӣ����������
a. ���n����mΪ1����ֻ��һ�л���һ�У������Ͻ��ߵ����½ǵ�·����Ϊn + m
���磺 1 * 1���ӣ������������ߣ��������ߣ��������½ǣ������������ߣ�
�������ߣ��������½ǣ����������� 1 + 1 = 2������1 * m�� n * m
b. ���n,m������1����ô�ߵ�[n][m]���ӵ����½�ֻ������·����
<1>: ��[n - 1][m]���ӵ����½������ߣ�����
<2>: ��[n][m - 1]���ӵ����½������ߣ�����
�����ߵ�[n][m]���ӵ����½ǵ�����Ϊ[n-1][m] + [n][m - 1],����ͨ���ݹ�ʵ�֣����aΪ�ݹ����ֹ��
����
*/


#include<iostream>
using namespace std;
int pathNum(int n, int m)
{
	if (n > 1 && m > 1)
		// b������ݹ�
		return pathNum(n - 1, m) + pathNum(n, m - 1);
	else if (((n >= 1) && (m == 1)) || ((n == 1) && (m >= 1)))
		// a�������ֹ����
		return n + m;
	else
		// ����Ϊ0ʱ�� ·��Ϊ0
		return 0;
} 
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		cout << pathNum(n, m) << endl;
	} 
	return 0;
}