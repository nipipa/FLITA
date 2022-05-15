#include <stdio.h>
#include <stdlib.h>
#define ARR_MAX 1001

int main()
{
  FILE *file;
  char arr[ARR_MAX][ARR_MAX], buffer;
  int i = 0, j = 0;
  file = fopen("matrix_of_incendence198.txt", "r");
  while (!feof(file))
  {
    fscanf(file, "%c", &buffer); // командой считываем символ из файла
    if (buffer != ' ' && buffer != '\n') // если символ не равен пробелу или не переносится на новую строку
    {
      arr[i][j] = buffer;
      j++;
      if (j == 16)
      {
        i++;
        j = 0;
      }
    }
  }
  fclose(file);
  file = fopen("graf.gv", "w");
  fprintf(file, "graph grath {\n");
  for (int d = 0; d < 5; d++)
  {
    fprintf(file, "%d\n", d + 1);
  }
  for (int a = 0; a < 16; a++)
  {
    buffer = 1;
    for (int y = 0; y < 5; y++)
    {
      if (arr[y][a] != '0')
      {
        if (buffer == 1)
        {
          fprintf(file, "%d", y + 1);
          printf("%d", y + 1);
          buffer = 0;
        }
        else
        {
          printf(" -- %d", y + 1);
          fprintf(file, " -- %d", y + 1, a + 1);
        }
      }
    }
    fprintf(file, "\n");
    printf("\n");
  }
  fprintf(file, "}");
  fclose(file);
  system("dot graf.gv -Tpng -o graf.png");
  system("graf.png");
}