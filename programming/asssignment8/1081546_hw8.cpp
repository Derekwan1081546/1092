#include<iostream> 
#include<cstring>
#include<list>
using namespace std;
void Listalldata(list<int> array)
{
    if (array.empty())
        cout << "The Linked List is empty!\n\n";
    else
    {
        cout << "The data of the Linked List: ";
        list<int>::iterator i;
        for (i = array.begin(); i != array.end(); ++i)
            cout << *i << " ";
        cout << endl << endl;
    }
}
int main(int argc, char* argv[])
{
    int a;
    int count = 1;
    list<int> array;
    list<int>::iterator i;
    cout << "Enter a choice:\n";
    cout << "1 List all data in the Linked List\n2 Add data into the end of the Linked List\n3 Insert data into specific location of the Linked List\n4 Delete data of specific location of the Linked List\n5 End program\n? ";
    while (cin >> a)
    {
        if (a == 5)
        {
            cout << "Bye!\n";
            break;
        }
        switch (a)
        {
        case 1:
            Listalldata(array);
            break;
        case 2:
            int b;
            cout << "Please input the data that you want to add into the Linked List:\n";
            cin >> b;
            array.push_back(b);
            Listalldata(array);
            break;
        case 3:
            int data, location;
            cout << "Please input the data and the location that you want to insert into the Linked List:\n";
            cin >> data >> location;
            count = 1;
            for (i = array.begin(); i != array.end(); ++i)
            {
                if (count == location)
                    break;
                else
                    count++;
            }
            array.insert(i, data);
            Listalldata(array);
            break;
        case 4:
            int c;
            cout << "Please input the location of the data that you want to delete from the Linked List:\n";
            cin >> c;
            //array.remove(c);
            count = 1;
            for (i = array.begin(); i != array.end(); ++i)
            {
                if (count == c)
                    break;
                else
                    count++;
            }
            array.erase(i);
            Listalldata(array);
            break;
        default:
            break;
        }
        cout << "Enter a choice:\n";
        cout << "1 List all data in the Linked List\n2 Add data into the end of the Linked List\n3 Insert data into specific location of the Linked List\n4 Delete data of specific location of the Linked List\n5 End program\n? ";
    }
    return 0;
}