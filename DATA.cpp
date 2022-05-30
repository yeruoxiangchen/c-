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
		cout << Year << "年" << Month << "月" << Day << "日" << endl;
	}
	void ifgreatermonth()
	{
		if (Month > 7)
		{
			if (Month % 2 == 0)cout << "大月" << endl;
			else cout << "小月" << endl;
		}
		else
		{
			if (Month % 2 == 1)cout << "大月" << endl;
			else cout << "小月" << endl;
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