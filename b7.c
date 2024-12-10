#include<stdio.h>
void addArr(int row, int col, int arr[100][100]){
    for(int i=0; i< row; i++){
        for(int j=0; j<col; j++){
            printf("Moi ban nhap phan tu arr[%d][%d]: ", i,j);
            scanf("%d", &arr[i][j]);
        }
    }
}
void showArr(int row, int col, int arr[100][100]){
    for(int i=0; i< row; i++){
        for(int j=0; j<col; j++){
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}
int main(void){
    int row=0, col=0, arr[100][100];
    printf("Moi ban nhap vao so hang: ");
    scanf("%d", &row);
    printf("Moi ban nhap vao so cot: ");
    scanf("%d", &col);
    addArr(row, col, arr);
    showArr(row, col, arr);
    return 0;
}
