#include "sort.h"

/**
* get_max_value - finds the max value and return it.
* @array: array of int.
* @size: size of the array.
* Return: max value in the array.
*/
int get_max_value(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}


/**
 * counting_sort -  sorts an array of integers in ascending order using the
 * Counting sort algorithm.
 * @array: array of int.
 * @size: size of the array.
 * Return: Nothing (void).
*/
void counting_sort(int *array, size_t size)
{
	int *count_array, *sorted_array, max_value, i;

	if (array == NULL || size < 2)
		return;

	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
		return;
	max_value = get_max_value(array, size);

	count_array = malloc((max_value + 1) * sizeof(int));
	if (count_array == NULL)
	{
		free(sorted_array);
		return;
	}

	for (i = 0; i < (max_value + 1); i++)
		count_array[i] = 0;

	for (i = 0; i < (int)size; i++)
		count_array[array[i]] += 1;

	for (i = 0; i < (max_value + 1); i++)
		count_array[i] += count_array[i - 1];
	print_array(count_array, max_value + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = sorted_array[i];
	free(sorted_array);
	free(count_array);
}
