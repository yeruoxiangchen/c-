#include"String_head.h"
#include<map>
#include<fstream>

int main()
{
	ifstream fin;
	fin.open("E12.txt");
	char s0[100];
	int n = 0;
	while (fin >> s0)
	{
		String s (s0);
		int i = 0;
		while (i < s.getsize())
		{
			if (s[i] >= 65 && s[i] <= 90) { s[i] += 32; i++; }
			else if (s[i] < 97 || s[i]>122)
				s.erase(i);
			else if (s[i] >= 97 && s[i] <= 122)i++;
		}
		if (s.getsize() != 0)
		{
			//cout << s << endl;
			int key = _find(s, n);
			if (key == -1)
			{
				strtxt[n].str = s; strtxt[n].count = 1;
				n++;
			}
			else strtxt[key].count++;
		}
		
	}
	sort(strtxt, strtxt + n, mycomp);
	for (int i = 0; i < n; i++)
	{
		cout << strtxt[i].str << endl;
	}
}