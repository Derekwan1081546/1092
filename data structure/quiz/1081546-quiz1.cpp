#include <iostream>
#include <fstream>
#include<stack>
using namespace std;

void Path(int** maze, int mazeR, int mazeC, int  Row, int Col)
{
	int size = 1;
	stack<int> mystack;
	/*cout << mazeR <<" "<< mazeC << endl;
	for (int i = 0; i < mazeR + 2; i++)
	{
		for (int j = 0; j < mazeC + 2; j++)
		{
			cout << maze[i][j];
		}
		cout << endl;
	}*/
	
	int curX = Col + 1;
	int curY = Row + 1;
	mystack.push(maze[curY][curX]);
	while (!mystack.empty())
	{
		int tmp = mystack.top();
		mystack.pop();
		if (maze[curY + 1][curX] == tmp)
		{
			size++;
			mystack.push(maze[curY + 1][curX]);
			curY = curY + 1;
		}
		else if (maze[curY][curX + 1] == tmp)
		{
			size++;
			mystack.push(maze[curY][curX + 1]);
			curX = curX + 1;
		}
		/*else if (maze[curY - 1][curX] == tmp)
		{
			size++;
			mystack.push(maze[curY - 1][curX]);
			curY = curY - 1;
		}
		else if (maze[curY][curX - 1] == maze[curX][curY])
		{
			size++;
			mystack.push(maze[curY][curX - 1]);
			curX = curX - 1;
		}*/
		
	}
	
	
	
	cout << "Size is " << size << endl;

}

int main()
{
	int mazeRows, mazeCols;
	int Row = 0, Col = 0, Size = 0;
	fstream inputfile("maze.txt");
	inputfile >> mazeRows >> mazeCols;
	cout << "Input position:\n";
	cout << "Row: ";
	cin >> Row;
	cout << "Col: ";
	cin >> Col;

	int rows = mazeRows + 2;
	int cols = mazeCols + 2;

	int** maze = new int* [rows];
	for (int j = 0; j < cols; ++j)
		maze[j] = new int[cols];

	for (int j = 0; j < rows; ++j) {
		for (int i = 0; i < cols; ++i) {
			if ((j == 0) || (j == rows - 1) || (i == 0) || (i == cols - 1)) {
				maze[j][i] = -1;
			}
			else {
				inputfile >> maze[j][i];
			}
		}

	}
	Path(maze, mazeRows, mazeCols, Row, Col);

	


	return 0;
}