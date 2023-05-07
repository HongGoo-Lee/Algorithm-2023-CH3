#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _point {
	int x;
	int y;
}Point;

typedef struct _pointPair {
	Point p1;
	Point p2;
	double dis;
}PointPair;

double dis(Point p1, Point p2)
{
	double res=0;
	int x = 0, y = 0;
	x = p1.x - p2.x;
	y = p1.y - p2.y;
	res = sqrt(x * x + y * y);

	return res;
}

void merge(Point list[], int left, int mid, int right)
{
    int i, j, k, l, size = 0;
    i = left;
    j = mid + 1;
    k = left;
    size = right - left + 1;

    Point* arr;
    arr = (Point*)malloc(sizeof(Point) * size);

    /* ���� ���ĵ� list�� �պ� */
    while (i <= mid && j <= right)
    {
        if (list[i].x <= list[j].x)
        {
            arr[k++].x = list[i++].x;
        }
        else
        {
            arr[k++].x = list[j++].x;
        }
    }

    // ���� �ִ� ������ �ϰ� ����
    if (i > mid)
    {
        for (l = j; l <= right; l++)
            arr[k++].x = list[l].x;
    }
    // ���� �ִ� ������ �ϰ� ����
    else {
        for (l = i; l <= mid; l++)
            arr[k++].x = list[l].x;
    }

    // �迭 arr[](�ӽ� �迭)�� ����Ʈ�� �迭 list[]�� �纹��
    for (l = left; l <= right; l++) {
        list[l].x = arr[l].x;
    }
    free(arr);
}

// �պ� ����
void merge_sort(Point list[], int left, int right)
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

void find_closest_pair(Point* arr, int left, int right)
{
	int size = right - left + 1;
	int mid_x = (arr[0].x + arr[size - 1].x) / 2;
    while()
}