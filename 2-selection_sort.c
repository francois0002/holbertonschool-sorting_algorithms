#include "sort.h"

/**
* selection_sort - sorts an array of integers in ascending order
* @array: an array of integers
* @size: the number of integers
* Return:  0
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;

/*Inner loop finds the index of the minimum element in the unsorted part*/
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
/* Swap the minimum element with the first element in the unsorted part*/
		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
