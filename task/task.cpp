#include <iostream>
#include "lib.h"
using std::endl;
using std::cin;
using std::cout;

int main()
{
	srand(time(0));
	char answer{ 0 };
	int choice{ 0 };

	do
	{
		cout << "Enter task number:: "
			<< "\nTask 1."
			<< "\nTask 2."
			<< "\nTask 3."
			<< "\nTask 4."
			<< "\nTask 5."
			<< "\nTask 6."
			<< "\nTask 7."
			<< endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			/*
			1. Написать функцию, которая получает указатель на массив и его
			размер, и возвращает количество отрицательных, положительных и
			нулевых элементов массива.
			*/
			const int size{ 10 };
			int arr[size]{ 0 };
			Init(arr, size, -10, 10);
			Print(arr, size);

			int neg{ 0 };
			int pos{ 0 };
			int zero{ 0 };
			int* ptrNeg = &neg;
			int* ptrPos = &pos;
			int* ptrZero = &zero;

			NegPosZeroArrEl(arr, size, ptrNeg, ptrPos, ptrZero);
			cout << "\nneg = " << neg << endl
				<< "zero = " << zero << endl
				<< "pos = " << pos << endl;
		}
		break;

		case 2:
		{
			/*
			2. Написать функцию, которая получает указатель на динамический
			массив и его размер. Функция должна удалить из массива все
			отрицательные числа и вернуть указатель на новый динамический
			массив.
			*/
			int* ptr{ nullptr };
			int size{ 10 };
			ptr = Allocate(size);
			Init(ptr, size, -10, 10);
			Print(ptr, size);
			ptr = DelNeg(ptr, &size);
			cout << endl;
			Print(ptr, size);
		}
		break;

		case 3:
		{
			/*
			3. Создать два массива: А[M] и B[N] (M и N вводятся с клавиатуры).
			Необходимо создать третий массив минимально возможного
			размера, в котором нужно собрать те элементы массива A, которых
			нет в массиве B, без повторений.
			*/
			/*int M{ 0 }, N{ 0 };
			int* ptrM = &M;
			int* ptrN = &N;
			cout << "Enter M: ";
			cin >> *(ptrM);
			cout << "\nEnter N: ";
			cin >> *(ptrN);

			int* ptrA{ nullptr };
			int* ptrB{ nullptr };
			ptrA = Allocate(*(ptrM));
			ptrB = Allocate(*(ptrN));
			Init(ptrA, *(ptrM), -10, 10);
			Init(ptrB, *(ptrN), -10, 10);
			cout << endl;
			Print(ptrA, *(ptrM));
			cout << endl;
			Print(ptrB, *(ptrN));
			cout << endl;*/
			int M{ 0 }, N{ 0 };
			cout << "Enter M: ";
			cin >> M;
			cout << "\nEnter N: ";
			cin >> N;
			int* ptrA = Allocate(M);
			int* ptrB = Allocate(N);
			Init(ptrA, M, -10, 10);
			Init(ptrB, N, -10, 10);
			cout << endl;
			Print(ptrA, M);
			cout << endl;
			Print(ptrB, N);
			cout << endl;
			ElOfArrAWhichNotInArrB(ptrA, ptrB, M, N);
		}
		break;

		case 4:
		{
			/*
			4. Написать функцию, которая позволяет добавлять массив в конец
			динамического массива. Функция должна возвращать указатель на
			динамический массив.
			*/

		}
		break;

		case 5:
		{
			/*
			5. Написать функцию, которая позволяет вставлять блок элементов
			(одномерный массив) в указанную позицию динамического массива.
			Функция должна возвращать указатель на динамический массив.
			*/

		}
		break;

		case 6:
		{
			/*
			6. Написать функцию, которая позволяет удалять с произвольного
			индекса указанное количество элементов из динамического
			массива. Функция должна возвращать указатель на динамический
			массив.
			*/

		}
		break;

		case 7:
		{
			/*
			7. Написать функцию, которая получает указатель на динамический
			массив и его размер. Функция должна удалить из массива все
			простые числа и вернуть указатель на новый динамический массив.
			*/

		}
		break;
		}

		cout << endl;
		cout << "Do you want to continue? ( y (yes) / n (no) )\n";
		cin >> answer;
		cout << endl;

	} while (answer == 'y');

	return 0;
}