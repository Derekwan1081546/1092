#include <iostream> 
#include <iomanip> 
#include <fstream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#define maxnumber 100
using namespace std;
#pragma warning( disable : 4996 )
void initializeFile();
void loadFile();
void saveFile();
void listfruit(void);
void updateRecord(void);
void insertRecord(void);
void deleteRecord(void);
void sortfruit(void);
int instructions();
int idArray[maxnumber];
int recordArray[maxnumber];
char nameArray[maxnumber][15];
char quantityArray[maxnumber][5];
double priceArray[maxnumber];
int counter;
int main()
{
	int choice;
	ifstream file("fruit.dat", ios::in);

	if (!file)
	{
		cout << "There is no file: fruit.dat!\n";
		cout << "New file is initialized!\n";
		initializeFile();
	}
	else
	{
		file.close();
		loadFile();
		cout << "Data of fruit.data is loaded!\n";
	}
	while ((choice = instructions()) != 5)
	{
		switch (choice)
		{
		case 1:
			listfruit();
			break;
		case 2:
			updateRecord();
			break;
		case 3:
			insertRecord();
			break;
		case 4:
			deleteRecord();
			break;
		default:
			break;
		}
	}
	cout << "Bye.\n";
	saveFile();
}
void initializeFile()
{
	ofstream fRef("fruit.dat", ios::out | ios::binary);
	counter = 0;
	int id = -1;
	int record = -1;
	char quantity[5] = "";
	double price = 0.0;
	char name[15] = "";

	for (int i = 0; i < maxnumber; i++)
	{
		fRef.write(reinterpret_cast<char*>(&id), sizeof(id));
		fRef.write(reinterpret_cast<char*>(&record), sizeof(record));
		fRef.write(reinterpret_cast<char*>(&name), sizeof(name));
		fRef.write(reinterpret_cast<char*>(&quantity), sizeof(quantity));
		fRef.write(reinterpret_cast<char*>(&price), sizeof(price));
		idArray[i] = id;
		recordArray[i] = record;
		strcpy_s(nameArray[i], name);
		strcpy_s(quantityArray[i], quantity);
		priceArray[i] = price;
	}
	fRef.close();
}
void loadFile()
{
	int id;
	int record;
	char name[15];
	char quantity[5];
	double price;
	counter = 0;
	fstream fRef("fruit.dat", ios::in);

	for (int i = 0; i < maxnumber && !fRef.eof(); i++)
	{
		fRef.read(reinterpret_cast<char*>(&id), sizeof(id));
		fRef.read(reinterpret_cast<char*>(&record), sizeof(record));
		fRef.read(reinterpret_cast<char*>(&name), sizeof(name));
		fRef.read(reinterpret_cast<char*>(&quantity), sizeof(quantity));
		fRef.read(reinterpret_cast<char*>(&price), sizeof(price));

		idArray[i] = id;
		recordArray[i] = record;
		strcpy_s(nameArray[i], name);
		strcpy_s(quantityArray[i], quantity);
		priceArray[i] = price;
		if (id > 0 && id <= maxnumber)
			counter++;
	}
	fRef.close();
}
void saveFile()
{
	//cout << "data save!\n";
	fstream fRef("fruit.dat", ios::out | ios::binary);
	for (int i = 0; i < maxnumber; i++)
	{
		fRef.write(reinterpret_cast<char*>(&idArray[i]), sizeof(idArray[i]));
		fRef.write(reinterpret_cast<char*>(&recordArray[i]), sizeof(recordArray[i]));
		fRef.write(reinterpret_cast<char*>(&nameArray[i]), sizeof(nameArray[i]));
		fRef.write(reinterpret_cast<char*>(&quantityArray[i]), sizeof(quantityArray[i]));
		fRef.write(reinterpret_cast<char*>(&priceArray[i]), sizeof(priceArray[i]));
	}
	fRef.close();
}
int instructions()
{
	int choice;
	cout << "\nEnter a choice:\n1  List all fruits." << "\n2  Update record.\n3  Insert record."
		<< "\n4  Delete record.\n5  End program.\n";
	do
	{
		cout << "? ";
		cin >> choice;
	} while (choice < 1 || choice > 5);
	return choice;
}

void listfruit(void)
{  // display
	cout << setw(7) << "\nRecord#" << "    " << left << setw(18) << "Fruit name" << left
		 << setw(13) << "Quantity" << left << setw(8) << "Price" << endl;

	for (int i = 0; i < maxnumber; i++)
	{
		if (idArray[i] > 0 && idArray[i] <= maxnumber)
		{
			cout << fixed << showpoint;
			cout << left << setw(7) << recordArray[i] << "    "
				<< left << setw(18) << nameArray[i] << left
				<< setw(13) << quantityArray[i] << right << setw(5) << fixed << setprecision(2) << priceArray[i] << '\n';
		}
	}
}
void updateRecord(void)
{
	int id;
	int record = 0;
	char name[15];
	char quantity[5];
	double price;
	int i = 0;
	int c;

	cout << "Enter the fruit number for update: ";
	cin >> c;
	while (i < maxnumber)
	{
		if (c == recordArray[i])
		{
			record = recordArray[i];
			break;
		}
		i++;
	}
	// read information
	// display phone information if id is not -1
	id = idArray[i];
	
	if (c == record)
	{
		cout << setw(7) << "Record#" << "    " << left << setw(18) << "Fruit name" << left
			<< setw(13) << "Quantity" << left << setw(8) << "Price" << endl;
		cout << fixed << showpoint;
		cout << setw(7) << recordArray[id - 1] << "    " << left << setw(18) << nameArray[id - 1]
			<< left << setw(13) << quantityArray[id - 1] << right << setw(5) << fixed << setprecision(2) << priceArray[id - 1] << '\n';

		cout << "Enter the fruit name: ";// ask user for name
		cin.ignore(); // ignore the newline on the input stream
		cin.getline(name, 15, '\n');

		cout << "Enter quantity and price: "; // ask user for quantity and price
		cin.getline(quantity, 5, ' ');
		cin >> price;

		strcpy_s(nameArray[id - 1], name);
		strcpy_s(quantityArray[id - 1], quantity);
		priceArray[id - 1] = price;

		cout << "Record updated.\n";
		sortfruit();
	}
	else
		cerr << "Cannot update. The record is empty.\n";
}

void insertRecord(void)
{
	int id;
	int fruitnumber;
	int record = 0;
	char name[15];
	char quantity[5];
	double price;
	
	int i = 0;
	// as long as record is empty get information from user
	while ((idArray[i] != -1) && (i < maxnumber))
		i++;
	if (i <= maxnumber)
	{
		cout << "Enter the fruit number for insertion: ";
		cin >> fruitnumber;
		for (int y = 0; y < i; y++)
		{
			if (fruitnumber == recordArray[y])
			{
				record = recordArray[y];
				break;
			}
		}
		if (record != fruitnumber)
		{
			record = fruitnumber;
			cout << "Enter the fruit name: ";// ask user for name
			cin.ignore(); // ignore 
			cin.getline(name, 15, '\n');
			cout << "Enter quantity and price: ";
			cin.getline(quantity, 5, ' ');
			cin >> price;
			idArray[i] = i + 1;
			recordArray[i] = record;
			strcpy_s(nameArray[i], name);
			strcpy_s(quantityArray[i], quantity);
			priceArray[i] = price;
			counter++;
			cout << "Record inserted.\n";
		}
		else
			cout << "Cannot insert. The record contains information.\n";
		sortfruit();
	}
	else
		cerr << "Cannot insert. The file is full.\n";
}

void deleteRecord(void)
{
	int c;
	int i = 0;
	int id;
	int record = 0;
	// get fruit user wants to delete
	cout << "Enter the fruit number for deletion: ";
	cin >> c;
	while (i < maxnumber)
	{
		if (c == recordArray[i])
		{
			record = recordArray[i];
			break;
		}
		i++;
	}
	id = idArray[i];
	if (c == record)
	{
		for (int j = id - 1; j < counter ; j++)
		{
			idArray[j + 1] = -1;
			recordArray[j] = recordArray[j + 1];
			strcpy(nameArray[j], nameArray[j + 1]);
			strcpy(quantityArray[j], quantityArray[j + 1]);
			priceArray[j] = priceArray[j + 1];
		}
		cout << "Record deleted.\n";
		sortfruit();
	}
	else
	{
		cerr << "Cannot delete. The record is empty.\n";
	}
}
void sortfruit(void)
{
	int temp = 0;
	double t;
	char hold[15];
	//Bubble sort
	for (int i = 0; i < counter - 1; i++)
	{
		for (int j = 0; j < counter - 1; j++)
		{
			if (recordArray[j + 1] != -1)
			{
				if (recordArray[j] > recordArray[j + 1])
				{
					temp = recordArray[j];
					recordArray[j] = recordArray[j + 1];
					recordArray[j + 1] = temp;

					strcpy_s(hold, nameArray[j]);
					strcpy_s(nameArray[j], nameArray[j + 1]);
					strcpy_s(nameArray[j + 1], hold);

					strcpy_s(hold, quantityArray[j]);
					strcpy_s(quantityArray[j], quantityArray[j + 1]);
					strcpy_s(quantityArray[j + 1], hold);

					t = priceArray[j];
					priceArray[j] = priceArray[j + 1];
					priceArray[j + 1] = t;
				}
			}
		}
	}
	//cout << "fruit is sorted by the record number.\n";
	saveFile();
}

//version 1.
//// function prototypes
//void initializeFile();
//void listfruit(void);
//void updateRecord(void);
//void insertRecord(void);
//void deleteRecord(void);
//void sortfruit(void);
//int instructions();
//
//int main()
//{
//	int choice;
//	ifstream file("fruit.dat", ios::in);
//
//	if (!file)
//	{
//		cout << "There is no file: Phones.dat!\n";
//		cout << "New file is initialized!\n";
//		initializeFile();
//	} // end if
//	else
//	{
//		cout << "Data of fruit.data is loaded!\n";
//		file.close();
//	}
//
//	while ((choice = instructions()) != 5)
//	{
//		if (choice == 1)
//			listfruit();
//		else if (choice == 2)
//			updateRecord();
//		else if (choice == 3)
//			insertRecord();
//		else if (choice == 4)
//			deleteRecord();
//	}
//	cout << "Bye.\n";
//	return 0;
//} 
//
//void initializeFile()
//{
//	ofstream fRef("fruit.dat", ios::out | ios::binary);
//	int id = -1;
//	int record = -1;
//	char name[10] = "";
//	char quantity[5] = "";
//	double price = 0.0;
//	for (int i = 0; i < maxnumber; i++)
//	{
//		fRef.write(reinterpret_cast<char*>(&id), sizeof(id));
//		fRef.write(reinterpret_cast<char*>(&record), sizeof(record));
//		fRef.write(reinterpret_cast<char*>(&name), sizeof(name));
//		fRef.write(reinterpret_cast<char*>(&quantity), sizeof(quantity));
//		fRef.write(reinterpret_cast<char*>(&price), sizeof(price));
//	}
//	fRef.close();
//}
//int instructions()
//{
//	int choice;
//	// ask user to enter a choice
//	cout << "\nEnter a choice:\n1  List all phones." << "\n2  Update phone.\n3  Insert phone."
//		<< "\n4  Delete phone.\n5  End program.\n";
//	// ask user for choice until a valid choice is entered
//	do
//	{
//		cout << "? ";
//		cin >> choice;
//	} while (choice < 1 || choice > 5);
//	return choice; // return user choice
//}
//void listfruit(void)
//{
//	ifstream fRef("fruit.dat");
//	int id;
//	int record;
//	char name[10];
//	char quantity[5];
//	double price;
//	// display
//	cout << setw(7) << "Record#" << "    " << left << setw(18) << "Fruit name" << left
//		 << setw(13) << "Quantity" << left << setw(8) << "Price" << endl;
//	for (int count = 1; count <= maxnumber && !fRef.eof(); count++)
//	{    	// set file position pointer and begin reading
//		fRef.read(reinterpret_cast<char*>(&id), sizeof(id));
//		fRef.read(reinterpret_cast<char*>(&record), sizeof(record));
//		fRef.read(reinterpret_cast<char*>(&name), sizeof(name));
//		fRef.read(reinterpret_cast<char*>(&quantity), sizeof(quantity));
//		fRef.read(reinterpret_cast<char*>(&price), sizeof(price));
//
//		// if id is valid, display phone information
//		if (id > 0 && id <= maxnumber)
//		{
//			cout << left << setw(7) << record << "    "
//				 << left << setw(18) << name << left
//				 << setw(13) << quantity << left << setw(8) << fixed << setprecision(2) << price << '\n';
//		} 
//	}
//	fRef.close();
//}
//void updateRecord(void)
//{
//	fstream fRef("fruit.dat", ios::out | ios::in);
//	int id;
//	int record;
//	char name[10];
//	char quantity[5];
//	double price;
//	int count = 1;
//	int c;
//	cout << "Enter the fruit number for update: ";
//	cin >> c;
//	while (count < maxnumber)
//	{
//		fRef.seekg((count - 1) * (sizeof(id) + sizeof(record) + sizeof(name) + sizeof(quantity) + sizeof(price)));
//		fRef.read(reinterpret_cast<char*>(&id), sizeof(id));
//		fRef.read(reinterpret_cast<char*>(&record), sizeof(record));
//		fRef.read(reinterpret_cast<char*>(&name), sizeof(name));
//		fRef.read(reinterpret_cast<char*>(&quantity), sizeof(quantity));
//		fRef.read(reinterpret_cast<char*>(&price), sizeof(price));
//		if (c == record)
//			break;
//		count++;
//	}
//	if (c ==record )
//	{
//		cout << setw(7) << "Record#" << "    " << left << setw(18) << "Fruit name" << left
//			<< setw(13) << "Quantity" << left << setw(8) << "Price" << endl;
//
//		cout << fixed << showpoint;
//		cout << left << setw(7) << record << "    "
//			<< left << setw(18) << name << left
//			<< setw(13) << quantity << left << setw(8) << price << '\n';
//
//		cout << "Enter the fruit name: ";// ask user for name
//		cin.ignore(); // ignore the newline on the input stream
//		cin.getline(name, 15, '\n');
//
//		cout << "Enter quantity and price: "; // ask user for quantity and price
//		cin.getline(quantity, 5, ' ');
//
//		cin >> price;
//
//		fRef.seekp((count - 1) * (sizeof(id) + sizeof(record) + sizeof(name) + sizeof(quantity) + sizeof(price)));
//		fRef.write(reinterpret_cast<char*>(&count), sizeof(count));
//		fRef.write(reinterpret_cast<char*>(&record), sizeof(record));
//		fRef.write(reinterpret_cast<char*>(&name), sizeof(name));
//		fRef.write(reinterpret_cast<char*>(&quantity), sizeof(quantity));
//		fRef.write(reinterpret_cast<char*>(&price), sizeof(price));
//
//		cout << "Record updated.\n";
//		fRef.close();
//		//sortfruit();
//	}
//	else
//	{
//		cerr << "Cannot update. The record is empty.\n";
//		fRef.close();
//	}
//} 
//void insertRecord(void)
//{
//	fstream fRef("fruit.dat", ios::out | ios::in);
//	int id;
//	
//	int record;
//	char quantity[5];
//	double price;
//	//char price[4];
//	char name[10];
//	int count = 1;
//
//	fRef.read(reinterpret_cast<char*>(&id), sizeof(id));
//
//	while ((id != -1) && (count < maxnumber))
//	{
//		count++;
//		fRef.seekg((count - 1) * (sizeof(id) + sizeof(record) + sizeof(name) + sizeof(quantity) + sizeof(price)));
//		fRef.read(reinterpret_cast<char*>(&id), sizeof(id));
//	}
//	if (count <= maxnumber)
//	{
//		int i = 1;
//		int c;
//		cout << "Enter the fruit number for insertion: ";
//		cin >> c;
//		while (i < maxnumber)
//		{
//			fRef.seekg((i - 1) * (sizeof(id) + sizeof(record) + sizeof(name) + sizeof(quantity) + sizeof(price)));
//			fRef.read(reinterpret_cast<char*>(&id), sizeof(id));
//			fRef.read(reinterpret_cast<char*>(&record), sizeof(record));
//			if (c == record)
//				break;
//			i++;
//		}
//
//		if (c != record)
//		{
//			record = c;
//			cout << "Enter the fruit name: ";// ask user for name
//			cin.ignore(); // ignore 
//			cin.getline(name, 15, '\n');
//			cout << "Enter quantity and price: ";
//			cin.getline(quantity, 5, ' ');
//
//			cin >> price;
//
//			fRef.seekp((count - 1) * (sizeof(id) + sizeof(record) + sizeof(name) + sizeof(quantity) + sizeof(price)));
//
//			fRef.write(reinterpret_cast<char*>(&count), sizeof(count));
//			fRef.write(reinterpret_cast<char*>(&record), sizeof(record));
//			fRef.write(reinterpret_cast<char*>(&name), sizeof(name));
//			fRef.write(reinterpret_cast<char*>(&quantity), sizeof(quantity));
//			fRef.write(reinterpret_cast<char*>(&price), sizeof(price));
//			cout << "Record inserted.\n";
//			fRef.close();
//		}
//		else
//			cout << "Cannot insert. The record contains information.\n";
//		
//		sortfruit();
//	}
//	else
//	{
//		cerr << "Cannot insert. The file is full.\n";
//		fRef.close();
//	}
//}
//void deleteRecord(void)
//{
//	fstream fRef("fruit.dat", ios::out | ios::in);
//	int id;
//	int record;
//	char quantity[5];
//	double price;
//	//char price[4];
//	char name[10];
//	int count = 1;
//	int c;
//	cout << "Enter the fruit number for deletion: ";
//	cin >> c;
//	while (count < maxnumber)
//	{
//		fRef.seekg((count - 1) * (sizeof(id) + sizeof(record) + sizeof(name) + sizeof(quantity) + sizeof(price)));
//		fRef.read(reinterpret_cast<char*>(&id), sizeof(id));
//		fRef.read(reinterpret_cast<char*>(&record), sizeof(record));
//		fRef.read(reinterpret_cast<char*>(&name), sizeof(name));
//		fRef.read(reinterpret_cast<char*>(&quantity), sizeof(quantity));
//		fRef.read(reinterpret_cast<char*>(&price), sizeof(price));
//		if (c == record)
//			break;
//		count++;
//	}
//	if (c == record)
//	{
//		fRef.seekp((count - 1) * (sizeof(id) + sizeof(record) + sizeof(name) + sizeof(quantity) + sizeof(price)));
//		id = -1;
//		record = -1;
//		strcpy(name, "");
//		strcpy(quantity, "");
//		price = -1;
//		fRef.write(reinterpret_cast<char*>(&id), sizeof(id));
//		fRef.write(reinterpret_cast<char*>(&record), sizeof(record));
//		fRef.write(reinterpret_cast<char*>(&name), sizeof(name));
//		fRef.write(reinterpret_cast<char*>(&quantity), sizeof(quantity));
//		fRef.write(reinterpret_cast<char*>(&price), sizeof(price));
//		cout << "Phone deleted.\n";
//		fRef.close();
//		//sortfruit();
//	}
//	else
//	{
//		cerr << "Cannot delete. The record is empty.\n";
//		fRef.close();
//	}
//}
//void sortfruit(void)
//{
//	fstream fRef("fruit.dat", ios::out | ios::in);
//	int id;
//	int record;
//	char quantity[5];
//	double price;
//	//char price[4];
//	char hold[15];
//	char hold2;
//	char name[15];
//	char idArray[maxnumber];
//	char recordArray[maxnumber];
//	char nameArray[maxnumber][15];
//	char quantityArray[maxnumber][5];
//	char priceArray[maxnumber];
//	int n = 0;
//	for (int count = 1; count <= maxnumber && !fRef.eof(); count++)
//	{   // set file position pointer and begin reading
//		fRef.read(reinterpret_cast<char*>(&id), sizeof(id));
//		fRef.read(reinterpret_cast<char*>(&record), sizeof(record));
//		fRef.read(reinterpret_cast<char*>(&name), sizeof(name));
//		fRef.read(reinterpret_cast<char*>(&quantity), sizeof(quantity));
//		fRef.read(reinterpret_cast<char*>(&price), sizeof(price));
//		if (record > 0 && record <= maxnumber)
//		{
//			idArray[n] = id;
//			recordArray[n] = record;
//			strcpy(nameArray[n], name);
//			strcpy(quantityArray[n], quantity);
//			priceArray[n] = price;
//			n++;
//		}
//	}
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = 0; j < n - 1; j++)
//		{
//			if (recordArray[j] < recordArray[j + 1])
//			{
//				hold2 = recordArray[j];
//				recordArray[j] = recordArray[j + 1];
//				recordArray[j + 1] = hold2;
//
//				strcpy(hold, nameArray[j]);
//				strcpy(nameArray[j], nameArray[j + 1]);
//				strcpy(nameArray[j + 1], hold);
//
//				strcpy(hold, quantityArray[j]);
//				strcpy(quantityArray[j], quantityArray[j + 1]);
//				strcpy(quantityArray[j + 1], hold);
//
//				hold2 = priceArray[j];
//				priceArray[j] = priceArray[j + 1];
//				priceArray[j + 1] = hold2;
//			}
//		}
//	}
//		
//	fRef.seekp(0);
//	for (int i = 1; i <= n; i++)
//	{
//		fRef.write(reinterpret_cast<char*>(&i), sizeof(i));
//		fRef.write(reinterpret_cast<char*>(&recordArray[i - 1]), sizeof(recordArray[i - 1]));
//		fRef.write(reinterpret_cast<char*>(&nameArray[i - 1]), sizeof(nameArray[i - 1]));
//		fRef.write(reinterpret_cast<char*>(&quantityArray[i - 1]), sizeof(quantityArray[i - 1]));
//		fRef.write(reinterpret_cast<char*>(&priceArray[i - 1]), sizeof(priceArray[i - 1]));
//		//fRef.write(reinterpret_cast<char*>(&numberArray[i - 1]), sizeof(numberArray[i - 1]));
//	}
//
//	id = -1;
//	record = -1;
//	strcpy(name, "");
//	strcpy(quantity, "");
//	price = 0.0;
//
//	// fill file with blank records
//	for (; n <= maxnumber; n++)
//	{
//		fRef.write(reinterpret_cast<char*>(&id), sizeof(id));
//		fRef.write(reinterpret_cast<char*>(&record), sizeof(record));
//		fRef.write(reinterpret_cast<char*>(&name), sizeof(name));
//		fRef.write(reinterpret_cast<char*>(&quantity), sizeof(quantity));
//		fRef.write(reinterpret_cast<char*>(&price), sizeof(price));
//	}
//
//	cout << "Fruit sorted by record.\n";
//	fRef.close();
//}