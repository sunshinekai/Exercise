/*
ѡ����

����һ�����ݿ�mydb����һ����tb1�������������ֶΣ�����ΪID����ʮ����¼��ID��0��9��
���´�����������(C)
A 6
B 4
C 3
D 5

mysql_num_fields ȡ�ý�������ֶε���Ŀselect�ӱ���ֻ����id,name��age��������3
*/


/*
�����

1.
���ӣ�https://www.nowcoder.com/questionTerminal/bb4f1a23dbb84fd7b77be1fbe9eaaf32
nowcoder�����У�A��B��ƹ�����к�˫ϲ�ġ��������ǵġ�����������Ҫ�б�A��
�Ƿ������B�������е����࣬����ÿ���������������B���е�����������ô���أ�

ʾ����
����
ABCDFYE CDE
ABCDGEAS CDECDE

���
Yes
No
*/

/*
˼·1�����ü�������
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string A, B;
	while (cin >> A >> B)
	{
		int countA[26] = { 0 };
		int countB[26] = { 0 };
		string res = "Yes";
		for (size_t i = 0; i < A.size(); i++)
		{
			countA[A[i] - 'A']++;
		}
		for (size_t i = 0; i < B.size(); i++)
		{
			countB[B[i] - 'A']++;
		}
		int index = 0;
		while (index <= 26)
		{
			if (countA[index] < countB[index])
			{
				res = "No";
				break;
			}
			index++;
		}
		cout << res << endl;
	}
	return 0;
}


/*
˼·2��
���� map ͳ�Ƴ�ÿ�������е�ÿ�����������Ŀ. Ȼ��������е�һ�� map ������һ�� map ���жԱȼ���.
*/

#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	string str, res;
	while (cin >> str >> res)
	{
		// sta ���������ʾ��ǰ�Ƿ����� B �е����� A ���д���, ������Ŀ������ A ��.
		bool sta = true;
		// strdata ������ A �е���. key Ϊ�������, value Ϊ�����Ŀ
		// resdata ������ B �е���. key Ϊ�������, value Ϊ�����Ŀ
		map<char, int> strdata, resdata;
		// ͳ�����������е����������Ŀ
		for (auto c : str)
			strdata[c]++;
		for (auto c : res)
			resdata[c]++;
		// �� B ���б����������, �� A �е�ͬ���������Ŀ�Ա�.
		for (map<char, int>::iterator it = resdata.begin(); it != resdata.end(); it++)
		{
			// ֻҪ��һ������Ŀ����������, ���� sta ���Ϊ false
			// ��֮, ����������������ܹ���������, ���ܱ���Ϊ true
			if (strdata[it->first] < it->second)
			{
				sta = false;
				break;
			}
		} 
		
		if(true == sta)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	} 
	return 0;
}


/*
2.
�����ֵܵ���
���ӣ�https://www.nowcoder.com/questionTerminal/03ba8aeeef73400ca7a37a5f3370fe68
�������ֵ��е��ʵĸ�����������n��������Ϊ�ֵ䵥�ʡ�
����һ�����ʣ����������ֵ����ֵܵ��ʵĸ���
����������n

ʾ��:
����
3 abc bca cab abc 1
���
2
bca
*/

/*
������˼·����
1. ���ֵ��еĵ����ȷŵ� vector ��
2. �� vector ��������
3. isBrother ���������ж�ÿ������ĵ����Ƿ����ֵܵ���
4. �ж��ֵܵ��ʵĹ�����
	1. ���ж�����
	2. ���������ͬ, �ٿ��Ƿ�����ȫ��ͬ(��ȫ��ͬ�����ֵ�)
	3. Ȼ��������������, ������ͬ�������ֵܵ���.
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
// �ж����������Ƿ����ֵܵ���
bool isBrother(string str, string s){
	// 1. ���ж������Ƿ���ͬ. ����ͬ��һ�������ֵܵ���
	if (str.size() == s.size()){
		// 2. ���ж��ַ����Ƿ���ȫ��ͬ. ��ͬ��Ҳ�����ֵ�����
		if (str == s)
			return false;
		// 3. ��������������. �������ͬ�����ֵܵ���(��˲��������� const&)
		sort(str.begin(), str.end());
		sort(s.begin(), s.end());
		if (str == s)
			return true;
	} 
	return false;
} 
int main(){
	int num;
	while (cin >> num)
	{
		string str;
		string word, s;
		int index;
		vector<string> vs;
		// ��ȡ�ֵ��еĵ���, ���ֵ�ŵ� vs ��.
		for (int i = 0; i < num; ++i)
		{
			cin >> str;
			vs.push_back(str);
		} 
		
		// [ע��!!] ����˵���� "�ֵ�", ���Ҫ������ĵ��ʰ����ֵ�������~����õ��� k ���������.
		sort(vs.begin(), vs.end());
		// ����Ҫ�ж��Ĵʺ�k
		cin >> word;
		cin >> index;
		int counts = 0;
		// ͳ���ֵ��д��ڶ��ٸ��ֵܵ���.
		for (int i = 0; i < num; ++i){
			if (isBrother(word, vs[i])){
				counts++;
				// ���� k ���ֵܵ��ʱ��浽 s ��.
				if (counts == index)
					s = vs[i];
			}
		} 
		
		// ���������
		if (!vs.empty())
			cout << counts << endl;
		if (counts >= index)
			cout << s << endl;
	}
	return 0;
}