#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	for (; true;)
	{
		srand(time(NULL));
		int a;
		int b = rand() % 1000 + 1;
		char c;
		cout << "I have a number between 1 and 1000.\nCan you guess my number?\nPlease type your first guess.\n?";
		cin >> a;
		for (; a != b;)
		{
			a > b ? cout << "Too high. Try again\n?" : cout << "Too low. Try again\n?";
			cin >> a;
		}
		cout << "\nExcellent! You guessed the number!\nWould you like to play again(y or n)? ";
		cin >> c;
		if (c == 'n')
			break;
	}
	return 0;
}