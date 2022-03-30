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