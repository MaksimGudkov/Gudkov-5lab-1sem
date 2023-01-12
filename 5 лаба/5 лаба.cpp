#include <iostream>
#include <conio.h>
#include <clocale>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;
const int cent = 10; 
struct f { 

	char name[100];
	char rejiser[100];
	char strana[100];

	int year;
	int stoimost;
	int sbori;
};

f films[cent] = {}; 
int menu() {

	cout << "\n Выберите действие: \n";
	cout << "1. Добавить новый фильм; \n";
	cout << "2. Найти фильм по заданному параметру; \n";
	cout << "3. Просмотреть все фильмы; \n";
	cout << "4. Сортировка фильмов; \n";
	cout << "5. Выход. \n";

	int a; 
	cin >> a;
	return a; 

}

int menu2() {

	cout << "\n Выберите интересующий вас пункт: \n";
	cout << "1. Название фильма; \n";
	cout << "2. Режиссёр; \n";
	cout << "3. Страна; \n";
	cout << "4. Год выпуска; \n";
	cout << "5. Стоимость; \n";
	cout << "6. Кассовые сборы. \n";

	int b;
	cin >> b;
	return b;
}

int menu3() {

	cout << "\n Выберите интересующий вас пункт для сортировки: \n";
	cout << "1. Название фильмов в алфавитном порядке; \n";
	cout << "2. Фамилии режиссёров в алфавитном порядке; \n";
	cout << "3. Название стран в алфавитном порядке; \n";
	cout << "4. Год выпуска по убиванию; \n";
	cout << "5. Стоимость по убыванию; \n";
	cout << "6. Кассовые сборы по убыванию. \n";

	int c;
	cin >> c;
	return c;
}

bool cmp1(f& a, f& b) { 

	int c = strcmp(a.name, b.name); //смотрит строчки и сравнивает названия фильмов из строчек a и b
	if (c < 0) return true;
	if (c > 0) return false;
}

bool cmp2(f& a, f& b) { 

	int c = strcmp(a.rejiser, b.rejiser); 
	if (c < 0) return true;
	if (c > 0) return false;
}

bool cmp3(f& a, f& b) { 

	int c = strcmp(a.strana, b.strana); 
	if (c < 0) return true;
	if (c > 0) return false;
}

bool cmp4(f& a, f& b) {

	return a.year > b.year;
}

bool cmp5(f& a, f& b) {

	return a.stoimost > b.stoimost;
}

bool cmp6(f& a, f& b) {

	return a.sbori > b.sbori;
}

int main() {

	system("chcp 1251"); 
	string str2, out, str;
	string line;
	int k = 0;
	ifstream fin;
	fin.open("MyInput.txt");
	int count2 = 0;
	while (!fin.eof()) {
		str = "";
		getline(fin, str);
		istringstream iss(str);
		string str2;
		int count = 1;
		while (iss >> str2) {
			switch (count) {
			case 1:
				strcpy_s(films[count2].name, str2.c_str());
				break;
			case 2:
				strcpy_s(films[count2].rejiser, str2.c_str());
				break;
			case 3:
				strcpy_s(films[count2].strana, str2.c_str());
				break;
			case 4:
				films[count2].year = stoi(str2);
				break;
			case 5:
				films[count2].stoimost = stoi(str2);
				break;
			case 6:
				films[count2].sbori = stoi(str2);
				break;
			}
			count++;
		}
		count2++;
	}
	cout << "\n";
	int a = menu(); 
	int j; 
	while (a != 5) {

		if (a == 1) {
			for (int i = 0; i < cent; i++) { //проверка (можно ли ввести новую команду)
				if (strlen(films[i].name) == 0) {
					j = i;
					break;
				}
			}

			cout << "Заполните данные о фильме: \n Название: \t";
			cin.ignore(); //очищает кеш данных
			cin.getline(films[j].name, 100); //записывает в films в строку j в названия фильмов то, что я ввожу

			cout << "\nРежиссёр: \t";
			cin.getline(films[j].rejiser, 100);

			cout << "\nСтрана: \t";
			cin.getline(films[j].strana, 100);

			cout << "\nГод выпуска: \t";
			cin >> films[j].year;

			cout << "\nСтоимость: \t";
			cin >> films[j].stoimost;

			cout << "\nКассовые сборы: \t";
			cin >> films[j].sbori;

		}

		else if (a == 2) {

			string str3 = "";
			int x;
			cout << "\n";

			int b = menu2();
			if (b == 1) {

				cout << "Введите название: ";
				cin >> str3;

				for (int i = 0; i < cent; i++) {
					if (films[i].name == str3) {
						cout << "\n Название: " << films[i].name << "\t Режиссер: " << films[i].rejiser << "\t Страна: " << films[i].strana << "\t Год выпуска: " << films[i].year << "\t Стоимость: " << films[i].stoimost << "\t Кассовые сборы: " << films[i].sbori << "\n";
					}

				}


			}

			else if (b == 2) {

				cout << "Введите режиссёра: ";
				cin >> str3;

				for (int i = 0; i < cent; i++) {
					if (films[i].rejiser == str3) {
						cout << "\n Название: " << films[i].name << "\t Режиссер: " << films[i].rejiser << "\t Страна: " << films[i].strana << "\t Год выпуска: " << films[i].year << "\t Стоимость: " << films[i].stoimost << "\t Кассовые сборы: " << films[i].sbori << "\n";
					}

				}


			}

			else if (b == 3) {

				cout << "Введите страну: ";
				cin >> str3;

				for (int i = 0; i < cent; i++) {
					if (films[i].strana == str3) {
						cout << "\n Название: " << films[i].name << "\t Режиссер: " << films[i].rejiser << "\t Страна: " << films[i].strana << "\t Год выпуска: " << films[i].year << "\t Стоимость: " << films[i].stoimost << "\t Кассовые сборы: " << films[i].sbori << "\n";
					}

				}


			}

			else if (b == 4) {

				cout << "Введите год: ";
				cin >> x;

				for (int i = 0; i < cent; i++) {
					if (films[i].year == x) {
						cout << "\n Название: " << films[i].name << "\t Режиссер: " << films[i].rejiser << "\t Страна: " << films[i].strana << "\t Год выпуска: " << films[i].year << "\t Стоимость: " << films[i].stoimost << "\t Кассовые сборы: " << films[i].sbori << "\n";
					}

				}


			}

			else if (b == 5) {

				cout << "Введите стоимость: ";
				cin >> x;

				for (int i = 0; i < cent; i++) {
					if (films[i].stoimost == x) {
						cout << "\n Название: " << films[i].name << "\t Режиссер: " << films[i].rejiser << "\t Страна: " << films[i].strana << "\t Год выпуска: " << films[i].year << "\t Стоимость: " << films[i].stoimost << "\t Кассовые сборы: " << films[i].sbori << "\n";
					}

				}


			}

			else if (b == 6) {

				cout << "Введите кассовые сборы: ";
				cin >> x;

				for (int i = 0; i < cent; i++) {
					if (films[i].sbori == x) {
						cout << "\n Название: " << films[i].name << "\t Режиссер: " << films[i].rejiser << "\t Страна: " << films[i].strana << "\t Год выпуска: " << films[i].year << "\t Стоимость: " << films[i].stoimost << "\t Кассовые сборы: " << films[i].sbori << "\n";
					}

				}


			}

		}

		else if (a == 3) {

			for (int i = 0; i < cent; i++) {
				if (strlen(films[i].name) > 0) {
					cout << "\n Название: " << films[i].name << "\t Режиссер: " << films[i].rejiser << "\t Страна: " << films[i].strana << "\t Год выпуска: " << films[i].year << "\t Стоимость: " << films[i].stoimost << "\t Кассовые сборы: " << films[i].sbori << "\n";
				}

			}

		}

		if (a == 4) {

			cout << "\n";

			int c = menu3();

			if (c == 1) { //ниже сортировка с помощью компораторов

				sort(films, films + cent - 1, cmp1);

				for (int i = 0; i < cent; i++) {
					if (strlen(films[i].name) > 0) {
						cout << "\n Название: " << films[i].name << "\t Режиссер: " << films[i].rejiser << "\t Страна: " << films[i].strana << "\t Год выпуска: " << films[i].year << "\t Стоимость: " << films[i].stoimost << "\t Кассовые сборы: " << films[i].sbori << "\n";
					}

				}

			}

			if (c == 2) {

				sort(films, films + cent - 1, cmp2);

				for (int i = 0; i < cent; i++) {
					if (strlen(films[i].name) > 0) {
						cout << "\n Название: " << films[i].name << "\t Режиссер: " << films[i].rejiser << "\t Страна: " << films[i].strana << "\t Год выпуска: " << films[i].year << "\t Стоимость: " << films[i].stoimost << "\t Кассовые сборы: " << films[i].sbori << "\n";
					}

				}

			}

			if (c == 3) {

				sort(films, films + cent - 1, cmp3);

				for (int i = 0; i < cent; i++) {
					if (strlen(films[i].name) > 0) {
						cout << "\n Название: " << films[i].name << "\t Режиссер: " << films[i].rejiser << "\t Страна: " << films[i].strana << "\t Год выпуска: " << films[i].year << "\t Стоимость: " << films[i].stoimost << "\t Кассовые сборы: " << films[i].sbori << "\n";
					}

				}

			}

			if (c == 4) {

				sort(films, films + cent - 1, cmp4);

				for (int i = 0; i < cent; i++) {
					if (strlen(films[i].name) > 0) {
						cout << "\n Название: " << films[i].name << "\t Режиссер: " << films[i].rejiser << "\t Страна: " << films[i].strana << "\t Год выпуска: " << films[i].year << "\t Стоимость: " << films[i].stoimost << "\t Кассовые сборы: " << films[i].sbori << "\n";
					}

				}

			}

			if (c == 5) {

				sort(films, films + cent - 1, cmp5);

				for (int i = 0; i < cent; i++) {
					if (strlen(films[i].name) > 0) {
						cout << "\n Название: " << films[i].name << "\t Режиссер: " << films[i].rejiser << "\t Страна: " << films[i].strana << "\t Год выпуска: " << films[i].year << "\t Стоимость: " << films[i].stoimost << "\t Кассовые сборы: " << films[i].sbori << "\n";
					}

				}

			}

			if (c == 6) {

				sort(films, films + cent - 1, cmp6);

				for (int i = 0; i < cent; i++) {
					if (strlen(films[i].name) > 0) {
						cout << "\n Название: " << films[i].name << "\t Режиссер: " << films[i].rejiser << "\t Страна: " << films[i].strana << "\t Год выпуска: " << films[i].year << "\t Стоимость: " << films[i].stoimost << "\t Кассовые сборы: " << films[i].sbori << "\n";
					}

				}

			}

		}

		a = menu();

	}

	ofstream fout; 
	fout.open("MyInput.txt");
	fout.clear();

	for (int i = 0; i < cent; i++) {
		if (strlen(films[i].name) > 0) {
			fout << films[i].name << "\t" << films[i].rejiser << "\t" << films[i].strana << "\t" << films[i].year << "\t" << films[i].stoimost << "\t" << films[i].sbori << "\n";
		}

	}

	fout.close();

}