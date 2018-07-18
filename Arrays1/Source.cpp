#include<iostream>
#include<time.h>
#include<iomanip>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	int n = 0;
	start:
	cout << "Введите номер задания." << endl;
	cin >> n;

	if (n == 1)
	{
		cout << "Написать программу, которая заполняет массив случайными числами и меняет порядок элементов в каждом столбце на обратный." << endl;

		int a[5][6];

		cout << "Изначальный массив:" << endl;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				a[i][j] = 1 + rand() % 15;
				cout << setw(4) << a[i][j];
			}
			cout << endl;
		}

		cout << endl;

		for (int j = 0; j < 6; j++)
		{
			for (int i = 0; i < 5 / 2; i++)
			{
				swap(a[i][j], a[4 - i][j]);
			}
		}

		cout << "Результат:" << endl;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				cout << setw(4) << a[i][j];
			}
			cout << endl;
		}

	}

	else if (n == 2)
	{
		cout << "Написать программу, которая заполняет массив 5х5 оценками по 12 бальной системе, преобразовать их в оценки по 5 бальной системе. Двойкой считается оценка ниже 4, тройкой – от 4 до 6 и т.д." << endl;
		int a[5][5];

		cout << "Изначальный массив:" << endl;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				a[i][j] = 1 + rand() % 12;
				cout << setw(4) << a[i][j];
			}
			cout << endl;
		}
		cout << endl;

		cout << "Результат:" << endl;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				switch (a[i][j])
				{
				case 1:
				case 2:
				case 3: a[i][j] = 2;
					break;
				case 4:
				case 5:
				case 6: a[i][j] = 3;
					break;
				case 7:
				case 8:
				case 9: a[i][j] = 4;
					break;
				case 10:
				case 11:
				case 12: a[i][j] = 5;
					break;
				}
				cout << setw(4) << a[i][j];
			}
			cout << endl;
		}
	}

	else if (n == 3)
	{
		cout << "Заполнить двухмерный массив 8х8 значениями 0 и 1 случайным образом, но так, чтобы нулей было в два раза больше, чем единичек." << endl;

		int a[8][8];
		int c_zero = 0;
		int c_one = 0;

		cout << "Изначальный массив:" << endl;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				a[i][j] = rand() % 2;
				cout << setw(4) << a[i][j];
			}
			cout << endl;
		}

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (a[i][j] == 0)
				{
					c_zero++;
				}
				else
				{
					c_one++;
				}
			}
		}

		cout << "Всего нулей = " << c_zero << endl;
		cout << "Всего единиц = " << c_one << endl;
		cout << "Соотношение нулей к единичкам = " << (float)c_zero / c_one << endl;

		for (int i, j; c_one > 8 * 8 / 3; )
		{
			i = rand() % 8;
			j = rand() % 8;
			if (a[i][j])
			{
				a[i][j] = 0;
				c_one--;
			}
		}
		c_zero = 0; c_one = 0;

		cout << "Результат:" << endl;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cout << setw(4) << a[i][j];
				if (a[i][j])
				{
					c_one++;
				}
				else
				{
					c_zero++;
				}
			}
			cout << endl;
		}

		cout << "Всего единиц = " << c_one << endl;
		cout << "Всего нулей = " << c_zero << endl;
		cout << "Соотношение нулей к единичкам = " << (float)c_zero / c_one << endl;
	}
	goto start;
	system("pause");
	return 0;

}