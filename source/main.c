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
	int* point = NULL;

	point = &num1; //��ָ��pointָ��num����point�õ��ڴ��Կ��
	*point = 20; //ͨ��Կ�׼���޸��ڴ��ֵ
	printf("num1:%d\n", num1);

	num2 = *point; //*point����=����� д�ڴ�,*p��=�ŵ��ұ� ���ڴ�
	printf("num2:%d\n", num2);
}


int main()
{
	//testSortArray();

	//dataType();

	//staticMemory();

	//wildPoint();

	//dynamicMemory();
	
	//stackMemoryGrowthDirection();
	
	pointIronLaw();
	
	return 0;
}