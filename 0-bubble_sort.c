#include "sort.h"

/**
* bubble_sort - sorts an array of integers in ascending order
* @array: array of integers
* @size: size of array
* Return: void
*/
void bubble_sort(int *array, size_t size)
{
	size_t current_index, unsorted_size = size;
	int temporary_value;
	/* Flag to track if any swapping occurred */
	bool has_swapped = false;
	/* Return if array is NULL or has less than 2 elements */
	if (array == NULL || size < 2)
		return;

	do {
		/* Iterate over each element in the unsorted part of the array */
		for (current_index = 0; current_index < unsorted_size - 1; current_index++)
		{
			/* If current element is greater than the next one, swap them */
			if (array[current_index] > array[current_index + 1])
			{
				temporary_value = array[current_index];
				array[current_index] = array[current_index + 1];
				array[current_index + 1] = temporary_value;

				print_array(array, size);
				has_swapped = true;
			}
		}

		unsorted_size--; /*Reduce size of unsorted array after each pass*/

	} while (has_swapped);
}
