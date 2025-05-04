#ifndef SORT_H
#define SORT_H
void bubble_sort(int arr[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]<arr[j]){
            temp = arr[j+1];//swapping numbers
            arr[j+1] = arr[j];
            arr[j] = temp;
            }

        }
    }
}
#endif