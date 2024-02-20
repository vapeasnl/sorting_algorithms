#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: integer.
 * @b: integer.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Order a subset of an array.
 * @array: array.
 * @size: size.
 * @left: start.
 * @right: end.
 * Return: The final partition index.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int flip, up, down;

	flip = array[right];
	for (up = left - 1, down = right + 1; up < down;)
	{
		do {
			up++;
		} while (array[up] < flip);
		do {
			down--;
		} while (array[down] > flip);

		if (up < down)
		{
			swap_ints(array + up, array + down);
			print_array(array, size);
		}
	}

	return (up);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: array.
 * @size: size.
 * @left: start.
 * @right: end.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int p;

	if (right - left > 0)
	{
		p = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, p - 1);
		hoare_sort(array, size, p, right);
	}
}

/**
 * quick_sort_hoare - Sort array.
 * @array: array.
 * @size: size.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
