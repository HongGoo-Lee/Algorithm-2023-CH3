#include <stdio.h>
#include <stdlib.h>

void merge(int list[], int left, int mid, int right)
{
    int i, j, k, l,size=0;
    i = left;
    j = mid + 1;
    k = left;
    size = right - left + 1;
    
    int* arr;
    arr = (int*)malloc(sizeof(int) * size);

    /* ���� ���ĵ� list�� �պ� */
    while (i <= mid && j <= right)
    {
        if (list[i] <= list[j])
        {
            arr[k++] = list[i++];
        }
        else
        {
            arr[k++] = list[j++];
        }
    }

    // ���� �ִ� ������ �ϰ� ����
    if (i > mid)
    {
        for (l = j; l <= right; l++)
            arr[k++] = list[l];
    }
    // ���� �ִ� ������ �ϰ� ����
    else {
        for (l = i; l <= mid; l++)
            arr[k++] = list[l];
    }

    // �迭 arr[](�ӽ� �迭)�� ����Ʈ�� �迭 list[]�� �纹��
    for (l = left; l <= right; l++) {
        list[l] = arr[l];
    }
    free(arr);
}

// �պ� ����
void merge_sort(int list[], int left, int right)
{
    int mid;

    if (left < right)
    {
        mid = (left + right) / 2;
        merge_sort(list, left, mid);
        merge_sort(list, mid + 1, right);
        merge(list, left, mid, right);
    }
}

void main()
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
    
    merge_sort(array, 0, size-1);

    fp = fopen("result.txt", "w");
    for (int i = 0; i < size; i++)
    {
        fprintf(fp, "%d\n", array[i]);
        printf("%d : %d\n", i + 1, array[i]);
    }
    fclose(fp);
}