#include<iostream>
using namespace std;

class Data
{
private:
	int Year;
	int Month;
	int Day;
public:
	void setdata(int year, int month, int day)
	{
		this->Year = year;
		this->Month = month;
		this->Day = day;
	}
	void printdata()
	{
		cout << Year << "��" << Month << "��" << Day << "��" << endl;
	}
	void ifgreatermonth()
	{
		if (Month > 7)
		{
			if (Month % 2 == 0)cout << "����" << endl;
			else cout << "С��" << endl;
		}
		else
		{
			if (Month % 2 == 1)cout << "����" << endl;
			else cout << "С��" << endl;
		}
	}
};



int main()
{
	Data data;
	data.setdata(2021, 6, 6);
	data.printdata();
	data.ifgreatermonth();
	return 0;
}