#include "sort.h"

/**
 * swap - swaps two int.
 * @num1: int number 1.
 * @num2: int number 2.
 * Return: Nothing (void).
*/
void swap(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}


/**
 * heapify - Perform the heapify operation on the heap.
 * @array: array of int.
 * @size: size of the array.
 * @base: index of the base row in the array.
 * @index: index to start the heap operation.
 * Return: Nothing (void).
*/
void heapify(int *array, size_t size, size_t base, size_t index)
{
	size_t left, right, largest;

	left = 2 * index + 1;
	right = 2 * index + 2;
	largest = index;

	if (left < base && array[left] > array[largest])
		largest = left;

	if (right < base && array[right] > array[largest])
		largest = right;

	if (largest != index)
	{
		swap(array + index, array + largest);
		print_array(array, size);
		heapify(array, size, base, largest);
	}
}

/**
* heap_sort -  sorts an array of integers in ascending
* order using the Heap sort algorithm.
* @array: array of int.
* @size: size of the array.
* Return: Nothing (void).
*/
void heap_sort(int *array, size_t size)
{
	int i;

	if (size < 2 || array == NULL)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, array + i);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}
