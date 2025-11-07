#include <stdio.h>
#include <stdbool.h>

void load_histogram(int *numbers, int *range, int histogram[]) {
  scanf("%d %d", numbers, range);
  for(int i = 0; i < *numbers; i++) {
    int value = 0;
    bool in_range = false;
    scanf("%d", &value);
    for(int j = *range; j <= *range + 8; j++){
      if(value == j){
        histogram[1 + j - *range]++;
        in_range = true;
      }
    }
    if(!in_range){
      histogram[0]++;
    }
  }
} 

int count_digits(int *range){
  int length1 = *range + 8;
  int digits1 = 0;
  while(length1 != 0){
    length1 /= 10;
    digits1++;
  }
  int length2 = *range;
  int digits2 = 0;
  while(length2 != 0){
    length2 /= 10;
    digits2++;
  }
  if(digits1 > digits2) return digits1;
  else return digits2;
}

void horizontal_histogram(int * range, int histogram[]){
  int digits = count_digits(range);
  for(int i = 1; i < 10; i++){
    printf("%*d", digits, *range + i - 1);
    bool space = true;
    for(int j = 0; j < histogram[i]; j++){
      if(space){
        printf(" ");
        space = false;
      }
      printf("#");
    }
    printf("\n");
  }
  if(histogram[0] > 0){
    printf("invalid: ");
    for(int k = 0; k < histogram[0]; k++){
      printf("#");
    }
    printf("\n");
  }
}

int max_number(int histogram[]){
  int max = histogram[0];
  for(int i = 1; i < 10; i++){
    if(histogram[i] > max) {
      max = histogram[i];
    }
  }
  return max;
}

void vertical_histogram(int * range, int histogram[]){
  int max = max_number(histogram);
  for(int i = max; i > 0; i--){
    for (int j = 0; j < 10; j++){
      if (histogram[j] >= i) {
        printf("#");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  printf("i");
  for(int i = 0; i < 9; i++){
    printf("%d", *range + i);
  }
  printf("\n");
}

int main() {
  int histogram[10] = {0};
  int numbers = 0;
  int range = 0;
  char sign = 0;
  scanf("%c", &sign);
  switch(sign){
    case 'h':
      load_histogram(&numbers, &range, histogram);
      horizontal_histogram(&range, histogram);
      break;
    case 'v':
      load_histogram(&numbers, &range, histogram);
      vertical_histogram(&range, histogram);
      break;
    default:
      printf("Neplatny mod vykresleni\n");
      return 1;
  }
  return 0;
}