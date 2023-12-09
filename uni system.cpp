#include <iostream>
#include <string>

using namespace std;

class student
{
private:
	int marks;
public:
	student(int m = 0)
	{
		marks = m;
	}
	void setStudent(int m)
	{
		marks = m;
	}
	void print()
	{
		cout << " Marks: " << marks << endl;
	}
	int getMarks()
	{
		return marks;
	}
};
class teacher
{
private:
	string name;
	student s[5];
	int totalMarks;
public:
	teacher(string tn = "Bilal", int m = 0)
	{
		name = tn;
		totalMarks = 0;
		for (int i = 0; i < 5; i++)
			s[i].setStudent(m);
	}
	void print()
	{
		cout << " Teacher name: " << name << endl;
		for (int i = 0; i < 5; i++)
		{
			s[i].print();
		}
	}
	void setteacher(string tn)
	{
		name = tn;
		int m;
		for (int i = 0; i < 5; i++)
		{
			cout << " enter marks:";
			cin >> m;

			s[i].setStudent(m);
		}
	}
	int marksCal()
	{
		for (int i = 0; i < 5; i++)
			totalMarks = totalMarks + s[i].getMarks();

		return totalMarks;
	}
};
class Batch
{
private:
	teacher t[2];
	int bn;
public:
	Batch(int b = 2020)
	{
		bn = b;
	}
	void print()
	{
		cout << " Batch number: " << bn << endl;
		t[0].print();
		t[1].print();
		cout << endl;
	}
	void setBatch(int b)
	{
		bn = b;
		string tn;
		for (int i = 0; i < 2; i++)
		{
			cout << " Enter teacher name: ";
			cin.ignore();
			getline(cin, tn);
			t[i].setteacher(tn);
		}
	}
	int marksComp()
	{
		int t1 = t[0].marksCal();
		int t2 = t[1].marksCal();

		return t1 + t2;
	}
};
class dept
{
private:
	string name;
	Batch b[2];
public:
	dept(string dn = "None")
	{
		name = dn;
	}
	void setDept(string n)
	{
		name = n;
		int b1;
		cout << " Enter batch number: ";
		cin >> b1;
		b[0].setBatch(b1);

		cout << " Enter batch number: ";
		cin >> b1;
		b[1].setBatch(b1);
	}
	void print()
	{
		cout << " Dept name: " << name << endl;
		b[0].print();
		b[1].print();
	}
	int add()
	{
		return (b[0].marksComp() + b[1].marksComp());
	}
};
int main()
{
	dept d1;
	dept d2;

	d1.setDept("IT");
	d1.setDept("Psychology");

	if (d1.add() > d2.add())
	{
		cout << " IT department wins!" << endl;
	}
	else
		cout << " Psychology department wins!" << endl;

	return 0;
}