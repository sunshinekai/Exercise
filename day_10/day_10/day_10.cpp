/*
ѡ����

1.
32λϵͳ�У�����**a[3][4],�����ռ���ڴ�ռ�Ϊ(B)
A 4
B 48
C 192
D 12
ע��**a[3][4]��ʾ����һ��3*4�Ķ�ά���飬���������ŵ����ݣ�
��**���͵�ָ�룬Ȼ��ÿ��ָ����4���ֽڣ���ô12��ָ�����48���ֽڡ�

2.
int I=1;
if(I<=0)
printf("****\n") ;
else
printf("%%%%\n");
A %%
B ****
C ���﷨��������ȷִ��
D %%%%
ע��%������ַ�%

3.
������C++���룺
struct A{
void foo(){printf("foo");}
virtual void bar(){printf("bar");}
A(){bar();}
};

struct B:A{
void foo(){printf("b_foo");}
void bar(){printf("b_bar");}
};
��ô��
A *p=new B;
p->foo();
p->bar();

���Ϊ(A)
A barfoob_bar
B foobarb_bar
C barfoob_foo
D foobarb_fpp
ע��A *p=newB;// A��ָ��ָ��һ��ʵ��������B��
B��̳�A�࣬�ȵ��ø�����޲ι��캯����bar()���bar��B��û���Լ���ʾ����Ĺ��캯����
p->foo();// ִ��B�����foo()��������Ϊfoo�����麯��������ֱ�ӵ��ø����foo���������foo
p->bar();// ִ��B���bar()����, �ú���Ϊ�麯�������������ʵ�֣����b_bar

4.
�������ͨ���������������Ӧ������޸�()
template<class T> class Foo{
T tVar;
public:
Foo(T t) : tVar(t) { }
};
template<class T> class FooDerived:public Foo<T>
{ };
int main()
{
FooDerived<int> d(5);
return 0;
}

A ���������ȷͨ�����롣
B �������FooDerived��һ���̳�ģ����ķ�ģ���࣬�������Ͳ��ܸı䡣
C �������tVal������һ����ȷ�������͡�
D ������󣬿�����FooDerived�������һ�����캯��������⡣

ע�������๹�캯����Ҫ�ⲿ���ݲ������ܽ��г�ʼ��ʱ��
�����������ʽ���幹�캯����Ϊ���ഫ�ݲ�����
�����������Ҫ���ݻ��߿��Բ����ݲ�������������Բ�����ʽ���幹�캯����
*/


/*
�����

1.
���ӣ�https://www.nowcoder.com/practice/e1bb714eb9924188a0d5a6df2216a3d1?tpId=8&&tqId=11055&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
����һ�������ľ��������̣������һ����Ч�㷨�жϵ�ǰ����Ƿ��ʤ��
����һ����ά����board������ǰ���̣�����Ԫ��Ϊ1�Ĵ����ǵ�ǰ��ҵ����ӣ�
Ϊ0��ʾû�����ӣ�Ϊ-1�����ǶԷ���ҵ����ӡ�

����������
[[1,0,1],[1,-1,-1],[1,-1,0]]
���أ�true
*/

/*
˼·1���ж��С��С��Խ����Ƿ�Ϊ1����
*/
class Board {
public:
	bool checkWon(vector<vector<int>> board) {
		for (int i = 0; i < 3; i++)
		{
			if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == 1)
				return true; //��

			else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == 1)
				return true; //��

			else if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == 1)
				|| (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == 1))
				return true; //�Խ���
			else
				return false;
		}
	}
};

/*
˼·2��
�����������������ʾ��ǰ��һ�ʤ��1����ǰ������� 
1. ��ȫΪ1�����еĺ�Ϊ3 
2. ��ȫΪ1���еĺ�Ϊ3 
3. ���Խ�ȫΪ1���ԽǺ�Ϊ3 
4. ���Խ�ȫΪ1���ԽǺ�Ϊ3
5. �����չΪN*N�Ļ����жϺ��Ƿ����N��
������������κ����
*/

class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		int row = board.size();
		//���ÿһ�еĺ����Ƿ����row
		int i, j, sum;
		for (i = 0; i<row; i++)
		{
			sum = 0;
			for (j = 0; j<row; j++)
			{
				sum += board[i][j];
			} 
			if(sum == row)
				return true;
		} 
		// ���ÿһ�еĺ����Ƿ����row
		for (i = 0; i< row; i++)
		{
			sum = 0;
			for (j = 0; j<row; j++)
			{
				sum += board[j][i];
			} 
			if(sum == row)
				return true;
		} 
		// ������Խ��ߵĺ����Ƿ����row
			sum = 0;
			for (i = 0; i<row; i++)
			{
				sum += board[i][i];
			} 
			if(sum == row)
				return true;
			//��鸱�Խ��ߵĺ����Ƿ����row
			sum = 0;
			for (i = 0; i<row; i++)
			{
				sum += board[i][row - i - 1];
			} 
			if(sum == row)
				return true;
			return false;
	}
};


/*
2.
���ӣ�https://www.nowcoder.com/practice/52d382c2a7164767bca2064c1c9d5361?tpId=37&&tqId=21310&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
���밴���¹�����мƷ֣������ݲ�ͬ�ĵ÷�Ϊ������а�ȫ�ȼ����֡�
һ�����볤��:
5��: С�ڵ���4���ַ�
10��: 5��7�ַ�
25��: ���ڵ���8���ַ�

������ĸ:
0��: û����ĸ
10��: ȫ����С����д��ĸ
20��: ��Сд�����ĸ

��������:
0��: û������
10��: 1������
20��: ����1������

�ġ�����:
0��: û�з���
10��: 1������
25��: ����1������

�塢����:

2 ��: ��ĸ������
3 ��: ��ĸ�����ֺͷ���
5 ��: ��Сд��ĸ�����ֺͷ���

�������ֱ�׼:
>= 90: �ǳ���ȫ
>= 80: ��ȫ��Secure��
>= 70: �ǳ�ǿ
>= 60: ǿ��Strong��
>= 50: һ�㣨Average��
>= 25: ����Weak��
>= 0:  �ǳ���


��Ӧ���Ϊ��
VERY_SECURE
SECURE,
VERY_STRONG,
STRONG,
AVERAGE,
WEAK,
VERY_WEAK,

���������������ַ��������а�ȫ������

����
38$@NoNoNo
���
VERY_SECURE
*/


/*
˼·��������ڲ�ͬ������ַ��÷ֲ�ͬ�������ֶ�ÿһ��ά�Ƚ��е����жϣ������ڳ��ȣ���ĸ�����֣�
���ŵ����жϣ��������еĵ���ֵ������ĿҪ����ӣ������Ӧ�İ�ȫ����
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	int score = 0;
	getline(cin, s);

	// �������룬�ж�������ַ����
	int number = 0; // ����
	int letter = 0, letters[2]; // ��ĸ
	int symbol = 0; // ����
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0'&& s[i] <= '9')
			number++;
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			letter = 1;
			letters[0] = 1;
		}
		else if (s[i] >= 'a' && s[i] <= 'z')
		{
			letter = 1;
			letters[1] = 1;
		}
		else
			symbol++;
	}

	// ���볤��
	if (s.size() <= 4)
		score += 5;
	else if (s.size() <= 7)
		score += 10;
	else
		score += 25;

	// �ж���ĸ
	if (letter == 0)
		score += 0;
	else if (letters[0] == 1 && letters[1] == 1)
		score += 20;
	else
		score += 10;

	// �ж�����
	if (number == 0)
		score += 0;
	else if (number == 1)
		score += 10;
	else
		score += 20;

	// �жϷ���
	if (symbol == 0)
		score += 0;
	else if (symbol == 1)
		score += 10;
	else
		score += 25;

	// ��������
	if (number > 0 && letter > 0)
		score += 2;
	else if (number > 0 && letter > 0 && symbol > 0)
		score += 3;
	else if (number > 0 && letter > 0 && symbol > 0
		&& letters[0] == 1 && letters[1] == 1)
		score += 5;

	// �ж����ս��
	if (score >= 90)
		cout << "VERY_SECURE" << endl;
	else if (score >= 80)
		cout << "SECURE" << endl;
	else if (score >= 70)
		cout << "VERY_STRONG" << endl;
	else if (score >= 60)
		cout << "STRONG" << endl;
	else if (score >= 50)
		cout << "AVERAGE" << endl;
	else if (score >= 25)
		cout << "WEAK" << endl;
	else
		cout << "VERY_WEAK" << endl;
	return 0;
}