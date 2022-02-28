#include <stdio.h>
#include <math.h>

int main()
{
  
  int n, i, summa, step, ost, count, equal, s1[10000], s2[10000];
  count = 0;
  i = 0;
  while ((scanf("%d", &s1[i])) != EOF) {
    i++;
  }
  printf("Массив двоичных чисел\n");
  for (int j = 0; j < i; j++) {
    printf("%d: ", j + 1);
    printf("%d\n", s1[j]);
  }
  for (int j = 0; j < i; j++) {
    ost = 0;
    equal = s1[j];
    while (s1[j] != 0) {
      ost = s1[j] % 10;
      s1[j] = s1[j] / 10;
      if (ost != 0 && ost != 1) {
        count++;
      }
    }
    s1[j] = eq;
  }
  if (count != 0) {
    printf("Ошибка! Вы ввели цифры не в двоичной системе счисления\n");
  }
  else {
    for (int j = 0; j < i; j++) {
      ost = 0;
      step = 0;
      while (s1[j] != 0) {
        ost = s1[j] % 10;
        s1[j] = s1[j] / 10;
        summa += ost * pow(2, step);
        step++;
      }
      s2[j] = summa;
      summ = 0;
    }
    printf("Массив десятичных чисел\n");
    for (int j = 0; j < i; j++) {
      printf("%d: ", j + 1);
      printf("%d\n", s2[j]);
    }
  }
}
