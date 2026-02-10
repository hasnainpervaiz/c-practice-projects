#include<stdio.h>

int main(){
	char opr;
	int num1, num2, total = 0;

	while(1){
		printf("Enter The Function That You Want To Perform(+, -, *, /, %)\n");
		printf("Enter 'R' Or 'r' To Exit The Program: ");
		scanf(" %c", &opr);
		if(opr == 'r' || opr == 'R'){
			break;
		}
		else if(opr != '+' && opr != '-' && opr != '*' && opr != '/' && opr != '%') {
            printf("Invalid Symbol! Please Try Again.\n\n");
            continue;
        }
		printf("Enter 1st Number: ");
		scanf("%d", &num1);
		printf("Enter 2nd Number: ");
		scanf("%d", &num2);
		
		if (opr == '+') {
            total = num1 + num2;
            printf("Sum: %d\n\n", total);
        }
        else if(opr == '-') {
            total = num1 - num2;
            printf("Difference: %d\n\n", total);
        }
        else if(opr == '*') {
            total = num1 * num2;
            printf("Product: %d\n\n", total);
        }
        else if(opr == '/') {
            total = num1 / num2;
            printf("Quotient: %d\n\n", total);
        }
        else if(opr == '%') {
            total = num1 % num2;
            printf("Remainder: %d\n\n", total);
    	}
	}
	
	return 0;
}
