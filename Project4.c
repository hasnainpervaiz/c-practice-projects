#include<stdio.h>

int main(){
	int opt, i, j, space, rows = 5;
	puts("\t\t\t\t------(Patterns)------\n");
	puts("Enter 1 For Pyramid Pattern.");
	puts("Enter 2 For Pyramid Pattern From Left To Right.");
	puts("Enter 3 For Pyramid Pattern From Right To Left.");
	puts("Enter 4 For Pyramid Pattern From Bottom To Up.");
	puts("Enter 5 For Diamond Pattern.");
	puts("Enter 6 For Square Pattern.");
	puts("Enter 7 For Rectangle Pattern.\n");
	puts("Enter -1 To Exit The Program.\n");
	while(1){
		printf("Enter Numbers From 1-7 To Draw Those Patterns(-1 To Exit): ");
		if(scanf("%d", &opt) != 1){
			printf("Invalid Input! Only Integers Are Allowed.\n");
			while (getchar() != '\n');
			continue;			
		}
		else if(opt == -1){
			printf("Thankyou!");
			break;
		}
		else if(opt < 1 || opt > 7){
			puts("Out Of Range! Try Again.");
			continue;
		}
		else if(opt == 1){
			for(i = 1; i <= rows; i++){
				for(space = 1; space <= (rows-i); space++){
					printf(" ");
				}
				for(j = 1; j <= i; j++){
					printf("* ");
				}
				printf("\n");
			}
		}
		else if(opt == 2){
			for(i = 1; i <= 5; i++){
				for(j = 1; j <= i; j++){
					printf("*");
				}
				printf("\n");
			}
		}
		else if(opt == 3){
			for (i = 1; i <= 5; i++) {
    			for (j = 1; j <= 5 - i; j++) {
        			printf(" ");
    			}
   				for (j = 1; j <= i; j++) {
    			    printf("*");
    			}
    			printf("\n");
			}
		}
		else if(opt == 4){
			for(i = rows; i >= 1; i--){
    			for(space = 1; space <= (rows - i); space++){
    			    printf(" ");
   				}
    			for(j = 1; j <= i; j++){
    			    printf("* ");
    			}
				printf("\n");
			}
		}
		else if(opt == 5){
			for(i = 1; i <= rows; i++){
				for(space = 1; space <= (rows-i); space++){
					printf(" ");
				}
				for(j = 1; j <= i; j++){
					printf("* ");
				}
				printf("\n");
			}
			for(i = (rows-1); i >= 1; i--){
    			for(space = 1; space <= (rows - i); space++){
    			    printf(" ");
   				}
    			for(j = 1; j <= i; j++){
    			    printf("* ");
    			}
				printf("\n");
			}
		}
		else if(opt == 6){
			for(i = 1; i <= 5; i++){
				for(j = 1; j <= 5; j++){
					printf("*");
				}
				printf("\n");
			}
		}
		else{
			for(i = 1; i <= 3; i++){
				for(j = 1; j <= 5; j++){
					printf("*");
				}
				printf("\n");
			}
		}
	}
	
	return 0;
}
