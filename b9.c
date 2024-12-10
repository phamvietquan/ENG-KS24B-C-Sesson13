#include <stdio.h>

int isPrime(int num) {
    if (num < 2){
    	 return ;
	}
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0){
         return ;	
		}
    }
    return ;
}

void inputMatrix(int matrix[][100], int rows, int cols) {
    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Nhap phan tu [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[][100], int rows, int cols) {
    printf("Ma tran:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printCorners(int matrix[][100], int rows, int cols) {
    printf("Cac phan tu o cac goc:\n");
    printf("%d %d\n", matrix[0][0], matrix[0][cols - 1]);
    printf("%d %d\n", matrix[rows - 1][0], matrix[rows - 1][cols - 1]);
}

void printBorder(int matrix[][100], int rows, int cols) {
    printf("Cac phan tu tren duong bien:\n");
    for (int i = 0; i < cols; i++) printf("%d ", matrix[0][i]); 
    for (int i = 1; i < rows - 1; i++) printf("%d ", matrix[i][cols - 1]);
    for (int i = cols - 1; i >= 0; i--) printf("%d ", matrix[rows - 1][i]); 
    for (int i = rows - 2; i > 0; i--) printf("%d ", matrix[i][0]);
    printf("\n");
}

void printDiagonals(int matrix[][100], int rows, int cols) {
    printf("Cac phan tu tren duong cheo chinh: ");
    for (int i = 0; i < rows && i < cols; i++) {
        printf("%d ", matrix[i][i]);
    }
    printf("\n");
    printf("Cac phan tu tren duong cheo phu: ");
    for (int i = 0; i < rows && i < cols; i++) {
        printf("%d ", matrix[i][cols - i - 1]);
    }
    printf("\n");
}

void printPrimes(int matrix[][100], int rows, int cols) {
    printf("Cac phan tu la so nguyen to:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (isPrime(matrix[i][j])) {
                printf("%d ", matrix[i][j]);
            }
        }
    }
    printf("\n");
}

int main() {
    int rows, cols;
    int matrix[100][100]; 
    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);

    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Nhap gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu o goc theo ma tran\n");
        printf("4. In ra cac phan tu nam tren duong bien theo ma tran\n");
        printf("5. In ra cac phan tu nam tren duong cheo chinh va cheo phu theo ma tran\n");
        printf("6. In ra cac phan tu la so nguyen to theo ma tran\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputMatrix(matrix, rows, cols);
				}
                break;
            case 2:
                printMatrix(matrix, rows, cols);
                break;
            case 3:
                printCorners(matrix, rows, cols);
                break;
            case 4:
                printBorder(matrix, rows, cols);
                break;
            case 5:
            	printDiagonals(matrix, rows, cols);
                break;
            case 6:
                printPrimes(matrix, rows, cols);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 7);

    return 0;
}

