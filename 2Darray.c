#include<stdio.h>
void main(){

    int i,j,row,col;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &row, &col);
    int arr[row][col];
    printf("Enter elements of the array:\n");
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) 
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("The elements in the 2D array are:\n");
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }

        printf("\n"); 
       
    }


    
}