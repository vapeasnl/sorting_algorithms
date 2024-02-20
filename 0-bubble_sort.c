#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: integer 1.
 * @b: integer 2.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: array.
 * @size: array's size.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, l = size;
	bool bub = false;

	if (array == NULL || size < 2)
		return;

	while (bub == false)
	{
		bub = true;
		for (i = 0; i < l - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bub = false;
			}
		}
		l--;
	}
}
