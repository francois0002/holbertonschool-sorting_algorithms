#include "sort.h"

/**
* bubble_sort - sorts an array of integers in ascending order
* @array: array of integers
* @size: size of array
*/
void bubble_sort(int *array, size_t size)
{
	int temp_value;
	int is_swapped;  /*Flag to track if any swapping occurred*/

	size_t outer_index, inner_index;

	/* Return if array is NULL or has less than 2 elements */
	if (array == NULL || size < 2)
		return;

	/*Outer loop: iterate over each element in the array*/
	for (outer_index = 0; outer_index < size - 1; outer_index++)
	{
		/*Reset the swap flag for each outer loop iteration*/
		is_swapped = 0;

		/*Inner loop: iterate over the unsorted part of the array*/
		for (inner_index = 0; inner_index < size - outer_index - 1; inner_index++)
		{
			/*If current element is greater than the next one, swap them*/
			if (array[inner_index] > array[inner_index + 1])
			{
				temp_value = array[inner_index];
				array[inner_index] = array[inner_index + 1];
				array[inner_index + 1] = temp_value;

				print_array(array, size);
				is_swapped = 1;  /*Set swap flag to true*/
			}
		}
		/*If no swaps were made in the inner loop, the array is sorted*/
		if (is_swapped == 0)
			break;
	}
}
