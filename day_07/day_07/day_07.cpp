/*
ѡ���⣺

1.��������ඨ���˵���У���ȷ����(A)
A �ඨ���а������ݳ�Ա�ͺ�����Ա������
B ���Ա��ȱʡ����Ȩ���Ǳ�����
C ���ݳ�Ա���뱻����Ϊ˽�е�
D ��Ա����ֻ������������ж���
ע������ȱʡ�ķ���Ȩ����˽�е�(private)��
������ݳ�Ա�ͺ�����Ա�ķ��ʿ���Ȩ�޾��ɱ�����Ϊ���С�˽�кͱ����е�����һ�֣�
��Ա������ʵ�ּ������������ڶ��壬Ҳ�����������ⶨ�壻

2.
#include <iostream>
using namespace std;
class parent
{
	int i;
protected:
	int x;
public:
	parent(){x=0;i=0;}
	void change(){x++;i++;}
	void display();
};
class son:public parent
{
public:
	void modify();
};
void parent::display(){cout<<"x="<<x<<endl;}
void son:: modify() {x++;}
int main()
{
	son A; parent B;
	A.display();
	A.change();
	A.modify();
	A.display();
	B.change();
	B.display();
}

�������������ʲô(C)
A x=1 x=0 x=2
B x=2 x=0 x=1
C x=0 x=2 x=1
D x=0 x=1 x=2
ע�������̳и�������캯������������֮�����е����ݳ�Ա�ͳ�Ա������
ʵ����������͸���Ķ��󻥲�Ӱ�졣

#include<iostream>
#include<string>
using namespace std;

class A
{
	friend long fun(A s)
	{
		if (s.x<3) {
		return 1;
	} 
	return s.x+fun(A(s.x - 1));
public:
	A(long a)
	{
		x = a--;
	}
private:
	long x;
};

int main()
{
	int sum=0;
	for( int i=0; i<5; i++) 
	{
		sum += fun(A(i));
	} 
	cout<<sum;
}
�������н����(B)
A 21
B 15
C 9
D 36
*/


/*
����⣺

1.
���ӣ�https://www.nowcoder.com/practice/18ecd0ecf5ef4fe9ba3f17f8d00d2d66?tpId=85&&tqId=29846&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
Fibonacci��������������ģ�
F[0] = 0
F[1] = 1
for each i �� 2: F[i] = F[i-1] + F[i-2]
��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...����Fibonacci�����е������ǳ�ΪFibonacci����
����һ��N�����������Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX-1����X+1��
���ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci����
����
15
���
2
*/


/*
˼·��ͨ�����ҵ�����N���������Fibonacci�������������ֱ�ȡ�Ծ���N����������һ����L���ұ�һ
����R��Ȼ��ͨ��min(N - L, R - N)�ҵ���С������
*/
#include <iostream>

using namespace std;

int Fibonacci(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
	int N;
	int Minstep;
	while (cin >> N)
	{
		int i = 0;
		for (; Fibonacci(i) < N; i++);
		if (Fibonacci(i) == N)
			Minstep = 0;
		else
			Minstep = abs(Fibonacci(i) - N) <= abs(Fibonacci(i - 1) - N) ? 
					  abs(Fibonacci(i) - N) : abs(Fibonacci(i - 1) - N);
		cout << Minstep << endl;
	}
	return 0;
}

/*
2.
���ӣ�https://www.nowcoder.com/practice/d8acfa0619814b2d98f12c071aef20d4?tpId=8&&tqId=11039&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
����һ���ַ����������һ���㷨���ж����Ƿ�Ϊһ���Ϸ������Ŵ���
����һ���ַ���A�����ĳ���n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���

����������
"(()())",6
���أ�true

����������
"()a()()",7
���أ�false

����������
"()(()()",7
���أ�false
*/

/*
˼·����ջ�ṹʵ�֣�ջ�д�������ţ�������������֮�󣬼��ջ���Ƿ��������ţ���������ջ�����û�У�
��˵����ƥ�䡣
*/

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		stack<char> st; // ����һ��ջ
		size_t i = 0;
		for (; i < n; i++)
		{
			if (A[i] == '(')
			{
				st.push(A[i]); // ���Ϊ'('��ѹջ
			} 
			else if (A[i] == ')')
			{
				if (st.empty())
					break;
				// ֮ǰΪ����ֱ���˳�ѭ��
				else
					st.pop();
				// ǰ���ж�Ӧ���������ջ
			}
		} 
		if(st.empty() && i == n)
			return true;
		return false;
	}
};