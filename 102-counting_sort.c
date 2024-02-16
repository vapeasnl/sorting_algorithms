#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
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
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void s_counting(int *array, size_t size)
{
	int *cnt, *srtd, max, i;

	if (array == NULL || size < 2)
		return;

	srtd = malloc(sizeof(int) * size);
	if (srtd == NULL)
		return;
	max = get_max(array, size);
	cnt = malloc(sizeof(int) * (max + 1));
	if (cnt == NULL)
	{
		free(srtd);
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
		srtd[cnt[array[i]] - 1] = array[i];
		cnt[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = srtd[i];

	free(srtd);
	free(cnt);
}
