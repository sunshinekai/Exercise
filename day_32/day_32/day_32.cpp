/*
ѡ����

1.
����������ǡ���������˽���TCP����ʱ����һ�����֡������Ĺ���(C)
A �����ӷ��𷽡��򡰽��շ�������һ��SYN-ACK��
B �����շ��������ӷ��𷽡�����һ��SYN-ACK��
C �����ӷ��𷽡���Ŀ��������TCP���̷���һ��SYN��
D �����շ�����Դ�����õ�TCP���̷���һ��SYN����ΪӦ��
ע��
��һ�����֣��ͻ�����������˷���SYN����syn��j��������SYN_SEND״̬���ȴ�������ȷ�ϡ�
�ڶ������֣��������յ�SYN����ȷ��SYN����ʱsyn��j+1��ͬʱ����һ��SYN����syn��k��
��SYN��ACK������ʱ����������SYN_RECV״̬�����������֣��ͻ����յ�SYN��ACK����
�����������ACKȷ�ϰ�����ʱ�ͻ��˺ͷ������˾�����ESTABLISHED״̬��

2.
�������� URL �������������(A)
A http����ʹ��TCPЭ�飻
B ����ͳһ��Դ��λ��������ȷ��һ����Դ������ʾ��������
C URL�������˶˿ںţ�Ĭ����80�˿�
D ����URL��ʹ�ô�д��ĸ
ע��
http��ʾʹ��HTTPЭ��,�ײ����TCP

3.
�����ڽ�������������(A)
A Ŀ¼��������
B MAC���鹥��
C VLAN����
D DHCP��ƭ����
ע��
�����������ֹ������ͣ�
1��vlan��Ծ����
2������������
3��mac���ˮ����
4��arp����
5��vtp����
*/


/*
�����

1.
���ӣ�https://www.nowcoder.com/questionTerminal/754921e9c98b43d1b2d70c227b844101
NowCoder���Ա��Ͽ���һ�����ꡣ���������·�Ϊ������ʱ�򣬵���ÿ����׬1Ԫ������ÿ����׬2Ԫ��
���ڸ���һ��ʱ�����䣬������������������ж��١�

����
2000 1 1 2000 1 31
2000 2 1 2000 2 29

���
62
29
*/


/*
���ڼ������Ļ������ǽ�������ڼ����Ϊ�������֣���һ������һ�����ݣ����һ������һ�����ݣ����м�
��������ݡ������������ֻ��Ҫ�ж�������365��366�����ˡ������꣬���Ǿ�Ҫ��������������һ��ĵ�
���졣����Ҫ�����1994��5��27�յ�2003��4��29�գ���ô�����Ǿ�Ҫ�����5��27������һ��ĵڼ��죬Ȼ��
�ж�1994�겻�����꣬���ǣ�������365��ȥ����������͵õ�����ˡ������е�һ��ҲҪ�㣬���Ի�Ҫ������һ
�졣Ȼ�������4��29����2003��ĵڼ��죬�Ϳ��Խ�������ˡ����ԣ�������Ҫһ�������������Ǹ���һ������
�գ����������һ��ĵڼ��졣
��ȥ����ʹ��1��4��6��8��9��10��12�µ�������������ô�����ȫ������ˡ�
*/

#include <cstdio>
#include <cmath>
#include <iostream>
// �����жϺ���
inline int leap_year(int year)
{
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
} 
// ��������
inline int profit_of_year(int year)
{
	return 2 * 31
		+ 1 * 28
		+ 1 * 31
		+ 2 * 30
		+ 1 * 31
		+ 2 * 30
		+ 1 * 31
		+ 2 * 31
		+ 2 * 30
		+ 2 * 31
		+ 1 * 30
		+ 2 * 31
		+ leap_year(year);
} 

// �ж�����·��ǲ���������
inline bool prime(int n)
{
	return n == 2 || n == 3 || n == 5 || n == 7 || n == 11;
} 

// ���һ����������һ��ĵڼ���
int profit_of_this_year(int year, int month, int day)
{
	if(!prime(month))
	{
		day *= 2;
	} 
	while(--month)
	{
			switch (month)
			{
				case 1:
				case 8:
				case 10:
				case 12:
					day += 62;
					break;
				case 3:
				case 5:
				case 7:
					day += 31;
					break;
				case 4:
				case 6:
				case 9:
					day += 60;
					break;
				case 11:
					day += 30;
					break;
				case 2:
					day += 28 + leap_year(year);
					break;
				default:;
			}
		}
	return day;
}

int main()
{
	int year1, month1, day1, year2, month2, day2;
	int count_profit = 0;
	while (std::cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
	{
		count_profit = 0;
		count_profit += profit_of_year(year1) - profit_of_this_year(year1, month1, day1 - 1);
		//�����day1 - 1��Ȼ�п��ܻ����0�գ�����ʵ��2��0�վ��൱��1��31�գ����Բ�Ӱ������
		count_profit += profit_of_this_year(year2, month2, day2);
		if(year1 == year2) //���������յ���ͬһ�꣬�����ͬһ�꣬Ҫ������һ���������
		{
			count_profit -= profit_of_year(year1);
		}
		for (int i = year1 + 1; i < year2; i++) //�м�����ÿһ�������
		{
			count_profit += profit_of_year(i);
		} 
		std::cout << count_profit << std::endl;
	} 
	return 0;
}



/*
2.
���ӣ�https://www.nowcoder.com/questionTerminal/c0a4b917a15f40a49ca10532ab9019fb

NowCoder�ų��Լ��Ѿ���ס��1-100000֮�����е�쳲���������
Ϊ�˿���������������һ����n������˵����n��쳲�����������Ȼ��쳲���������ܴ�
��ˣ������n��쳲�����������6λ����˵������������ֻ˵�����6λ��

����
1
2
3
4
100000
���
1
2
3
5
537501
*/

/*
˼·������쳲�����������100000���ڵ�ÿһ��ĺ���λ��Ȼ����Ҫ��ʱ��ֱ�����������Ķ�Ӧֵ���ɡ�
*/

#include <iostream>
#include <cstdio>
int main()
{
	int fib[100001];
	fib[0] = 1;
	fib[1] = 1;
	//��ǰ����쳲��������У�ֻ������6λ
	for (int i = 2; i <= 100000; ++i)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
		fib[i] = fib[i] % 1000000; //��������ӣ�����ֻҪ����λ��Ӱ����һ�����Ľ��
	} 
	//����������OJƽ̨��ʱ�ӿ�ʼ��ȡ���ݵ�trick��������ɿ������ںܶ���Ŀ��
	int n;
	while (std::cin >> n)
	{
		if (n < 29)
		{
			//쳲���������С��6λ
			printf("%d\n", fib[n]);
		} 
		else
		{
			printf("%06d\n", fib[n]);
		}
	} 
	return 0;
}