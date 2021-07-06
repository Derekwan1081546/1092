#include<iostream>
using namespace std;

int main()
{
    int a;
    cout << "Checking whether a year is leap year or not. Please input a year: ";
    cin >> a;
    if ((a % 4 == 0  && a % 100 != 0) || a % 400 == 0)
        cout << a << " is a leap year.\n";
    else
        cout << a << " is not a leap year.\n";
    return 0;
}