#include <stdio.h>

void selection_sort(int *ary, int n);
void selection_sort_v2(int *ary, int n);

void print_ary(int ary[], int n);

int main()
{
  int ary[6] = {4, 2, 3, 1, 6, 5};
  // int ary[6] = {4, 5, 6, 3, 2, 1};
  int n = 6;

  selection_sort(ary, n);
  print_ary(ary, n);
}

void selection_sort(int *ary, int n)
{
  for (int i = 0; i < n; i++)
  {
    int temp;
    int minIndex = i;
    int min = ary[i];

    for (int j = i + 1; j < n; j++)
      if (ary[j] < ary[minIndex])
        minIndex = j;

    temp = ary[i];
    ary[i] = ary[minIndex];
    ary[minIndex] = temp;
  }
}

void selection_sort_v2(int *ary, int n)
{
  for (int i = 0; i < n; i++)
  {
    int minIndex = i;
    int min = ary[i];

    for (int j = i + 1; j < n; j++)
    {
      if (ary[j] < min)
      {
        minIndex = j;
        min = ary[j];
      }
    }

    ary[minIndex] = ary[i];
    ary[i] = min;
  }
}
// 打印数组
void print_ary(int ary[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", ary[i]);
  printf("\n");
}