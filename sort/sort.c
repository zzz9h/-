
#include <stdio.h>
#include <malloc.h>
#include<windows.h>
void Swap(int* p, int* q)
{
	int buf;
	buf = *p;
	*p = *q;
	*q = buf;
	return;
}
/*快速排序
在数组中选择一个基准点

分别从数组的两端扫描数组，设两个指示标志

从后半部分开始，如果发现有元素比该基准点的值小，就交换位置

然后从前半部分开始扫描，发现有元素大于基准点的值，继续交换位置

如此往复循环，然后把基准点的值放到high这个位置,排序完成

以后采用递归的方式分别对前半部分和后半部分排序，当前半部分和后半部分均有序时该数组就自然有序了。
*/
void QuickSort(int* a, int low, int high)
{
	int i = low;
	int j = high;
	int key = a[low];
	if (low >= high)  //如果low >= high说明排序结束了
	{
		return;
	}
	while (low < high)  //该while循环结束一次表示比较了一轮
	{
		while (low < high && key <= a[high])
		{
			--high;  //向前寻找
		}
		if (key > a[high])
		{
			Swap(&a[low], &a[high]);
			++low;
		}
		while (low < high && key >= a[low])
		{
			++low;  //向后寻找
		}
		if (key < a[low])
		{
			Swap(&a[low], &a[high]);
			--high;
		}
	}
	QuickSort(a, i, high - 1);  //用同样的方式对分出来的左边的部分进行同上的做法
	QuickSort(a, high + 1, j);  //用同样的方式对分出来的右边的部分进行同上的做法
}

int main()
{
	int a[] = { 2,6,5,8,7,9,4 };
	int n = sizeof(a);
	n /= 4;
	int i = 0;
	int j = n - 1;
	QuickSort(a, i, j);
	for (int i = 0; i < n; i++)
	{
		printf("%d|", a[i]);
	}

}
/*
* 希尔排序
先将整个待排序的记录序列分组，对若干子序列分别进行直接插入排序，随着增量逐渐减少即整个序列中的记录“基本有序”时，再对全体记录进行依次直接插入排序。

过程如下：

选择一个增量序列 t1，t2，……，tk，其中 ti > tj, tk = 1；

按增量序列个数 k，对序列进行 k 趟排序；

每趟排序，根据对应的增量 ti，将待排序列分割成若干长度为 m 的子序列，分别对各子表进行直接插入排序。

仅增量因子为 1 时，整个序列作为一个表来处理，表长度即为整个序列的长度。
*/
void shell_sort()
{
	int arr[] = { 2,6,5,8,7,9,4 };
	int n = sizeof(arr);
	n /= 4;
	int i, j, gap;
	for (gap = n / 2; gap > 0; gap /= 2) {
		for (i = 0; i < gap; i++) {
			for (j = i + gap; j < n; j += gap) {
				for (int k = j; k > i && arr[k] < arr[k - gap]; k -= gap) {
					int tmp = arr[k - gap];
					arr[k - gap] = arr[k];
					arr[k] = tmp;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d|", arr[i]);
	}
}
/*
插入排序
每次从无序表中取出第一个元素，把它插入到有序表的合适位置，使有序表仍然有序。

第一趟比较前两个数，然后把第二个数按大小插入到有序表中；

第二趟把第三个数据与前两个数从后向前扫描，把第三个数按大小插入到有序表中；

依次进行下去，进行了(n-1)趟扫描以后就完成了整个排序过程。
*/
void insert_sort()
{
	int a[] = { 2,6,5,8,7,9,4 };
	int i, j;
	int n = sizeof(a);
	n /= 4;
	//外层循环标识并决定待比较的数值
	for (i = 1; i < n; i++) { //循环从第2个元素开始
		if (a[i] < a[i - 1]) {
			int temp = a[i];
			//待比较数值确定其最终位置
			for (j = i - 1; j >= 0 && a[j] > temp; j--) {
				a[j + 1] = a[j];
			}
			a[j + 1] = temp;//此处就是a[j+1]=temp;
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d|", a[i]);
	}
}
/*选择排序
首先设置两个记录i和j，i从数组第一个元素开始，j从(i+1)个元素开始。

接着j遍历整个数组，选出整个数组最小的值，并让这个最小的值和i的位置交换。

i选中下一个元素(i++)，重复进行每一趟选择排序。

持续上述步骤，使得i到达(n-1)处，即完成排序 。
*/
void select_sort()
{
	int arry[] = { 2,6,5,8,7,9,4 };
	int s = sizeof(arry);
	s /= 4; int tmp, temp;
	for (int i = 0; i < s; i++)
	{
		tmp = i;
		for (int j = i + 1; j < s; j++)
		{
			if (arry[tmp] > arry[j])
			{
				tmp = j;
			}
		}
		temp = arry[i];
		arry[i] = arry[tmp];
		arry[tmp] = temp;
	}
	for (int i = 0; i < s; i++)
	{
		printf("%d|", arry[i]);
	}
}

