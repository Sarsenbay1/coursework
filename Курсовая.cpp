#include <windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <random>
#include <time.h>
#define UP 72
#define DOWN 80
#define ESC 27
#define ENTER 13
using namespace std;
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//об авторе
void authr()
{
	while (true) {
		HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

		COORD position;
		position.X = 45;
		position.Y = 7;
		SetConsoleCursorPosition(color, position);
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		printf("_______________________________");
		position.X = 44;
		position.Y = 8;
		SetConsoleCursorPosition(color, position);
		printf("|                               |");
		position.X = 44;
		position.Y = 9;
		SetConsoleCursorPosition(color, position);
		printf("|       -Студент ФИТиКС-        |");
		position.X = 44;
		position.Y = 10;
		SetConsoleCursorPosition(color, position);
		printf("|_______________________________|");
		position.X = 44;
		position.Y = 11;
		SetConsoleCursorPosition(color, position);
		printf("|                               |");
		position.X = 44;
		position.Y = 12;
		SetConsoleCursorPosition(color, position);
		printf("|        -Группы ИВТ-222-       |");
		position.X = 44;
		position.Y = 13;
		SetConsoleCursorPosition(color, position);
		printf("|_______________________________|");
		position.X = 44;
		position.Y = 14;
		SetConsoleCursorPosition(color, position);
		printf("|                               |");
		position.X = 44;
		position.Y = 15;
		SetConsoleCursorPosition(color, position);
		printf("|->Сарсенбаев Максат Серикович<-|");
		position.X = 44;
		position.Y = 16;
		SetConsoleCursorPosition(color, position);
		printf("|_______________________________|\n");
		if (_getch() == ESC)return;
	}
}
void GoToXY(short x, short y)
{
	SetConsoleCursorPosition(hStdOut, { x, y });
}
void ConsoleCursorVisible(bool show, short size)
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show; // изменяем видимость курсора
	structCursorInfo.dwSize = size; // изменяем размер курсора
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}
//функции для поиска чисел и сортировки в массивах
int poiskMinMax(int arr[], unsigned size, int num)
{
	int max = arr[0]; int min = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] > max)max = arr[i];
		if (arr[i] < min)min = arr[i];
	}
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == num) {
			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_BLUE);
			cout << " " << arr[i];
		}
		else if (arr[i] == max) {
			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
			cout << " " << arr[i];
		}
		else if (arr[i] == min) {
			SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
			cout << " " << arr[i];
		}
		else
		{
			SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
			cout << " " << arr[i];
		}

	}

	return 0;
}
int sort1(int arr[], unsigned size)
{
	int i, j, tmp;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
					tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				
			}
		}
	}

	return 0;
}

int vvod_mass(int arr[], int size)
{
	GoToXY(40, 10);

	cout << "введите элементы массива" << endl;
	GoToXY(40, 11);
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	return 0;
}
int mass1()
{
	SetConsoleTitle(L"Сортировка и поиск чисел в массивах");
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
	int x = 45, y = 10;
	int mass[1111], number;
	unsigned size;
	GoToXY(x, y);
	cout << "введите размер массива ";
	cin >> size;
	GoToXY(x, y + 1);
	system("CLS");
	vvod_mass(mass, size);
	system("cls");
	GoToXY(x, y);
	cout << "какой элемент искать?";
	GoToXY(x, y + 1);
	cin >> number;
	system("CLS");

	GoToXY(x, y);
	sort1(mass, size);
	system("cls");
	GoToXY(x, y);
	cout << "отсортированный массив";
	GoToXY(x, y + 1);
	poiskMinMax(mass, size, number);
	GoToXY(x, y + 2);

	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
	cout << "красный - max";
	GoToXY(x, y + 3); SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
	cout << "синий - min";
	GoToXY(x, y + 4); SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "фиолетовый - искомый элемент";
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
	_getch();
	return 0;
}
//Функции для двумерного массива
void sort2(int a[][100], int size1, int size2)
{
	int inext, jnext;
	int i, j;
	int temp;
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		i = 0; j = 0;
		for (inext = 0; inext < size1; inext++)
			for (jnext = (inext ? 0 : 1); jnext < size2; jnext++)
			{
				if (a[i][j] > a[inext][jnext]) {
					temp = a[i][j];
					a[i][j] = a[inext][jnext];
					a[inext][jnext] = temp;
					sorted = false;
				}
				i = inext;
				j = jnext;
			}

	}
}
void poiskMinMax2(int arr[][100], int size1, int size2, int number)
{

	int x = 40, y = 10;
	GoToXY(x, y);


	int max = arr[0][0], min = arr[0][0];
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (arr[i][j] > max)max = arr[i][j];
			if (arr[i][j] < min)min = arr[i][j];
		}
	}

	for (int i = 0; i < size1; i++)
	{
		GoToXY(x, ++y);
		for (int j = 0; j < size2; j++)
		{

			if (arr[i][j] == number) {
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_BLUE);
				cout << " " << arr[i][j];
			}
			else if (arr[i][j] == max) {
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
				cout << " " << arr[i][j];
			}
			else if (arr[i][j] == min) {
				SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
				cout << " " << arr[i][j];
			}
			else
			{
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
				cout << " " << arr[i][j];
			}
		}

	}

}
int mass2()
{
	SetConsoleTitle(L"Сортировка и поиск чисел в двумерных массивах");
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
	int x = 40, y = 10;
	int mass[100][100], number;
	unsigned size1, size2;
	GoToXY(x, y);
	cout << "введите размер двумерного массива ";
	cin >> size1 >> size2;
	cout << endl;
	GoToXY(x, ++y);
	cout << "Введите двумерный массив";
	GoToXY(x, ++y);
	for (int i = 0; i < size1; i++)
	{
		GoToXY(x, ++y);
		for (int j = 0; j < size2; j++) { cin >> mass[i][j]; }
	}
	GoToXY(x, ++y);
	cout << "какой элемент искать ";
	cin >> number;
	sort2(mass, size1, size2);
	system("CLS");

	GoToXY(40, 10);
	cout << "ОТСОРТИРОВАННЫЙ ДВУМЕРНЫЙ МАССИВ";
	poiskMinMax2(mass, size1, size2, number);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
	GoToXY(x, ++y);
	cout << "красный - max";
	GoToXY(x, ++y); SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
	cout << "синий - min";
	GoToXY(x, ++y); SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "фиолетовый - искомый элемент";
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
	_getch();
	return 0;
}
//сортировка и поиск чисел в массивах
int sortirovka()
{
	SetConsoleTitle(L"Сортировка и поиск чисел в массивах");
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
	system("CLS");
	system("chcp 1251");
	system("cls"); int active_menu = 0;

	string Menu[] = { "Одномерный массив","Двумерный массив" };
	ConsoleCursorVisible(false, 100);
	//string Menu[] = { "Об авторе","Сортировка и поиск чисел в массивах","Типы в языке С/С++» с элементами обучения","Графическая заставка", "Выход" };


	char ch;
	while (true)
	{
		int x = 45, y = 10;
		GoToXY(x, y);
		int size = 2;
		for (int i = 0; i < size; i++)
		{
			if (i == active_menu) SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			if (i == active_menu) SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			else SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
			GoToXY(x, y++);
			cout << Menu[i] << endl;
		}

		ch = _getch();
		if (ch == -32) ch = _getch(); // Отлавливаем стрелочки
		switch (ch)
		{
		case ESC:
			return 0;
		case UP:
			if (active_menu > 0)
				--active_menu;
			break;
		case DOWN:
			if (active_menu < size - 1)
				++active_menu;
			break;
		case ENTER:
			switch (active_menu)
			{
			case 0: system("CLS");
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				mass1();
				system("CLS");
				break;
			case 1: system("CLS");
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				mass2();
				system("CLS");
				break;
			}
		}
	}
}
//АНИМАЦИЯ
void animation()
{
	system("cls");
	srand(time(NULL));
	HDC screen = GetDC(GetConsoleWindow());
	HPEN pensun = CreatePen(PS_DASH, 120, RGB(252, 211, 2));
	HPEN penearth = CreatePen(PS_DASH, 30, RGB(84, 181, 7));
	HPEN penmoon = CreatePen(PS_DASH, 10, RGB(124, 124, 124));
	HPEN penback = CreatePen(PS_DASH, 100, RGB(12, 12, 12));
	char key;
	int x0 = 500;
	int y0 = 230;
	int r = 180;
	int rr = 30;
	int xe, ye, xm, ym;
	float pi = 3.1415;
	SelectObject(screen, pensun);
	MoveToEx(screen, x0, y0, NULL);
	LineTo(screen, x0, y0);
	while (true)
	{
		for (int i = 0; i < 200; i++)
		{
			xe = x0 + r * cos(pi * i / 50);
			ye = y0 - r * sin(pi * i / 50);
			xm = xe + rr * cos(pi * i / 10);
			ym = ye - rr * sin(pi * i / 10);
			SelectObject(screen, penearth);
			MoveToEx(screen, xe, ye, NULL);
			LineTo(screen, xe, ye);
			SelectObject(screen, penmoon);
			MoveToEx(screen, xm, ym, NULL);
			LineTo(screen, xm, ym);
			Sleep(50);
			SelectObject(screen, penback);
			MoveToEx(screen, xe, ye, NULL);
			LineTo(screen, xe, ye);
			if (_kbhit())
			{
				key = _getch();
				if (key == ESC)
				{
					system("cls");
					return;
				}
			}
		}
		
	}
}
//Обучающая программа по типам данных в С++ 
struct val_test
{
	string vopros[32], AnswerOptions[96];
	int otvet[32];
	string obyasnenie[32];
};
void RANDOM(int* array, int size) {
	int num;
	bool isExists;

	for (int i = 0; i < size; i++) {
		do {
			num = (rand() % size);
			isExists = false;

			for (int j = 0; j < i; j++) {
				if (array[j] == num) {
					isExists = true;
					break;
				}
			}
		} while (isExists);

		array[i] = num;
	}
}
int dataTypes()
{
	SetConsoleTitle(L"Типы в языке С/С++» с элементами обучения");
	system("cls");
	system("chcp 1251");
	system("cls");
	ifstream vopros("вопросы.txt"), answer("варианты ответов_1.txt"),
		otvet("ответы для клавиатуры.txt"), poyasn("пояснение к вопросам.txt");
	val_test exam[32];
	int	prav_otvtetov = 0, num[32];
	for (int i = 0; i < 32; i++)
	{
		getline(vopros, exam->vopros[i]);
		//getline(answer, exam->AnswerOptions[i]);
		otvet >> exam->otvet[i];
		getline(poyasn, exam->obyasnenie[i]);
	}
	for (int i = 0; i < 96; i++) {
		getline(answer, exam->AnswerOptions[i]);
	}
	RANDOM(num, size(num));
	for (int i = 0; i < 32; i++)
	{
		system("cls");

		int j = num[i];
		SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_RED);
		int x = 45, y = 2;
		GoToXY(x, y); cout << "КОЛИЧЕСТВО ВЕРНЫХ ОТВЕТОВ:" << prav_otvtetov << endl << endl;
		GoToXY(x, ++y); cout << "ВОПРОС № " << i + 1;
		SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);
		GoToXY(x, ++++++y);
		//вопрос
		cout << exam->vopros[j] << endl;
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		// варианты ответов
		int m = (j + 1) * 3 - 3;
		GoToXY(x, ++++y);
		cout << exam->AnswerOptions[m] << endl;// << exam->otvet[i] << endl;
		GoToXY(x, ++y);
		cout << exam->AnswerOptions[++m] << endl;
		GoToXY(x, ++y);
		cout << exam->AnswerOptions[++m] << endl;
		GoToXY(x, ++++y);
		cout << "ВАШ ОТВЕТ: ";
		int value = _getch();
		if (value == ESC)return 0;
		cout << value - 48 << endl; GoToXY(x, ++++y);
		if (value == (int)exam->otvet[j])
		{
			SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
			cout << "ВЕРНО!!!" << endl;
			prav_otvtetov++;
			SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_RED);
			GoToXY(45, 2); cout << "КОЛИЧЕСТВО ВЕРНЫХ ОТВЕТОВ:" << prav_otvtetov << endl << endl;
		}
		else
		{
			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
			cout << "НЕПРАВИЛЬНО!!!" << endl;
			SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
			GoToXY(x, ++++y);
			cout << "ПРАВИЛЬНЫЙ ОТВЕТ:" << exam->otvet[j] - 48 << endl;
			GoToXY(x, ++y);
			SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << exam->obyasnenie[j] << endl;
		}
		SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_RED);
		_getch();


	}
	_getch();
	double result = (float)prav_otvtetov / 32 *100;
	system("CLS");
	GoToXY(45, 7);
	cout << "ТЕСТ ЗАВЕРШЕН" << endl;
	GoToXY(45, 8);
	
	GoToXY(45, 9);

	if (prav_otvtetov > 28) {
		SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
		cout << "РЕЗУЛЬТАТ " << result<<"%"<< endl;
	}
	else if (prav_otvtetov > 16) {
		SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_RED);
		cout << "РЕЗУЛЬТАТ " << result << "%" << endl;
	}
	else if (prav_otvtetov <= 16) {
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
		cout << "РЕЗУЛЬТАТ " << result << "%" << endl;
	}
	poyasn.close();
	vopros.close();
	answer.close();
	otvet.close();
	_getch();
	return 0;
}
int main()
{

	SetConsoleTitle(L"MENU");
	system("CLS");
	setlocale(0, "RUS");
	ConsoleCursorVisible(false, 100);
	string Menu[] = { "Об авторе","Сортировка и поиск чисел в массивах",
		"Типы в языке С/С++ с элементами обучения","Графическая Заставка", "Выход" };
	int active_menu = 0;

	char ch;
	while (true)
	{
		int x = 40, y = 10;
		GoToXY(x, y);

		for (int i = 0; i < size(Menu); i++)
		{
			if (i == active_menu) SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			if (i == active_menu) SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			else SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
			GoToXY(x, y++);
			cout << Menu[i] << endl;
		}

		ch = _getch();
		if (ch == -32) ch = _getch(); // Отлавливаем стрелочки
		switch (ch)
		{
		case ESC:
			exit(0);
		case UP:
			if (active_menu > 0)
				--active_menu;
			break;
		case DOWN:
			if (active_menu < size(Menu) - 1)
				++active_menu;
			break;
		case ENTER:
			switch (active_menu)
			{
			case 0: system("CLS");
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				authr();
				system("CLS");
				break;
			case 1: system("CLS");
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				sortirovka();
				system("CLS");
				break;
			case 2: system("CLS");
				GoToXY(x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				dataTypes();
				system("CLS");
				break;
			case 3:
				system("CLS");
				GoToXY(x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				animation();
				system("CLS");
				break;
			case 4:
				exit(0);

			}
			break;

		}
	}
}
