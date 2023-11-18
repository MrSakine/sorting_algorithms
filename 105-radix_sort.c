#include "sort.h"

int get_max_value(int *array, int size);

/**
 * radix_sort - sorts an array of integers
 * in ascending order using the Radix sort algorithm
 *
 * @array: array of int.
 * @size: size of the array.
 *
 * Return: max value in the array.
 */
void radix_sort(int *array, size_t size)
{
	int *result;
	int i;
	int digit_place = 1;
	int largest_number;

	if (array == NULL || size < 2)
		return;

	result = malloc(size * sizeof(int));
	if (!result)
		return;

	largest_number = get_max_value(array, size);

	while ((largest_number / digit_place) > 0)
	{
		int count[10] = {0};

		for (i = 0; i < (int)size; i++)
			count[(array[i] / digit_place) % 10]++;

		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (i = size - 1; i >= 0; i--)
		{
			result[count[(array[i] / digit_place) % 10] - 1] = array[i];
			count[(array[i] / digit_place) % 10]--;
		}

		for (i = 0; i < (int)size; i++)
			array[i] = result[i];

		print_array(array, size);
		digit_place *= 10;
	}

	free(result);
}

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
