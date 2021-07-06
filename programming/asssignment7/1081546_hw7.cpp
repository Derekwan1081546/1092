#include<iostream> 
#include<cstring>
#include<vector>
using namespace std;
#pragma warning( disable : 4996 )
void print(vector<char*> str)
{
    cout << "\nThe tokens in sorted order are:\n";
    for (int i = 0; i < str.size(); i++)
        cout << str[i] << " ";
    cout << endl;
}
void bubbleSort(vector<char*> str)
{
    int n = str.size();
    for (int i = n-1; i >0; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (strcmp(str[j], str[j + 1]) > 0)
            {
                swap(str[j], str[j + 1]);
            }
        }
    }
    print(str);
}
void Sorting(char str[])
{
    vector<char*> str1;
    char* token = strtok(str, " ");
    while (token != NULL)
    {
        str1.push_back(token);
        token = strtok(NULL, " ");
    }
    bubbleSort(str1);
}
int main()
{
    const int SIZE = 80;
    char str[SIZE];
    cout << "Enter a line of text:\n";
    cin.getline(str, SIZE);
    Sorting(str);
    return 0;
}