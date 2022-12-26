//1.hashing
#include <iostream>
#include <string>
using namespace std;
struct rec
{
	string name;
	long int tel;
	int comp;
};

class hasht
{
public:
	rec Dir[10];
	rec create();
	int ascci(string);
	void linear(rec L);
	void quad(rec Q);
	void display();
	void searchlinear();
	void searchquad();
	hasht()
	{
		for (int i = 0; i < 10; i++)
		{
			Dir[i].name = "none";
			Dir[i].tel = 0;
			Dir[i].comp = 0;
		}
	}
};
rec hasht ::create()
{
	char ch;
	long int t;
	string n;
	rec data;

	cout << "\nenter the name : ";
	cin >> n;
	cout << "\nenter the tel no : ";
	cin >> t;

	data.name = n;
	data.tel = t;
	return data;
}

int hasht ::ascci(string value)
{
	int ask = 0;
	int sum = 0;
	int i = 0;
	while (value[i] != '\0')
	{
		sum = sum + int(value[i]);
		i++;
	}
	ask = sum % 10;
	return ask;
}

void hasht ::linear(rec L)
{   
	int c=1;
	int pos = ascci(L.name);

	while (Dir[pos].name != "none")
	{
		pos++;
		c++;
	}
	Dir[pos].name = L.name;
	Dir[pos].tel = L.tel;
	Dir[pos].comp=c;
	//	display();
}

void hasht ::quad(rec Q)
{
	int max = 10;
	int pos = ascci(Q.name);
	int z, i = 1;
	int c=1;
	z = pos;
	while (Dir[pos].name != "none")
	{
		pos = (z + i * i) % max;
		c++;
		//cout<<c;
		i++;
	}
	//cout<<"\n and "<<c;
	Dir[pos].name = Q.name;
	Dir[pos].tel = Q.tel;
	Dir[pos].comp=c;
	//	display();
}

void hasht ::display()
{
	for (int i = 0; i < 10; i++)
	{
		cout << Dir[i].name << "	" << Dir[i].tel << "	" << Dir[i].comp << endl;
	}
}

void hasht ::searchlinear()
{
	int pos, max = 10, i = 1;
	string n;
	cout << "\nenter name which you have to search : ";
	cin >> n;
	pos = ascci(n);
	while (Dir[pos].name != n)
	{ 
		pos++;
	}
	cout << "\ntel no of person is : " << Dir[pos].tel;
	cout << "\ncomparision required to find it is " << Dir[pos].comp << endl;
}

void hasht ::searchquad() 
{
	int pos, max = 10, i = 1;
	string n;
	cout << "\nenter name which you have to search : ";
	cin >> n;
	pos = ascci(n);
	int z = pos;
	int flag=0;
	while (Dir[pos].name != n)
	{
		pos = (z + i * i) % max;
		i++;
		flag=1;
	}
	if (flag==0)
	{
		cout<<"\nperson is not present";
	}
	else{
	cout << "\ntel no of person is : " << Dir[pos].tel;
	cout << "\ncomparision required to find it is " << Dir[pos].comp << endl;
	}
}

int main()
{
	hasht h1, h2;
	int op;
	char ch;
	rec e;
	do
	{
		cout << "\nChoose one of the option below : "
			 << "\n1. create"
			 << "\n2. display linear"
			 << "\n3. display quadratic"
			 << "\n4. search in linear"
			 << "\n5. search in quad"
			 << "\nEnter option here : ";
		cin >> op;
		switch (op)
		{
		case 1:
			do
			{
				e = h1.create();
				h1.linear(e);
				h2.quad(e);
				cout << "\ndo you want to add info y or n : ";
				cin >> ch;
			} while (ch == 'y');
			break;

		case 2:
			h1.display();
			break;

		case 3:
			h2.display(); 
			break;

		case 4:
			h1.searchlinear();
			break;

		case 5:
			h2.searchquad();
			break;
		default:
			cout << "\nInvalid option";
		}
		cout << "\n Do want do more opration : y or n : ";
		cin >> ch;
	} while (ch == 'y');

	return 0;
}
