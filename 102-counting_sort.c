#include "sort.h"

/**
 * get_max - Get the maximum value in array.
 * @array: array.
 * @size: array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
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
 * counting_sort - Sort array in ascending order.
 * @array: array.
 * @size: array.
 */
void counting_sort(int *array, size_t size)
{
	int *cnt, *sorted, max, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	cnt = malloc(sizeof(int) * (max + 1));
	if (cnt == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		cnt[i] = 0;
	for (i = 0; i < (int)size; i++)
		cnt[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		cnt[i] += cnt[i - 1];
	print_array(cnt, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[cnt[array[i]] - 1] = array[i];
		cnt[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(cnt);
}
