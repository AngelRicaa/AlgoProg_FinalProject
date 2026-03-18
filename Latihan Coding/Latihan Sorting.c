//BUBBLE SORTING
//#include <stdio.h>
//
//int main(){
//	int i, j, n;
//	
//	int arr[] = {3, 5, 2, 9, 7, 8 , 10, 6};
//	n = sizeof(arr)/sizeof(arr[0]);
//	for(i = 0; i < n-1; i++){
//		for(j = 0; j < n - i - 1; j++){
//			if(arr[j] < arr[j+1]){
//				int temp = arr[j];
//				arr[j] = arr[j+1];
//				arr[j+1] = temp;
//			}
//		}
//	}
//	
//	printf("Sorting: ");
//	for(i = 0; i < n; i++){
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//quickSort =======================================================================
//#include <stdio.h>
//
//void viewAll(int arr[], int size){
//	int i;
//	for(i = 0; i < size; i++){
//		printf("%d", arr[i]);
//		if(i != size-1){
//			printf(" ");
//		}else{
//			printf("\n");
//		}
//	}	
//}
//
//void swap(int *a, int *b){
//	int temp;
//	temp = *a;
//	*a = *b;
//	*b = temp;	
//}
//
//int partition(int arr[], int left, int right){
//	int pivot = right;
//	int insert = left;
//	int i;
//	
//	for(i = left; i < right; i++){
//		if(arr[i] < arr[pivot]){
//			swap(&arr[i], &arr[insert]);
//			insert++;
//		}
//	}
//	
//	swap(&arr[pivot], &arr[insert]);
//	return insert;
//}
//
//void quickSort(int arr[], int left, int right){
//	if(left < right){
//		int pivot = partition(arr, left, right);
//		
//		quickSort(arr, left, pivot-1);
//		quickSort(arr, pivot+1, right);
//	}
//}
//
//int main(){
//	int arr[] = {2, 5, 7, 3, 4, 1, 8};
//	int size = sizeof(arr)/sizeof(arr[0]);
//	
//	quickSort(arr, 0, size-1);
//	
//	viewAll(arr, size);
//	return 0;
//}

//#include <stdio.h>
//
//void swap(int *a, int *b){
//	int temp;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//int partition(int arr[], int left, int right){
//	int pivot = right;
//	int tempat = left;
//	int i;
//	
//	for(i = left; i < right; i++){
//		if(arr[i] < arr[pivot]){
//			swap(&arr[i], &arr[tempat]);
//			tempat++;
//		}
//	}
//	
//	swap(&arr[tempat], &arr[pivot]);
//	return tempat;
//}
//
//void quickSort(int arr[], int left, int right){
//	if(left < right){
//		int pivot = partition(arr, left, right);
//		
//		quickSort(arr, left, pivot-1);
//		quickSort(arr, pivot+1, right);
//	}	
//}
//
//int search(int arr[], int target, int n){
//	int i;
//	for(i = 0; i < n; i++){
//		if(arr[i] == target) return i;
//	}
//	
//	return -1;
//}
//
//int main(){
//	int t, tc, i, j, n, target;
//
//	
//	scanf("%d", &tc); getchar();
//	for(t = 0; t < tc; t++){
//		scanf("%d", &n); getchar();
//		int arr[n];
//		for(i = 0; i < n; i++){
//			scanf("%d", &arr[i]); getchar();
//		}
//		
//		scanf("%d", &target); getchar();
//		
//		quickSort(arr, 0, n-1);
//		
//		int result = search(arr, target, n);
//		
//		if(result != -1){
//			if(result == n-1) printf("Case #%d: %d %d\n", t+1, arr[result-1], arr[result]);
//			else if(result == 0) printf("Case #%d: %d %d\n", t+1, arr[result], arr[result+1]);
//			else{
//				printf("Case #%d: %d %d\n", t+1, arr[result], arr[result+1]);
//			}
//		}else{
//			printf("Case #%d: -1 -1\n", t+1);
//		}
//	}
//	return 0;
//}

//merge sort =========================================================================
//#include <stdio.h>
//
//void merge(int arr[], int left, int mid, int right){
//	int i = left;
//	int j = mid;
//	int k = 0;
//	int temp[right-left+1];
//	
//	
//}
//
//void mergeSort(int arr[], int left, int right){
//	if(left < right){
//		int mid = (left+right)/2;
//		
//		mergeSort(arr, left, mid);
//		mergeSort(arr, mid+1, right);
//		
//		merge
//	}
//}
//
//int main(){
//	int arr[] = {3, 2, 7, 9, 10, 11, 4};
//	int size = 7;
//	
//	mergeSort(arr, 0, size-1);
//	return 0;
//}

//#include <stdio.h>
//
//struct data{
//	char nim[200];
//	char nama[200];	
//};
//
//void merge(struct data data[], int left, int mid, int right){
//	int i = left, j = mid+1, k = 0;
//	struct data temp[right-left+1];
//	
//	while(i <= mid && j <= right){
//		if(strcmp(data[i].nim, data[j].nim) < 0){
//			temp[k++] = data[i++];
//		}
//		else{
//			temp[k++] = data[j++];
//		}
//}
//	
//	while(i <= mid){
//		temp[k++] = data[i++];
//	}
//	
//	while(j <= right){
//		temp[k++] = data[j++];
//	}
//	
//	int p;
//	int index = 0;
//	
//	for(p = left; p <= right; p++){
//		data[p] = temp[index++];
//	}
//}
//
//void mergeSort(struct data data[], int left, int right){
//	if(left < right){
//		int mid = (left + right)/2;
//		
//		mergeSort(data, left, mid);
//		mergeSort(data, mid+1, right);
//		
//		merge(data, left, mid, right);
//	}	
//}
//
//int main(){
//	int t, i, tc;
//	FILE *fp;
//	fp = fopen("testdata.in", "r");
//	fscanf(fp, "%d\n", &tc);
//	struct data data[tc];
//	
//	for(t = 0; t < tc; t++){
//		fscanf(fp, "%s %s\n", data[t].nim, data[t].nama);
//	}
//	
//	mergeSort(data, 0, tc-1);
//	
//	for(i = 0; i < tc; i++){
//		printf("%s %s\n", data[i].nim, data[i].nama);
//	}
//	fclose(fp);
//	return 0; 
//}

//#include <stdio.h>
//
//int binary(int arr[], int right, int target){
//	int left = 0;
//	while(left <= right){
//		int mid = (left+right)/2;
//		
//		if(arr[mid] == target){
//			return mid;
//		}
//		
//		if(arr[mid] > target){
//			right = mid-1;
//		}
//		
//		else if(arr[mid] < target){
//			left = mid+1;
//		}
//	}
//	
//	return -1;
//}
//
//int main(){
//	int a,b, i;
//	
//	scanf("%d %d", &a, &b); getchar();
//	int arr[a], target;
//	for(i = 0; i < a; i++){
//		scanf("%d", &arr[i]); getchar();
//	}
//	
//	for(i = 0; i < b; i++){
//		scanf("%d", &target); getchar();
//		
//		int result = binary(arr, a-1, target);
//		
//		if(result == -1){
//			printf("%d\n", result);
//		}
//		else{
//			printf("%d\n", result+1);
//		}
//	}
//	
//	return 0;
//}

//#include <stdio.h>
//
//void swap(int *a, int *b){
//	int temp = *a;
//	*a = *b;
//	*b = temp;	
//}
//
//int partition(int arr[], int left, int right){
//	int indexPivot = right;
//	int indexInsert = left;
//	
//	int i;
//	for(i = left; i < indexPivot; i++){
//		if(arr[i] < arr[indexPivot]){
//			swap(&arr[i], &arr[indexInsert]);
//			indexInsert++;
//		}
//	}
//	
//	swap(&arr[indexPivot], &arr[indexInsert]);
//	
//	return indexInsert;
//}
//
//void quickSort(int arr[], int left, int right){
//	if(left < right){
//		int indexPivot = partition(arr, left, right);
//		
//		quickSort(arr, left, indexPivot-1);
//		quickSort(arr, indexPivot+1, right);
//	}
//}
//	
//int main(){
//	int arr[] = {3,5, 9, 7, 2, 1, 8, 6, 10 , 17, 13, 21};
//	int size = sizeof(arr)/sizeof(arr[0]);
//	
//	quickSort(arr, 0, size-1);
//	
//	int i;
//	for(i = 0; i < size; i++){
//		printf("%d ", arr[i]);
//	}
//	
//	return 0;
//}

//#include <stdio.h>
//
//int main(){
//	
//	return 0;
//}
