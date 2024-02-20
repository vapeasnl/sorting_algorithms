#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

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
 * bitonic_merge - Sort a bitonic sequence inside array.
 * @array: array.
 * @size: size.
 * @start: start.
 * @seq: size of the sequence to sort.
 * @flow: direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, j = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + j; i++)
		{
			if ((flow == UP && array[i] > array[i + j]) ||
			    (flow == DOWN && array[i] < array[i + j]))
				swap_ints(array + i, array + i + j);
		}
		bitonic_merge(array, size, start, j, flow);
		bitonic_merge(array, size, start + j, j, flow);
	}
}

/**
 * bitonic_seq - Convert array into a bitonic sequence.
 * @array: array.
 * @size: size.
 * @start: starting index of a block of the building bitonic sequence.
 * @seq: size of a block of the building bitonic sequence.
 * @flow: direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort array.
 * @array: array.
 * @size: size.
*/
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
