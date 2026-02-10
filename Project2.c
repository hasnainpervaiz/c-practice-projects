#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int i, num, opt;
	srand(time(NULL));
    num = rand() % 1001;
	int numbers[3];
	puts("\t\t\t\t\t------(This Is A Number Guessing Game!)------\n");
	for(i = 0; i < 4; i++){
		if(i == 3){
			puts("\nYou Have Ran Out Of Tries!");
			puts("Enter 1 If You Want To Have Another Try Or -1 If You Want To Exit The Game: ");
			scanf("%d", &opt);
			if(opt == 1){
				i = i - 2;
				continue;
			}
			else if(opt == -1){
				puts("ThankYou!");	
				printf("The Number Was: %d", num);
				return 0;
			}
		}
		
		printf("You Have 3 Tries.\nTry No. %d.\n", i+1);
		puts("Numbers Should Be Between 0-1000");
		printf("Enter A Number: ");
		
		
		if(scanf("%d", &numbers[i]) != 1){
			printf("Invalid Input! Only Integers Are Allowed.\n");
			while (getchar() != '\n');
			i--;
			continue;
		}
		else if(numbers[i] > 1000 || numbers[i] < 0){
			printf("Invalid Value Entered! Try Again.\n");
			i--;
			continue;
		}
		else if(numbers[i] == num){
			puts("You Got It. Congratulations!");
			puts("Enter 1 If You Want To Continue Or -1 If You Want To Exit: ");
			scanf("%d", &opt);
			if(opt == 1){
				i = -1;
				num = rand() % 1001;
				continue;
			}
			else if(opt == -1){
				return 0;
			}
		}
		else if(numbers[i] != num){
			if(numbers[i] < (num - 250)){
				puts("Oh No! The Number Is Too Low. Try Again.");
			}
			else if(numbers[i] < num){
				puts("You Almost Had It. Try Again.");
				puts("Hint: Try A Bit Higher!\n");
				continue;
			}
			else if(numbers[i] > (num + 250)){
				puts("Oh No! The Number Is Too High. Try Again.");
				continue;
			}
		
			else{
				puts("You Almost Had It.");
    			puts("Hint: Try A Bit Lower!");
				continue;
			}
		}
	}

	return 0;
}
