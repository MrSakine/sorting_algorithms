#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 *
 * @array: The array to be used
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t j, i;
	int temp;

	if (array == NULL || size < 2)
		return;

	i = 0;
	while (i < ((size * 2) + 1))
	{
		for (j = 0; (j + 1) < size; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
		i++;
	}
}

