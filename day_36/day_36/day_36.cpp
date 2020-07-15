/*
ѡ����

1.
���¼���·�ɣ�10.1.193.0/24,10.1.194.0/24,10.1.196.0/24,10.1.198.0/24���������·�ɻ�ۣ����ܸ����⼸��·�ɵ�ַ����(C)
A 10.1.192.0/22
B 10.1.200.0/22
C 10.1.192.0/21
D 10.1.224.0/20

10.1.193.0/24ת��Ϊ�����ƺ��IP��ַΪ��00001010.00000001.11000001.00000000
10.1.194.0/24ת��Ϊ�����ƺ��IP��ַΪ��00001010.00000001.11000010.00000000
10.1.196.0/24ת��Ϊ�����ƺ��IP��ַΪ��00001010.00000001.11000100.00000000
10.1.198.0/24ת��Ϊ�����ƺ��IP��ַΪ��00001010.00000001.11000110.00000000
�����4��·�ɽ���·�ɻ�ۺ��IP��ַΪ��10.1.192.0/21����ѡ����ֻ�� 10.1.192.0/21�����˵�ַ��
*/


/*
�����

1.
���ӣ�https://www.nowcoder.com/questionTerminal/b388bdee5e3e4b1c86a79ad1877a3aa4

For two rational numbers, your task is to implement the basic arithmetics,
that is, to calculate their sum, difference,product and quotient.

����
5/3 0/6
���
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
*/

/*
���룺
ʵ�ֶ������������Ļ������㣬�����ӡ������ˡ�����

������ڼ������⣺
1������Ϊ0������ܺý���������жϼ��ɡ�
2����������������ֻҪһ����ǩ���ɡ�
3����Ŀ����Ȼû����˵������������ִ������ʵ���п��ܲ����ڷ������ֻ����������ֵġ�Ҳ����˵�����ݴ�
�����γ�k a/b�ĸ�ʽ���п���ֻ��һ��k��Ҳ����ֻ��һ��a/b��Ҳ�п������߽��У�����Ҫ�ֱ����⼸����
��

˼·��
���Գ���ʵ��һ���������࣬�����ݴ��������һ�¼Ӽ��˳����ɡ��������ݵķ������ǳ�һ��modһ�µ����⣬
�Ӽ��˳���ѭ�����ķ����Ӽ��˳�ԭ�������һ�����Լ������һ��Լ�֣��ٴ���һ�����ݼ��ɡ�
*/

#include <iostream>
#include <cmath>
//long long�������ؼ���ƴ�����ģ��������ܲ����㣬������һ��
typedef long long _sint64;
//�������������
class RationalNumber
{
	bool m_infinate; //�������Ϊ��
	bool m_negative; //������
	_sint64 m_numerator; //���ӣ��������
	_sint64 m_denominator; //��ĸ
	_sint64 m_integer; //��������
	_sint64 m_numeratorAll; //��¼�����������ķ��ӣ������������
	_sint64 calcGCD(_sint64 a, _sint64 b); //�����Լ���ĺ���
public:
	RationalNumber(_sint64 numerator, _sint64 denominator); //���캯��
	RationalNumber operator+(RationalNumber const& o) const; //������������
	RationalNumber operator-(RationalNumber const& o) const;
	RationalNumber operator*(RationalNumber const& o) const;
	RationalNumber operator/(RationalNumber const& o) const;
	//��������������
	friend std::ostream &operator<<(std::ostream &os, RationalNumber const& o);
};
//��������ÿ��������ʵ��
_sint64 RationalNumber::calcGCD(_sint64 a, _sint64 b)
{
	if (b == 0)
	{
		return a;
	} 
	// շת�����
	return calcGCD(b, a % b);
} 

RationalNumber::RationalNumber(_sint64 numerator, _sint64 denominator)
{
	m_negative = false;
	m_infinate = false;
	//�����ĸΪ������
	if (denominator == 0)
	{
		m_infinate = true;
		return;
	} 
	
	// ��������д������Ϊ��ͨ�����������й�������У��п��ܳ��ַ��ӷ�ĸ��Ϊ���������
	if (numerator < 0)
	{
		m_negative = !m_negative;
	}
	if
		(denominator < 0)
	{
		m_negative = !m_negative;
	} 
	
	// �������������ӡ���ĸ�����з�ĸҪ������������㣬���Բ����Ǹ��ģ���absȡ����ֵ������Ҫ����ԭֵ
	m_integer = numerator / denominator;
	m_numerator = numerator - m_integer * denominator;
	m_denominator = abs(denominator);
	//Լ�֣�ע�⴫���Ӻ����ķ��ӱ��������ģ���ĸ���洦�����
	if (m_numerator)
	{
		_sint64 maxtmp = calcGCD(abs(m_numerator), m_denominator);
		if (maxtmp)
		{
			m_numerator /= maxtmp;
			m_denominator /= maxtmp;
		}
	}
	// ����Լ�ֺ�ٷ�����ķ��ӣ���Ϊ���������ǲ���Ҫ�������ֵģ����Ա����üٷ����ķ����㡣
	m_numeratorAll = m_numerator + m_integer * m_denominator;
} 

// ����Ϊ�����ļӼ��˳���ͳͳʹ��m_numeratorAll���ٷ����ķ��ӣ��������㡣
RationalNumber RationalNumber::operator+(RationalNumber const& o) const
{
	_sint64 numerator = (m_numeratorAll * o.m_denominator) +
		(o.m_numeratorAll * m_denominator);
	_sint64 denominator = m_denominator * o.m_denominator;
	return RationalNumber(numerator, denominator);
} 

RationalNumber RationalNumber::operator-(RationalNumber const& o) const
{
	_sint64 numerator = (m_numeratorAll * o.m_denominator) -
		(o.m_numeratorAll * m_denominator);
	_sint64 denominator = m_denominator * o.m_denominator;
	return RationalNumber(numerator, denominator);
} 

RationalNumber RationalNumber::operator*(RationalNumber const& o) const
{
	_sint64 numerator = m_numeratorAll * o.m_numeratorAll;
	_sint64 denominator = m_denominator * o.m_denominator;
	return RationalNumber(numerator, denominator);
} 

RationalNumber RationalNumber::operator/(RationalNumber const& o) const
{
	_sint64 numerator = m_numeratorAll * o.m_denominator;
	_sint64 denominator = m_denominator * o.m_numeratorAll;
	return RationalNumber(numerator, denominator);
}

std::ostream &operator<<(std::ostream &os, RationalNumber const& o)
{
	//��ĸΪ0������Ͳ��ü�����
	if (o.m_infinate)
	{
		os << "Inf";
		return os;
	} 
	
	// �����ͷ���Ϊ0�Ǹɴ����0��
	if (o.m_numerator == 0 && o.m_integer == 0)
	{
		os << "0";
		return os;
	} 
	
	// ������ӡ���ź͸���
	if (o.m_negative)
	{
		os << "(-";
	} 
	
	// �������ʹ�����
	if (o.m_integer)
	{
		os << abs(o.m_integer);
		if (o.m_numerator) //����С�����оʹ���ո����
		{
			os << " ";
		}
	} 
	
	// �з����ʹ��������ĸ�Ѿ�abs���ˣ�������Բ���
	if (o.m_numerator)
	{
		os << abs(o.m_numerator) << '/' << o.m_denominator;
	} 
	
	// �����ĺ�������
	if (o.m_negative)
	{
		os << ")";
	} 
	return os;
}

int main()
{
	_sint64 n1, d1, n2, d2;
	scanf("%lld/%lld %lld/%lld", &n1, &d1, &n2, &d2);
	RationalNumber rn1(n1, d1), rn2(n2, d2);
	//����+����ʹ�ú���ʱ��
	std::cout << rn1 << " + " << rn2 << " = " << rn1 + rn2 << '\n';
	std::cout << rn1 << " - " << rn2 << " = " << rn1 - rn2 << '\n';
	std::cout << rn1 << " * " << rn2 << " = " << rn1 * rn2 << '\n';
	std::cout << rn1 << " / " << rn2 << " = " << rn1 / rn2 << '\n';
	return 0;
}


/*
2.
���ӣ�https://www.nowcoder.com/questionTerminal/89844f1f632c475ab6f4a600f71683a8

We are all familiar with pre-order, in-order and post-order traversals of binary trees.
A common problem in data structure classes is to find the pre-order traversal of a binary 
tree when given the in-order and post-order traversals. Alternatively, 
you can find the post-order traversal when given the in-order and pre-order.
However, in general you cannot determine the in-order traversal of a tree 
when given its pre-order and post-order traversals. 
Consider the four binary trees below:
     a     a     a      a
    /     /       \      \
   b     b         b      b
  /       \       /        \
 c         c     c          c

All of these trees have the same pre-order and post-order traversals. 
This phenomenon is not restricted to binary trees, but holds for general m-ary trees as well.

����
2 abc cba
2 abc bca
10 abc bca
13 abejkcfghid jkebfghicda
���
4
1
45
207352860
*/


/*
��Ŀ���룺
���Ƕ�����Ϥ��������ǰ������ͺ�������������ݽṹ���У�ͨ����������������ͺ�����������ǰ�����
�⣬���Ǹ���ǰ����������������⡣��һ������£�����������ǰ��ͺ���ʱ��������ȷ���������������
������������ĸ���������
		a     a     a      a
	   /     /       \      \
	  b     b         b      b
	 /       \       /        \
	c         c     c          c
���Ƕ�ӵ������ͬ��ǰ��ͺ�����ʵ����������������ڶ�������M����Ҳ��һ����
����������
�������ɶ������������ɡ�ÿ������ֻ��һ�У���ʽΪm s1 s2����ʾ����m������s1��ǰ�������s2�Ǻ����
���������ַ�������Сд��ĸ�ַ���ɡ��������е�����ʵ����1<=m<=20��s1��s2�ĳ��Ƚ�����1��26֮�䣨��
1��26�������s1�ĳ�����k����Ȼ��s2Ҳ����ô��������ʹ�õľ�����ĸ���ǰK����ĸ������һ��0��ʾ��ֹ��
�롣
���������
����ÿ������������Ҫ���һ�У���ʾ���������������������ĸ���������ķ�Χ���ᳬ��int�ķ�Χ������ÿ��
����������֤������һ��������Ҫ��

�������ǵ�ǰ����abejkcfghid��������jkebfghicda����ô���Ǹ���ǰ�򣬾���֪����
1����������13��������Ҳ����ÿһ�㶼��13������λ��
2��a�Ǹ�����һ�������ĸ���b
3��ͨ������������֪����b��������j��k��e��b���ĸ����
4���ٻص�ǰ����ǰ��4����㣬��һ�������ĸ��� c
5���Դ����ƣ����յõ� a Ϊ������һ�㹲�� 3 ������
��������������������
ǰ�� bejk cfghi d
���� jkeb fghic d
����һ��һ���Ŀ����Ծ���13����λ�����3������3����������ô��C3/13
�ֿ��ܡ�
֮���ٵݹ鴦��b���������bejk|jkeb������bΪ��ʱ��һ���ж��ٿ����������Կ�����ֻ��һ����eΪ����������
��ô�����Ծ�ֻ��C1/13�֡��ٵݹ�ejk|jke����������������Ȼ��C2/13�֣��ݹ�cfghi|fghic����������������C4/13
�֡��ʶ����ս��������C1/13*C2/13*C3/13*C4/13�֡�����������������ɡ�
��������������������������⣬������Ҫʵ����������е�C���������
*/

#include <string>
#include <tuple>
#include <list>
#include <cstdio>
// ��n�Ľ׳�
long long factorial(int n)
{
	long long r = 1;
	for (int i = 1; i <= n; i++)
	{
		r *= i;
	} 
	return r;
} 

// �� n, m ����� C(n, m)
// ���� C(n, m) == C(n, n - m) ���ص㣬�������׵�
long long combination(int n, int m)
{
	int max = m > (n - m) ? m : (n - m);
	long long numerator = 1;
	for (int i = max + 1; i <= n; i++)
	{
		numerator *= i;
	} 
	return numerator / factorial(n - max);
} 

// ���������ͣ������� typedef ����
using PrePost = std::tuple<std::string, std::string>;
// ����һ������ǰ��+��������������ע�͵�ԭ��
// ��ÿ��������ǰ��+�����зֳ���
std::list<PrePost> splitSubTrees(std::string const& pre, std::string const& post)
{
	std::list<PrePost> list{};
	size_t preIdx = 1;
	size_t lastPost = 0;
	while (preIdx < pre.size())
	{
		char rootValue = pre[preIdx];
		size_t postIdx = post.find(rootValue);
		int countOfNode = postIdx - lastPost + 1;
		list.emplace_back(std::make_tuple(
			pre.substr(preIdx, countOfNode),
			post.substr(lastPost, countOfNode)
			)
			);
		preIdx += countOfNode;
		lastPost += countOfNode;
	} 
	return list;
} 

// �ݹ�����ÿһ��Ŀ����ԣ�ֱ������ֻʣһ������������
long long calculateNumOfPossibilities(int m,
std::string const& pre,
std::string const& post)
{
	if (pre.size() == 0 || pre.size() == 1) 
	{
		return 1;
	} 
	
	std::list<PrePost> subTrees = splitSubTrees(pre, post);
	long long result = combination(m, subTrees.size());
	for (PrePost const& prePost : subTrees)
	{
		result *= calculateNumOfPossibilities(m,
			std::get<0>(prePost),
			std::get<1>(prePost));
	} 
	return result;
}

int main()
{
	int m;
	char pre[30];
	char post[30];
	while (scanf("%d %s %s", &m, pre, post) != EOF)
	{
		printf("%lld\n", calculateNumOfPossibilities(m, pre, post));
	} 
	return 0;
}