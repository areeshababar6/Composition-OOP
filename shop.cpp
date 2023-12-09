#include <iostream>
#include <string>
using namespace std;

//-------------------------------------------- Base Class
class product
{
private:
	double price;
	double discount;
public:
	product(double = 0, double = 0);
	void setPrice(double);
	void setDiscount(double);
	double getPrice();
	double getDiscount();
};
product::product(double p, double d)
{
	price = p; discount = d;
}
void product::setPrice(double p)
{
	price = p;
}
void product::setDiscount(double d)
{
	discount = d;
}
double product::getDiscount()
{
	return discount;
}
double product::getPrice()
{
	return price;
}
//-----------------------------------------
class Electronics :public product
{
private: 
	string Manu;
public:
	Electronics(double =0, double =0, string = "Null");
	void setvalues(double, double, string);
	string getMan();
};
Electronics::Electronics(double p, double d, string n)
{
	setPrice(p); setDiscount(d);
	Manu = n;
}
void Electronics::setvalues(double p, double d, string n)
{
	setPrice(p); setDiscount(d);
	Manu = n;
}
string Electronics::getMan()
{
	return Manu;
}
//--------------------------------
class TV :public Electronics
{
private:
	int size;
public:
	TV(double = 0, double = 0, string = "Null", int = 0);
	double SalePrice();
	void setValues(double, double, string, int);
	void print();
};
TV::TV(double p, double d, string n, int s)
{
	setvalues(p, d, n);
	size = s;
}
void TV::setValues(double p, double d, string n, int s)
{
	setvalues(p, d, n);
	size = s;
}
double TV::SalePrice()
{
	double dp = (getDiscount() / 100) * getPrice();
	return (getPrice() - dp);
}
void TV::print()
{
	cout << " TV manufacturer: " << getMan() << endl;
	cout << " Size: " << size << endl;
	cout << " Price: " << getPrice() << endl;
	cout << " Discount: " << getDiscount() << endl;
}
// --------------------------------
class MP3player :public Electronics
{
private:
	string color;
	int cap;
public:
	MP3player(double, double, string, string, int);
	double SalePrice();
	void setValues(double, double, string, string, int);
	void print();
	int getCapacity();
};
MP3player::MP3player(double p, double d, string n, string c, int ca)
{
	setvalues(p, d, n);
	color = c; cap = ca;
}
double MP3player::SalePrice()
{
	double dp = (getDiscount() / 100) * getPrice();
	return (getPrice() - dp);
}
void MP3player::setValues(double p, double d, string n, string c, int ca)
{
	setvalues(p, d, n);
	color = c; cap = ca;
}
void MP3player::print()
{
	cout << " TV manufacturer: " << getMan() << endl;
	cout << " Color: " << color << endl;
	cout << " Capacity: " << cap << endl;
	cout << " Price: " << getPrice() << endl;
	cout << " Discount: " << getDiscount() << endl;
}
int MP3player::getCapacity()
{
	return cap;
}
//------------------------------------
class Book:public product
{
private:
	string name;
	string Aname;
public:
	Book(double, double, string, string);
	void setName(string);
	void setAuthor(string);
	string getName();
	string getAuthor();
	void print();
	double SalePrice();
};
Book::Book(double p, double d, string n, string an)
{
	setDiscount(d); setPrice(p);

	name = an; Aname = n;
}
void Book::setAuthor(string n)
{
	Aname = n;
}
void Book::setName(string n)
{
	name = n;
}
void Book::print()
{
	cout << " Book name: " << name << endl;
	cout << " Author's name: " << Aname << endl;
	cout << " Price: " << getPrice() << endl;
	cout << " Discount: " << getDiscount() << endl;
}
string Book::getAuthor()
{
	return Aname;
}
string Book::getName()
{
	return name;
}
double Book::SalePrice()
{
	double dp = (getDiscount() / 100) * getPrice();
	return (getPrice() - dp);
}
//----------------------------------------

void main() 
{
	int choice1 = 0, choice2 = 0, capacity, size;
	double price, discount;
	string manufacturer, color, author, name;
	cout << "\n*************WELCOME TO ONLINE SHOP******************\n";
	cout << "\nPress 1 for Electronics." << "\nPress 2 for Books\n";
	cout << " Enter: ";
	cin >> choice1;
	if (choice1 == 1) 
	{
		cout << "\nPress 1 for MP3Players." << "\nPress 2 for TV\n";
		cout << " Enter: ";
		cin >> choice2;
		if (choice2 == 1) 
		{
			cout << "\nSet Attributes\n";
			cout << "Price: ";
			cin >> price;
			cout << "\nDiscount in %: ";
			cin >> discount;
			cout << "\nManufacturer: ";
			cin.ignore();
			cin >> manufacturer;
			cout << "\nColor: ";
			cin >> color;
			cout << "\nCapacity in GB: ";
			cin >> capacity;


			MP3player m1(price, discount, manufacturer, color, capacity);
			
			if (m1.getCapacity() == 1)
				m1.setDiscount(10);
			else
				m1.setDiscount(50);
			
			m1.print();
			cout << m1.SalePrice();
		}
		else if(choice2 == 2) 
		{
			cout << "\nSet Attributes\n";
			cout << "Price: ";
			cin >> price;
			cout << "\nDiscount in %: ";
			cin >> discount;
			cout << "\nManufacturer: ";
			cin >> manufacturer;
			cout << "\nSize: ";
			cin >> size;

			TV t1(price, discount, manufacturer, size);
			t1.print();
			cout << t1.SalePrice();
		}
		else
			cout << "\nInvalid value... try again later";
	}
	else if(choice1 == 2) 
	{
		cout << "\nSet Attributes\n";
		cout << "Price: ";
		cin >> price;
		cout << "\nDiscount in %: ";
		cin >> discount;
		cout << "\nAuthor: ";
		cin.ignore();
		getline(cin, author);
		cout << "\nName: ";
		getline(cin, name);

		Book b1(price, discount, author, name);

		b1.print();
		cout << b1.SalePrice();
	}
	else
		cout << "\nInvalid value... try again later";
}