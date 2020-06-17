/*
ѡ����

�������������(B)

class A
{
public :
	void foo()
	{
		printf("1");
	}
	virtual void fun()
	{
		printf("2");
	}
};

class B : public A
{
public :
	void foo()
	{
		printf("3");
	} 
	void fun()
	{
		printf("4");
	}
};
int main()
{
	A a;
	B b;
	A *p = &a;
	p->foo();
	p->fun();
	p = &b;
	p->foo();
	p->fun();
	A *ptr = (A *)&b;
	ptr->foo();
	ptr->fun();
	return 0;
}

A 121434
B 121414
C 121232
D 123434


1.��������ΪA���͵�ָ��ָ��ʵ������ΪA�Ķ��󣬵��õĿ϶���A�ķ��������1 2,
2.Ȼ������ΪA���͵�ָ��ָ��ʵ������ΪB�Ķ�������麯������A�ķ�����
���1���麯������ʵ������B�ķ��������4
3.��������ΪA��ָ��ָ��ʵ������ΪB�Ķ��󣬽���һ��ǿ������ת����
��ʵ���ָ���ָ��ָ��������Զ���������ת���������Ƿ�ǿ������ת������Ӱ��ṹ��ԭ��ͬ��һ����������1 4
*/


/*
�����

1.
���ӣ�https://www.nowcoder.com/practice/70e00e490b454006976c1fdf47f155d9?tpId=8&&tqId=11017&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
��һ���������������������㰴�����һ��һ��ش����������α�ţ��������Ϊ1��
�������������a��b�������һ���㷨�����a��b�������������ȵı�š�
��������int a,b��Ϊ�������ı�š��뷵��a��b������������ȵı�š�
ע�������㱾��Ҳ����Ϊ�������ȡ�

����������
2��3
���أ�1
*/

/*
˼·����Ŀ�������������������£� 
        1
	   / \ 
	  2   3
	 / \ / \ 
    4   56  7 ...
���������ӽڵ��븸�ڵ�֮��Ĺ�ϵΪroot = child / 2
�������a ��= b���������еĽϴ�������2�� ���ѭ��ֱ��a == b ����ԭ��������������������� ���磺 2
��7������������ȣ�7/2 = 3 ---> 3/2 = 1�� 2/2 = 1�� �õ�1Ϊ���ǵĹ�������
*/

class LCA {
public:
	int getLCA(int a, int b) {
		while (a != b)
		{
			if (a > b)
				a /= 2;
			else
				b /= 2;
		}
		return a;
	}
};


/*
���ӣ�https://www.nowcoder.com/practice/4b1658fd8ffb4217bc3b7e85a38cfaf2?tpId=37&&tqId=21309&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
2.����: ��һ��byte���ֶ�Ӧ�Ķ�����������1�����������������3�Ķ�����Ϊ00000011���������2��1
����: һ��byte�͵�����
���: ��Ӧ�Ķ�����������1�����������
*/

/*
�ⷨ1����byte����ת��Ϊ�����ƣ���¼����1�ĸ�������
*/

#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

int main()
{
	int input;
	while (cin >> input)
	{
		bitset<8> bitnum(input);
		int count = 0, maxcount = 0;
		for (size_t i = 0; i < bitnum.size(); i++)
		{
			if (bitnum[i] == 1)
				count++;
			else
				count = 0;
			maxcount = max(count, maxcount);
		}
		cout << maxcount << endl;
	}
	return 0;
}

/*
�ⷨ2������λ���㣬��ȡÿһλ�Ķ�����ֵ����ȡ��iλ��ֵ�� (n >> i) & 1�����1������������ۼӣ��������
�������0��ʼ������
*/

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0, maxCount = 0;
		// n����32�ξͱ�Ϊ0
		while (n)
		{
			//��ȡ��ǰλ�Ķ�����ֵ
			if (n & 1)
				++count;
			else
				count = 0;
			maxCount = max(count, maxCount);
			n = n >> 1;
		} 
		cout << maxCount << endl;
	}
	return 0;
}