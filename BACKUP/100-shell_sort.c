#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * s_shell - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void s_shell(int *array, size_t size)
{
	size_t sp, i, j;

	if (array == NULL || size < 2)
		return;

	for (sp = 1; sp < (size / 3);)
		sp = sp * 3 + 1;

	for (; sp >= 1; sp /= 3)
	{
		for (i = sp; i < size; i++)
		{
			j = i;
			while (j >= sp && array[j - sp] > array[j])
			{
				swap_ints(array + j, array + (j - sp));
				j -= sp;
			}
		}
		array_print(array, size);
	}
}
