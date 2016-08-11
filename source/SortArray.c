#include <stdio.h>
#include "stdbool.h"

//交换两个数据
void exchange(int* pData1, int* pData2)
{
	*pData1 = (*pData1)^(*pData2);
	*pData2 = (*pData1)^(*pData2);
	*pData1 = (*pData1)^(*pData2);
}

//数组排序,flag为true时，从小到大排序，否则从大到小排序
bool bubbleSort(int* pArray, int size, bool flag)
{
	int i, j;

	if (NULL == pArray || size <= 0)
	{
		return false;
	}

	for (i = 0; i < size; i++)
	{	
		for (j = 0; j < size - 1 -i; j++)
		{
			if (flag)
			{
				if (pArray[j] > pArray[j + 1])
				{
					exchange(&pArray[j], &pArray[j + 1]);
				}
			}
			else
			{
				if (pArray[j] < pArray[j + 1])
				{
					exchange(&pArray[j], &pArray[j + 1]);
				}
			}
		}			
	}

	return true;
}