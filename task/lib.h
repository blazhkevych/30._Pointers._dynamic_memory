// Функция получает указатель на массив и его размер, и 
// заполняет массив случайными числами
void Init(int ptr[], int size, int min, int max);

// Функция получает указатель на массив и его размер, и 
// выводит массив на экран
void Print(int* ptr, int size);

//Возвращает количество отрицательных, положительных и нулевых элементов массива.
void NegPosZeroArrEl(int ptr[], int size, int* ptrNeg, int* ptrPos, int* ptrZero);

// функция печати массива
void Print(int* ptr, int size);

// функция создания динамического массива
int* Allocate(int size);

// функция удаления динамического массива
void Free(int* ptr);

// функция добавления элемента в конец массива
int* Add(int* ptr, int* size, int value);

// функция вставки элемента по указанному индексу 
int* InsertByIndex(int* ptr, int* size, int value, int index);

// функция удаления элемента по указанному индексу
int* RemoveByIndex(int* ptr, int* size, int index);

// Функция удаляет из массива все отрицательные числа и возвращает указатель на новый динамический массив.
int* DelNeg(int* ptr, int* size);

// Функция создает третий массив минимально возможного размера, в котором собраны те элементы массива A, 
// которых нет в массиве B, без повторений.
int* ElOfArrAWhichNotInArrB(int* ptrArr1, int* ptrArr2, int M, int N, int* ptrC_size);

//функция, добавляет массив в конец динамического массива. Возвращает указатель на динамический массив.
int* AddArrToTheEndOfADynamicArr(int* ptrB, int* sizeB, int arrA[], int arr_Size);

// Функция проверяющая является ли число простым.
bool IsPrime(int number);

// Функция возвращающая количество простых чисел в массиве.
int NumberOfPrimesIn1DArr(int* ptrA, int size);

// Функция, получает указатель на динамический
// массив и его размер. Удаляет из массива все
// простые числа и возвращает указатель на новый динамический массив.
int* DelPrimeNumInArr(int* ptrA, int* size);

//Функция, которая позволяет вставлять блок элементов
//(одномерный массив) в указанную позицию динамического массива.
//Функция возвращает указатель на динамический массив.
int* InsertArrInArrByIndex(int* ptrA, int* sizeA, int* ptrB, int* sizeB, int index);