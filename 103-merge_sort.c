#include "sort.h"

void copy_array(
		int *array, int *dest, size_t start, size_t end);
void top_down_split_merge(
		int *sorted_data, int *source, size_t start, size_t end);
void top_down_merge(
		int *sorted_data, int *source, size_t start, size_t middle, size_t end);
/**
 * merge_sort - sorts an array of integers in
 * ascending order using the Merge sort algorithm
 *
 * @array: The array to be used
 * @size: Number of elements in @array
 *
 * Return: Nothing (void)
 */
void merge_sort(int *array, size_t size)
{
	int *copy;

	if (array == NULL || size < 2)
		return;

	copy = malloc(size * sizeof(int));
	if (!copy)
		return;

	copy_array(array, copy, 0, size);
	top_down_split_merge(array, copy, 0, size);
	free(copy);
}

/**
 * copy_array - copy array into another one
 *
 * @array: The array to be used
 * @dest: pointer to the dest
 * @start: starting point
 * @end: ending point
 *
 * Return: Nothing (void)
 */
void copy_array(int *array, int *dest, size_t start, size_t end)
{
	size_t i;

	for (i = start; i < end; i++)
		dest[i] = array[i];
}

/**
 * top_down_split_merge - split @source into 2 runs,
 * sort both runs into @sorted_data,
 * merge both runs from @sorted_data to @source
 * start is inclusive;
 * end is exclusive (source[end] is not in the set)
 *
 * @sorted_data: The array to be used
 * @source: pointer to the new source (copy)
 * @start: starting point
 * @end: ending point
 *
 * Return: Nothing (void)
 */
void top_down_split_merge(
		int *sorted_data, int *source, size_t start, size_t end)
{
	size_t middle;

	if (end - start <= 1)
		return;

	middle = (start + end) / 2;
	top_down_split_merge(source, sorted_data, start, middle);
	top_down_split_merge(source, sorted_data, middle, end);
	top_down_merge(sorted_data, source, start, middle, end);
}

/**
 * top_down_merge - run top down merge algorithm
 *
 * @sorted_data: The array to be used
 * @source: pointer to the new source (copy)
 * @start: starting point
 * @middle: middle point
 * @end: ending point
 *
 * Return: Nothing (void)
 */
void top_down_merge(
		int *sorted_data, int *source, size_t start, size_t middle, size_t end)
{
	size_t i = start;
	size_t j = middle;
	size_t k;

	printf("Merging...\n[left]: ");
	print_array(source + start, middle - start);

	printf("[right]: ");
	print_array(source + middle, end - middle);

	for (k = start; k < end; k++)
	{
		if (i < middle && (j >= end || source[i] <= source[j]))
		{
			sorted_data[k] = source[i];
			i++;
		}
		else
		{
			sorted_data[k] = source[j];
			j++;
		}
	}

	printf("[Done]: ");
	print_array(sorted_data + start, end - start);
}
