#include "sort.h"

void quick_sort_recursion(int *array, size_t size, size_t start, size_t end);
int quick_sort_partition(int *array, size_t size, size_t start, size_t end);
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

	if (start - end > 0)
	{
		pivot = quick_sort_partition(array, size, end, start);
		quick_sort_recursion(array, size, start, pivot - 1);
		quick_sort_recursion(array, size, pivot, end);
	}
}

/**
 * quick_sort_partition - look for a pivot from the array
 * @array: The array to be used
 * @size: size of the array.
 * @start: start index of the array
 * @end: end index of the array
 *
 * Return: Nothing (void)
 */
int quick_sort_partition(int *array, size_t size, size_t start, size_t end)
{
	int pivot, above, below;

	pivot = array[start];
	for (above = end - 1, below = start + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_quick_sort(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
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
