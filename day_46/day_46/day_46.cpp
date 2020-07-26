/*
ѡ����

ѧ����ϵģʽS(S#,Sname,Sex,Age)��S�����Էֱ��ʾѧ����ѧ�š��������Ա����䡣Ҫ�ڱ�S��ɾ��һ�����ԡ����䡱����ѡ�õ�SQL����ǣ���
A ALTER TABLE S DROP Age
B ALTER TABLE S ��Age��
C UPDATE S Age
D DELETE Age from S

ע��
ɾ��ʹ��ALTER
*/


/*
�����

1.
���ӣ�https://www.nowcoder.com/questionTerminal/e8a1b01a2df14cb2b228b30ee6a92163
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
*/


/*
˼·��
������ع��ص�˼�룺 ��һ��������Ϊ��һ��ʿ��������أ�count = 1�� ������ͬԪ�أ�count++; ������
��ͬԪ�أ���Ϊ���ˣ�ͬ���ھ�,count--��������countΪ0������������µ�iֵ��Ϊ����ص�ʿ����������
ȥ���������������ϵ�ʿ�����п�������Ԫ�ء� ��Ϊ��Ԫ����Ŀ���������������һ��, �����������
���ǲ��ܰ������ָ���Ϊ 0 ��. �ټ�һ��ѭ������¼���ʿ���ĸ������Ƿ��������һ�㼴�ɡ�
*/

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int n = numbers.size();
		if (n == 0) 
			return 0;
		int num = numbers[0], count = 1;
		for (int i = 1; i < n; i++) 
		{
			if (numbers[i] == num) 
				count++;
			else 
				count--;

			if(count == 0) 
			{
				num = numbers[i];
				count = 1;
			}
		}
		// ��������Ĳ���, �Ѿ��ҵ����� num ��.
		// ����Ĳ�����Ϊ��ȷ�� num ȷʵ�ǳ��ִ�������һ��.
		count = 0;
		for (int i = 0; i < n; i++) 
		{
			if (numbers[i] == num) 
				count++;
		}
		if(count * 2 > n) 
			return num;
		return 0;
	}
};


/*
2.���ӣ�https://www.nowcoder.com/questionTerminal/2baa6aba39214d6ea91a2e03dff3fbeb

����һ���򵥴����¼����Сģ�飬�ܹ���¼����Ĵ������ڵ��ļ����ƺ��кš�
����
1�� ��¼���8�������¼��ѭ����¼������˵���ֻ��������ֵİ��������¼����
����ͬ�Ĵ����¼�����ļ������������16λ���ƺ��к���ȫƥ�䣩ֻ��¼һ��������������ӣ�
2�� ����16���ַ����ļ����ƣ�ֻ��¼�ļ��������Ч16���ַ���
3�� ������ļ����ܴ�·������¼�ļ����Ʋ��ܴ�·����

����
E:\V1R2\product\fpgadrive.c   1325
���
fpgadrive.c 1325 1
*/

/*
ʵ�ֹ��̱Ƚϼ�, ������Ŀ�����������.ע���ȡ�ļ�����ʱ����Ҫ�õ� std::string::rfind �����ķ�����
�����
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
string getFileName(string path)
{
	int pos = path.rfind('\\');
	return path.substr(pos + 1);
} 

string modifyName(string name)
{
	if (name.size() > 16)
	{
		name = name.substr(name.size() - 16);
	} 
	return name;
} 

struct ErrRecord
{
	string file;
	int lineNo;
	int count;
	ErrRecord(string file, int lineNo)
	{
		this->file = file;
		this->lineNo = lineNo;
		count = 1;
	}
	// ������Ҫ���в���, �����ȶ�������������¼ʲô��������
	bool operator==(const ErrRecord & a)
	{
		return (file == a.file) && (lineNo == a.lineNo);
	}
};
int main()
{
	string file;
	int lineNo;
	vector<ErrRecord> myvec;
	while (cin >> file >> lineNo) 
	{
		ErrRecord record(getFileName(file), lineNo);
		auto res = find(myvec.begin(), myvec.end(), record);
		if (res == myvec.end())
		{
			myvec.push_back(record);
		}

		else 
		{
			res->count++;
		}
	} 
	int count = 0;
	for (auto item : myvec)
	{
		if (count + 8 >= myvec.size())
		{
			cout << modifyName(item.file) << " " << item.lineNo << " "
				<< item.count << endl;
		} 
		count++;
	}
	return 0;
}