#include "sort.h"

/**
 * swap - swaps two int.
 * @current: the first int.
 * @next: the second int.
 * Return: Nothing (void)
*/

void swap(int *current, int *next)
{
	int temp;

	temp = *current;
	*current = *next;
	*next = temp;
}

/**
 * lomuto_partition - order a subnet of an array.
 * @array: array of int.
 * @size: size of the array.
 * @left: the starting index.
 * @right: the ending index.
 * Return: above (0).
*/
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;

	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Sort algo through recursion.
 * @array: array of int.
 * @size: size of the array.
 * @left: starting index.
 * @right: ending index.
 * Return: Nothing (void).
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: an array of int.
 * @size: size of the array.
 * Return: Nothing (void).
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
