#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double matrix[4][5];
	cout << "Enter the salesperson (1 - 4), product number (1 - 5), and total sales.\nEnter -1 for the salesperson to end input.\n";
	int person, product;
	double sale;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			matrix[i][j] = 0;
		}
	}
	while (cin >> person  )
	{
		if (person == -1)
			break;
		cin >> product >> sale;
		matrix[person - 1][product - 1] += sale;
	}
	cout << "The total sales for each salesperson are displayed at the end of each row,and the total sales for each product are displayed at the bottom of each column.\n";
	cout << right << setw(13) << fixed << "1";
	for (int i = 2; i <= 5; i++)
		cout << right << setw(12) << fixed << i;
	cout << right << setw(14) << fixed << "Total\n";
	int a = 1;
	double total1 = 0;
	double total2 = 0;
	for (int i = 0; i < 4; i++)
	{
		cout << a;
		for (int j = 0; j < 5; j++)
		{
			cout << right << setw(12) << fixed << setprecision(2) << matrix[i][j];
			total1 += matrix[i][j];
		}
		cout << right << setw(13) << fixed << setprecision(2) << total1 << endl;
		total1 = 0;
		a++;
	}
	cout << "\nTotal";
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
			total2 += matrix[j][i];
		if (i == 0)
			cout << right << setw(8) << fixed << setprecision(2) << total2;
		else
			cout << right << setw(12) << fixed << setprecision(2) << total2;
		
		total2 = 0;
	}
	return 0;
}