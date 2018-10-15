/* ===========================================================================
 * > File Name: b.c
 * > Author: geometry
 * > Mail: 
 * > Created Time: Sun 14 Oct 2018 09:51:45 PM CST
 * =========================================================================*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	int *pa = (int*)a;
	int *pb = (int*)b;
	int num1 = *pa;
	int num2 = *pb;

	return (num1 - num2);
}

void quicksortSub(int array[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int pivot = array[(left+right) / 2];
	int i = left;
	int Lp = left;
	int Rp = right;

	while (i <= Rp)
	{
		if (array[i] > pivot)
		{
			int temp = array[Rp];
			array[Rp] = array[i];
			array[i] = temp;
			Rp--;
		}
		else if (array[i] < pivot)
		{
			int temp = array[Lp];
			array[Lp] = array[i];
			array[i] = temp;
			i++;
			Lp++;
		}
		else
		{
			i++;
		}
	}
	quicksortSub(array, left, Lp-1);
	quicksortSub(array, Rp+1, right);
}

void quicksort(int array[], int left, int right)
{
	int i = left;
	int j = right;
	//int pivot = array[(left + right) / 2];
	int pivot = array[right];

	while (i <= j)
	{
		while (array[i] < pivot)
		{
			i++;
		}
		while (array[j] > pivot)
		{
			j--;
		}

		if (i <= j)
		{
			int temp = array[i];
		    array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}

	if (left < j)
	{
		quicksort(array, left ,j);
	}
	if (i < right)
	{
		quicksort(array, i ,right);
	}
}

void insertsort(int array[], int length)
{
	int i, j;

	for (i = 0; i < length; i++)
	{
		int temp = i;
		for (j = i; j >= 0; j--)
		{
			if (array[temp] < array[j])
			{
				int tem = array[j];
				array[temp] = array[j];
				array[i] = tem;
			}
		}
	}
}

void Swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int Partition(int A[], int left, int right)  // 划分函数
{
    int pivot = A[right];               // 这里每次都选择最后一个元素作为基准
    int tail = left - 1;                // tail为小于基准的子数组最后一个元素的索引
	int i;
    for (i = left; i < right; i++)  // 遍历基准以外的其他元素
    {
        if (A[i] <= pivot)              // 把小于等于基准的元素放到前一个子数组末尾
        {
            Swap(A, ++tail, i);
        }
    }
    Swap(A, tail + 1, right);           // 最后把基准放到前一个子数组的后边，剩下的子数组既是大于基准的子数组
                                        // 该操作很有可能把后面元素的稳定性打乱，所以快速排序是不稳定的排序算法
    return tail + 1;                    // 返回基准的索引
}

void QuickSort(int A[], int left, int right)
{
    if (left >= right)
        return;
    int pivot_index = Partition(A, left, right); // 基准的索引
    QuickSort(A, left, pivot_index - 1);
    QuickSort(A, pivot_index + 1, right);
}

void ShellSort(int A[], int n)
{
	int i;
    int h = 0;
    while (h <= n)                          // 生成初始增量
    {
        h = 3 * h + 1;
    }
    while (h >= 1)
    {
        for (i = h; i < n; i++)
        {
            int j = i - h;
            int get = A[i];
            while (j >= 0 && A[j] > get)
            {
                A[j + h] = A[j];
                j = j - h;
            }
            A[j + h] = get;
        }
        h = (h - 1) / 3;                    // 递减增量
    }
}

void bublleSort(int array[], int length)
{
	int i, j;

	for (i = 0; i < length-1; i++)
	{
		for (j = length-1; j > i ; j--)
		{
			if (array[j] < array[i])
			{
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

void bublleSort01(int array[], int length)
{
	int i;

	for (i = 0; i < length-1; i++)
	{
		if (array[i] > array[i+1])
		{
			int temp = array[i];
			array[i] = array[i+1];
			array[i+1] = temp;
		}
	}
}

void bublleSort10(int array[], int length)
{
	int i;
	for (i = length; i >= 1; i--)
	{
		bublleSort01(array, i);
	}
}

void selectionSort(int array[], int length)
{
	int i;
	
}

void quicksortSub02(int array[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int pivot = array[(left + right) / 2];
	int i = left;
	int Lp = left;
	int Rp = right;

	while (i <= Rp)
	{
		if (array[i] > pivot)
		{
			int temp  = array[Rp];
			array[Rp] = array[i];
			array[i]  = temp;
			Rp--;
		}
		else if (array[i] < pivot)
		{
			int temp  = array[Lp];
			array[Lp] = array[i];
			array[i]  = temp;
			i++;
			Lp++;
		}
		else
		{
			i++;
		}
	}

	quicksortSub02(array, left, Lp-1);
	quicksortSub02(array, Rp+1, right);
}


int main(void)
{
	//int array[] = {22,90};
	int array[200] = {0};
	//int array01[1000000] = {0};
	srand(time(0));
	//int array[] = {1,3,4,9,2,4,-8,-1,7,5,11,14,21,27,7,2,26,12,2,4,3,5,2,6,8,7,7,1,2,1,-1,13,-2,17,-9,-10,14,17,7,20,21,22,24,26,29,-8,-9,-11,-12,-13,19,18,16,21,22,29,30,9,0,11,12,13,7,9,0,5,1,8,7,6,6,7,4,13,20,9,7,-6,-1,1,5,5,0,3,1,7,5,9,10,5,16,11,0,16,6,7,7,8,23,3,1,12,15,-3,-7,14,19,20,4,-2,-2,2,17,7,0,-5,-9,-10,-17};
	int length = sizeof(array)/sizeof(int);
	//int length01 = sizeof(array01)/sizeof(int);
	int i, j, x;

	for (i = 0; i < length; i++)
	{
		array[i] = rand()%1000-50;
	}

/*
	for (j = 0; j < length01; j++)
	{
		array01[j] = rand()%100000;
	}
*/

/*
 	for (i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	printf("\n");
*/
	//printf("Please input the number that needs to move:");
	//scanf("%d", &x);

	//movenumber01(x, array, length);
	//movenumber02(x, array, length);
	//intervalMove01(x, array, length);
	//intervalMove02(x, array, length);
	//partition(array, 0, length);
	//quicksortSub(array, 0, length-1);
	//quicksortSub02(array, 0, length-1);

	clock_t beg = clock();	// Get the CPU time occupancy value before entering.

	//quicksortSub(array, 0, length-1);
	//quicksortSub02(array, 0, length-1);
	//quicksort(array, 0, length-1);
	//insertsort(array, length);
	//ShellSort(array, length);
	//qsort(array, length, sizeof(int), compare);
	//QuickSort(array, 0, length-1);
	bublleSort(array, length);


	clock_t end = clock();	// Get the CPU time occupancy value after execution.
	
	printf("%lf\n", (double)(end - beg) / CLOCKS_PER_SEC);	// unit converted to milliseconds. clock_t is long intege.

/*
	quicksortSub(array01, 0, length01-1);
	clock_t enter = clock();	// Get the CPU time occupancy value before entering.

	quicksortSub(array01, 0, length01-1);
	//quicksort(array, 0, length-1);
	//insertsort(array, length);
	//QuickSort(array, 0, length-1);
	//ShellSort(array, length);

	clock_t out = clock();	// Get the CPU time occupancy value after execution.

	printf("%lf\n", (double)(out - enter) / CLOCKS_PER_SEC);	// unit converted to milliseconds. clock_t is long intege.
*/


	for (i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	printf("\n");

	printf("%lf\n", (double)(end - beg) / CLOCKS_PER_SEC);	// unit converted to milliseconds. clock_t is long intege.

	return 0;
}
