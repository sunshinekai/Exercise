/*
ѡ����

����ѡ���У����� ���� �½��̵Ĳ�����(C)

I�û���½�ɹ�II�豸����III��������ִ��

A ��I��II
B ��II��III
C ��I��III
D I��II��III

ע��
�û���¼�ɹ��󣬲���ϵͳ���������û��йصĳ�ʼ���򣬴�ʱ��Ҫ�����µĽ��̡�
��������ִ��ʱ�������ʻ������½��̡����豸������������н��̣����ᴴ���½���
*/


/*
�����

1.
���ӣ�https://wenku.baidu.com/view/b18808d8a48da0116c175f0e7cd184254b351bfb.html
дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��-��*��/�����������
*/

/*
����˼·�����ֵ���ӿ���ת��Ϊ�����Ƶļӷ���ע��ÿһλ������λ����
1. ����������൱��ÿһλ��ӣ��������ǽ�λ��
*/

class Solution {
public:
	int Add(int num1, int num2) {
		while (num2 != 0){
			int sum = num1 ^ num2; //�õ���Ӻ󲻰�����λ������
			int carray = (num1 & num2) << 1; //�õ�������ӵĽ�λ
			num1 = sum; //���������ӣ�ֱ����λΪ0
			num2 = carray;
		} 
		return num1;
	}
};



/*
2.
���ӣ�https://www.nowcoder.com/questionTerminal/c67a09062c0f4a5b964eef0945d3dd06
���������ߣ������ж�һ���ܲ������һ�������Ρ�

����
1 2 3
2 2 2
���
No
Yes
*/

/*
˼·����������������ֱַ���������������һ�������бȽ�
*/

#include <iostream>
#include <string>
#define ADD(x, y) ((x) + (y))
#define CMP(x, y) ((x) > (y))
int main()
{
	double a, b, c;
	while (std::cin >> a >> b >> c)
	{
		//�����߽���������������бȽ�
		if (CMP(ADD(a, b), c) && CMP(ADD(b, c), a) && CMP(ADD(a, c), b))
			std::cout << "Yes" << std::endl;
		else
			std::cout << "No" << std::endl;
	} 
	return 0;
}