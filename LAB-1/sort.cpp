#include<stdio.h>
void bubble_sort(int arr[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]<arr[j]){
                //swap the elements
            temp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = temp;
            }

        }
    }
}
void print_array(int arr[],int n){//function to print array
for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
}
printf("\n");
}
void selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minIndex=i;//assume the current index is smallest
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        int temp=arr[minIndex];
        arr[minIndex]=arr[i];
        arr[i]=temp;
    }
}
void insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int k =arr[i];//current element to be inserted
        int j=i-1;
        //Shift elements 
        while(j>=0 && arr[i]>k){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=k;
    }
}
int main(){
    int arr[]={12,89,90,45,2,4,6};
    int n =sizeof(arr)/sizeof(arr[0]);
    int choice;
    do{
        printf("Menu:\n1.Bubblesort:\n2.Selectionsort:\n3.Insertionsort:\n4.Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            bubble_sort(arr,n);
            printf("Array after bubble sort: ");
            print_array(arr,n);
            break;
            case 2:
            selection_sort(arr,n);
            printf("Array after selection sort: ");
            print_array(arr,n);
            break;
            case 3:
            insertion_sort(arr,n);
            printf("Array after insertion sort: ");
            print_array(arr,n);
            break;
            case 4:
            printf("Exit\n");
            break;
            default:
            printf("Invalid choice");
            
            
}
    }
    while(choice !=4);
    return 0;

}
