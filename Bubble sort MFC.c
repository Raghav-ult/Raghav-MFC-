#include<stdio.h>
#include<stdlib.h>
/*Time complexity-->In our BubbleSort function we see a nested for loop the outer loop runs "n" times and 
the inner also runs "n" times making the time complexity 0(n^2)*/
void BubbleSort(int*a,int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(*(a+j)>*(a+j+1)){
                temp=*(a+j);
                *(a+j) = *(a+j+1);
                *(a+j+1) = temp;
            }
        }
    }
}
int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    BubbleSort(arr,n);

    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}