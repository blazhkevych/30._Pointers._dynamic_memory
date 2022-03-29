﻿// Функция получает указатель на массив и его размер, и 
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