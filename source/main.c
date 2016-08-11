#include <stdio.h>
#include "stdbool.h"
#include "SortArray.h"

//打印数组
void printArray(int* pArray, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", pArray[i]);
	}
	printf("\n");
}

//测试排序
void testSortArray()
{
	int array[] = {3, 5, 1, 7, 4, 2};
	int size = sizeof(array)/sizeof(array[0]);
	bool bRet = false;

	printf("排序前:");
	printArray(array, size);

	bRet = bubbleSort(array, size, true);
	printf("从小到大排序后:");
	printArray((int*)array, size);

	bRet = bubbleSort(array, size, false);
	printf("从大到小排序后:");
	printArray((int*)array, size);

}

int main()
{
	testSortArray();
	
	return 0;
}