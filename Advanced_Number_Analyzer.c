#include<stdio.h>

int main(){
	int arr[100];
	int choice, size, i, j, largest, sum = 0, compare, smallest, found = 0, search, dup = 0;
	int even = 0, odd = 0, positive = 0, negative = 0, zero = 0;
	char sort;
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
		
	while(1){
		puts("Menu:\n");
		puts("1. Show Analysis");
		puts("2. Search Number");
		puts("3. Reverse Array");
		puts("4. Detect Duplicates");
		puts("5. Sort Array");
		puts("6. Exit\n");
		printf("Enter Choice: ");
				
		if(scanf("%d", &choice) != 1){
			puts("Invalid Value! Only Integers Are Allowed. Try Again.\n");
			while (getchar() != '\n');
			continue;
		}
		
		else if(choice < 1 || choice > 6){
			printf("Invalid Choice!\n\n");
			continue;
		}
		else if(choice == 1){
			even = odd = 0;
			positive = negative = zero = 0;
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
			printf("Odd Count = %d\n\n", odd);
			
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
		}
		
		else if(choice == 2){
			found = 0;
			printf("\n\nEnter The No. To Search: ");
			scanf("%d", &search);
			
			for(i = 0; i < size; i++){
				if(search == arr[i]){
					printf("The No. %d Found At Position %d.\n", search, i + 1);
					found = 1;
					break;
				}
			}
			if(found == 0){
				printf("The No. Is Not Present!\n");
			}
		}
		
		else if(choice == 3){
			puts("\n\nOriginal List: ");
			for(i = 0; i < size; i++){
    			printf("%d\t", arr[i]);
			}
			printf("\n\n");
			printf("Reversed List:\n");
			for(i = (size - 1); i >= 0; i--){
				printf("%d\t", arr[i]);
			}
			printf("\n");
		}
		
		else if(choice == 4){
			printf("The Duplicates Are:\n");
			for(i = 0; i < size; i++){
				dup = 0;
				for(j = 0; j < i; j++){
					if(arr[i] == arr[j]){
						dup = 1;
						break;
					}
				}
				if(!dup){
					for(j = i + 1; j < size; j++){
			 			if(arr[i] == arr[j]){
			 	 			printf("%d\t", arr[i]);
			 	 			dup++;
			 	 			break;
						}
					}
				}		
			}
			if(dup == 0){
				printf("None");
			}
			printf("\n\n");
		}
		
		else if(choice == 5){
			puts("\n\nDo You Want To Sort The List In Ascending Or Descending Order?");
			puts("Write 'A' For Ascending Or 'D' For Descending Order: ");
			scanf(" %c", &sort);
			
			puts("\n\nOriginal List: ");
				for(i = 0; i < size; i++){
    				printf("%d\t", arr[i]);
				}
				printf("\n\n");
			
			if(sort == 'A' || sort == 'a'){
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
				printf("\n");
			}
			
			else if(sort == 'D' || sort == 'd'){
				for(j = 1; j < size; ++j){
					for(i = 0; i < (size - j); ++i){
						if(arr[i] < arr[i + 1]){
							int hold = arr[i];
							arr[i] = arr[i + 1];
							arr[i + 1] = hold;
						}
					}
				}
				printf("Data Items In Descending Order:\n");
				for (i = 0; i < size; i++) {
			   		printf("%d\t", arr[i]);
				}
				printf("\n");			
			}
		}
		
		else{
			printf("Thankyou!");
			break;
		}
	}	
	
	return 0;
}
