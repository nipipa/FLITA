#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int take_vertex();
int matrix();
int find();

int main()
{
    FILE *file = fopen("matrix_of_incendence198.txt", "r");
    char arr[ARR_MAX][ARR_MAX], s;
    int line = 1, ver = 0, reb = 0, max_len = 0;
    while (!feof(file))
    {
        fscanf(file, "%c", &s);
        if (s != ' ' && s != '\n' && s != '\0')
        {
            arr[line][ver] = s;
            ver++;
        }
        else if (s == '\n')
        {
            line++;
            max_len = ver;
            ver = 0;
        }
    }
    arr[line][max_len] = '\0';
    fclose(file);
    take_vertex(arr, line, ver);
}
