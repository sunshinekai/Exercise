/*
ѡ����

ѭ�����з���һά����A[0��M-1]�У�end1ָ���ͷԪ�أ�end2ָ���βԪ�صĺ�һ��λ�á������������
���ɽ�����Ӻͳ��Ӳ��������������������M-1��Ԫ�ء���ʼʱΪ�գ������ж϶ӿպͶ����������У���
ȷ����(A)

A �ӿգ�end1==end2�� ������end1==(end2+1)modM
B �ӿգ�end1==end2; ������end2==(end1+1)mod(M-1)
C �ӿգ�end2==(end1+1)modM ; ������end1==��end2+1��modM
D �ӿգ�end1==��end2+1��modM; ������end2==(end1+1)mod(M-1)

ע������ʱ��end2ָ��M-1����ʱend1ָ��0��end2+1��Ӧ����M����(end2 + 1)% M �� 0 �� end1
����ʱend1 = end2
*/



/*
�����

1.
���ӣ�https://www.nowcoder.com/practice/fe6c73cb899c4fe1bdd773f8d3b42c3d?tpId=49&&tqId=29329&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
С�׾���������������Ϸ.��һ��,������һ�������������Ϸ,���Ľ�ɫ�ĳ�ʼ����ֵΪ a.
�ڽ�������һ��ʱ����,��������������n������,ÿ������ķ�����Ϊb1,b2,b3...bn. 
��������Ĺ��������biС�ڵ���С�׵ĵ�ǰ����ֵc,��ô���������ɴ�ܹ���,
����ʹ���Լ�������ֵ����bi;���bi����c,����Ҳ�ܴ�ܹ���,
����������ֵֻ������bi ��c�����Լ��.��ô��������,��һϵ�еĶ�����,С�׵���������ֵΪ����?

����
3 50
50 105 200

5 20
30 20 15 40 100

���
110

205
*/

/*
˼·�����������ֵ���ۼӷ����������һ����ֱ�����bi,һ�����ۼӵ�ǰ����ֵ��bi�����Լ�������Լ��
����ͨ����ת�������ã�a��b�����Լ���൱��b��a,b���������Լ�������������Ϊ0�� ��bΪ��
����
*/

#include <iostream>
#include <vector>

using namespace std;
int maxnum(int a, int b)
{
	int r;
	while (r = a % b)
	{
		a = b;
		b = r;
	}
	return b;
}
int main()
{
	int n, c;
	while (cin >> n >> c)
	{
		while (n--)
		{
			vector<int> v;
			for (auto &e : v)
				cin >> e;
			for (auto & e : v)
			{
				if (c >= e)
					c += e;
				else
					c += maxnum(c, e);
			}
			cout << c << endl;
		}
	}
	return 0;
}


/*
2.
���ӣ�https://www.nowcoder.com/practice/e896d0f82f1246a3aa7b232ce38029d4?tpId=37&&tqId=21282&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
�ҳ��ַ����е�һ��ֻ����һ�ε��ַ�

���룺
asdfasdfo
���
o
*/

/*
˼·��
��һ�������ÿһ��λ�ñ�ʾ��Ӧ��λ�á���Ӧ���ַ�λ�ô���ַ����ֵĴ�����ͳ����֮�󣬱���������
����������һ��ֻ����һ�ε��ַ���ֹͣ
*/

#include <string>
#include <iostream>
using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		int hashtable[256] = { 0 };
		for (auto& e : s)
		{
			hashtable[e]++;
		} 
		int i;
		for (i = 0; i < s.size(); i++)
		{
			if (hashtable[s[i]] == 1)
			{
				cout << s[i] << endl;
				break;
			}
		} 
		if(i >= s.size())
			cout << -1 << endl;
	} 
	return 0;
}
