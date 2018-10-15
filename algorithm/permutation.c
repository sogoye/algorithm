/* ===========================================================================
 * > File Name: permutation.c
 * > Author: geometry
 * > Mail: 
 * > Created Time: Mon 15 Oct 2018 11:19:17 PM CST
 * =========================================================================*/

#include <stdio.h>

void swap(int array[], int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void printArray(int array[], int length)
{
	int i;
	for (i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void permutation(int array[], int left, int right)
{
	if (left == right)
	{
		printArray(array, right+1);
	}
	else
	{
		int i;

		for (i = left; i <= right; i++)
		{
			swap(array, left, i);
			permutation(array, left + 1, right);
			swap(array, left, i);
		}
	}
}

int main(void)
{
	int array[6] = {0};
	srand(time(0));
	int length = sizeof(array)/sizeof(int);
	int i;

	for (i = 0; i < length; i++)
	{
		array[i] = rand()%10;
	}
	printf("\n");

	permutation(array, 0, length);

	printf("\n");

	for (i = 0;	i < length; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}
