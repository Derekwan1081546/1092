#include<iostream>
using namespace std;
char matrix[20][20];
int direction = 0;//0為朝右 1為朝左
int dirright = 0;// 0右 1下 2左 3上
int dirleft = 0;// 0左 1下 2右 3上
int row = 0;
int col = 0;
int pos = 0;//0為朝上 1為朝下
int rowfinal = 0;//當前列位置
int colfinal = 0;//當前行位置
void forward(int step)
{
	if (pos == 0)//比朝上不會印出星號
	{
		if (direction == 0)//右轉
		{
			if (col != 0 && row != 0)
			{
				if (dirleft == 0)
					dirright = 3;
				else if (dirleft == 1)
					dirright = 2;
				else if (dirleft == 2)
					dirright = 1;
				else if (dirleft == 3)
					dirright = 0;
			}
			if (dirright == 0)//右
			{
				row = rowfinal;
				int c = colfinal;
				for (int i = 0; i < step; i++)
				{
					c += 1;
				}
				colfinal = c;
			}
			else if (dirright == 1)//下
			{
				col = colfinal;
				int r = rowfinal;
				for (int i = 0; i < step; i++)
				{
					r += 1;
				}
				rowfinal = r;
			}
			else if (dirright == 2)//左
			{
				row = rowfinal;
				int c = colfinal;
				for (int i = 0; i < step; i++)
				{
					c -= 1;
				}
				colfinal = c;
			}
			else if (dirright == 3)//上
			{
				col = colfinal;
				int r = rowfinal;
				for (int i = 0; i < step; i++)
				{
					r -= 1;
				}
				rowfinal = r;
			}
		}
		else if (direction == 1)//左轉
		{
			if (dirright == 0)
				dirleft = 3;
			else if (dirright == 1)
				dirleft = 2;
			else if (dirright == 2)
				dirleft = 1;
			else if (dirright == 3)
				dirleft = 0;
			if (dirleft == 0)//左
			{
				row = rowfinal;
				int c = colfinal;
				for (int i = 0; i < step; i++)
				{
					c -= 1;
				}
				colfinal = c;
			}
			else if (dirleft == 1)//下
			{
				col = colfinal;
				int r = rowfinal;
				for (int i = 0; i < step; i++)
				{
					r += 1;
				}
				rowfinal = r;
			}
			else if (dirleft == 2)//右
			{
				row = rowfinal;
				int c = colfinal;
				for (int i = 0; i < step; i++)
				{
					c += 1;
				}
				colfinal = c;
			}
			else if (dirleft == 3)//上
			{
				col = colfinal;
				int r = rowfinal;
				for (int i = 0; i < step; i++)
				{
					r -= 1;
				}
				rowfinal = r;
			}
		}
	}
	else//比朝下會印出星號
	{
		if (direction == 0)//右轉
		{
			if (col != 0 && row != 0)
			{
				if (dirleft == 0)
					dirright = 3;
				else if (dirleft == 1)
					dirright = 2;
				else if (dirleft == 2)
					dirright = 1;
				else if (dirleft == 3)
					dirright = 0;
			}
			if (dirright == 0)//右
			{
				row = rowfinal;
				int c = colfinal;
				for (int i = 0; i < step; i++)
				{
					matrix[row][c] = '*';
					c += 1;
				}
				colfinal = c;
			}
			else if (dirright == 1)//下
			{
				col = colfinal;
				int r = rowfinal;
				for (int i = 0; i < step; i++)
				{
					matrix[r][col] = '*';
					r += 1;
				}
				rowfinal = r;
			}
			else if (dirright == 2)//左
			{
				row = rowfinal;
				int c = colfinal;
				for (int i = 0; i < step; i++)
				{
					matrix[row][c] = '*';
					c -= 1;
				}
				colfinal = c;
			}
			else if (dirright == 3)//上
			{
				col = colfinal;
				int r = rowfinal;
				for (int i = 0; i < step; i++)
				{
					matrix[r][col] = '*';
					r -= 1;
				}
				rowfinal = r;
			}

		}
		else if (direction == 1)//左轉
		{
			if (dirright == 0)
				dirleft = 3;
			else if(dirright == 1)
				dirleft = 2;
			else if (dirright == 2)
				dirleft = 1;
			else if (dirright == 3)
				dirleft = 0;
			if (dirleft == 0)//左
			{
				row = rowfinal;
				int c = colfinal;
				for (int i = 0; i < step; i++)
				{
					matrix[row][c] = '*';
					c -= 1;
				}
				colfinal = c;
			}
			else if(dirleft == 1)//下
			{
				col = colfinal;
				int r = rowfinal;
				for (int i = 0; i < step; i++)
				{
					matrix[r][col] = '*';
					r += 1;
				}
				rowfinal = r;
			}
			else if (dirleft == 2)//右
			{
				row = rowfinal;
				int c = colfinal;
				for (int i = 0; i < step; i++)
				{
					matrix[row][c] = '*';
					c += 1;
				}
				colfinal = c;
			}
			else if (dirleft == 3)//上
			{
				col = colfinal;
				int r = rowfinal;
				for (int i = 0; i < step; i++)
				{
					matrix[r][col] = '*';
					r -= 1;
				}
				rowfinal = r;
			}
			
		}
	}
}
void print()
{
	cout << "The drawing is:\n\n";
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (matrix[i][j] == NULL) cout << " ";
			else cout << "*";
		}
		cout << endl;
	}
	cout << endl;
}
int main()
{
	int a;
	int step = 0;//走幾步
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			matrix[i][j] = NULL;
	cout << "Enter command (9 to end input): ";
	cin >> a;
	while (a != 9)
	{
		switch (a)
		{
		case 1:
			pos = 0;
			break;
		case 2:
			pos = 1;
			break;
		case 3:
			direction = 0;
			dirright++;
			dirright %= 4;
			break;
		case 4:
			direction = 1;
			dirleft++;
			dirleft %= 4;
			break;
		case 5:
			cin >> step;
			forward(step);
			break;
		case 6:
			print();
			break;
		}
		cout << "Enter command (9 to end input): ";
		cin >> a;
	}
	return 0;
}