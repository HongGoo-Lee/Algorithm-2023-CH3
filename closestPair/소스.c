#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 구조체 타입 선언 */
typedef struct {
    int x;
    int y;
} Point;

typedef struct _Pair {
    Point p1;
    Point p2;
    double dis;
}PointPair;

double get_distance(Point p1, Point p2)
{
    double res = 0;
    int x = (p1.x - p2.x);
    int y = (p1.y - p2.y);
    res = sqrt(x * x + y * y);
    return res;
}

PointPair find_closest_pair(Point array[], int size)
{
    PointPair cp = { 10000,10000,10000,10000,10000 };
    double dis = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            dis = get_distance(array[i], array[j]);
            if (dis < cp.dis)
            {
                cp.p1.x = array[i].x;
                cp.p1.y = array[i].y;
                cp.p2.x = array[j].x;
                cp.p2.y = array[j].y;
                cp.dis = dis;
            }
        }
    }

    return cp;
}

void main(void)
{
    Point* array;
    Point p;
    PointPair cp;
    int size = 0, c = 0;
    FILE* fp = NULL;
    fp = fopen("data.txt", "r");

    while (!feof(fp))
    {
        fscanf(fp, "%d %d\n", &p.x, &p.y);
        size++;
    }

    array = (Point*)malloc(sizeof(Point) * size);

    fseek(fp, 0, SEEK_SET);
    for (int i = 0; i < size; i++)
    {
        fscanf(fp, "%d %d\n", &p.x, &p.y);
        array[i] = p;
    }
    fclose(fp);

    cp = find_closest_pair(array,size);
    printf("최근접 점의 쌍\n");
    printf("p1(%d, %d), p2(%d, %d)\n", cp.p1.x, cp.p1.y, cp.p2.x, cp.p2.y);
    printf("거리: %lf", cp.dis);
    fp = fopen("result.txt", "w");
    fprintf(fp, "%d, %d\n", cp.p1.x, cp.p1.y);
    fprintf(fp, "%d, %d\n", cp.p2.x, cp.p2.y);
    fprintf(fp, "%lf\n", cp.dis);
    fclose(fp);
}