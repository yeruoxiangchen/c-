#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<io.h>
using namespace std;
void selfDir(string&s)
{
    struct _finddata_t data;
	string sr=s + "\\*.*";
	const char* path = sr.data();
	long handle = _findfirst(path,&data);
	if (handle < 0)
	{
		perror(path); return;
	}
	int hdl = (handle < 0) ? -1 : 1;
	while (hdl >= 0)
	{
		string str = data.name;
		if (str.compare(".") != 0 && str.compare("..") != 0) {
			if (data.attrib == _A_SUBDIR) 		
			{
				cout << "文件夹“" << str << "”: " << endl;
				string newstr = s + "\\" + str;
				selfDir(newstr);
			}
			else 
				cout << "文件--> " << data.name << endl;
		}
		hdl = _findnext(handle, &data);
	}
	_findclose(handle);
}

int main(int argc, char* argv[])
{
	cout << argc << endl;
	string s = argv[1];
	
    selfDir(s);
    return 0;
}

