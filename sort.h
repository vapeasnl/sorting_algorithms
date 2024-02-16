#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/* Comparison direction macros for bitonic sort */
#define UP 0
#define DOWN 1

/**
 * enum bool - Enumeration of Boolean values.
 * @false: Equals 0.
 * @true: Equals 1.
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Printing helper functions */
void array_print(const int *array, size_t size);
void list_print(const listint_t *list);

/* Sorting algoritms */
void s_bubble(int *array, size_t size);
void s_insertlist(listint_t **list);
void s_selection(int *array, size_t size);
void s_quick(int *array, size_t size);
void s_shell(int *array, size_t size);
void s_cocktaillist(listint_t **list);
void s_counting(int *array, size_t size);
void s_merge(int *array, size_t size);
void s_heap(int *array, size_t size);
void s_radix(int *array, size_t size);
void s_bitonic(int *array, size_t size);
void s_quickhoare(int *array, size_t size);

#endif /* SORT_H */
