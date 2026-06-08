#include<stdio.h>

typedef struct bank_management{
	int account;
	char name[100];
	float balance;	
}bank_m;

int main(){
	FILE *fptr;
	bank_m bank;
	
	int opt, dup = 0;
	char ch;
	
	while(1){
		puts("Menu:\n");
		puts("1. Create Account");
		puts("2. Display All Accounts");
		puts("3. Search Account");
		puts("4. Deposit Money");
		puts("5. Withdraw Money");
		puts("6. Delete Account");
		puts("7. Exit\n");
		printf("Enter The Option That You Want To Select: ");
		
		if(scanf("%d", &opt) != 1){
			puts("Invalid Value! Only Integers Are Allowed. Try Again.\n");
			while (getchar() != '\n');
			continue;
		}
		
		else if(opt < 1 || opt > 7){
			puts("Option Should Be Between 1-7. Try Again.\n");
			continue;
		}
		
		else if(opt == 1){
			printf("Enter Account Number: ");
			if(scanf("%d", &bank.account) != 1){
				puts("Invalid Value! Only Integers Are Allowed. Try Again.\n");
				while (getchar() != '\n');
				continue;
			}
			int file_account;
			
			fptr = fopen("bank.txt", "r");
			if(fptr != NULL){
			    while(fscanf(fptr, "Account Number: %d\n", &file_account) == 1){
			    	fgets(bank.name, sizeof(bank.name), fptr);
			    	fscanf(fptr, "Balance: %f\n\n", &bank.balance);
			    	
        			if(file_account == bank.account){
            			printf("Account Number Already Exists!\n\n");
            			dup = 1;
            			break;
        			}
    			}
    		fclose(fptr);
			}
			
			if(dup == 1){
				while (getchar() != '\n');
    			continue;
			}
			dup = 0;
			while (getchar() != '\n');
			printf("Enter Your Name: ");
			fgets(bank.name, sizeof(bank.name), stdin);
			printf("Enter Initial Balance: ");
			if(scanf("%f", &bank.balance) != 1){
				puts("Invalid Value! Enter A Valid Number. Try Again.\n");
				while (getchar() != '\n');
				continue;
			}
			else if(bank.balance <= 0.00){
				puts("Invalid Value! Only Positive Values Are Allowed. Try Again.\n");
				while (getchar() != '\n');
				continue;
			}
			
			fptr = fopen("bank.txt", "a");
			fprintf(fptr, "Account Number: %d\n", bank.account);
			fprintf(fptr, "Name: %s", bank.name);
			fprintf(fptr, "Balance: %.2f\n\n", bank.balance);
			fclose(fptr);
			printf("\n");
		}
		
		else if(opt == 2){
			fptr = fopen("bank.txt", "r");
			if(fptr == NULL){
				printf("File doesn't exist!\n");
				continue;
			}
			puts("\n--- All User Data ---\n");
			while((ch = fgetc(fptr)) != EOF){
				printf("%c", ch);
			}
			puts("--- End Of Data! ---");
			fclose(fptr);
		}
		
		else if(opt == 3){
			int search_account, found = 0;

    		printf("Enter The Account To Search: ");
    		scanf("%d", &search_account);
			while (getchar() != '\n');
			
			fptr = fopen("bank.txt", "r");
    		if(fptr == NULL){
        		printf("File Doesn't Exist!\n");
        		continue;
    		}

    		while(fscanf(fptr, "Account Number: %d\n", &bank.account) == 1){
        		fgets(bank.name, sizeof(bank.name), fptr);
        		fscanf(fptr, "Balance: %f\n\n", &bank.balance);
        		
				if(bank.account == search_account){
					found = 1;
            		printf("\nAccount Found!\n");
            		printf("Account: %d\n", bank.account);
            		printf("%s", bank.name);
            		printf("Balance: %f\n", bank.balance);
        			}
    			}
    		if(!found){
        		printf("Account Not Found!\n\n");
        		break;
    		}

    		fclose(fptr);
		}
		
		else if(opt == 4){
			FILE *temp;
			int search_account, found = 0;
			float amount;
			
			printf("Enter Account To Deposit Money: ");
			scanf("%d", &search_account);
			
			fptr = fopen("bank.txt", "r");
			if(fptr == NULL){
				printf("File doesn't exist!\n");
				continue;
			}
			temp = fopen("temp.txt", "w");
			if(temp == NULL){
				printf("Error Creating New File!\n");
				fclose(fptr);
				continue;
			}
			while(fscanf(fptr, "Account Number: %d\n", &bank.account) == 1){
				fgets(bank.name, sizeof(bank.name), fptr);
				fscanf(fptr, "Balance: %f\n\n", &bank.balance);
				
				if(bank.account == search_account){
					printf("Enter The Amount: ");
					scanf("%f", &amount);
					if(amount <= 0){
    					printf("Invalid Amount!\n\n");
					}
					else{
						bank.balance += amount;
						found = 1;
						printf("\nAmount Deposited Successfully!\n");	
					}
				}
				fprintf(temp, "Account Number: %d\n", bank.account);
				fprintf(temp, "%s", bank.name);
				fprintf(temp, "Balance: %.2f\n\n", bank.balance);
			}
			fclose(fptr);
			fclose(temp);
			
			if(found == 1){
					remove("bank.txt");
					rename("temp.txt", "bank.txt");
				}
			else{
				printf("Bank Account Not Found!\n\n");
				remove("temp.txt");
			}
		}
		
		else if(opt == 5){
			FILE *temp;
			int search_account, found = 0, withdrawn = 0;
			float amount;
			
			printf("Enter Account Withdraw Money: ");
			scanf("%d", &search_account);
			
			fptr = fopen("bank.txt", "r");
			if(fptr == NULL){
				printf("File doesn't exist!\n");
				continue;
			}
			temp = fopen("temp.txt", "w");
			if(temp == NULL){
				printf("Error Creating New File!\n");
				fclose(fptr);
				continue;
			}
			
			while(fscanf(fptr, "Account Number: %d\n", &bank.account) == 1){
				fgets(bank.name, sizeof(bank.name), fptr);
				fscanf(fptr, "Balance: %f\n\n", &bank.balance);
				
				if(bank.account == search_account){
					found = 1;
					printf("Enter The Amount: ");
					scanf("%f", &amount);
					if(amount <= 0){
    					printf("Invalid Amount!\n\n");
					}
					else if(bank.balance >= amount){
						bank.balance -= amount;
						withdrawn = 1;
						printf("\nAmount Withdrawn Successfully!\n\n");
					}
					else{
						printf("\nBalance Is Insufficient!\n\n");
					}
				}
				fprintf(temp, "Account Number: %d\n", bank.account);
				fprintf(temp, "%s", bank.name);
				fprintf(temp, "Balance: %.2f\n\n", bank.balance);
			}
			fclose(fptr);
			fclose(temp);
			
			if(withdrawn){
					remove("bank.txt");
					rename("temp.txt", "bank.txt");
				}
			else{
				remove("temp.txt");
				
				if(!found){
					printf("Bank Account Not Found!\n\n");
				}
			}			
		}
		
		else if(opt == 6){
			FILE *temp;
			int delete_account, found = 0;
			
			fptr = fopen("bank.txt", "r");
			if(fptr == NULL){
				printf("File doesn't exist!\n");
				break;
			}
			temp = fopen("temp.txt", "w");
			if(temp == NULL){
				printf("Error Creating New File!\n");
				fclose(fptr);
				break;
			}
			printf("Enter Account To Delete: ");
			scanf("%d", &delete_account);
			while(fscanf(fptr, "Account Number: %d\n", &bank.account) == 1){
				fgets(bank.name, sizeof(bank.name), fptr);
				fscanf(fptr, "Balance: %f\n\n", &bank.balance);
				
				if(bank.account == delete_account){
					found = 1;
				}
				else{
					fprintf(temp, "Account Number: %d\n", bank.account);
					fprintf(temp, "Name: %s", bank.name);
					fprintf(temp, "Balance: %.2f\n\n", bank.balance);	
				}
			}
			fclose(fptr);
			fclose(temp);
			
			if(found){
				remove("bank.txt");
				rename("temp.txt", "bank.txt");
				printf("Record Deleted Successfully!\n\n");
			}
			else{
				remove("temp.txt");
				printf("ID not found!\n\n");
			}	
		}
		
		else if(opt == 7){
			printf("Thankyou!");
			break;
		}
	}
	
	return 0;
}
