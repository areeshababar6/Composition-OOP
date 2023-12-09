#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class item
{
private:
	string name;
	float price;
	int quant;
public:
	item(string = "None", float = 0.00, int = 0);
	void print(int );
	void setName(string);
	void setPrice(float);
	void setQuant(int);
	string getName();
	float getPrice();
	int getQuant();
	void setValues(string, float, int);
};
string item :: getName()
{
	return name;
}
float item::getPrice()
{
	return price;
}
int item::getQuant()
{
	return quant;
}
void item::setPrice(float p)
{
	price = p;
}
void item::setQuant(int q)
{
	quant = q;
}
void item::setValues(string n, float p, int q)
{
	name = n; price = p; quant = q;
}
void item::setName(string n)
{
	name = n;
}
item::item(string n, float p, int q)
{
	name = n; price = p; quant = q;
}
void item :: print(int i)
{
	cout << left << setw(5) << i;
	cout << left << setw(20) << name;
	cout << left << setw(10) << price;
	cout << left << setw(5) << quant << endl;
}

class cafe
{
private:
	int itemNum;
	item* i;
public:
	cafe(int = 1);
	void print();
	void setArray();
	void set(string, float, int, int);
	void setItemNum(int);
	int getItem();
	void bill();
};
int cafe::getItem()
{
	return itemNum;
}
void cafe::setItemNum(int in)
{
	itemNum = in;
	setArray();
}
void cafe::set(string n, float p, int q, int c)
{
	i[c].setValues(n, p, q);
}
void cafe::setArray()
{
	i = new item[itemNum];
}
void cafe::print()
{
	cout << "\n Displaying menu...\n\n";
	cout << left << setw(5) << "Sr#";
	cout << left << setw(20) << "Name";
	cout << left << setw(10) << "Price";
	cout << left << setw(5) << "Qty" << endl;

	for (int j = 0; j < itemNum; j++)
		i[j].print(j+1);


	cout << " \n----------------------------------\n" << endl;
}
cafe::cafe(int in)
{
	itemNum = in;
	i = new item[itemNum];
}
void cafe::bill()
{
	float totalBill = 0;
	int totalQ = 0;
	int o, q, c = 0;
	bool temp = false;

	system("pause");
	system("cls");


	cout << "\n \t Welcome to Cafe!!!" << endl;
	do
	{
		print();
		do
		{
			cout << " Enter your option: ";
			cin >> o;
			if (o <= itemNum)
				temp = true;
			else
			{
				temp = false;
				cout << " Wrong input of option!!\n" << endl;
			}

			if (temp)
			{
				cout << " Enter the quantity: ";
				cin >> q;

				if (q <= i[o - 1].getQuant())
					temp = true;
				else
				{
					temp = false;
					cout << " Out of stock!! \n" << endl;
				}
			}
		} while (!temp);

		totalBill = totalBill + (q * i[o - 1].getPrice());
		totalQ = totalQ + q;

		int qn = i[o - 1].getQuant() - q;
		i[o - 1].setQuant(qn);

		cout << "\n\n Do you want to select another item?\n";
		cout << " 1. Yes      0. No" << endl;
		cout << " Enter: ";
		cin >> c;
	} while (c);
	
	system("pause");
	system("cls");

	cout << "   !!! Bill !!!";
	cout << "\n ---------------" << endl;
	cout << "\n Total items: " << totalQ << endl;
	cout << " Total Bill: " << totalBill << endl;
	cout << "\n ---------------" << endl;
}
int main()
{
	int in;
	string n; float p; int q;
	cout << " Enter the number of items in cafe: ";
	cin >> in;

	cafe c(in);
	for (int i = 0; i < in; i++)
	{
		cout << "\n Item# " << i + 1 << endl;
		cout << " Enter name: ";
		cin.ignore();
		getline(cin, n);
		
		cout << " Enter price: ";
		cin >> p;
		cout << " Enter quantity: ";
		cin >> q;

		c.set(n, p, q, i);
	}

	c.bill();

	return 0;
}