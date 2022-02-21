#include <stdio.h>

int main() {
  int i, b = 0;
  int a[100];

  printf("Введите количетство желементов массива (макс 100)\n");
  scanf("%d", & b);
  for (i = 0; i < b; i++) {
    printf("a[%d] = ", i);
    scanf("%d", & a[i]);
  }
  for (i = 0; i<5; i++)
    printf("%d ", a[i]);
  getchar(); getchar();
  return 0;
}
