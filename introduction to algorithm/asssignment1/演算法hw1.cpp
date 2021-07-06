#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int lcs(string X, string Y)
{
    /*if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + lcs(X, Y, m - 1, n - 1);
    else
        return max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));*/
    int L[101][101];
    int m = X.size();
    int n = Y.size();
    int maxl = 0;//³Ì²×ªð¦^ªºlcs
    for (int i = 0; i <= m; i++) 
    {
        for (int j = 0; j <= n; j++) 
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            maxl = max(maxl, L[i][j]);
        }
    }
    return maxl;
}

int main()
{
    string a, b;
    while (cin>>a>>b)
    {
        cout << lcs(a, b) << '\n';
    }
    return 0;
}
