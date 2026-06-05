#include<stdio.h>

int main(){
	int arr[100];
	int size, i, j, sum = 0, compare, search, found = 0, largest, smallest;
	int even = 0, odd = 0, positive = 0, negative = 0, zero = 0;
	char choice;
	float average;
	
	printf("Enter The No. Of Elements You Want To Analyze: ");
	scanf("%d", &size);
	
	if(size <= 0 || size > 100){
    	printf("Invalid Size!");
    	return 0;
	}
	
	for(i = 0; i < size; i++){
		printf("Enter No. %d: ", i+1);
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	printf("\n");
	largest = arr[0];
	
	for(i = 1; i < size; i++){
		if(arr[i] > largest){
			largest = arr[i];
		}
	}
	printf("Largest No. Is: %d\n", largest);	
	
	compare = -99999;
	
	for(i = 0; i < size; i++){
		if(arr[i] > compare && arr[i] < largest){
			compare = arr[i];
		}
	}
	printf("Second Largest No. Is: %d\n", compare);
	
	smallest = arr[0];
	
	for(i = 1; i < size; i++){
		if(arr[i] < smallest){
			smallest = arr[i];
		}
	}
	printf("Smallest No. Is: %d\n", smallest);
	
	compare = 999999;
	
	for(i = 0; i < size; i++){
		if(arr[i] < compare && arr[i] > smallest){
			compare = arr[i];
		}
	}
	printf("Second Smallest No. Is: %d\n\n", compare);
		
	printf("The Sum Is: %d\n", sum);
	average = (float)sum/size;
	printf("The Average Is: %.2f\n\n", average);
	
	for(i = 0; i < size; i++){
		if(arr[i] % 2 == 0){
			even++;
		}
		else{
			odd++;
		}
	}
	printf("Even Count = %d\n", even);
	printf("Odd Count = %d\n", odd);
	
	printf("\n");
	
	for(i = 0; i < size; i++){
		if(arr[i] > 0){
			positive++;
		}
		else if(arr[i] < 0){
			negative++;
		}
		else{
			zero++;
		}
	}
	printf("Positive Count = %d\n", positive);
	printf("Negative Count = %d\n", negative);
	printf("Zero Count = %d\n\n", zero);
	
	puts("Original List: ");
	for(i = 0; i < size; i++){
    	printf("%d\t", arr[i]);
	}
	printf("\n\n");
	printf("Reversed List:\n");
	for(i = (size - 1); i >= 0; i--){
		printf("%d\t", arr[i]);
	}
	
	puts("\n\nOriginal List: ");
	for(i = 0; i < size; i++){
    	printf("%d\t", arr[i]);
	}
	printf("\n\n");
	for(j = 1; j < size; ++j){
		for(i = 0; i < (size - j); ++i){
			if(arr[i] > arr[i + 1]){
				int hold = arr[i];
				arr[i] = arr[i + 1];                                
	        	arr[i + 1] = hold;
			}
		}
	}
	printf("Data Items In Ascending Order:\n");
	for (i = 0; i < size; ++i) {
	   printf("%d\t", arr[i]);
	}
	printf("");
	
	printf("\n\nDo You Want To Search A Number? (y/n): ");
	scanf(" %c", &choice);
	if(choice == 'Y' || choice == 'y'){
		printf("Enter The No.: ");
		scanf("%d", &search);
		
		for(i = 0; i < size; i++){
			if(search == arr[i]){
				printf("The No. %d Found At Position %d.\n", search, i + 1);
				found = 1;
				break;
			}
		}
		if(found == 0){
			printf("The No. Is Not Present!");
		}
	}
	else{
		printf("Thankyou!");
		return 0;
	}

	return 0;
}
