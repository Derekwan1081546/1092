#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node
{
	int start;
	int end;
	int length;
};
bool compare(Node a, Node b)
{
	return a.length < b.length;
}
int find(vector<int> visited, int x)
{
	int a = x;
	while (x != visited[x])
	{
		x = visited[x];
	}
	int z;
	while (a != visited[a])
	{
		z = a;
		a = visited[a];
		visited[z] = x;
	}
	return x;
}
void kruskal(vector<Node> array, vector<int> visited)
{
	int a = array.size(), b = 0, c = visited.size();
	for (int i = 0; i < a; i++)
		cin >> array[i].start >> array[i].end >> array[i].length;
	for (int i = 0; i < c; ++i)
	{
		visited[i] = i;
	}
	sort(array.begin(), array.end(), compare);
	int weight = 0;
	int fastart, faend;
	for (int i = 0; i < a; ++i)
	{
		fastart = find(visited, array[i].start);
		faend = find(visited, array[i].end);
		if (fastart != faend)
		{
			visited[fastart] = faend;
			if (b == 0)
			{
				if (weight == 0)
					weight = array[i].length;
				b++;
			}
			else
			{
				weight *= array[i].length;
				weight %= 65537;
			}
		}
	}
	cout << weight << endl;
}
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		if (a == 0 && b == 0)
			break;
		vector<Node> array(b);
		vector<int> visited(a);
		kruskal(array, visited);
	}
	return 0;
}