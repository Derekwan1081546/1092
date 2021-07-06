#include<iostream>
using namespace std;

int main()
{
    cout << "Please input an integer for listing a rhombus with n asterisks in each side \n: ";
    int n, k, c, space;
    cin >> n;
    space = n - 1;
    for (k = 1; k <= n; k++)
    {
        for (c = 1; c <= space; c++)
        {
            cout << " ";
        }
        space--;
        for (c = 1; c <= 2 * k - 1; c++)
        {
            cout << "*";
        }
        cout << endl;
    }
    space = 1;
    for (k = 1; k <= n; k++)
    {
        for (c = 1; c <= space; c++)
        {
            cout << " ";
        }
        space++;
        for (c = 1; c <= 2 * (n - k) - 1; c++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}