#include <stdio.h>
#include "stdbool.h"
#include "SortArray.h"

//��ӡ����
void printArray(int* pArray, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", pArray[i]);
	}
	printf("\n");
}

//��������
void testSortArray()
{
	int array[] = {3, 5, 1, 7, 4, 2};
	int size = sizeof(array)/sizeof(array[0]);
	bool bRet = false;

	printf("����ǰ:");
	printArray(array, size);

	bRet = bubbleSort(array, size, true);
	printf("��С���������:");
	printArray((int*)array, size);

	bRet = bubbleSort(array, size, false);
	printf("�Ӵ�С�����:");
	printArray((int*)array, size);

}

int main()
{
	testSortArray();
	
	return 0;
}