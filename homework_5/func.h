#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARR_MAX 1001

struct timeval tv1, tv2, dtv;
struct timezone tz;

int take_vertex();
int matrix();
int find();

void time_start() { 
    mingw_gettimeofday(&tv1, &tz); 
    }

long time_stop()
{
    mingw_gettimeofday(&tv2, &tz);
    dtv.tv_sec = tv2.tv_sec - tv1.tv_sec;
    dtv.tv_usec = tv2.tv_usec - tv1.tv_usec;
    if (dtv.tv_usec < 0)
    {
        dtv.tv_sec--;
        dtv.tv_usec += 1000000;
    }
    return dtv.tv_sec * 1000 + dtv.tv_usec / 1000;
}

int find(char arr[ARR_MAX][ARR_MAX], int line, int ver)
{
    int v, a = 0, b = 0, num = 0, kol = 0;
    int vertex[ARR_MAX];
    puts("Write require grade of vertex:");
    scanf("%d", &v);    
    time_start();
    puts("------------------------");
    puts("Required edges:");
    puts("***************");
    for (a = 0; a <= line; a++)
    {
        for (b = 0; b <= ver; b++)
        {
            if (arr[a][b] == '1')
            {
                for (int i = 0; i <= line; i++)
                {
                    if (arr[i][b] == '1' && i != a)
                        num++;
                }
            }
        }
        vertex[a] = num;
        num = 0;
    }
    for (int i = 0; i <= line; i++)
    {
        if (vertex[i] == v)
        {
            printf("Vertex %d || grade %d \n", i, vertex[i]);
            puts("***************");
            for (b = 0; b <= ver; b++)
            {
                if (arr[i][b] == '1')
                {
                    for (int k = 0; k <= line; k++)
                    {
                        if (arr[k][b] == '1' && k != i)
                            printf("%d --> %d \n", i, k);
                    }
                }
            }
            puts("***************");
        }
    }
    puts("------------------------");
    printf("Time of finding: %ld mc\n", time_stop());
    take_vertex(arr, line, ver);
    return 0;
}
int take_vertex(char arr[ARR_MAX][ARR_MAX], int line, int ver)
{
    int vertex = 0, j = 0;
    printf("Select motion:\n");
    printf("0 - exit\n");
    printf("1 - enter the required vertex and find edges\n");
    printf("2 - show your matrix\n");
    scanf("%d", &j);
    switch (j)
    {
    case 1:
        find(arr, line, ver);
        break;
    case 2:
        matrix(arr, line, ver);
        break;
    case 0:
        exit(EXIT_SUCCESS);
        break;
    default:
        exit(EXIT_FAILURE);
        break;
    }
    return 0;
}

int matrix(char arr[ARR_MAX][ARR_MAX], int line, int ver)
{
    puts("------------------------");
    puts("Your matrix:\n");
    for (int a = 0; a <= line; a++)
    {
        int c = a + 1;
        for (int b = 0; b <= ver; b++)
        {
            printf("%c ", arr[a][b]);
        }
        putchar('\n');
    }
    puts("------------------------");
    take_vertex(arr, line, ver);
    return 0;
}
