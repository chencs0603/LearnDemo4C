#define  _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
//�������͵ı���:�̶���С�ڴ��ı���
void dataType()
{
	int a[10];
	int b = 10;//ֱ�Ӹ�ֵ

	//a �����������Ԫ�صĵ�ַ
	//&a���������������ĵ�ַ 
	printf("a:%d, a+1:%d, &a:%d, &a+1:%d\n", a, a+1, &a, &a+1);

	printf("b:%d, b+1:%d, &b:%d, &b+1:%d\n", b, b+1, &b, &b+1);
	//��Ӹ�ֵ
	*(&b) = 20;

	printf("b:%d\n", b);
}

//��̬�洢�����
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
	//��ӡp1 p2 p3 ��ָ���ڴ�ռ������
	printf("p1:%s, p2:%s, p3:%s \n", p1, p2, p3);

	//��ӡp1 p2 ��ֵ
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

//����Ұָ��
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
		p1 = NULL; //��ֹҰָ��
	}
	if (NULL != p2)
	{
		free(p2);
	}
	printf("p1:%s p1:%d\n", p1, p1);
	printf("p2:%s p2:%d\n", p2, p2);
}
//��
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
//ջ:return���ǰ��ڴ�鷵��,���ǰ��ڴ����׵�ַ����
char *getStackMemory()
{
	char buf[64]; //��ʱ���� ջ�����
	strcpy(buf, "123456789");
	//printf("buf:%s\n", buf);
	return buf;//������ʱ�����ᱨ��
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
	strcpy(heapPoint, "111222"); //��heapPoint��ָ����ڴ�ռ���copy����
	printf("heapPoint:%s\n", heapPoint);
	free(heapPoint);//���ڴ�������Ҫ�ͷ��ڴ�

	stackPoint = getStackMemory();
	if (stackPoint == NULL)
	{
		return ;
	}
	printf("stackPoint:%s\n", stackPoint);//ջ�ڴ���Զ�������
}

//˵��ջ���ڴ��ַ����������
void stackMemoryGrowthDirection()
{
	int a;
	int b;

	int buf[64];

	printf("&a:%d, &b:%d\n", &a, &b);
	if (&a > &b)
	{
		printf("ջ��������������\n");
	}
	else
	{
		printf("ջ��������������\n");
	}

	printf("&buf[10]:%d, &buf[20]:%d\n", &buf[10], &buf[20]);
	if (&buf[10] > &buf[20])
	{
		printf("�ڴ��������������\n");
	}
	else
	{
		printf("�ڴ��������������\n");
	}
}

//ָ������
void pointIronLaw()
{
	int num1 = 10;
	int num2 = 0;
	int* iPoint = NULL;
	char* szPoint = "abcd";

	iPoint = &num1; //��ָ��pointָ��num����point�õ��ڴ��Կ��
	*iPoint = 20; //ͨ��Կ�׼���޸��ڴ��ֵ
	printf("num1:%d\n", num1);

	num2 = *iPoint; //*point����=����� д�ڴ�,*p��=�ŵ��ұ� ���ڴ�
	printf("num2:%d\n", num2);

	//ָ��Ҳ��һ���������ͣ�ռ���ڴ��СΪ4�ֽڣ�32bit OS����8�ֽڣ�64bit OS��
	printf("size(iPoint):%d, size(long*):%d, size(char*):%d\n", sizeof(iPoint), sizeof(long*), sizeof(char*));
	//ָ���size��Ȼһ�������ǲ������ڲ��
	printf("int*������%d, char*������%d\n", (int)(iPoint + 1) - (int)iPoint, (int)(szPoint + 1) - (int)szPoint);
	printf("(iPoint + 1) - iPoint��%d, (szPoint + 1) - szPoint��%d\n", (iPoint + 1) - iPoint, (szPoint + 1) - szPoint);

	//��Ӹ�ֵ��ǰ;��������ָ�ڴ��ǿ��޸ĵ�
	*(szPoint + 1) = '4';
	printf("*szPoint��%s", szPoint);//debug���������a4cd,release���������abcd
}
//��Ӹ�ֵ������3������
void clearNum(int* num)
{
	*num = 0;
}
void indirectAssign()
{
	//1����������������ʵ�κ��βΣ�
	int num = 10;
	int* point = NULL;
	//2������������ʵ��ȡ��ַ�����β�ָ��
	point = &num;

	printf("num:%d\n", num);
	//3����Ӹ�ֵ��*point��=����޸�ʵ�ε�ֵ
	clearNum(point);

	printf("num:%d\n", num);
}
//һ��ָ�������롢����ĵ����÷�
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
	//C�����е��ַ������ԡ�\0���������ַ�����
	//�ַ������Է�����ջ�ռ䣬�ѿռ����ֻ���洢��
	char* pszOriginal = "aBcDe1g4";
	int originalStrLen = strlen(pszOriginal);//strlenֻ�����ַ����ĸ��������ƽ�����'\0'

	char* pszRet = (char*)malloc(originalStrLen + 1);
	int retStrLen = 0;
	bool bRet = false;
	memset(pszRet, 0x00, originalStrLen + 1);//���ǽ�����'\0'

	bRet = toggleString(pszOriginal, originalStrLen, pszRet, &retStrLen);
	if (bRet)
	{
		printf("str:%s, retStr:%s\n", pszOriginal, pszRet);
	}
}
//�ַ�������������
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