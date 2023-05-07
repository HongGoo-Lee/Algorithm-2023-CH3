#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection(int arr[], int L, int R, int selec)
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
            while ((arr[i] < arr[L]) && (i <= j))
                i++;
            while ((arr[j] > arr[L]) && (j >= i))
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

    if (L < pivot_i - 1 && selec < pivot_i - 1)
        selection(arr, L, pivot_i - 1,selec);    // 왼쪽 배열 재귀적으로 반복 

    if (pivot_i + 1 < R && pivot_i + 1 < selec)
        selection(arr, pivot_i + 1, R,selec);    // 오른쪽 배열 재귀적으로 반복 

    if (selec == pivot_i)
        return 0;
}

void test(void)
{
    int* array;
    int size = 0, c = 0,selec=0;
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

    printf("몇번째로 작은 값을 구할까요 ");
    scanf("%d", &selec);

    if (selec > size || selec < 0)
    {
        printf("잘못된 입력입니다.\n");
    }
    else
    {
        selection(array, 0, size - 1, selec);

        fp = fopen("result.txt", "w");
        printf("%d번째로 작은 값은 %d입니다.\n", selec, array[selec - 1]);
        fprintf(fp, "%d\n", array[selec - 1]);
        fclose(fp);
    }
}

void main(void)
{
    test();
}