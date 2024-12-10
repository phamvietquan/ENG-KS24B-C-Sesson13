#include <stdio.h>
//nhap cac phan tu cua mang
void addItem(int arr[], int size){
	for(int i=0;i<size;i++){
		printf("Moi ban nhap vao phan tu arr[%d]= ", i+1);
		scanf("%d", &arr[i]);
	}
}
//In ra cac phan tu trog mang
void showItem(int arr[], int size){
	for(int i=0;i<size;i++){
		printf("arr[%d]= %d",i, arr[i]);
		printf("\n");
	}
}
//Them mot phan tu vao vi tri chi dinh
void insertElement(int arr[], int *size, int index, int item){ 
    if(index>=0 && index< *size){
        for(int i= *size -1; i>= index; i--){
            arr[i+1] = arr[i];
            printf(" %d\n", i);
        }
        arr[index]= item;
        *size= *size+1;
    }else if(index == *size){
        arr[index]= item;
        *size=*size+1;
    }else if(index> *size){
        for(int i=*size; i<index; i++){
            arr[i]=0;
        }
        arr[index-1]= item;
        *size= index;
    }else{
        printf("vi tri ban nhap khong hop le \n");
    }
}
// Sua mot phan tu o vi tri chi dinh
void fixItem(int index, int item, int size, int arr[]){
    if(index >= 0 && index < size){
        arr[index]= item;
    }
}
//Xoa mot phan tu o vi tri chi dinh
void deleteItem(int index, int *size, int arr[]){ // xoa phan tu
    if(index<0){
        printf("vi tri ban nhap khong hop le \n");
    }else{
        for(int i= index; i< *size; i++){
            arr[i]= arr[i+1];
        }
    }
    *size= *size-1;
}
//Sap xep cac phan tu
void increase(int arr[], int size){ // tang dan
    for(int i=0; i<size-1; i++){
        for(int j = 0; j< size -1-i; j++){
            if(arr[j]> arr[j+1]){
                int temp= arr[j];
                arr[j]= arr[j+1];
                arr[j+1]= temp;
            }
        }
    }
}
//Sap xep cac phan tu
void reduce(int arr[], int size){ // giam dan
    for(int i=0; i<size-1; i++){
        for(int j = 0; j< size -1-i; j++){
            if(arr[j]< arr[j+1]){
                int temp= arr[j];
                arr[j]= arr[j+1];
                arr[j+1]= temp;
            }
        }
    }
}
//Tim kiem phan tu nhap vao
void linearSearch(int arr[], int size, int item){// tim kiem tuyen tinh
    int count=0;
    for(int i=0; i<size; i++){
        if(item == arr[i]){
            printf("Phan tu %d o vi tri arr[%d] \n", item, i);
            count++;
            break;
        }
    }
    if(count==0){
        printf("Phan tu %d khong co trong mang \n", item);
    }
}
//Tim kiem phan tu nhap vao
void binarySearch(int arr[], int size, int item){// tim kiem nhi phan
    increase(arr, size);
    int count=0;
    int start=0, end= size-1;
    while(start<=end){
        int mid= (start +end)/2;
        if(arr[mid]== item){
            printf("Phan tu %d o vi tri arr[%d] \n", item, mid);
            count=1;
            break;
        }else if(arr[mid]> item){
            end= mid-1;
        }else{
            start= mid+1;
        }
    }
    if(count==0){
        printf("Phan tu %d khong co trong mang \n", item);
    }
}
int main(){
	int arr[100];
	int menu;
	int flag=-1;
    int size=0, item=0, index =0;
    int letter=0;
	do{
		printf("Menu\n");
		printf("1. Nhap so phan tu va gia tri cac phan tu\n");
		printf("2. In ra cac gia tri phan tu dang quan ly\n");
		printf("3. Them mot phan tu vao vi tri chi dinh\n");
		printf("4. Sua mot phan tu o vi tri chi dinh\n");
		printf("5. Xoa mot phan tu o vi tri chi dinh\n");
		printf("6. Sap xep cac phan tu\n");
		printf("7. Tim kiem phan tu nhap vao\n");
		printf("8. Thoat\n");
		printf("Lua chon cua ban: ");
		scanf("%d", &menu);
		switch(menu){
			case 1:
				printf("Moi ban nhap vao kich thuoc cua mang: ");
				scanf("%d", &size);
				flag =1;
				addItem(arr,size);
				break;
			case 2:
				printf("Cac phan tu trong mang la: \n");
				showItem(arr, size);
				break;
			case 3:
				if(flag!=1){
                    printf("ban chua khoi tao mang \n");
                }else{
                    printf("moi ban nhap gia tri muon them: ");
                    scanf("%d", &item);
                    printf("moi ban nhap vi tri muon them: ");
                    scanf("%d", &index);
                    insertElement(arr,&size,index, item);
                    showItem(arr, size);
                }
				break;
			case 4:
				if(flag!=1){
                    printf("ban chua khoi tao mang \n");
                }else{
                    printf("Moi ban nhap vi tri muon sua: ");
                    scanf("%d", &index);
                    printf("Moi ban nhap gia tri phan tu moi: ");
                    scanf("%d", &item);
                    fixItem(index, item, size, arr);
                }
				break;
			case 5:
				if(flag!=1){
                    printf("ban chua khoi tao mang \n");
                }else{
                    printf("Moi ban nhap vi tri muon xoa ");
                    scanf("%d", &index);
                    deleteItem(index, &size, arr);
                }
				break;
			case 6:
				 if(flag!=1){
                    printf("ban chua khoi tao mang \n");
                }else{
                    printf(" 1. Giam dan \n 2. Tang dan \n");
                    scanf("\t %d", &letter);
                    if(letter == 1 ){
                        increase(arr, size);
                    }
                    if(letter ==2){
                        reduce(arr, size);
                    }
                }
				break;
			case 7:
				if(flag!=1){
                    printf("ban chua khoi tao mang \n");
                }else{
                    printf("Moi ban nhap phan tu muon tim: ");
                    scanf("%d", &item);
                    printf(" 1. Tim kiem tuyen tinh \n 2. Tim kiem nhi phan \n");
                    scanf("\t %d", &letter);
                    if(letter ==1 ){
                        linearSearch(arr, size, item);
                    }
                    if(letter==2){
                        
                    }
                }
				break;
			case 8:
				
				break;	
			default:
                printf("Lua chon khong co trong MENU \n");
		}
	}while(menu!=8);

	return 0;
}

