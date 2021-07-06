#include<iostream>
using namespace std;
int main()
{
    int a, i = 2;
    cout << "Please input an integer for listing all the primes less than the integer:  ";
    cin >> a;
    cout << "Primes less than " << a << " are ";
    for (int i = 2; i < a; i++)
    {
        if ((i % 2 != 0 || i / 2 == 1) && (i % 3 != 0 || i / 3 == 1) && (i % 5 != 0 || i / 5 == 1) && (i % 7 != 0 || i / 7 == 1))
        {
            cout << i << " ";
        }
    }
    return 0;
}
