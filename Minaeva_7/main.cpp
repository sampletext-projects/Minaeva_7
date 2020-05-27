#include <iomanip>
#include <iostream>

using namespace std;

void read_mas(double* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "[" << i + 1 << "] = ";
		cin >> mas[i];
	}
}

void write_mas(double* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << setw(3) << setprecision(5) << mas[i] << " ";
	}
	cout << "\n";
}


double arifm(double* mas, int size)
{
	double d = mas[1] - mas[0];
	for (int i = 2; i < size; i++)
	{
		if (mas[i] - mas[i - 1] != d)
		{
			return 0;
		}
	}
	return d;
}

double geom(double* mas, int size)
{
	double q = mas[1] / mas[0];
	for (int i = 2; i < size; i++)
	{
		if (mas[i] / mas[i - 1] != q)
		{
			return 1;
		}
	}
	return q;
}

void remove_start_end(double** mas, int& size)
{
	double* src = *mas;
	double* m = new double[size - 2];
	for (int i = 1; i < size - 1; i++)
	{
		m[i - 1] = src[i];
	}
	size = size - 2;
	*mas = m;
}

void demonstrate(double* mas, int size)
{
	cout << "Mas: ";
	write_mas(mas, size);

	double d = arifm(mas, size);
	if (d == 0)
	{
		cout << "Массив не образует арифметическую прогрессию.\n";
	}
	else
	{
		cout << "Массив образует арифметическую прогрессию. D = " << d << "\n";
	}

	double q = geom(mas, size);
	if (q == 1)
	{
		cout << "Массив не образует геометрическую прогрессию.\n";
	}
	else
	{
		cout << "Массив образует геометрическую прогрессию. Q = " << q << "\n";
	}
}

int main()
{
	setlocale(LC_ALL, "russian");

	cout << "Выполнила Минаева Полина Валерьевна УТН - 111\n";
	cout << "Программа для управления массивом с помощью функций\n";

	int size = 10;
	double* mas;

	mas = new double[size]{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
	demonstrate(mas, size);

	mas = new double[size]{2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0, 512.0, 1024.0};
	demonstrate(mas, size);

	mas = new double[size]{7, 17, 54, 12, 91, 87, 39, 56, 90, 37};
	demonstrate(mas, size);

	remove_start_end(&mas, size);
	cout << "После удаления первого и последнего элементов\nMas: ";
	write_mas(mas, size);

	system("pause");

	return 0;
}
