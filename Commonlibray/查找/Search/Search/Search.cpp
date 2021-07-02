#include <stdio.h>    
#include <string.h>
#include <ctype.h>      
#include <stdlib.h>   
#include <io.h>  
#include <math.h>  
#include <time.h>

#define	MAXSIZE	10000
typedef struct
{
	int r[MAXSIZE + 1];
	int length;
}SqList;

void print(SqList L)
{
	int i;
	for (i = 1; i < L.length; i++)
		printf("%d,", L.r[i]);
	printf("%d", L.r[i]);
	printf("\n");
}

void swap(SqList *L, int i, int j)
{
	if (i == j)
		return;

	L->r[j] = L->r[i] + L->r[j];
	L->r[i] = L->r[j] - L->r[i];
	L->r[j] = L->r[j] - L->r[i];
}


/* ����L������r���±�Ϊi��j��ֵ */
void swap0(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

/*ʱ�临�Ӷ�O(n^2)*/
void BubbleSort0(SqList *L)
{
	int i, j;

	for (i = 0; i < L->length; i++)
		for (j = i + 1; j <= L->length; j++)
		{
			if (L->r[j] < L->r[i])
				swap(L, i, j);
		}
}
/*ʱ�临�Ӷ�O(n^2)*/
void BubbleSort(SqList *L)
{
	int i, j;

	for (i = 0; i < L->length; i++)
		for (j = L->length - 1; j >= i; j--)
		{
			if (L->r[j] > L->r[j + 1])
				swap(L, j, j + 1);
		}
}
/*ʱ�临�Ӷ�O(n^2)*/
void SelectSort(SqList *L)
{
	int i, j, min;

	for (i = 0; i < L->length; i++)
	{
		min = i;
		for (j = i + 1; j <= L->length; j++)
		{
			if (L->r[j] < L->r[min])
				min = j;
		}

		if (min != i)
			swap(L, i, min);
	}

}

/*ʱ�临�Ӷ�O(n^2)*/
void InsertSort(SqList *L)
{
	int i, j;

	for (i = 2; i <= L->length; i++)
	{
		if (L->r[i] < L->r[i - 1])
		{
			L->r[0] = L->r[i];  //�����ڱ�,L->r[0]�൱��temp
			for (j = i - 1; L->r[j] > L->r[0]; j--)//����
			{
				L->r[j + 1] = L->r[j];
			}
			L->r[j + 1] = L->r[0];	//���뵽��ȷλ��
		}
	}
}

/*ʱ�临�Ӷ�O(n^3/2)*/
void ShellSort(SqList *L)
{
	int i, j;
	int increment = L->length;
	do
	{
		increment = increment / 3 + 1;
		for (i = increment + 1; i <= L->length; i++)
		{
			if (L->r[i] < L->r[i - increment])
			{
				L->r[0] = L->r[i];
				for (j = i - increment; j > 0 && L->r[0] < L->r[j]; j -= increment)
					L->r[j + increment] = L->r[j];
				L->r[j + increment] = L->r[0];
			}
		}
	} while (increment > 1);
}


void Merge(int SR[], int TR[], int i, int m, int n)
{
	int j, k, l;
	for (j = m + 1, k = i; i <= m && j <= n; k++)
	{
		if (SR[i] < SR[j])
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}

	if (i <= m)
	{
		for (l = 0; l <= m - i; l++)
			TR[k + l] = SR[i + l];
	}

	if (j <= n)
	{
		for (l = 0; l <= n - j; l++)
			TR[k + l] = SR[j + l];
	}
}

void MSort(int SR[], int TR1[], int s, int t)
{
	int m;
	int TR2[MAXSIZE + 1];
	if (s == t)
		TR1[s] = SR[s];
	else
	{
		m = (s + t) / 2;
		MSort(SR, TR2, s, m);
		MSort(SR, TR2, m + 1, t);
		Merge(TR2, TR1, s, m, t);
	}
}

//O(n+logn)
void MergeSort(SqList *L)
{
	MSort(L->r, L->r, 1, L->length);
}


/* **************************************** */

/* ��������******************************** */

/* ����˳���L���ӱ�ļ�¼��ʹ�����¼��λ��������������λ�� */
/* ��ʱ����֮ǰ(��)�ļ�¼������(С)������ */
int Partition(SqList *L, int low, int high)
{
	int pivotkey;

	pivotkey = L->r[low]; /* ���ӱ�ĵ�һ����¼�������¼ */
	while (low < high) /*  �ӱ�����˽�������м�ɨ�� */
	{
		while (low < high&&L->r[high] >= pivotkey)
			high--;
		swap(L, low, high);/* ���������¼С�ļ�¼�������Ͷ� */
		while (low < high&&L->r[low] <= pivotkey)
			low++;
		swap(L, low, high);/* ���������¼��ļ�¼�������߶� */
	}
	return low; /* ������������λ�� */
}

/* ��˳���L�е�������L->r[low..high]���������� */
void QSort(SqList *L, int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = Partition(L, low, high); /*  ��L->r[low..high]һ��Ϊ�����������ֵpivot */
		QSort(L, low, pivot - 1);		/*  �Ե��ӱ�ݹ����� */
		QSort(L, pivot + 1, high);		/*  �Ը��ӱ�ݹ����� */
	}
}

/* ��˳���L���������� */
void QuickSort(SqList *L)
{
	QSort(L, 1, L->length);
}




#define N 9

int main()
{
	int i;

	/* int d[N]={9,1,5,8,3,7,4,6,2}; */
	int d[N] = { 50,10,90,30,70,40,80,60,20 };
	/* int d[N]={9,8,7,6,5,4,3,2,1}; */

	SqList l0, l1, l2, l3, l4, l5, l6, l7, l8, l9, l10, l11;

	for (i = 0; i < N; i++)
		l0.r[i + 1] = d[i];
	l0.length = N;
	l1 = l2 = l3 = l4 = l5 = l6 = l7 = l8 = l9 = l10 = l11 = l0;
	//   printf("Sort Before:\n");
	//   print(l0);
	//
	//   printf("BubbleSort0:\n");
	//   BubbleSort0(&l0);
	//   print(l0);
	//   
	//   printf("BubbleSort:\n");
	//   BubbleSort(&l1);
	//   print(l1);
	//   
	//   printf("SelectSort:\n");
	//   SelectSort(&l2);
	//   print(l2);
	//   
	//   printf("InsertSort:\n");
	//   InsertSort(&l3);
	//   print(l3);
	//   
	//   printf("ShellSort:\n");
	//   ShellSort(&l4);
	//   print(l4);
	//   
	//   printf("MergeSort:\n");
	//   MergeSort(&l5);
	//   print(l5);

	printf("QuickSort:\n");
	QuickSort(&l6);
	print(l6);
}