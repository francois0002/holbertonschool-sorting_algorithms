#include "sort.h"

/**
* lomuto - Lomuto partition scheme, choose a pivot,
* here the last element of the array
* @array: pointer to first element of array
* @low: start index of array
* @high: end index of array
* @size: number of elements in the array
* Return: next sorting element location
*/
size_t lomuto(int *array, int low, int high, size_t size)
{
	int pivot_index, current_index, pivot_value, temp_value;

	pivot_index = low - 1;
	pivot_value = array[high];

	/* Iterate over the array */
	for (current_index = low; current_index < high; ++current_index)
	{
		/* If current element < pivot, increment pivot index and swap elements */
		if (array[current_index] < pivot_value)
		{
			pivot_index++;
			if (pivot_index != current_index)
			{
				temp_value = array[pivot_index];
				array[pivot_index] = array[current_index];
				array[current_index] = temp_value;
				print_array(array, size);  /*Print array after swap*/
			}
		}
	}

	/* Swap pivot element to its correct position */
	temp_value = array[pivot_index + 1];
	array[pivot_index + 1] = array[high];
	array[high] = temp_value;
	print_array(array, size);  /*Print array after swap*/

	return (pivot_index + 1);
}

/**
* quicksort - sorts an array of integers in ascending
*  order using the Quick sort algorithm
* @array: array of integer
* @start: the starter
* @end: end of array
* @size: size of array
*/
void quicksort(int *array, int start, int end, size_t size)
{
	size_t pivot;

	if (start < end)
	{
		/* Partition the array and get the pivot index */
		pivot = lomuto(array, start, end, size);

		/* Recursively sort elements before and after pivot */
		quicksort(array, start, pivot - 1, size);
		quicksort(array, pivot + 1, end, size);
	}
}

/**
* quick_sort - sorts an array of integers in ascending
*  order using the Quick sort algorithm
* @array: array if integer
* @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
	/* Only sort if array is not NULL and size is greater than 2 */
	if (array && size > 2)
		quicksort(array, 0, size - 1, size);
}
