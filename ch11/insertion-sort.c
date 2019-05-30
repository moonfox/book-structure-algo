#include <stdio.h>
void insertion_sort(int *ary, int n);
void print_ary(int ary[], int n);

int main()
{
  int ary[6] = {4, 2, 3, 1, 6, 5};

  int n = 6;

  printf("排序前: ");
  print_ary(ary, n);

  insertion_sort(ary, n);

  printf("排序后: ");
  print_ary(ary, n);
}

// 算法思路
// 待插入的元素依次和已经排好的序列中的元素从后向前进行比较
// 大于要插入的数据时，向后移动一个元素，
// 当找到位置后(当ary[j] < value时)，插入，
// 否则和一下个元素再比较

// 程序中，j的范围为有序元素的范围，从0开始

// 要插入元素的位置，要么在已经排序的某个元素的后面a[j + 1]，
// 要么在已经排序列的第一个位置: a[-1 + 1]

// 当比已经排序序列的第一个还小时，可以看成和一下个要比，时此
// 因为已经没有要比的了，可以假设前面还有一个a[-1]，但比要插入的元素小
// 插入位置在它后面，即a[0],a[-1+1]
// a[-1], a[0], a[1], a[2]....a[5]

void insertion_sort(int *ary, int n)
{

  int value, j;
  for (int i = 1; i < n; i++)
  {
    // 要插入的元素的值暂存在value中
    value = ary[i];
    j = i - 1;

    printf("第%d次循环, ", i);
    printf("待排序元素[%d], 已排序的元素j的范围: 0~%d,", value, j);
    printf("已排序元素: ");
    for (int i = 0; i <= j; i++)
      printf("%d ", ary[i]);
    printf("\n");

    // 查找插入的位置，并移动数据
    for (; j >= 0; j--)
    {
      // 当 ary[j] > value（要插入的元素)，a[j]要向后移动，空出自己的位置
      // 这个位置就是value要插入的位置，当第一次循环时，a[j]向后移动，覆盖的
      // 是要插入元素的位置，利用要插入元素的位置取得空位

      // 循环退出的条件是：
      // 1.要插入的元素比当前比较的元素大
      // 2.要插入的元素与有序序列中的所有元素比较完成，这种情况是要插入的元素
      //   被放在了有序序列的第一个位置(比所有元素都小)

      if (ary[j] > value)
      {
        // 注意:这里执行 j--
        ary[j + 1] = ary[j];

        // 打印移动过程
        printf("\t当前j的值为:%d, ", j);
        printf("正在移动已排序元素%d, ", ary[j]);
        printf("移动后数组为: ");
        print_ary(ary, n);
      }
      else
        // 注意:这里不执行 j--
        break;
    }

    // 插入数据: 当ary[j] < value时
    // 当ary[j] < value时，value插入的位置为j的后面，即[j + 1]，此时不用再移动数据
    // 当value比所有要比的都小时，value要插入的位置为a[0],此时j = -1
    // ary[j + 1] 刚好为ary[0]

    // ary[j + 1] = value,j + 1为空出来的位置，之所以有空位是因为元素向后移动，占用了
    // 要插入元素的位置，要插入的元素保存在value中
    ary[j + 1] = value;

    // 打印插入元素后的数组
    printf("\t当前j的值为:%d, ", j);
    printf("插入元素[%d]后的新数组: ", value);
    print_ary(ary, n);
    printf("\n");
  }
}

// 打印数组
void print_ary(int ary[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", ary[i]);
  printf("\n");
}
