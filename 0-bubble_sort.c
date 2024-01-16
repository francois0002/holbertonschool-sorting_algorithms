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

	bool has_swapped;

	if (array == NULL || size < 2)
		return;

	do {
		bool has_swapped = false;

		for (current_index = 0; current_index < unsorted_size - 1; current_index++)
		{
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
