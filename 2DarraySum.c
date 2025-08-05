#include<stdio.h>
int main(){

      int row,col;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &row, &col);
    int a[row][col] , b[row][col], sum[row][col];
    printf("Enter elements of the 1st matrix :\n");
    for( int i = 0; i < row; i++) {
        for( int j = 0; j < col; j++) 
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("The elements in the 2nd matrix are:\n");
    for( int i = 0; i < row; i++) {
        for( int j = 0; j < col; j++) {
            scanf("%d", &b[i][j]);
           
        }

        
       
    }
    printf("The sum of the two matrices is:\n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            sum[i][j] = a[i][j] + b[i][j];
           
        }
        
    }

    for (int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%d ", sum[i][j]);
        }   
        printf("\n");
    }
    
    return 0;
}