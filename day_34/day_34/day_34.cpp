/*
�����

1.
���ӣ�https://www.nowcoder.com/questionTerminal/5973a31d58234b068fa1fe34f7290855

NowCoderÿ��Ҫ�����ͻ�д�����ʼ�����������֪�����һ���ʼ��а�������ռ��ˣ�
�ռ�������֮�����һ�����źͿո����������ռ�������Ҳ�����ո�򶺺ţ���������Ҫ��˫���Ű�����
���ڸ���һ���ռ����������������������Ӧ���ռ����б�

����
3
Joe
Quan, William
Letendre,Bruce
2
Leon
Kewell
���
Joe, "Quan, William", "Letendre,Bruce"
Leon, Kewell
*/


/*
�Ƚ��յ�һ�����֣�����������Ƕ��������ݣ�һ��һ���ӣ��ӵ�һ����ƴһ�����������һ�����ź�һ���ո�
ȫ������͸����س������������ַ������ж��Ż��߿ո񣬾�Ҫ��˫���š�����ѡ��ƴ�Ӻ��������Ҳ����ѡ��
һ�ζ�ֱ�����������Ĵ�����ֱ��һ�ζ�����Ľ����
*/


#include <iostream>
#include <string>
#include <cstdio>
int main()
{
	int n;
	while (std::cin >> n) //��������
	{
		std::cin.get(); //����س�
		std::string name;
		for (int i = 0; i < n; i++) //���ֱַ���
		{
			bool quote = false;
			std::getline(std::cin, name);
			if (name.find(',') != std::string::npos ||
				name.find(' ') != std::string::npos) //�ҵ����Ż��߿ո񣬾�Ҫ��˫����
			{
				quote = true;
			} 
			
			if(quote)
			{
				putchar('\"'); //putcharЧ�ʸ���
			}

			std::cout << name;
			if (quote)
			{
				putchar('\"');
			}
			if(i == n - 1) //����Ѿ������һ���ַ������ǾͲ��س�������Ӷ��źͿո�
			{
				putchar('\n');
			} 
			else
			{
				putchar(',');
				putchar(' ');
			}
		}
	} 
	return 0;
}



/*
2.
���ӣ�https://www.nowcoder.com/questionTerminal/71d3849a19f04a1591c415964ac148f1
һֻ���������ÿ���ܲ���һ̥���ӡ�ÿֻС���ӵĳ�������һ�졣 ĳ��������һֻС���ӣ����ʵ�N���Ժ�������õ�����ֻ���ӡ�
����
1
2

���
1
2
*/

/*
��������ӵڶ���Ϳ�ʼ��С���ˣ���������Ǵӵڶ��ʼ��쳲��������С�ǰ90�������ǡ�û���long long
�ķ�Χ�ڣ����Բ���Ҫ�߾��ȣ�ֱ��long long���
*/

#include <iostream>
#include <cstdio>
int main()
{
	long long n[91] = { 1, 2 };
	for (int i = 2; i <= 90; i++)
	{
		n[i] = n[i - 1] + n[i - 2];
	} 
	int d;
	while (std::cin >> d)
	{
		printf("%lld\n", n[d - 1]);
	}
}