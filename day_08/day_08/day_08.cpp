/*
ѡ����

1.
���ҳ��������������Щ����(C)
int main()
{
	int i=10;
	int j=1;
	const int *p1; //(1)
	int const *p2=&i; //(2)
	p2=&j; //(3)
	int *const p3=&i;//(4)
	*p3=20;//(5)
	*p2=30;//(6)
	p3=&j;//(7)
	return 0;
}

A 1,2,3,4,5,6,7
B 1,3,5,6
C 6,7
D 3,5
ע��const��ǰ�����ݲ��ܱ䣻
const�ں�ָ�벻�ܱ䣻
const* ��ָ��ָ��Ϊ������
*const ��ָ�뱾��Ϊ������

2.
�ٶ�����AB������Ӧ�Ĺ��캯�����壬����ȷִ��
AB a(4),b(5),c[3],*p[2]={&a,&b};
��䣬����ִ��������󹲵��ø���Ĺ��캯������Ϊ(A)
A 5
B 4
C 3
D 9
ע��ֻ���ڸ�ָ�����ռ�ʱ�ŵ��ù��캯��

3.
���ں�����������ȷ����(D)��
A �麯����һ��static�͵ĺ���
B ��������麯���������麯�����в�ͬ�Ĳ�������������
C �麯����һ���ǳ�Ա����
D ������˵�����麯���������������Ӧ�ĺ������Բ���˵��Ϊ�麯��

ע���麯���������������������¶��������ͬ���ĺ�����
���ҿ���ͨ������ָ������������ʻ�����������е�ͬ��������
�ڻ�������virtual������Ա����Ϊ�麯�����������������¶���˺�����
Ҫ���������������͡�������������������ȫ���������麯����ͬ��

4.
�����³���ִ�к�����Ľ����(D)
#include <iostream.h>
class cla
{
	static int n;
public:
	cla(){n++;}
	~cla(){n--;}
	static int get_n(){return n;}
};

int cla::n= 0;

int main()
{
	cla *p = new cla;
	delete p;
	cout<<"n ="<< cla::get_n() << endl;
	return 0;
}

A n=3
B n=4
C n=1
D n=0

ע��
���ʵ������cla *p = new cla��p������ջ�ϣ�pָ��Ķ�������ڶ��ϡ�
nΪ��̬��Ա������û��thisָ�룬�����������ж�����
ʵ�����������ù��캯��������n++��
delete����������������������n--��
������Ծ�Ϊ0��

5.
���³�����������()
class A
{
public:
	A ():m_iVal(0){test();}
	virtual void func() {std::cout<<m_iVal<<�� ��;}
	void test(){func();}
public:
	int m_iVal;
};
class B : public A
{
public:
	B(){test();}
	virtual void func()
	{
		++m_iVal;
		std::cout<<m_iVal<<�� ��;
	}
};
int main(int argc ,char* argv[])
{
	A*p = new B;
	p->test();
	return 0;
}

A 1 0
B 0 1
C 0 1 2
D 2 1 0
E ����Ԥ��
F ���϶�����

�������漰���������棺
1.C++�̳���ϵ�й��캯���ĵ���˳��
2.���캯���е����麯�����⡣

C++�̳���ϵ�У���ʼ��ʱ���캯���ĵ���˳������
(1).�κ��������Ĺ��캯���������Ǳ��̳е�˳����
(2).�κη��������Ĺ��캯���������Ǳ��̳е�˳����
(3).�κγ�Ա����ĺ�����������������˳����
(4).���Լ��Ĺ��캯��

�ݴ˿�֪ A*p = newB;�ȵ���A��Ĺ��캯���ٵ���B��Ĺ��캯����
���캯���е����麯��,�麯������Ϊ�������麯������Ϊ�����ڸ��๹�캯���е����麯����
�麯���ı��־��Ǹ��ඨ��ĺ����ı��֡�

ԭ�����£�
���蹹�캯���е����麯��������Ϊ��ͨ���麯��������Ϊ�����麯�������Ϊ��Ӧ�����ຯ����Ϊ�����Ҽ����������һ����Ա����int a��
���ඨ����麯�����µ���Ϊ�����a�������������ʼ��ʱ���ݹ��캯������˳������ȵ��ø��๹�캯������ô�麯����ȥ����a��
����Ϊa�������Ա��������ʱa��δ��ʼ��������һ��Σ�յ���Ϊ����Ϊһ�����ǵ�ѡ��Ӧ�ý�ֹ������Ϊ�������麯���ᱻ���͵�������������ࡣ
*/


/*
�����

1.
���ӣ�https://www.nowcoder.com/practice/839f681bf36c486fbcc5fcb977ffe432?tpId=85&&tqId=29844&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

������n���ַ����ַ��������������ַ������ȶ��ǲ�ͬ�ġ��������ѧϰ���������ַ��������򷽷���
1.�����ַ������ֵ����������磺
"car" < "carriage" < "cats" < "doggies < "koala"
2.�����ַ����ĳ����������磺
"car" < "cats" < "koala" < "doggies" < "carriage"
������֪���Լ�����Щ�ַ�������˳���Ƿ��������������򷽷�������Ҫæ�ų���Ҷ��������Ҫ������æ��֤��

ʾ����
����
3
a
aa
bbb

���
both
*/

/*
˼·�������ܵ��ַ������ŵ�vector�����У�����string��operator>=�������������ascii�Ƚ��ַ�
��������string��size���Ƚ��ַ����ĳ���
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//int main()
//{
//	int n;
//	cin >> n;
//	vector<string> v;
//	v.resize(n);
//	for (auto& str : v)
//		cin >> str;
//
//	bool lenSym = true, lexSym = true;
//	// ����Ҫע���i=1��ʼ������ǰ��Ƚϣ��Ƚϳ���
//	for (size_t i = 1; i < v.size(); ++i)
//	{
//		if (v[i - 1].size() >= v[i].size())
//		{
//			lenSym = false;
//			break;
//		}
//	}
//	
//	// �Ƚ�ASCII��
//	for (size_t i = 1; i < v.size(); ++i)
//	{
//		if (v[i - 1] >= v[i])
//		{
//			lexSym = false;
//			break;
//		}
//	}
//
//	if(lenSym && lexSym)
//		cout << "both" << endl;
//	else if (!lenSym && lexSym)
//		cout << "lexicographically" << endl;
//	else if (lenSym && !lexSym)
//		cout << "lengths" << endl;
//	else if (!lenSym && !lexSym)
//		cout << "none" << endl;
//	return 0;
//}

/*
2.
���ӣ�https://www.nowcoder.com/practice/22948c2cad484e0291350abad86136c3?tpId=37&&tqId=21331&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
������A��������B ����С��������ָ �ܱ�A��B��������С��������ֵ��
���һ���㷨��������A��B����С��������

ʾ����
����
5 7
���
35
*/

/*
˼·����С������ = ����֮���������Լ��������ʹ����ת������������Լ������⣺��a��b�����Լ��
����ת��Ϊa��b֮�������Ϊ����֮����С����֮��Ĺ�Լ�������Զ�������������������������ֱ࣬��
����Ϊ0������ķ�ĸ��Ϊ���
*/

#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	int r;
	while (r = a%b)
	{
		a = b;
		b = r;
	}
	return b;
} 

int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		cout << a*b / gcd(a, b) << endl;
	} 
	return 0;
}