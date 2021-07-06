#include<iostream>
using namespace std;

int main()
{
    cout << "Please input an integer for listing a rhombus with n asterisks in each side \n: ";
    int n, k, c, space;
    cin >> n;
    space = n - 1;
    k = 1;
    while (k <= n)
    {
        c = 1;
        while (c <= space)
        {
            cout << " ";
            c++;
        }
        space--;
        c = 1;
        while (c <= 2 * k - 1)
        {
            cout << "*";
            c++;
        }
        cout << endl;
        k++;
    }
    space = 1;
    k = 1;
    while (k <= n)
    {
        c = 1;
        while (c <= space)
        {
            cout << " ";
            c++;
        }
        space++;
        c = 1;
        while (c <= 2 * (n - k) - 1)
        {
            cout << "*";
            c++;
        }
        cout << endl;
        k++;
    }
    return 0;
}