#include<stdio.h>
int main() {
    int arr[100],n,i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("enter elements are:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
  printf("sum of the elements in the array is: ");
    int sum = 0;
    for(i = 0; i < n; i++) {
        sum =sum + arr[i];
    }
    printf("%d\n", sum);
    return 0;
}