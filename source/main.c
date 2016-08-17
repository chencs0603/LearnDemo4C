#define  _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
//堆
char *getHeapMemory(int num)
{
	char *point = NULL;
	point = (char *)malloc(sizeof(char) * num);
	if (point == NULL)
	{
		return NULL;
	}
	strcpy(point, "123456789");
	return point;
}
//栈:return不是把内存块返回,而是把内存块的首地址返回
char *getStackMemory()
{
	char buf[64]; //临时变量 栈区存放
	strcpy(buf, "123456789");
	//printf("buf:%s\n", buf);
	return buf;//返回临时变量会报警
}
void dynamicMemory()
{
	char* heapPoint = NULL;
	char* stackPoint = NULL;

	heapPoint = getHeapMemory(10);
	if (heapPoint == NULL)
	{
		return ;
	}
	printf("heapPoint:%s\n", heapPoint);
	strcpy(heapPoint, "111222"); //向heapPoint做指向的内存空间中copy数据
	printf("heapPoint:%s\n", heapPoint);
	free(heapPoint);//堆内存用完需要释放内存

	stackPoint = getStackMemory();
	if (stackPoint == NULL)
	{
		return ;
	}
	printf("stackPoint:%s\n", stackPoint);//栈内存会自动被回收
}

//说明栈和内存地址的生长方向
void stackMemoryGrowthDirection()
{
	int a;
	int b;

	int buf[64];

	printf("&a:%d, &b:%d\n", &a, &b);
	if (&a > &b)
	{
		printf("栈的生长方向向下\n");
	}
	else
	{
		printf("栈的生长方向向上\n");
	}

	printf("&buf[10]:%d, &buf[20]:%d\n", &buf[10], &buf[20]);
	if (&buf[10] > &buf[20])
	{
		printf("内存的生长方向向下\n");
	}
	else
	{
		printf("内存的生长方向向上\n");
	}
}

//指针铁律
void pointIronLaw()
{
	int num1 = 10;
	int num2 = 0;
	int* iPoint = NULL;
	char* szPoint = "abcd";

	iPoint = &num1; //让指针point指向num，即point拿到内存的钥匙
	*iPoint = 20; //通过钥匙间接修改内存的值
	printf("num1:%d\n", num1);

	num2 = *iPoint; //*point放在=号左边 写内存,*p放=号的右边 读内存
	printf("num2:%d\n", num2);

	//指针也是一种数据类型，占用内存大小为4字节（32bit OS）或8字节（64bit OS）
	printf("size(iPoint):%d, size(long*):%d, size(char*):%d\n", sizeof(iPoint), sizeof(long*), sizeof(char*));
	//指针的size虽然一样，但是步长存在差别
	printf("int*步长：%d, char*步长：%d\n", (int)(iPoint + 1) - (int)iPoint, (int)(szPoint + 1) - (int)szPoint);
	printf("(iPoint + 1) - iPoint：%d, (szPoint + 1) - szPoint：%d\n", (iPoint + 1) - iPoint, (szPoint + 1) - szPoint);

	//间接赋值的前途条件是所指内存是可修改的
	*(szPoint + 1) = '4';
	printf("*szPoint：%s", szPoint);//debug版下输出：a4cd,release版下输出：abcd
}
//间接赋值成立的3个条件
void clearNum(int* num)
{
	*num = 0;
}
void indirectAssign()
{
	//1、定义两个变量（实参和形参）
	int num = 10;
	int* point = NULL;
	//2、建立关联，实参取地址赋给形参指针
	point = &num;

	printf("num:%d\n", num);
	//3、间接赋值，*point放=左边修改实参的值
	clearNum(point);

	printf("num:%d\n", num);
}
//一级指针做输入、输出的典型用法
bool toggleString(char* pszOriginal, int originalStrLen, char* pszRet, int* retStrLen)
{
	int i;

	if (NULL == pszOriginal || 0 >= originalStrLen)
	{
		return false;
	}

	for (i = 0; i < originalStrLen; i++)
	{
		if (pszOriginal[i] >= 'a' && pszOriginal[i] <= 'z')
		{
			pszRet[i] = pszOriginal[i] - 0x20;
		}
		else if (pszOriginal[i] >= 'A' && pszOriginal[i] <= 'Z')
		{
			pszRet[i] = pszOriginal[i] + 0x20;
		}
		else
		{
			pszRet[i] = pszOriginal[i];
		}	
	}
	*retStrLen = originalStrLen;
	
	return true;
}

void pointTypicalUse()
{
	//C语言中的字符串是以’\0’结束的字符数组
	//字符串可以分配于栈空间，堆空间或者只读存储区
	char* pszOriginal = "aBcDe1g4";
	int originalStrLen = strlen(pszOriginal);//strlen只计算字符串的个数，不计结束符'\0'

	char* pszRet = (char*)malloc(originalStrLen + 1);
	int retStrLen = 0;
	bool bRet = false;
	memset(pszRet, 0x00, originalStrLen + 1);//考虑结束符'\0'

	bRet = toggleString(pszOriginal, originalStrLen, pszRet, &retStrLen);
	if (bRet)
	{
		printf("str:%s, retStr:%s\n", pszOriginal, pszRet);
	}
}
//字符串作函数参数
bool myStrCpy(char* pszDst, char* pszSrc)
{
	if (pszSrc == NULL || pszDst == NULL)
	{
		return false;
	}

	while((*pszDst++ = *pszSrc++));

	return true;
}

void strCpyTest()
{
	char dstStr[0x10];

	bool bRet = myStrCpy(dstStr, "abac");

	if (bRet)
	{
		printf("%s\n", dstStr);
	}
	else
	{
		printf("str copy error\n");
	}
	
}

int main()
{
	//testSortArray();

	//dataType();

	//staticMemory();

	//wildPoint();

	//dynamicMemory();
	
	//stackMemoryGrowthDirection();
	
	//pointIronLaw();

	//indirectAssign();

	//pointTypicalUse();

	strCpyTest();

	return 0;
}