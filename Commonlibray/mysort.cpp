#include<iostream>
using namespace std;
#include <vector>
#include <limits>
#include <stdio.h>  
#include <assert.h>  //断言头文件
#include <stdlib.h>  
/*
https://blog.csdn.net/yushiyi6453/article/details/76407640

时间复杂度记忆-

    冒泡、选择、直接 排序需要两个for循环，每次只关注一个元素，平均时间复杂度为O（n2）（一遍找元素O(n)，一遍找位置O(n)）
    
	快速、归并、希尔、堆基于二分思想，log以2为底，平均时间复杂度为O(nlogn)（一遍找元素O(n)，一遍找位置O(logn)）

稳定性记忆-“快希选堆”（快牺牲稳定性）

    排序算法的稳定性：排序前后相同元素的相对位置不变，则称排序算法是稳定的；否则排序算法是不稳定的。

*/



void BubbleSort(int array[], int n);
void selectSort(int array[], int n);
void insertSort(int array[], int n);
void MergeSort(vector<int> &Array, int front, int end);
void adjust_quicksort(int k[],int n); 
void quicksort(int a[], int left, int right);  
void heapSort(int array[], int n);
void SheelSort( int array[], int n);
void counting_sort(int *ini_arr, int *sorted_arr, int n);
void LSDSort(int *a, int n);


void printArray(int array[], int size)
{
	int i=0;
    for(i=0; i<size; i++)
    {
        printf("%d ", array[i]);
    }
}

void printVArray(vector<int> &array, int size)
{
	int i=0;
    for(i=0; i<size; i++)
    {
        printf("%d ", array[i]);
    }
}

int main(void)  
{  
//    int size = 0; 
//	printf("Please input array size!\n");
//    scanf("%d", &size);   //首先输入数组个数
//    printf("Please input array, length = %d \n",size);
//    assert(size > 0);     //判断数组个数是否非法
//
//    int *array = (int *)calloc(size, sizeof(int));  //动态分配数组
//
//    int i = 0;  
//    for (i = 0; i < size; ++i) {  
//        scanf("%d", &array[i]);  
//    }  

    int array[49] = {1332802,1177178,1514891,871248,753214,123866,1615405,328656,1540395,968891,1884022,252932,1034406,1455178,821713,486232,860175,1896237,852300,566715,1285209,1845742,883142,259266,520911,1844960,218188,1528217,332380,261485,1111670,16920,1249664,1199799,1959818,1546744,1904944,51047,1176397,190970,48715,349690,673887,1648782,1010556,1165786,937247,986578,798663};
    
	vector<int> varray = {1332802,1177178,1514891,871248,753214,123866,1615405,328656,1540395,968891,1884022,252932,1034406,1455178,821713,486232,860175,1896237,852300,566715,1285209,1845742,883142,259266,520911,1844960,218188,1528217,332380,261485,1111670,16920,1249664,1199799,1959818,1546744,1904944,51047,1176397,190970,48715,349690,673887,1648782,1010556,1165786,937247,986578,798663};
    //adjust_quicksort(array, 49); 
	MergeSort(varray,0,varray.size()-1);
    printVArray(varray, 49);  
    
    //printf("\n%d ", array[49-24]);

    //free(array);  
    return 0;  
} 

void BubbleSort(int array[], int n)
{
	int i = 0;
	int j = 0;
	int temp;
	for(i = 0; i < n-1;i++)
	{
		for(j = i+1; j < n;j++)
		{
			if(array[j] < array[i])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

/*
首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，
然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
以此类推，直到所有元素均排序完毕。 
*/
void selectSort(int array[], int n)
{
	int i = 0;
	int j = 0;
	int temp;
	int min;  //最小值的index
	for(i = 0; i < n-1;i++)
	{
		min = i;				//从第i个开始找
		for( j=i+1; j<n; j++)   //从i之后的数组中找到最小的数
        {
            if(array[min]>array[j])
            {
                min=j;
            }
        }

		if(min != i)         //交换位置
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;		
		}
	}
}

void insertSort(int array[], int n)
{
	int i = 0;
	int j = 0;
	int temp;
	for(i = 1; i < n;i++)
	{	
		if(array[i] < array[i-1])
		{
			temp = array[i];
			for( j=i;array[j-1]>temp;j--)//位置k上的数和之前的数依次进行比较，如果位置K上的数更小，将之前的数向后移位
            {
                array[j]=array[j-1];
            }
			array[j] = temp;
		}
	}
}

//接口调整
void adjust_quicksort(int k[],int n)  
{  
   quicksort(k,0,n-1);  
}  
void quicksort(int a[], int left, int right)  
{  
    int i,j,t,temp;  
    if(left>right)   //（递归过程先写结束条件）
       return;  

    temp=a[left]; //temp中存的就是基准数  
    i=left;  
    j=right;  
    while(i!=j)  
	{  
       //顺序很重要，要先从右边开始找（最后交换基准时换过去的数要保证比基准小，因为基准                               
       //选取数组第一个数，在小数堆中） 
       while(a[j]>=temp && i<j)  
                j--;  
       //再找右边的  
       while(a[i]<=temp && i<j)  
                i++;  
       //交换两个数在数组中的位置  
       if(i<j)  
       {  
            a[j] = a[j] + a[i];
		    a[i] = a[j] - a[i];
		    a[j] = a[j] - a[i];
       }  
    }  
    //最终将基准数归位 （之前已经temp=a[left]过了，交换只需要再进行两步）
    a[left]=a[i];  
    a[i]=temp;  

    quicksort(a,left,i-1);//继续处理左边的，这里是一个递归的过程  
    quicksort(a,i+1,right);//继续处理右边的 ，这里是一个递归的过程  
} 

void Merge(vector<int> &Array, int front, int mid, int end)
{
	vector<int> LeftSubArray(Array.begin() + front, Array.begin() + mid + 1);
	vector<int> RightSubArray(Array.begin() + mid + 1,Array.begin() + end + 1);
	
	int idxLeft = 0, idxRight = 0;
	
	LeftSubArray.insert(LeftSubArray.end(), numeric_limits<int>::max());
    RightSubArray.insert(RightSubArray.end(), numeric_limits<int>::max());
    // Pick min of LeftSubArray[idxLeft] and RightSubArray[idxRight], and put into Array[i]
    for (int i = front; i <= end; i++) {
        if (LeftSubArray[idxLeft] < RightSubArray[idxRight]) {
            Array[i] = LeftSubArray[idxLeft];
            idxLeft++;
        } else {
            Array[i] = RightSubArray[idxRight];
            idxRight++;
        }
    }
}


void MergeSort(vector<int> &Array, int front, int end)
{
	if(front >= end)
		return;
	
	int mid = (front+end)/2;
	
	MergeSort(Array, front, mid);
    MergeSort(Array, mid + 1, end);
    Merge(Array, front, mid, end);
}



