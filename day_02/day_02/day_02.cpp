#include <iostream>
#include <string>

using namespace std;
int main()
{
	string s, s1,s2;
	getline(cin, s1);
	int pos = s1.find(' ');
	int rpos = s1.rfind(' ');
	s2 = s1.substr(0, pos);
	while (rpos >= 0)
	{
		s += s1.substr(rpos + 1) + ' ';
		s1.erase(rpos);
		rpos = s1.rfind(' ');
	}
	s += s2;
	cout << s << endl;
	return 0;
}



#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0, i = 0;
	cin >> n;
	int	a[6];
	while (cin >> a[i])
		i++;
}