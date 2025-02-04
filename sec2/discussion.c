#include <stdio.h>

int add_three_nums(int* numbers) {
  int sum = 0;
  for (int i = 0; i < 3; i++) {
    sum = sum + *(numbers + i);
  }

  return sum;
}

int main() {
  int nums[3];
  nums[0] = 19240;
  nums[1] = 12645;
  nums[2] = 912831;

  int result = add_three_nums(nums);
  printf("The result is: %d\n", result);

  return 0;
}

