/*
ѡ����

1.
��˫��ѭ�������У���pָ����ָ�Ľڵ�����һ��ָ��q��ָ����½ڵ㣬�޸�ָ��Ĳ�����(C)

A p->next=q;q->prior=p;p->next->prior=q;q->next=q;
B p->next=q;p->next->prior=q;q->prior=p;q->next=p->next;
C q->prior=p;q->next=p->next;p->next->prior=q;p->next=q;
D q->next=p->next;q->prior=;p->next=q;p->next=q;
ע��q����ָ�븳Ϊp����ָ�룬q����ָ�븳Ϊp��
���������Ի�����Ȼ��p����ָ��ָ��Ľ�����ָ�븳Ϊq�����p����ָ�븳Ϊq����ӦѡC

2.
��֪һ�����Ա�38��25��74��63��52��48�����ٶ�����ɢ�к���h��key) = key%7 
����ɢ�е�ַ����ɢ�д洢��ɢ�б�A��0....6���У�����������̽�ⷽ�����
��ͻ�����ڸ�ɢ�б��Ͻ��еȸ��ʳɹ����ҵ�ƽ�����ҳ���Ϊ(C)
A��1.4
B��1.6
C��2.0
D��2.2
ע����ɢ�к���h(key)=key%7������̽�ⷽ�������ͻ�����Ա�(38,25,74,63,52,48)ɢ�д洢��ɢ�б�A[0��6]
�ڸ�ɢ�б��Ͻ��еȸ��ʳɹ����ҵ�ƽ�����ҳ��ȡ�
*/



/*
1.
���ӣ�https://www.nowcoder.com/practice/fbcf95ed620f42a88be24eb2cd57ec54?tpId=49&&tqId=29311&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
��΢�ź����
�����ڼ�С��ʹ��΢���յ��ܶ��������ǳ����ġ��ڲ鿴��ȡ�����¼ʱ���֣�ĳ����������ֵĴ��������˺��������һ�롣���С���ҵ��ú����д��
�����㷨˼·�ʹ���ʵ�֣�Ҫ���㷨�����ܸ�Ч��
����һ������Ľ������gifts�����Ĵ�Сn���뷵���������Ľ�
��û�н���������һ�룬����0��

[1,2,3,2,2],5
���أ�2
*/

/*
˼·1�����һ�������ִ�������һ���ˣ�������󣬱�Ȼ�����м䣬��������
��������鿴�Ƿ���ϼ��ɡ�
*/

class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		sort(gifts.begin(), gifts.end());
		//����һ���������֮���Ȼ�����м�
		int middle = gifts[n / 2];
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			//ͳ�������м�����ĸ���
			if (gifts[i] == middle)
				count++;
		} 
		// �����������һ�룬����ڳ���һ�����
		if (count > n / 2)
			return middle;
		else
			return 0;
	}
};

/*
˼·2��������mapͳ��ÿ�����ֳ��ֵĴ���������ж���û�г���һ���
����
*/

class Gift {
public:
	int getValue(vector<int> gifts, int n) 
	{
		map<int, int> count;
		int middle = n / 2;
		for (const auto& e : gifts)
			++count[e];

		for(const auto& e : count)
		{
			if (e.second >= middle)
				return e.first;
		} 
		return 0;
	}
};



/*
2.
���ӣ�https://www.nowcoder.com/practice/3959837097c7413a961a135d7104c314?tpId=37&&tqId=21275&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

Levenshtein ���룬�ֳƱ༭���룬ָ���������ַ���֮�䣬��һ��ת������һ����������ٱ༭����������
��ɵı༭����������һ���ַ��滻����һ���ַ�������һ���ַ���ɾ��һ���ַ���
�༭������㷨�������ɶ����ѧ��Levenshtein����ģ����ֽ�Levenshtein Distance��
Ex��
�ַ���A:abcdefg
�ַ���B: abcdef
ͨ�����ӻ���ɾ���ַ���g���ķ�ʽ�ﵽĿ�ġ�
�����ַ�������Ҫһ�β������������������Ҫ�Ĵ�������Ϊ�����ַ����ľ��롣
Ҫ��
�������������ַ�����д��һ���㷨�������ǵı༭���롣
*/

/*
F(i,j):word1��ǰi���ַ���word2��ǰj���ַ��ı༭���� ״̬���ƣ� F(i,j) = min { F(i-1,j��+1, F(i,j-1) +1, F(i-
1,j-1) +(w1[i]==w2[j]?0:1) } ��ʽ��ʾ��ɾ�������Ӻ��滻������ѡ��һ����С������ F(i-1,j): w1[1,...,i-1]��
w2[1,...,j]�ı༭���룬ɾ��w1[i]���ַ�--->F(i,j) F(i,j-1): w1[1,...,i]��w2[1,...,j-1]�ı༭���룬����һ���ַ�---
>F(i,j) F(i-1,j-1): w1[1,...,i-1]��w2[1,...,j-1]�ı༭���룬���w1[i]��w2[j]��ͬ�� �����κβ������༭���벻
�䣬���w1[i]��w2[j]��ͬ���滻w1[i]���ַ�Ϊw2[j]--->F(i,j) ��ʼ���� ��ʼ��һ��Ҫ��ȷ����ֵ���������
������մ�����ʼֵ�޷�ȷ�� F(i,0) = i :word��մ��ı༭���룬ɾ������ F(0,i) = i :�մ���word�ı༭��
�룬���Ӳ��� 
���ؽ����F(m,n)
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int minDistance(string word1, string word2)
{
	// word��մ�֮��ı༭����Ϊword�ĳ���
	if (word1.empty() || word2.empty())
		return max(word1.size(), word2.size());

	int len1 = word1.size();
	int len2 = word2.size();
	// F(i,j)��ʼ��
	vector<vector<int> > f(1 + len1, vector<int>(1 + len2, 0));
	for (int i = 0; i <= len1; ++i)
		f[i][0] = i;

	for (int i = 0; i <= len2; ++i)
		f[0][i] = i;

	for (int i = 1; i <= len1; ++i)
	{
		for (int j = 1; j <= len2; ++j)
		{
			// F(i,j) = min { F(i-1,j��+1, F(i,j-1) +1, F(i-1,j-1) +
			//(w1[i]==w2[j]?0:1) }
			// �ж�word1�ĵ�i���ַ��Ƿ���word2�ĵ�j���ַ����
			if (word1[i - 1] == word2[j - 1])
			{
				f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]);
				// �ַ���ȣ�F(i-1,j-1)�༭���벻��
				f[i][j] = min(f[i][j], f[i - 1][j - 1]);
			}
			else
			{
				f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]);
				// �ַ�����ȣ�F(i-1,j-1)�༭���� + 1
				f[i][j] = min(f[i][j], 1 + f[i - 1][j - 1]);
			}
		}
	}
	return f[len1][len2];
}

int main()
{
	string a, b;
	while (cin >> a >> b)
		cout << minDistance(a, b) << endl;
	return 0;
}