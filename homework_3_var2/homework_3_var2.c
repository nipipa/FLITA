#include <stdio.h>
#include <stdlib.h>
#define ARR_MAX 1001

int main()
{
  FILE *file;
  char arr[ARR_MAX][ARR_MAX], s;
  int i = 0, j = 0;
  file = fopen("matrix_of_incendence198.txt", "r");
  while (!feof(file))
  {
    fscanf(file, "%c", &s);
    if (s != ' ' && s != '\n')
    {
      arr[i][j] = s;
      j++;
      if (j == 16)
      {
        i++;
        j = 0;
      }
    }
  }
  fclose(file);

  int sum = 0;

  file = fopen("graf.gv", "w");
  fprintf(file, "graph grath {\n");
  for (int d = 0; d < 5; d++)
  {
    fprintf(file, "%d\n", d + 1);
  }
  for (int a = 0; a < 16; a++)
  {
    s = 1;
    for (int y = 0; y < 5; y++)
    {
      if (arr[i][j] == '1')
      {
        for (int h; h < 5; h++)
        {
          if (arr[i][j] == '1')
          {
            sum++;
          }
        }
      }
    }
    printf("%d", sum);
  }
  // fprintf(file, "}");
  fclose(file);
  // system("dot graf.gv -Tpng -o graf.png");
  // system("graf.png");
}