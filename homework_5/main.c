#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int matrix_rewrite(){
    FILE *file = fopen("matrix_of_incendence198.txt", "r");
    int **arr, line = 1, ver = 0, reb = 0, max_len = 0;
    char s;
    arr = (int**) malloc(line * sizeof(int*));
    while (!feof(file)) 
    {
        fscanf(file, "%c", &s);
        if (s != ' ' && s != '\n' && s != '\0')
        {
            arr[line] = (int*) malloc(ver * sizeof(int));
            arr[line][ver] = s;
            ver++;
        }
        else if (s == '\n')
        {
            line++;
            arr = (int**) realloc(arr,line * sizeof(int*));
            max_len = ver;
            ver = 0;
        }
    }
    arr[line][max_len] = '\0';
    fclose(file);
    return **arr;
}
int main(){
    int **arr;
    **arr = matrix_rewrite();
    printf("%d",arr[1][1]);
}