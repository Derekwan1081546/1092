#include<iostream>
using namespace std;
struct poly
{
	double coef;
	double pow;
	poly* next;
};
class add
{
	poly* poly1, * poly2, * poly3, * poly4;
public:
	add() { poly1 = poly2 = poly3 = poly4 = NULL; }
	void addpoly();
	void display();
};
void add::addpoly()
{
	int p;
	cout << "enter the highest degree:";
	cin >> p;
	poly* new1 = NULL;
	poly* end = NULL;
	cout << "first poly\n";
	for (int i = p; i >= 0; i--)
	{
		new1 = new poly;
		new1->pow = p;
		cout << "degree" << i << ":";
		cin >> new1->coef;
		new1->next = NULL;
		if (poly1 == NULL)
			poly1 = new1;
		else
			end->next = new1;
		end = new1;
	}
	cout << "second poly\n";
	end = NULL;
	for (int i = p; i >= 0; i--)
	{
		new1 = new poly;
		new1->pow = p;
		cout << "degree" << i << ":";
		cin >> new1->coef;
		new1->next = NULL;
		if (poly2 == NULL)
			poly2 = new1;
		else
			end->next = new1;
		end = new1;
	}
	poly* new2 = NULL;
	poly* end2 = NULL;
	end = NULL;
	while (poly1 != NULL && poly2 != NULL)
	{
		if (poly1->pow == poly2->pow)
		{
			new1 = new poly;
			new1->pow = p--;
			if (poly1->coef >= poly2->coef)
				new1->coef = poly1->coef;
			else if(poly1->coef <= poly2->coef)
				new1->coef = poly2->coef;
			//new1->coef = poly1->coef + poly2->coef;
			new1->next = NULL;
			new2 = new poly;
			new2->pow = new1->pow;
			new2->coef = poly1->coef - poly2->coef;
			new2->next = NULL;
			if (poly3 == NULL)
				poly3 = new1;
			else
				end->next = new1;
			end = new1;
			if (poly4 == NULL)
				poly4 = new2;
			else
				end2->next = new2;
			end2 = new2;
		}
		poly1 = poly1->next;
		poly2 = poly2->next;
	}
}
void add::display()
{
	poly* p3 = poly3, * p4 = poly4;
	cout << "output:";
	cout << p3->coef << "x^" << p3->pow;
	p3 = p3->next;
	while (p3 != NULL)
	{
		if (p3->coef >= 0)
		{
			cout << "+" << p3->coef << "x^" << p3->pow;
		}

		//cout << "+" << p3->coef << "x^" << p3->pow;
		p3 = p3->next;
	}
	cout << endl;
	/*cout << "subtraction:";
	cout << p4->coef << "x^" << p4->pow;
	p4 = p4->next;
	while (p4 != NULL)
	{
		if (p4->coef >= 0)
		{
			cout << "+" << p4->coef << "x^" << p4->pow;
		}
		else
		{
			cout << p4->coef << "x^" << p4->pow;
		}
		p4 = p4->next;
	}*/
}
int main()
{
	add a;
	a.addpoly();
	a.display();

}