// PR2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы. 
// 

#include <time.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <iostream> 
#include <chrono> 

using namespace std;
int main()
{
	std::chrono::seconds sec(1);
	setlocale(LC_ALL, "rus");
	const int N = 100;
	int arr[N];
	int brr[N];
	int i;
	int znak;
	int ch;
	int cik = 1;
	int p = 0;
	int max = -99, min = 99;
	int avg;
	int k;
	int a;
	int b;

	cout << "Полученый массив: \n";
	for (i = 0; i < N; i++) {
		if (i % 10 == 0) cout << "\n";
		znak = rand() % 2;
		if (znak == 0) {
			arr[i] = rand() % 100;
		}
		if (znak == 1) {
			arr[i] = -rand() % 100;
		}

		if (arr[i] >= 0) cout << " ";
		if (abs(arr[i]) / 10 == 0) cout << " ";
		cout << arr[i] << " ";
	}
	cout << "\n \n Отсортированный массив: \n";
	auto begin = chrono::steady_clock::now();
	for (int i = 0; i < N; i++) {
		brr[i] = arr[i];
	}

	while (true)
	{
		p = 0;
		for (int i = 0; i < 99; i++)
		{

			if (brr[i] > brr[i + 1])
			{
				swap(brr[i], brr[i + 1]);
				p = 1;
			}


		}
		if (p == 0)
			break;

	}
	auto end = chrono::steady_clock::now();
	auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);

	for (i = 0; i < N; i++) {
		if (i % 10 == 0) cout << "\n";

		if (abs(brr[i]) / 10 == 0) cout << " ";
		if (brr[i] >= 0) cout << " ";
		cout<<  brr[i] << " ";

	}
	cout << "\n" << "Время сортировки: " << elapsed_ms.count() << " мкс\n";


	while (cik == 1) {

		cout
			<< "\n" << "1) Найти максимальный и минимальный элемент массива"
			<< "\n" << "2) Среднее значение максимального и минимального элементов"
			<< "\n" << "3) Элементы меньше вводимого числа"
			<< "\n" << "4) Элементы больше вводимого числа"
			<< "\n" << "5) Проверить наличие вводимого числа в массиве"
			<< "\n" << "6) Поменять местами два элемента"
			<< "\n" << "ALT+F4 - выйти из программы" << "\n";
		cin >> ch;
		if (ch < 1 || ch>6) cout << "Введите другое число";

		if (ch == 1) {
			auto begin = chrono::steady_clock::now();
			max = -99, min = 99;
			for (i = 0; i < N; i++) {
				if (arr[i] > max) max = arr[i];
				if (arr[i] < min) min = arr[i];
			}
			auto end = chrono::steady_clock::now();
			auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);
			cout << "Наибольший элемент массива: " << max<<"\n";
			cout << "Наименьший элемент массива: " << min << "\n";
			cout << "\n" << "Неотсортированный массив: " << elapsed_ms.count() << " мкс\n";
			begin = chrono::steady_clock::now();
			max = -99, min = 99;
			for (i = 0; i < N; i++) {
				if (brr[i] > max) max = arr[i];
				if (brr[i] < min) min = arr[i];
			}
			end = chrono::steady_clock::now();
			elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);
			cout << "\n" << "Отсортированный массив: " << elapsed_ms.count() << " мкс\n";
		}
		if (ch == 2) {
			max = -99, min = 99;
			for (i = 0; i < 99; i++) {
				if (arr[i] > max) max = arr[i];
				if (arr[i] < min) min = arr[i];
			}
			avg = (max + min) / 2;
			cout << "\nСреднее значение: " << avg<<"\n";
			k = 0;
			cout <<"Индексы элементов, равных среднему значению: ";
			for (i = 0; i < N; i++) {
				if (arr[i] == avg) {
					k = k + 1;
					cout << i <<" ";
				}
			}
			cout << "\nКоличество элементов: " << k;
		}
		if (ch == 3) {
			k = 0;
			cout << "\nВведите число: ";
			cin >> a;
			for (i = 0; i < N; i++) {
				if (brr[i] < a)
					k = k + 1;
			}
			cout << "\nКоличество элементов: " << k;
		}
		if (ch == 4) {
			k = 0;
			cout << "\nВведите число: ";
			cin >> a;
			for (i = 0; i < N; i++) {
				if (brr[i] > a)
					k = k + 1;
				auto end = chrono::steady_clock::now();
				auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);

			}
			cout << "\nКоличество элементов: " << k;
		}
		if (ch == 5) {
			cout << "\nВведите число: ";
			cin >> a;
			auto begin = chrono::steady_clock::now();
			for (i = 0; i < N; i++) {
				if (brr[i] == a) {
					auto end = chrono::steady_clock::now();
					auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);
					cout << "\n" << "Элемент найден обычным перебором за " << elapsed_ms.count() << " мкс\n";
					break;
				}
				if (i == N - 1)cout << "\nЭлемент не найден обычным перебором";
			}
			begin = chrono::steady_clock::now();
			if (a > brr[50]) {

				for (i = 50; i < N; i++) {
					if (brr[i] == a) {
						auto end = chrono::steady_clock::now();
						auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);
						cout << "\n" << "Элемент найден бинарным перебором за " << elapsed_ms.count() << " мкс\n";
						break;
					}
					if (i == N - 1)cout << "\nЭлемент не найден бинарным перебором";
				}
			}
			if (a < brr[50]) {
				for (i = 50; i > 0; i--) {
					if (brr[i] == a) {
						auto end = chrono::steady_clock::now();
						auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);
						cout << "\n" << "Элемент найден бинарным перебором за " << elapsed_ms.count() << " мкс\n";
						break;
					}
					if (i == 0)cout << "\nЭлемент не найден бинарным перебором";
				}
			}
			if (a == brr[50]) {
				auto end = chrono::steady_clock::now();
				auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);
				cout << "\n" << "Элемент найден бинарным перебором за " << elapsed_ms.count() << " мкс\n";
			}
		}
		if (ch == 6) {
			cout << "\nВведите индекс первого числа: ";
			cin >> a;
			cout << "\nВведите индекс второго числа: ";
			cin >> b;
			if (a < 0 || a>99 || b < 0 || b>99) cout << "\nВы ввели несуществующий индекс";
			else {
			auto begin = chrono::steady_clock::now();
			swap(arr[a], arr[b]);
			auto end = chrono::steady_clock::now();
			cout << "\nПолученый массив: \n";
			for (i = 0; i < N; i++) {
				if (i % 10 == 0) cout << "\n";
				if (arr[i] >= 0) cout << " ";
				if (abs(arr[i]) / 10 == 0) cout << " ";
				cout << arr[i] << " ";
			}
			auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);
			cout << "\n" << "Элементы поменяны местами за " << elapsed_ms.count() << " мкс\n";
		}
		}

	}

	return 0;
}