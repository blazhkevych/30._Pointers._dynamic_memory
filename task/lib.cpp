#include <iostream>
using std::cout;
using std::endl;
// Функция получает указатель на массив и его размер, и 
// заполняет массив случайными числами
void Init(int ptr[], int size, int min, int max)
{
	for (int i = 0; i < size; i++)
	{
		*ptr = rand() % (max - min + 1) + min;
		ptr++;
	}
}

// Функция получает указатель на массив и его размер, и 
// выводит массив на экран
void Print(int* ptr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << ptr[i] << '\t';
	}
}

//Возвращает количество отрицательных, положительных и нулевых элементов массива.
void NegPosZeroArrEl(int ptr[], int size, int* ptrNeg, int* ptrPos, int* ptrZero)
{
	for (int i = 0; i < size; i++)
	{
		if (ptr[i] < 0)
			(*ptrNeg)++;
		else if (ptr[i] > 0)
			(*ptrPos)++;
		else
			(*ptrZero)++;
	}
}

// функция создания динамического массива
int* Allocate(int size)
{
	return new int[size];
}

// функция удаления динамического массива
void Free(int* ptr)
{
	delete[] ptr;
}

// функция добавления элемента в конец массива
int* Add(int* ptr, int* size, int value)
{
	int* p = new int[++ * size];
	for (int i = 0; i < *size - 1; i++)
		p[i] = ptr[i];
	p[*size - 1] = value;
	delete[]ptr;
	return p;
}

// функция вставки элемента по указанному индексу 
int* InsertByIndex(int* ptr, int* size, int value, int index)
{
	if (index < 0 || index > *size - 1)
		return ptr;
	int* p = new int[++ * size];
	int k = 0;
	for (int i = 0; i < *size; i++)
	{
		if (index == i)
		{
			k = 1;
			p[i] = value;
		}
		else
			p[i] = ptr[i - k];
	}
	delete[]ptr;
	return p;
}

// функция удаления элемента по указанному индексу
int* RemoveByIndex(int* ptr, int* size, int index)
{
	if (index < 0 || index > *size - 1)
		return ptr;
	int* p = new int[-- * size];
	int k = 0;
	for (int i = 0; i < *size; i++)
	{
		if (index == i)
			k = 1;
		p[i] = ptr[i + k];
	}
	delete[]ptr;
	return p;
}

// Функция удаляет из массива все отрицательные числа и возвращает указатель на новый динамический массив.
int* DelNeg(int* ptr, int* size)
{
	int newSize{ 0 };
	for (int i = 0; i < *size; i++)
	{
		if (ptr[i] >= 0)
			newSize++;
	}
	if (newSize < 1 || newSize > *size - 1)
		return ptr;
	int* p = new int[newSize] {0};
	int k{ 0 };
	for (int i = 0; i < *size; i++)
	{
		if (ptr[i] > 0)
		{
			p[k++] = ptr[i];
		}
	}
	*size = newSize;
	delete[] ptr;
	return p;
}

// Функция создает третий массив минимально возможного размера, в котором собраны те элементы массива A, 
// которых нет в массиве B, без повторений.
int* ElOfArrAWhichNotInArrB(int* ptrA, int* ptrB, int M, int N, int* ptrC_size)
{
	int k{ 0 }; // Размер третьего массива.
	int povtor = 0;
	for (int i = 0; i < M; i++) // ptrA
	{
		povtor = 0;
		for (int j = 0; j < N; j++) // ptrB
		{
			if (ptrA[i] == ptrB[j]) // проверка на совпадение
			{
				povtor++;
				break; // при совпадении дальше не идем
			}
		}
		if (povtor == 0)
			k++;
	}
	//cout << endl << k << endl;

	int* ptrC = Allocate(k);
	int y{ 0 };
	for (int i = 0; i < M; i++) // ptrA
	{
		povtor = 0;
		for (int j = 0; j < N; j++) // ptrB
		{
			if (ptrA[i] == ptrB[j]) // проверка на совпадение
			{
				povtor++;
				break; // при совпадении дальше не идем
			}
		}
		if (povtor == 0)
		{
			for (int q = 0; q < k; q++) // ptrC
			{
				if (ptrA[i] == ptrC[q]) // проверка на совпадение
				{
					povtor++;
					k--;
					break; // при совпадении дальше не идем
				}
			}
			if (povtor == 0)
			{
				ptrC[y] = ptrA[i];
				y++;
			}
		}
	}
	*(ptrC_size) = k;
	return ptrC;
}

// функция, добавляет массив в конец динамического массива. Возвращает указатель на динамический массив.
int* AddArrToTheEndOfADynamicArr(int* ptrB, int* sizeB, int arrA[], int arr_Size)
{
	int newSize = arr_Size + *(sizeB);
	ptrB = Allocate(newSize);
	Init(ptrB, (newSize - arr_Size), -1, -1);
	int j{ 0 };
	for (int i = newSize - arr_Size; i < newSize; i++)
	{
		ptrB[i] = arrA[j];
		j++;
	}
	*(sizeB) = newSize;

	return ptrB;
}

// Функция проверяющая является ли число простым.
bool IsPrime(int number)
{
	if (number < 2)
		return false;
	for (int i = 2; i * i <= number; i++) // Проверка до квадратного корня из number.
		if (number % i == 0) // Если найден другой делитель числа number.
			return false;
	return true;
}

// Функция возвращающая количество простых чисел в массиве.
int NumberOfPrimesIn1DArr(int* ptrA, int size)
{
	int count{ 0 };

	for (int i = 0; i < size; i++)
		if (IsPrime(ptrA[i]))
			count++;

	return count;
}

// Функция, получает указатель на динамический
// массив и его размер. Удаляет из массива все
// простые числа и возвращает указатель на новый динамический массив.
int* DelPrimeNumInArr(int* ptrA, int* size)
{
	int n = NumberOfPrimesIn1DArr(ptrA, *(size));
	int newSize = *(size)-n;
	int* ptrB = Allocate(newSize);
	int j{ 0 };
	for (int i = 0; i < *(size); i++) // бежим до размера старого массива
	{
		if (IsPrime(ptrA[i]) == false)
		{
			ptrB[j] = ptrA[i];
			j++;
		}
	}
	*(size) = newSize;
	return ptrB;
}

// Функция, которая позволяет вставлять блок элементов
// (одномерный массив) в указанную позицию динамического массива.
// Функция возвращает указатель на динамический массив.
int* InsertArrInArrByIndex(int* ptrA, int* sizeA, int* ptrB, int* sizeB, int index)
{
	int sizeP = *sizeA + *sizeB;
	if (index < 0 || index > sizeP - *sizeA)
		return ptrB;
	int* p = new int[sizeP];
	int k = index + *sizeA;
	int j{ 0 }, q{ 0 };
	for (int i = 0; i < sizeP; i++)
	{
		if (i < index || i >= k)
		{
			p[i] = ptrB[j];
			j++;
		}
		else if (i >= index && i < k)
		{
			p[i] = ptrA[q];
			q++;
		}
	}
	*sizeB = sizeP;
	delete[]ptrA;
	return p;
}

// Функция, которая позволяет удалять с произвольного
// индекса указанное количество элементов из динамического
// массива.Функция должна возвращать указатель на динамический
// массив.
int* RemoveByIndexInArr(int* ptrA, int* sizeA, int index, int amount)
{
	int sizeP = *sizeA - amount;
	if (index < 0 || index > *sizeA - amount)
		return ptrA;
	int* p = new int[sizeP];
	int j = 0;
	for (int i = 0; i < *sizeA; i++)
	{
		if (i < index || i >= index + amount)
		{
			p[j] = ptrA[i];
			j++;
		}
	}
	*sizeA = sizeP;
	delete[]ptrA;
	return p;
}