/*
ѡ����

1.
����Ĵ���Ϊ8λ���ò�����ʽ�洢������������һλ����λ����ôʮ������-25�ڼĴ�����ʾΪ(D)
A 67H
B 99H
C E6H
D E7H

ע��
ʮ������-25��ԭ��Ϊ10011001������Ϊ11100110�������Ƿ����1����Ϊ11100111��ת��Ϊʮ�����Ƽ�ΪE7

2.
��һ����B�̳�����A���������ݳ�Ա���£�
class A {
	...
private:
	int a;
};
class B : public A {
	...
private:
	int a;
public:
	const int b;
	A &c;
	static const char* d;
	B* e;
}

���캯���У���Ա����һ��Ҫͨ����ʼ���б�����ʼ������(F)��
A a b c
B b c e
C b c d e
D c e
E b d
F b c

ע��
���캯����ʼ��ʱ������ó�ʼ���б�һ�������������
a.��Ҫ��ʼ�������ݳ�Ա�Ƕ���(�̳�ʱ���û��๹�캯��)
b.��Ҫ��ʼ��const���ε����Ա
c.��Ҫ��ʼ�����ó�Ա����

3.
����������к�Ľ��Ϊ(D)

char str[] = "glad to test something";
char *p = str;
p++;
int *p1 = reinterpret_cast<int *>(p);
p1++;
p = reinterpret_cast<char *>(p1);
printf("result is %s\n", p);

A result is glad to test something
B result is ad to test something
C result is test something
D result is to test something

ע��
p������Ϊchar *��p++��pָ��str����ĵ�2��Ԫ�ؼ���ĸ��l����λ�á�
p1������Ϊint *��p1++��p1ָ���λ������4���ֽڣ�ָ��str�����еĵ�6��Ԫ�ؼ���ĸ��t����λ�á�
������p������Ϊ��to test something��

4.���³���������(C)

#include <iostream>
class Base {
public:
	Base(int j) : i(j) {}
	virtual~Base() {}
	void func1() 
	{
		i *= 10;
		func2();
	} 
	int getValue() 
	{
		return i;
	} 
protected:
	virtual void func2() 
	{
		i++;
	} 
protected:
	int i;
};
class Child : public Base {
public:
	Child(int j) : Base(j) {}
	void func1() {
		i *= 100;
		func2();
	} 
protected :
	void func2() {
		i += 2;
	}
};
int main() {
	Base * pb = new Child(1);
	pb->func1();
	cout << pb->getValue() << endl; 
	delete pb;
}

A 11
B 101
C 12
D 102

ע��
func1�����麯����func2���麯��������
pb->func1();
���õ���Base���func1��Child���func2
*/

/*
����⣺

1.
���ӣ�https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded?tpId=37&&tqId=21296&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
������������ڣ���������һ��ĵڼ��졣��
��ϸ������
����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿

����
2012
12
31

���
366
*/

/*
˼·����һ��������ÿ�µ��ۻ�����
������������� = ���µ����� + ����֮ǰ���ۻ�����
����������£���ȥ�ж��Ƿ�Ϊ���꣬��������꣬�ټ�1�켴��
*/

#include <iostream>
using namespace std;

int main()
{
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		int MonthDays[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
		int days = MonthDays[month - 1] + day;
		if ((month > 2) && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
			days++;
		cout << days << endl;
	}
	return 0;
}


/*
2.
���ӣ�https://www.nowcoder.com/practice/a5190a7c3ec045ce9273beebdfe029ee?tpId=85&&tqId=29839&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

һ������������n����ÿ�������涼��һ������(ӵ����ͬ����������������)�����һ�����������˵ĵ��ҽ���������ĺ���ĺʹ���������ĺ���Ļ���
���磺��������������ĺ�����{1, 1, 2, 3}��������Ӿ������˵ģ���Ϊ1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
������ʵ��Ӵ������Ƴ�һЩ��(�����Ƴ�0��,���Ǳ��Ƴ���)��Ҫʹ�Ƴ���Ĵ��������˵ġ����������̼���һ������Ի�õĶ����ֲ�ͬ�����˵Ĵ��ӡ�

����
3
1 1 1
���
2
*/
/*
����ı�����������������Ӽ�������

����˼·��
ÿ�δ�ȫ����ѡ������Ԫ�أ�С������Ӽ������ӣ���������������������a, b�������
a + b>ab�������һ����Ϊ1.��������֤������a = 1 + x, b = 1 + y����1 + x + 1 + y>(1 + x)(1 + y)��--->
1>xy����x��y����һ��Ϊ0����a, b��һ��Ϊ1.�ƹ㵽����k��������������a1, a2, ...ak���������
���������������sumС�ڵ��ڻ�pi�������ʱ��ѡ��һ����b, ��ʹ������sum + b > pib����b��
ȻΪ1����Ϊ��Ҫ�ǳ����������֮�����ѡ���b>1����sum + b <= pi*b����a1, a2, ..., ak, b����
�����������
��ˣ����򰴱����������ÿ�δ�С����ѡ�񣬵�ѡ��a1, a2, ..., ak - 1ʱ�����������������
����ѡ��akʱ������������ak��Ȼ���ڵ���max(a1, a2, ..., ak - 1)�����������ѡ������������Ȼ
�޷����㣡��ʱ�����ټ����������������ж��1������k = 1ʱ��sum(1)>pi(1)�����㣬����һ
��Ԫ����Ϊ1�����������1 + 1>1 * 1��
����Ҫ�жϵ�ǰak�Ƿ����1���������1����Ȼ�������㣬��ϵĸ����������ӣ����Ǽ������
��������Ȼ�����������Ŀ���.�����ظ����֣����ֻ����һ����Ҫȥ�ء�
*/


#include<iostream>
#include<algorithm>
using namespace std;
/*
getLuckyPacket:�ӵ�ǰλ�ÿ�ʼ��������Ҫ�����ϣ�һֱ���������һ��λ�ý���
x[]: �����е�������
n: �������
pos: ��ǰ������λ��
sum: ��Ŀǰλ�õ��ۼӺ�
multi: ��Ŀǰλ�õ��ۻ�ֵ
*/
int getLuckyPacket(int x[], int n, int pos, int sum, int multi)
{
	int count = 0;
	//ѭ����������λ��i��ʼ���п��ܵ����
	for (int i = pos; i<n; i++)
	{
		sum += x[i];
		multi *= x[i];
		if (sum > multi)
		{
			//�ҵ�����Ҫ�����ϣ���1�������ۼӺ�����ֵ�����Ƿ��з���Ҫ��ļ���
			count += 1 + getLuckyPacket(x, n, i + 1, sum, multi);
		}
		
		else if (x[i] == 1)
		{
			//��β�����Ҫ���ҵ�ǰԪ��ֵΪ1��������������
			count += getLuckyPacket(x, n, i + 1, sum, multi);
		}

		else
		{
			//���sum����multi,������û�з���Ҫ��������
			break;
		} 
		// Ҫ������һ��λ��֮ǰ�����Ȼָ�sum��multi
			sum -= x[i];
		multi /= x[i];
		//������ͬ����û��ʲô���𣬶�ֻ����һ����ϣ�����ֱ������
		while (i < n - 1 && x[i] == x[i + 1])
		{
			i++;
		}
	} 
	return count;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int x[n];
		for (int i = 0; i < n; i++)
		{
			cin >> x[i];
		} 
		sort(x, x + n);
		//�ӵ�һ��λ�ÿ�ʼ����
		cout << getLuckyPacket(x, n, 0, 0, 1) << endl;
	} 
	return 0;
}