/*
ѡ����

1.
���и��������У�����fun�Ĺ�����:��ss��ָ�ַ��������г�����̵��ַ������ڵ����±꣬
��Ϊ����ֵ���أ������䴮�������β�n��ָ�ı����С�ss��ָ�ַ���
�������й���M���ַ������Ҵ���С��N��
���ڳ�����»��ߴ�������ȷ�����ݲ����»���ɾ����ʹ����ó���ȷ�Ľ��(C)

#define M 5
#define N 20
int fun(char(*ss)[N], int *n)
{
	int i, k = 0, len = N;
	for (i = 0; i < ______; i++)
	{
		len = strlen(ss[i]);
		if (i == 0)
			*n = len;
		if (len ____ * n)
		{
			*n = len;
			k = i;
		}
	} 
	return(_____);
} 

main()
{
	char ss[M][N] = { "shanghai", "guangzhou", "beijing", "tianjing", "chongqing" };
	int n, k, i;
	printf("\nThe originalb stringsare:\n");
	for (i = 0; i < M; i++)
		puts(ss[i]);
	k = fun(ss, &n);
	printf("\nThe length of shortest string is: % d\n", n);
	printf("\nThe shortest string is: % s\n", ss[k]);
}

A N��<��k
B N��>��k
C M��<��k
D M��>��k
ע��������ʾ������Ӧ�жϼ���

2.
��β����쳣����ʹ�ô���ͨ������(B)
class A 
{
public:
	A(){}
};

void foo()
{
	throw new A;
}
A catch (A && x)
B catch (A * x)
C catch (A & x)
D ���϶���

��Ŀ���ʵ����ܷ�ͨ�����룬ֻ��B�Ჶ���쳣�������쳣����
��A��C���ں�throw�׳����쳣���Ͳ�ƥ�䣬��������쳣��������
�Ӷ���Ϊδ������쳣������terminate������������

3.
���д������ͨ������������޸�ʹ��ͨ������(C)

template <class T>
struct sum 
{
	static void foo(T op1 , T op2)
	{
		cout << op1 <<op2;
	}
};
sum::foo(1,3);
A ����ͨ��
B Ӧ��ȥ��static�ؼ���
C ����Ӧ�����£� sum<int>:: foo(1,3)
D ����Ӧ�����£� sum:: <int>foo(1,3)
ע��ģ���Ӧ��

4.
�����³���Σ�
#include <iostream>
using namespace std;

class A
{
public:
	~A() 
	{
		cout << "~A()";
	}
};

class B
{
public:
	virtual ~B()
	{
		cout << "~B()";
	}
};

class C : public A, public B
{
public:
	~C()
	{
		cout << "~C()";
	}
};

int main() 
{
	C * c = new C;
	B * b1 = dynamic_cast<B *>(c);
	A * a2 = dynamic_cast<A *>(b1);
	delete a2;
}

��������(D)
A ~C()~B()~A()
B ~C()~A()~B()
C A��B���п���
D ���϶�����

ע���̳е��ó���ᱨ��
*/


/*
�����

1.
���ӣ�https://www.nowcoder.com/practice/8ef655edf42d4e08b44be4d777edbf43?tpId=37&&tqId=21276&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
1
1  1  1
1  2  3  2  1
1  3  6  7  6  3  1
1  4  10 16 19  16 10  4  1
���������ε����󣬵�һ��ֻ��һ����1������ÿ�е�ÿ��������ǡ������������������Ͻ��������Ͻǵ�����3����֮�ͣ����������ĳ��������Ϊ��������0����
���n�е�һ��ż�����ֵ�λ�á����û��ż���������-1����������3,�����2������4�����3��

����
4
���
3
*/

/*
˼·��������Ŀ��˼�����Է��ֵ�n����2n - 1��Ԫ�أ���i,jԪ�ص�����һ�е�j - 2,j - 1,j����Ԫ��֮�ͣ�
ÿһ�еĵ�һ�к����һ�ж�Ϊ1������ǵڶ��У���ֻ������Ԫ��֮��
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int n, m;
	while (cin >> n)
	{
		m = 2 * n - 1;
		vector<vector<int>> dp(n, vector<int>(m, 0));
		dp[0][0] = 1;
		for (int i = 1; i < n; i++)
		{
			//��һ�к����һ�ж�Ϊ1
			dp[i][0] = dp[i][2 * i] = 1;
			for (int j = 1; j < 2 * i; ++j)
			{
				if (j == 1)
					//����ǵڶ��У���ֻ������Ԫ��֮��
					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				else
					//��i,jԪ�ص�����һ�е�j - 2,j - 1,j����Ԫ��֮��
					dp[i][j] = dp[i - 1][j - 2] + dp[i - 1][j - 1] + dp[i - 1][j];
			}
		} 
		int k;
		for (k = 0; k < m; k++)
		{
			if (dp[n - 1][k] % 2 == 0 && dp[n - 1][k] != 0)
			{
				cout << k + 1 << endl;
				break;
			}
		} 
		if(k == m)
			cout << -1 << endl;
	} 
	return 0;
}


/*
˼·��������ѧ����
*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int pos = 0;
		if (n == 1 || n == 2)
			pos = -1;
		else if (n % 2 == 1 && n > 2)
			pos = 2;
		else if (n % 4 == 0)
			pos = 3;
		else
			pos = 4;
		cout << pos << endl;
	}
	return 0;
}

/*
2.
���ӣ�https://www.nowcoder.com/practice/5821836e0ec140c1aa29510fd05f45fc?tpId=37&&tqId=21301&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
�����һ���㷨������������������ļӷ���
����
99999999999999999999999999999999999999999999999999
1
���
100000000000000000000000000000000000000000000000000
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addStrings(string num1, string num2) 
{
	// �ɵ�λ���λ���
	int i = num1.size() - 1;
	int j = num2.size() - 1;
	string result = "";
	// ��ǰλ����ӽ��
	int carry = 0;
	while (i >= 0 || j >= 0)
	{
		if (i >= 0) 
			carry += num1[i] - '0';
		
		if(j >= 0)
			carry += num2[j] - '0';
		// ��ǰΪ�����ֵ������10
		result += (char)(carry % 10 + '0');
		// �������10,���Ͻ�һλ
		carry /= 10;
		i--;
		j--;
	}
	// �����֮��������н�λ�����ټ�1
	if(carry == 1) 
		result += '1';
	// ��������
	reverse(result.begin(), result.end());
	return result;
} 

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << addStrings(s1, s2) << endl;
	} 
	return 0;
}