#include "sort.h"

void quick_sort_recursion(int *array, size_t size, size_t start, size_t end);
size_t quick_sort_partition(int *array, size_t start, size_t end);
void swap_quick_sort(int *current, int *next);

/**
 * quick_sort_hoare - run the sorting algorithm
 * @array: The array to be used
 * @size: Number of elements in @array
 *
 * Return: Nothing (void)
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursion(array, size, 0, size - 1);
}

/**
 * quick_sort_recursion - root of the sorting algorithm
 * @array: The array to be used
 * @size: Number of elements in @array
 * @start: start index of the array
 * @end: end index of the array
 *
 * Return: Nothing (void)
 */
void quick_sort_recursion(int *array, size_t size, size_t start, size_t end)
{
	size_t pivot;

	if (start < end)
	{
		pivot = quick_sort_partition(array, start, end);
		quick_sort_recursion(array, size, start, pivot);
		quick_sort_recursion(array, size, pivot + 1, end);
		print_array(array, size);
	}
}

/**
 * quick_sort_partition - look for a pivot from the array
 * @array: The array to be used
 * @start: start index of the array
 * @end: end index of the array
 *
 * Return: Nothing (void)
 */
size_t quick_sort_partition(int *array, size_t start, size_t end)
{
	int pivot;
	size_t i;
	size_t j;

	pivot = array[((end - start) / 2) + start];
	i = start - 1;
	j = end + 1;

	while (1)
	{
		do
			i++;
		while (array[i] < pivot);

		do
			j--;
		while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap_quick_sort(&array[i], &array[j]);
	}
}

/**
 * swap_quick_sort - swaps two int.
 * @current: the first int.
 * @next: the second int.
 *
 * Return: Nothing (void)
 */
void swap_quick_sort(int *current, int *next)
{
	int temp;

	temp = *current;
	*current = *next;
	*next = temp;
}
