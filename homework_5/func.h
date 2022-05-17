#include <stdio.h>
#include <stdlib.h>
#define ARR_MAX 1001

int take_vertex();
int matrix();
int find();

int find(char arr[ARR_MAX][ARR_MAX], int line, int ver)
{
    int a, b = 0;
    puts("Write require vertex:");
    scanf("%d", &a);
    puts("------------------------");
    puts("Required edges:");
    for (b = 0; b <= ver; b++)
    {
        if (arr[a][b] == '1')
        {
            for (int i = 0; i < line; i++)
            {
                if (arr[i][b] == '1' && i != a)
                    printf("%d --> %d \n", a, i);
            }
        }
    }
    puts("------------------------");
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
        exit(0);
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
