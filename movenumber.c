/* ===========================================================================
 * > File Name: movenumber.c
 * > Author: geometry
 * > Mail: 
 * > Created Time: Sat 13 Oct 2018 07:22:16 PM CST
 * =========================================================================*/

#include <stdio.h>

void movenumber01(int x, int array[], int length)
{
	int i = 0;
	int number = 0;

	for (i = 0; i < length; i++)
	{
		if (array[i] == x)
		{
			number++;
		}
		if (number > 0 && array[i] != x)
		{
			int temp = array[i-number];
			array[i-number] = array[i];
			array[i] = temp;
		}
	}
}

void movenumber02(int x, int array[], int length)
{
	int i = 0;
	int number = 0;

	for (i = 0; i < length; i++)
	{
		if (array[i] != x)
		{
			array[i-number] = array[i];
		}
		else
		{
			number++;
		}
	}

	for (i = length -number; i < length; i++)
	{
		array[i] = x;
	}
}

void intervalMove01(int x, int array[], int length)
{
	int i = 0;
	int j = 0;
	int count = 0;

	for (i = 0; i < length; i++)
	{
		if (array[i] == x && ++count == 1)
		{
			j = i;
		}
		if (array[i] != x && array[j] == x)
		{
			int temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			j++;
		}
	}
}

void intervalMove02(int x, int array[], int length)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < length; i++)
	{
		if (array[i] != x)
		{
			int temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			j++;
		}
	}
}

int partition(int array[], int left, int right)
{
	int pivot = array[right];
	int i;
	int j = left;

	for (i = left; i < right; i++)
	{
		if (array[i] < pivot)
		{
			int temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			j++;
		}
	}
	int temp = array[j];
	array[j] = array[right];
	array[right] = temp;

	return j;
}

void quicksort(int array[], int left, int right)
{
	if (left < right)
	{
		int middle = partition(array, left, right);
		quicksort(array, left, middle-1);
		quicksort(array, middle+1, right);
	}
}

int main(void)
{
	//int array[] = {1,3,4,0,9,0,2,3,-10};
	int array[] = {1,3,4,9,2,4,-8,-1,7,5,11,14,21,27,7,2,26,12,2,4,3,5,2,6,8,7,7,1,2,1,-1,13,-2,17,-9,-10,14,17,7,20,21,22,24,26,29,-8,-9,-11,-12,-13,19,18,16,21,22,29,30,9,0,11,12,13,7,9,0,5,1,8,7,6,6,7,4,13,20,9,7,-6,-1,1,5,5,0,3,1,7,5,9,10,5,16,11,0,16,6,7,7,8,23,3,1,12,15,-3,-7,14,19,20,4,-2,-2,2,17,7,0,-5,-9,-10,-17};
	int length = sizeof(array)/sizeof(int);
	int i, x;

	for (i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

	//printf("Please input the number that needs to move:");
	//scanf("%d", &x);

	//movenumber01(x, array, length);
	//movenumber02(x, array, length);
	//intervalMove01(x, array, length);
	//intervalMove02(x, array, length);
	//partition(array, 0, length);
	quicksort(array, 0, length);

	for (i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}
