#include <stdio.h>
int uocChungLonNhat(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main(){
	int n,m;
	printf("Moi ban nhap vao so nguyen  thu nhat: ");
	scanf("%d", &n);
	printf("Moi ban nhap vao so nguyen thu hai: ");
	scanf("%d", &m);
	int max= uocChungLonNhat(n,m);
	printf("%d", max);
	return 0;
}

