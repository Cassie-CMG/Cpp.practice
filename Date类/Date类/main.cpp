#include <iostream>
#include <cstdlib>
#include "Date.h"
using namespace std;
void test()
{
	Date d1(2018, 5, 5);
	Date d2(2019, 3, 14);
	Date d3(d1);
	d3.DisPlay();

	d1 += 60;
	cout << "d1(2018, 5, 5) += 60: " << endl;
	d1.DisPlay();

	d2 -= 364;
	cout << "d2(2019, 3, 14) -= 364:" << endl;
	d2.DisPlay();

	cout << "(d1(2018, 5, 5) += 60)  -  (d2(2019, 3, 14) -= 364)" << endl;
	cout << (d1 - d2) << endl;

	cout << (d1 > d2) << endl;
	cout << (d1 >= d2) << endl;
	cout << (d1 != d2) << endl;
	cout << (d1 == d2) << endl;
	cout << (d1 < d2) << endl;
	cout << (d1 <= d2) << endl;

	d2 = d1;
	d2.DisPlay();

}

int main()
{
	test();
	system("pause");
	return 0;
}