#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string>
#include <windows.h>
#include <algorithm>
using namespace std;

int n = 15;

struct cars {
	int kod;
	string name;
	string motor; 
	int hp;
	string color;
	string privod;
	int kol;
};

void showspisok(cars* a) {
	cout << "Код" << "  " << "Марка" << "     " << "Мотор" << "  " << "Мощность двигателя" << "   " << "Цвет" << "       " << "Привод" << "    " << "Количество" << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i].kod << "    ";
		cout << a[i].name << "    ";
		cout << a[i].motor << "        ";
		cout << a[i].hp << "           ";
		cout << a[i].color << "    ";
		cout << a[i].privod << "       ";
		cout << a[i].kol << "  ";
		cout << endl;
	}
}

void spisok(cars* a) {
	string NAME[5] = { "Toyota", "Ferari", "Suzuki", "Nissan", "Jaguar" };
	string COLOR[5] = { "Красный", "Зеленый", "Голубой", "Бежевый", "Лиловый" };
	string PRIVOD[3] = { "Полный", "Передний", "Задний" };
	string MOTOR[2] = { "Дизель", "Бензин" };
	for (int i = 0; i < n; i++) {
		a[i].kod = i;
		a[i].name = NAME[rand() % 5];
		a[i].motor = MOTOR[rand() % 2];
		a[i].hp = 100 + rand() % 200;
		a[i].color = COLOR[rand() % 5];
		a[i].privod = PRIVOD[rand() % 3];
		a[i].kol = rand() % 25;



	}
	showspisok(a);
}


cars* addcar(cars* f) { //создание функции с указателем на структуру 
	cars* templist = new cars[n + 1]; //создание нового массива в куче с дополнительной ячейкой
	cars newone; //новый автомобиль
	cout << "Введите Марку: ";
	cin >> newone.name;
	cout << "Какой мотор?(бензин;дизель): ";
	cin >> newone.motor;
	cout << "Какая мощность?:  ";
	cin >> newone.hp;
	newone.kod = n;
	cout << "Введите цвет: ";
	cin >> newone.color;
	cout << "Какой привод?(задний;передний): ";
	cin >> newone.privod;
	cout << "Какое Количество?: ";
	cin >> newone.kol;

	for (int i = 0; i < n; i++) {
		templist[i] = f[i]; //приравнивание старого массива к новому поэлементно
	}
	templist[n] = newone; //добавление в массив новогого элемента
	delete[] f; //удаление старого содержимого(массива) у f
	n++;
	return templist; //функция будет иметь значение(возвращать) адрес templist

}

void poisk1(cars* a) {
	int temp;
	string h;
	cout << "Введите код товара:";
	cin >> temp;
	cout << endl;
	for (int i = 0; i < n; i++) {
		if (a[i].kod == temp) {
			cout << "Код" << "  " << "Марка" << "     " << "Мотор" << "  " << "Мощность двигателя" << "   " << "Цвет" << "       " << "Привод" << "    " << "Количество" << endl;
			cout << a[i].kod << "    ";
			cout << a[i].name << "    ";
			cout << a[i].motor << "        ";
			cout << a[i].hp << "           ";
			cout << a[i].color << "    ";
			cout << a[i].privod << "       ";
			cout << a[i].kol << "  ";
			cout << endl;
			cout << "Хотите ли вы купить данный товар?(нет/да) ";
			cin >> h;
			if (h == "да") {
				a[i].kol --;
				cout << "Товар успешно куплен";
				cout << endl;

				cout << "Код" << "  " << "Марка" << "     " << "Мотор" << "  " << "Мощность двигателя" << "   " << "Цвет" << "       " << "Привод" << "    " << "Количество" << endl;
				cout << a[i].kod << "    ";
				cout << a[i].name << "    ";
				cout << a[i].motor << "        ";
				cout << a[i].hp << "           ";
				cout << a[i].color << "    ";
				cout << a[i].privod << "       ";
				cout << a[i].kol << "  ";
				cout << endl;
			}

		}

		

	}

}

void poisk2(cars* a) {
	int p = 0;
	string h;
	string ask_name, ask_motor, ask_color, ask_privod;
	int ask_hp;
	cars g[100];
	cout << "Введите данные по всем критериям, если критерий не важен, введите 0 (Марка автомобиля обязательный критерий): " << endl;
	cout << "Марка автомобиля: ";
	cin >> ask_name;
	cout << "Мотор: ";
	cin >> ask_motor;
	cout << "Мощность двигателя: ";
	cin >> ask_hp;
	cout << "Цвет: ";
	cin >> ask_color;
	cout << "Привод: ";
	cin >> ask_privod;


	if (ask_name != "0") {
		int t = 0;
		for (int i = 0; i < 100; i++) {
			if ((a[i].name == ask_name)) {
				g[t] = a[i];
				t++;
			}
		}
		int q = 0;
		if (ask_motor != "0") {
			for (int i = 0; i < t; i++) {
				if ((g[i].motor == ask_motor)) {
					g[q] = g[i];
					q++;
				}
			}
		}
		int w = 0;
		if (ask_hp != 0) {
			for (int i = 0; i < q; i++) {
				if ((g[i].hp == ask_hp)) {
					g[w] = g[i];
					w++;
				}
			}
		}
		int e = 0;
		if (ask_color != "0") {
			for (int i = 0; i < w; i++) {
				if ((g[i].color == ask_color)) {
					g[e] = g[i];
					e++;
				}
			}
		}
		int r = 0;
		if (ask_privod != "0") {
			for (int i = 0; i < e; i++) {
				if ((g[i].privod == ask_privod)) {
					g[r] = g[i];
					r++;
				}
			}
		}
		if (q == 0) q = t;
		if (w == 0) w = q;
		if (e == 0) e = w;
		if (r == 0)	r = e;

		cout << endl;
		for (int i = 0; i < r; i++) {
			cout << "Код" << "  " << "Марка" << "     " << "Мотор" << "  " << "Мощность двигателя" << "   " << "Цвет" << "       " << "Привод" << "    " << "Количество" << endl;
			cout << g[i].kod << "    ";
			cout << g[i].name << "    ";
			cout << g[i].motor << "        ";
			cout << g[i].hp << "           ";
			cout << g[i].color << "    ";
			cout << g[i].privod << "       ";
			cout << g[i].kol << "  ";
			cout << endl;
			cout << "Хотите ли вы купить данный товар?(нет/да) ";
			cin >> h;
			if (h == "да") {
				p = 1;
				g[i].kol--;
				cout << "Товар успешно куплен";
				cout << endl;
				cout << "Код" << "  " << "Марка" << "     " << "Мотор" << "  " << "Мощность двигателя" << "   " << "Цвет" << "       " << "Привод" << "    " << "Количество" << endl;
				cout << g[i].kod << "    ";
				cout << g[i].name << "    ";
				cout << g[i].motor << "        ";
				cout << g[i].hp << "           ";
				cout << g[i].color << "    ";
				cout << g[i].privod << "       ";
				cout << g[i].kol << "  ";
				cout << endl;
			}
			cout << endl;
			if (p == 1) {
				break;
			}
		}
	}
}





int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int x = 1;
	cars* f = new cars[n]; //указатель на использовании кучи
	spisok(f);
	cout << endl;
	while (x != 0) {
		cout << "Какую функцию хотите выполнить(1-поиск по коду товара;2-поиск по критериям;3-добавление нового товара)? ";
		cin >> x;
		switch (x) {
		case 1:  poisk1(f);
			cout << endl;
			break;
		case 2:  poisk2(f);
			cout << endl;
			break;
		case 3: f = addcar(f);
			showspisok(f);
			cout << endl;
			break;
		}
	}

}




