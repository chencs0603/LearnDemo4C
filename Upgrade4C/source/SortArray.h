#ifndef _SORTARRAY_H
#define _SORTARRAY_H

#ifdef  __cplusplus  
extern "C" {
#endif

#include "stdbool.h"

//交换两个数据
void exchange(int* pData1, int* pData2);
//数组排序
bool bubbleSort(int* pArray, int size, bool flag);

#ifdef  __cplusplus
}
#endif

#endif