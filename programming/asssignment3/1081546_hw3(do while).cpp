#include<iostream>
using namespace std;

int main()
{
    cout << "Please input an integer for listing a rhombus with n asterisks in each side \n: ";
    int n, k, c, space;
    cin >> n;
    space = n - 1;
    k = 1;
    do{
        c = 1;
        do{
            cout << " ";
            c++;
        } while (c <= space);
        space--;
        c = 1;
        do{
            cout << "*";
            c++;
        } while (c <= 2 * k - 1);
        cout << endl;
        k++;
    } while (k <= n);
    space = 1;
    k = 1;
    do{
        c = 1;
        do{
            cout << " ";
            c++;
        } while (c <= space);
        space++;
        c = 1;
        do{
            cout << "*";
            c++;
        } while (c <= 2 * (n - k) - 1);
        cout << endl;
        k++;
    } while (k <= n);
    return 0;
}