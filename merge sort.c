#include<stdio.h>
#include<stdlib.h>

void merge(int *arr, int left, int mid, int right) {
	int i = left, j = mid + 1, k = 0;
	int *temp = (int *)malloc((right - left + 1) * sizeof(int));

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
		}
	}

	while (i <= mid) {
		temp[k++] = arr[i++];
	}

	while (j <= right) {
		temp[k++] = arr[j++];
	}

	for (i = left, k = 0; i <= right; i++, k++) {
		arr[i] = temp[k];
	}

	free(temp);
}

void mergeSort(int *arr, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
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

	mergeSort(arr, 0, n - 1);

	printf("Sorted Array: ");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr);
	return 0;
}
