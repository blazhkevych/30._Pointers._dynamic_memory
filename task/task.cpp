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

			delete[]ptr;
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
			int C_size{ 0 };
			int* ptrC_size = &C_size;
			int* ptrC = ElOfArrAWhichNotInArrB(ptrA, ptrB, M, N, ptrC_size);
			Print(ptrC, C_size);

			delete[] ptrA;
			delete[] ptrB;
			delete[] ptrC;
		}
		break;

		case 4:
		{
			/*
			4. Написать функцию, которая позволяет добавлять массив в конец
			динамического массива. Функция должна возвращать указатель на
			динамический массив.
			*/
			const int arr_Size{ 10 }; // Размер массива.
			int arrA[arr_Size]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // Создаем массив.

			int sizeB{ 0 };
			cout << "sizeA: ";
			cin >> sizeB;

			int* ptrB = Allocate(sizeB);
			ptrB = AddArrToTheEndOfADynamicArr(ptrB, &sizeB, arrA, arr_Size);
			cout << endl;
			Print(ptrB, sizeB);

			delete[] ptrB;
		}
		break;

		case 5:
		{
			/*
			5. Написать функцию, которая позволяет вставлять блок элементов
			(одномерный массив) в указанную позицию динамического массива.
			Функция должна возвращать указатель на динамический массив.
			*/
			int sizeA{ 5 };
			int sizeB{ 5 };
			int* ptrSizeA = &sizeA;
			int* ptrSizeB = &sizeB;
			int* ptrA = Allocate(sizeA);
			int* ptrB = Allocate(sizeB);
			Init(ptrA, sizeA, 1, 99);
			Init(ptrB, sizeB, 1, 99);
			cout << "ptrA :"
				<< endl;
			Print(ptrA, sizeA);
			cout << "\nptrB :"
				<< endl;
			Print(ptrB, sizeB);
			cout << "\nEnter an index to insert: ";
			int index{ 0 };
			cin >> index;
			ptrB = InsertArrInArrByIndex(ptrA, &sizeA, ptrB, &sizeB, index);
			cout << "\nptrA in ptrB:"
				<< endl;
			Print(ptrB, sizeB);

			delete[] ptrB;
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
			int size{ 5 };
			int* ptrA = Allocate(size);
			Init(ptrA, size, 2, 19);
			Print(ptrA, size);
			ptrA = DelPrimeNumInArr(ptrA, &size);
			cout << endl;
			Print(ptrA, size);

			delete[]ptrA;
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