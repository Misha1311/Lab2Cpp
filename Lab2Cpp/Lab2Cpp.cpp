#include <iostream>
#include <iomanip>

using namespace std;


struct FULLNAME
{
	char Surname[50];

	char Name[40];

	char MiddleName[40];

};


struct PHONENUMBER
{
	long long int PhoneNumber;
};

struct HOMEADDRESS
{
	char state[40];

	char region[40];

	char city[40];

	char district[40];

	char street[40];

	int zipcode;

	int homenumber;

	int apartment;
};


struct AUTO
{
	char brand[30];

	char autonumber[15];

	char techpassnumber[25];
};

struct MEN
{
	FULLNAME name;

	PHONENUMBER numberphone;

	HOMEADDRESS addresshome;

	AUTO automen;

};

void search(MEN* info, int Size)
{
	int z, k, c = 0;
	string Surname, markautosearch;

	cout << "Если вы хотите найти нужного вам человека по фамилии нажмите - 1 или найти по  марке авто нажмите - 2\n";
	cout << "Введите соответствующий номер для поиска либо 0 для пропуска поиска: ";
	cin >> z;
	cout << endl;

	if (z == 1)
	{
		cout << "Введите фамилию: ";
		cin >> Surname;
		cout << endl;

		for (int i = 0; i < Size; i++)
		{
			if (Surname == info[i].name.Surname)
			{
				cout << "Фамилия имя отчество : " << info[i].name.Surname << " " << info[i].name.Name << " " << info[i].name.MiddleName << endl;
				cout << "Номер телефона : " << info[i].numberphone.PhoneNumber << endl;
				cout << "Почтовый индекс : " << info[i].addresshome.zipcode << endl << "Страна : " << info[i].addresshome.state << endl << "Регион : " << info[i].addresshome.region << endl << "Город : " << info[i].addresshome.city << endl << "Район : " << info[i].addresshome.district << endl << "Улица : " << info[i].addresshome.street << endl << "Дом : " << info[i].addresshome.homenumber << endl << "Квартира : " << info[i].addresshome.apartment << endl;
				cout << "Марка авто : " << info[i].automen.brand << endl << "Номер авто : " << info[i].automen.autonumber << endl << "Номер техпаспрорта автомобиля : " << info[i].automen.techpassnumber << endl << endl;

				c++;
			}
		}

		if (c == 0)
		{
			cout << "Человек с данной фамилией не найден" << endl;
		}

		cout << endl;
		cout << "Хотите продолжить? Да - 1, Нет - 0: ";
		cin >> k;
		cout << endl;

		if (k == 1)
		{
			search(info, Size);
			c = 0;
		}

		else if (k == 0)
		{
			c = 0;
		}

		cout << endl;
	}

	if (z == 2)
	{
		cout << "Введите марку авто: ";
		cin >> markautosearch;
		cout << endl;

		for (int i = 0; i < Size; i++)
		{
			if (markautosearch == info[i].automen.brand)
			{
				cout << "Фамилия имя отчество : " << info[i].name.Surname << " " << info[i].name.Name << " " << info[i].name.MiddleName << endl;
				cout << "Номер телефона : " << info[i].numberphone.PhoneNumber << endl;
				cout << "Почтовый индекс : " << info[i].addresshome.zipcode << endl << "Страна : " << info[i].addresshome.state << endl << "Регион : " << info[i].addresshome.region << endl << "Город : " << info[i].addresshome.city << endl << "Район : " << info[i].addresshome.district << endl << "Улица : " << info[i].addresshome.street << endl << "Дом : " << info[i].addresshome.homenumber << endl << "Квартира : " << info[i].addresshome.apartment << endl;
				cout << "Марка авто : " << info[i].automen.brand << endl << "Номер авто : " << info[i].automen.autonumber << endl << "Номер техпаспрорта автомобиля : " << info[i].automen.techpassnumber << endl << endl;

				c++;
			}
		}

		if (c == 0)
		{
			cout << "Человека с даным авто не найден" << endl;
		}

		cout << endl;
		cout << "Хотите продолжить? Да - 1, Нет - 0: ";
		cin >> k;
		cout << endl;

		if (k == 1)
		{
			search(info, Size);
			c = 0;
		}

		else if (k == 0)
		{
			c = 0;
		}

		cout << endl;
	}
}


void sortirovka(MEN* info, int Size)
{
	int g;
	cout << "Что бы отсортировать людей нужно выбрать как вы хотите сортировать.\n" << endl;
	cout << "Если хотите отсортировать по номеру техпаспрорта автомобиля нажмите 1," << endl;
	cout << "если по номеру авто нажмите - 2, если Вы не хотите сортировать нажмите - 0:";
	cin >> g;

	if (g == 1)
	{
		for (int i = 0; i < Size; i++)
		{
			for (int i = 0; i < Size - 1; i++)
			{
				if (info[i].automen.techpassnumber > info[i + 1].automen.techpassnumber)
				{
					MEN temp = info[i];
					info[i] = info[i + 1];
					info[i + 1] = temp;
				}
			}
		}

	}

	else if (g == 2)
	{
		for (int i = 0; i < Size; i++)
		{
			for (int i = 0; i < Size - 1; i++)
			{
				if (info[i].automen.autonumber > info[i + 1].automen.autonumber)
				{
					MEN temp = info[i];
					info[i] = info[i + 1];
					info[i + 1] = temp;
				}
			}
		}

	}

	else if (g == 0)
	{
		cout << endl;
		cout << "Вы передумали и решили не сортировать." << endl;
		cout << endl;
	}
}




void memory(MEN*& info, int& Size)
{
	MEN* new_info = new MEN[Size + 1];

	for (int i = 0; i < Size; i++)
	{
		new_info[i] = info[i];
	}

	Size++;

	delete[] info;

	info = new_info;
}

void outputinfo(MEN* info, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Фамилия имя отчество : " << info[i].name.Surname << " " << info[i].name.Name << " " << info[i].name.MiddleName << endl;
		cout << "Номер телефона : " << info[i].numberphone.PhoneNumber << endl;
		cout << "Почтовый индекс : " << info[i].addresshome.zipcode << endl << "Страна : " << info[i].addresshome.state << endl << "Регион : " << info[i].addresshome.region << endl << "Город : " << info[i].addresshome.city << endl << "Район : " << info[i].addresshome.district << endl << "Улица : " << info[i].addresshome.street << endl << "Дом : " << info[i].addresshome.homenumber << endl << "Квартира : " << info[i].addresshome.apartment << endl;
		cout << "Марка авто : " << info[i].automen.brand << endl << "Номер авто : " << info[i].automen.autonumber << endl << "Номер техпаспрорта автомобиля : " << info[i].automen.techpassnumber << endl << endl;

	}
}


int main()
{
	setlocale(LC_ALL, "Russian");

	MEN* info;
	int Size;
	
	
do
	{
		cout << "Введите количество человек, данные которых вы будете вводить: ";
		cin >> Size;
	} while (Size < 1);

	info = new MEN[Size];

	for (int i = 0; i < Size; i++)
	{
		cout << "Введите Фамилию" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(info[i].name.Surname, 50);

		cout << "Введите Имя" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(info[i].name.Name, 30);

		cout << "Введите Отчество" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(info[i].name.MiddleName, 30);

		cout << "Введите номер телефона (Пример : 380667777777)" << endl;
		cin >> info[i].numberphone.PhoneNumber;

		do
		{
			cout << "Введите почтовый индекс" << endl;
			cin.ignore(std::cin.rdbuf()->in_avail());
			cin >> info[i].addresshome.zipcode;
		} while ((info[i].addresshome.zipcode >= 100000) || (info[i].addresshome.zipcode < 10000));

		cout << "Введите страну" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(info[i].addresshome.state, 30);

		cout << "Введите регион" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(info[i].addresshome.region, 30);

		cout << "Введите город" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(info[i].addresshome.city, 30);

		cout << "Введите район" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(info[i].addresshome.district, 30);

		cout << "Введите улицу" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(info[i].addresshome.street, 30);

		do
		{
			cout << "Введите номер дома" << endl;
			cin >> info[i].addresshome.homenumber;
		} while ((info[i].addresshome.homenumber > 1000) || (info[i].addresshome.homenumber < 1));

		do
		{
			cout << "Введите номер квартиры" << endl;
			cin >> info[i].addresshome.apartment;
		} while ((info[i].addresshome.apartment > 1000) || (info[i].addresshome.apartment < 1));

		cout << "Введите марку авто" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(info[i].automen.brand, 30);

		cout << "Введите номер авто" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(info[i].automen.autonumber, 15);

		cout << "Введите номер техпаспрорта автомобиля" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(info[i].automen.techpassnumber, 25);


		if (i < Size)
		{
			int number;

			cout << "Если Вы хотите добавить нового владельца авто нажмите - 1, если не хотите нажмите - 0" << endl;
			cin >> number;
			cout << endl;

			if (number == 1)
			{
				memory(info, Size);
			}
		}

	}

	if (Size > 1)
	{
		search(info, Size);
		sortirovka(info, Size);
	}

	outputinfo(info, Size);
}
