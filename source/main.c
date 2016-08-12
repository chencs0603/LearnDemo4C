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
//数据类型的本质:固定大小内存块的别名
void dataType()
{
	int a[10];
	int b = 10;//直接赋值

	//a 代表的数组首元素的地址
	//&a代表的是整个数组的地址 
	printf("a:%d, a+1:%d, &a:%d, &a+1:%d\n", a, a+1, &a, &a+1);

	printf("b:%d, b+1:%d, &b:%d, &b+1:%d\n", b, b+1, &b, &b+1);
	//间接赋值
	*(&b) = 20;

	printf("b:%d\n", b);
}

//静态存储区理解
char *getStaticMemory1()
{
	char *p2 = "sgaggag";
	return p2;
}
char* getStaticMemory2()
{
	char *p = "sgaggag";
	return p;
}

char* getStaticMemory3()
{
	char *p = "sgaggag2";
	return p;
}

void staticMemory()
{
	char* p1 = NULL;
	char* p2 = NULL;
	char* p3 = NULL;

	p1 = getStaticMemory1();
	p2 = getStaticMemory2();
	p3 = getStaticMemory3();
	//打印p1 p2 p3 所指向内存空间的数据
	printf("p1:%s, p2:%s, p3:%s \n", p1, p2, p3);

	//打印p1 p2 的值
	printf("p1:%d, p2:%d, p3:%d \n", p1, p2, p3);

	if (p1 == p2)
	{
		printf("p1 == p2\n");
	}
	else
	{
		printf("p1 != p2\n");
	}

	if (p1 != p3)
	{
		printf("p1 != p3\n");
	}
	else
	{
		printf("p1 != p3\n");
	}
}

//测试野指针
void wildPoint()
{
	char* p1 = (char*)malloc(10);
	char* p2 = (char*)malloc(10);

	strcpy(p1, "abc");
	strcpy(p2, "123");

	printf("p1:%s p1:%d\n", p1, p1);
	printf("p2:%s p2:%d\n", p2, p2);
	if (NULL != p1)
	{
		free(p1);
		p1 = NULL; //防止野指针
	}
	if (NULL != p2)
	{
		free(p2);
	}
	printf("p1:%s p1:%d\n", p1, p1);
	printf("p2:%s p2:%d\n", p2, p2);
}

int main()
{
	//testSortArray();

	//dataType();

	//staticMemory();

	wildPoint();
	
	return 0;
}