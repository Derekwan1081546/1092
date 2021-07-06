#include <iostream>
#include <fstream>
#include<stack>;
#include<vector>
using namespace std;

// 定義每一步x, y位移量
struct offsets
{
	int xShift, yShift;
};
// 8種移動方向
enum directions { N, NE, E, SE, S, SW, W, NW };//北 東北 東 東南 南 西南 西 西北
// 8個移動方向的x, y位移量
struct offsets mymove[8] = { {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1} };

// stack 的一個資料
struct Items {
	int x, y, dir;
};



// maze為padded過的陣列  高mazeR+2 寬為mazeC+2 
void Path(int** maze, int mazeR, int mazeC)
{
	cout << "mazeRows=" << mazeR << " mazeCols=" << mazeC << endl;

	cout << "Padded maze matrix:" << endl;
	for (int j = 0; j < mazeR + 2; ++j) {
		for (int i = 0; i < mazeC + 2; ++i) {
			cout << maze[j][i];
		}
		cout << endl;
	}
	cout << endl;



	int** mark = new int* [mazeR + 2];
	for (int j = 0; j < mazeR + 2; ++j)
		mark[j] = new int[mazeC + 2];

	for (int j = 0; j < mazeR + 2; ++j) {
		for (int i = 0; i < mazeC + 2; ++i) {
			mark[j][i] = 0;
		}

	}

	mark[1][1] = 1;
	stack<Items> mystack;
	vector<Items> vector;
	Items temp = { 1, 1, E };
	mystack.push(temp);
	vector.push_back(temp);
	while (!mystack.empty())
	{
		temp = mystack.top();
		mystack.pop();
		vector.pop_back();

		int curX = temp.x;
		int curY = temp.y;
		int direction = temp.dir;

		while (direction < 8)//總共8個方向
		{
			int nextX = curX + mymove[direction].xShift;
			int nextY = curY + mymove[direction].yShift;

			// 注意終點出口在 (mazeC + 1, mazeR + 1)
			if ((nextX == mazeC + 1) && (nextY == mazeR + 1)) {
				cout << "A path in maze is found:" << endl;
				cout << "(x, y,  dir)" << endl;

				// 列印路徑
				for (int j = 0; j < vector.size(); ++j)
				{
					cout << '(' << vector[j].x << ", " << vector[j].y << ", " << vector[j].dir - 1 << ')' << endl;
				}
				cout << "(" << mazeC << ", " << mazeR << ")" << endl;

				return;
			}
			if ((!maze[nextY][nextX]) && (!mark[nextY][nextX])) {
				mark[nextY][nextX] = 1;
				temp.x = curX;
				temp.y = curY;
				temp.dir = direction + 1;

				mystack.push(temp);
				vector.push_back(temp);

				curX = nextX;
				curY = nextY;
				direction = N;
			}
			else direction++;
		}
	}
	cout << "No path in maze." << endl;

}

int main()
{
	int mazeRows, mazeCols;
	fstream inputfile("maze.txt");
	inputfile >> mazeRows >> mazeCols; //讀進 高rows    寬cols

	int rows = mazeRows + 2;
	int cols = mazeCols + 2;

	// 建立 高rows+2 寬cols+2 陣列
	int** maze = new int* [rows];
	for (int j = 0; j < cols; ++j)
		maze[j] = new int[cols];

	// 讀取maze資料,外圍填1
	for (int j = 0; j < rows; ++j) {
		for (int i = 0; i < cols; ++i) {
			if ((j == 0) || (j == rows - 1) || (i == 0) || (i == cols - 1)) {
				maze[j][i] = 1;
			}
			else {
				inputfile >> maze[j][i];
			}
		}

	}

	Path(maze, mazeRows, mazeCols);
}