#include <stdio.h>

int main() {
  int i = 0, j = 0, o = 0;
  int a = 0, b = 0, d = 0;
  int mass_1[100] = {0};
  int mass_2[100] = {0};
  printf("Введите количетство элементов массива (макс 100):\n");
  scanf("%d", &j);
  if (j > 100) {
    j = 100;
  }
  for (i = 0; i < j; i++) {
    printf("%d член => ", i);
    scanf("%d", &mass_1[i]);
  }
  printf("Ваш массив из десятичных чисел:\n");
  for (i = 0; i < j; i++) {
    printf("%d член => ", i);
    printf("%d\n", mass_1[i]);
  }
  for (i = 0; i < j; i++) {
    a = mass_1[i];
    b, d = 0;
    while (a != 0) {
      b = b * 10 + a % 2;
      a = a / 2;
    }
    while (b != 0) {
      d = d * 10 + b % 10;
      b = b / 10;
    }
    mass_2[i] = d;
  }
  printf("\nВаш массив из двоичных чисел:\n");
  for (i = 0; i < j; i++) {
    printf("%d член => ", i);
    printf("%d\n", mass_2[i]);
  }
  return 0;
}
