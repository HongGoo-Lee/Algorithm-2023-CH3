#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quick_sort(int arr[], int L, int R)
{
    srand(time(NULL));
    int i = L, j = R;
    int size = R - L + 1;
    int pivot_i = (rand() % size) + L;    // pivot 설정
    int temp;
    if (size == 1)
    {
        return 0;
    }
    else if (size == 2)
    {
        if (arr[i] > arr[j])
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        return 0;
    }
    else
    {
        temp = arr[i];
        arr[i] = arr[pivot_i];
        arr[pivot_i] = temp;
        i++;
        do
        {
            while ((arr[i] < arr[L]) && (i<=j))
                i++;
            while ((arr[j] > arr[L]) && (j>=i))
                j--;
            if (i <= j)    // i가 j보다 왼쪽에 있다면 교환 
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                //i 오른쪽으로 한칸, j 왼쪽으로 한칸 이동
                i++;
                j--;
            }
        } while (i <= j);    // i가 j보다 오른쪽으로 갈때까지 반복
    } 

    if (i == j)
    {
        pivot_i = i;
        temp = arr[i];
        arr[i] = arr[L];
        arr[L] = temp;
    }
    if (i > j)
    {
        pivot_i = j;
        temp = arr[j];
        arr[j] = arr[L];
        arr[L] = temp;
    }

    if (L < j)
        quick_sort(arr, L, pivot_i - 1);    // 왼쪽 배열 재귀적으로 반복 

    if (i < R)
        quick_sort(arr, pivot_i + 1, R);    // 오른쪽 배열 재귀적으로 반복 
}

void test(void)
{
    int* array;
    int size = 0, c = 0;
    FILE* fp = NULL;
    fp = fopen("data.txt", "r");

    while (!feof(fp))
    {
        fscanf(fp, "%d\n", &c);
        size++;
    }

    array = (int*)malloc(sizeof(int) * size);

    fseek(fp, 0, SEEK_SET);
    for (int i = 0; i < size; i++)
    {
        fscanf(fp, "%d\n", &c);
        array[i] = c;
    }
    fclose(fp);

    quick_sort(array, 0, size - 1);

    fp = fopen("result.txt", "w");
    for (int i = 0; i < size; i++)
    {
        fprintf(fp, "%d\n", array[i]);
        printf("%d : %d\n", i + 1, array[i]);
    }
    fclose(fp);
}

void main(void)
{
    test();
}