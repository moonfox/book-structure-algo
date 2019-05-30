#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

void bubble_sort(int ary[], int n);

int main()
{
  // printf("hello, world\n");

  int a[6] = {3, 4, 5, 1, 2, 6};
  // 冒泡排序，a 表示数组，n 表示数组大小
  int n = 6;

  for (int i = 0; i < n; ++i)
  {
    printf("%d ", a[i]);
  }

  printf("resualt:=====\n");

  bubble_sort(a, n);

  // int a[6] = {3, 4, 5, 1, 2, 6};
  // 数组a是按址传递的，在bubble_sort中内容被修改，
  // 修改后在主函数main中其内容被修改
  for (int i = 0; i < n; ++i)
  {
    printf("%d ", a[i]);
  }
}

void bubble_sort(int a[], int n)
{
  for (int i = 0; i < n; ++i)
  {
    int j = 0;
    // 提前退出冒泡循环的标志位
    bool flag = false;
    //  printf(" i: %d, j: %d, n: %d \n", i, n - i - 1, n);

    for (j = 0; j < n - i - 1; ++j)
    {
      if (a[j] > a[j + 1])
      { // 交换
        int tmp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = tmp;
        flag = true; // 表示有数据交换
      }
    }

    for (int ii = 0; ii < n; ++ii)
    {
      printf("%d ", a[ii]);
    }

    printf(" i=%d, j<%d, n=%d \n", i, j, n);
    printf("\n");
    printf("\n");
    if (flag == false)
      break; // 没有数据交换，提前退出
  }
}