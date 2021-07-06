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
void kruskal(vector<Node> array, vector<bool> visited)
{
	int a = array.size(), b = 0;
	for (int i = 0; i < a; i++)
		cin >> array[i].start >> array[i].end >> array[i].length;
	sort(array.begin(), array.end(), compare);
	int weight = 0;
	for (int i = 0; i < a; i++)
	{
		if (!visited[array[i].start] || !visited[array[i].end])
		{
			if (b == 0)
			{
				if (weight == 0)
					weight = array[i].length;
				b++;
			}
			else
				weight *= array[i].length;
			visited[array[i].start] = true;
			visited[array[i].end] = true;
		}
	}
	weight %= 65537;
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
		vector<bool> visited(a);
		kruskal(array, visited);
	}
	return 0;
}