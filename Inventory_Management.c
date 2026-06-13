#include<stdio.h>

typedef struct inventory_management{
	int id;
	char name[100];
	float price;
	int quantity;	
}inventory_m;

int main(){
	FILE *fptr;
	inventory_m invent;
	
	int opt, dup = 0;
	char ch;
	
	while(1){
		puts("Menu:\n");
		puts("1. Add Product");
		puts("2. Display Products");
		puts("3. Search Product");
		puts("4. Restock Product");
		puts("5. Sell Product");
		puts("6. Delete Product");
		puts("7. Low Stock Report");
		puts("8. Exit\n");
		printf("Enter The Option That You Want To Select: ");
		
		if(scanf("%d", &opt) != 1){
			puts("Invalid Value! Only Integers Are Allowed. Try Again.\n");
			while (getchar() != '\n');
			continue;
		}
		
		else if(opt < 1 || opt > 8){
			puts("Option Should Be Between 1-8. Try Again.\n");
			continue;
		}
		
		else if(opt == 1){
			printf("Enter Product ID: ");
			if(scanf("%d", &invent.id) != 1){
				puts("Invalid Value! Only Integers Are Allowed. Try Again.\n");
				while (getchar() != '\n');
				continue;
			}
			int file_id;
			
			fptr = fopen("inventory.txt", "r");
			if(fptr != NULL){
			    while(fscanf(fptr, "Product ID: %d\n", &file_id) == 1){
			    	fgets(invent.name, sizeof(invent.name), fptr);
			    	fscanf(fptr, "Price: %f\n", &invent.price);
			    	fscanf(fptr, "Quantity: %d\n\n", &invent.quantity);
			    	
        			if(file_id == invent.id){
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
			printf("Enter Product Name: ");
			fgets(invent.name, sizeof(invent.name), stdin);
			printf("Enter Price: ");
			if(scanf("%f", &invent.price) != 1){
				puts("Invalid Value! Enter A Valid Number. Try Again.\n");
				while (getchar() != '\n');
				continue;
			}
			else if(invent.price <= 0.00){
				puts("Invalid Value! Only Positive Values Are Allowed. Try Again.\n");
				while (getchar() != '\n');
				continue;
			}
			
			printf("Enter Quantity: ");
			if(scanf("%f", &invent.quantity) != 1){
				puts("Invalid Value! Enter A Valid Number. Try Again.\n");
				while (getchar() != '\n');
				continue;
			}
			else if(invent.quantity <= 0){
				puts("Invalid Value! Only Positive Values Are Allowed. Try Again.\n");
				while (getchar() != '\n');
				continue;
			}
			
			fptr = fopen("inventory.txt", "a");
			fprintf(fptr, "Product ID: %d\n", invent.id);
			fprintf(fptr, "Product Name: %s", invent.name);
			fprintf(fptr, "Price: %.2f\n", invent.price);
			fprintf(fptr, "Quantity: %d\n\n", invent.quantity);
			fclose(fptr);
			printf("\n");
		}
		
		else if(opt == 2){
			fptr = fopen("inventory.txt", "r");
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
			int search_id, found = 0;

    		printf("Enter The ID To Search: ");
			if(scanf("%d", &search_id) != 1){
				puts("Invalid Value! Enter A Valid Number. Try Again.\n");
				while (getchar() != '\n');
				continue;
			}
			
			fptr = fopen("inventory.txt", "r");
    		if(fptr == NULL){
        		printf("File Doesn't Exist!\n");
        		continue;
    		}

    		while(fscanf(fptr, "Product ID: %d\n", &invent.id) == 1){
        		fgets(invent.name, sizeof(invent.name), fptr);
        		fscanf(fptr, "Price: %f\n", &invent.price);
        		fscanf(fptr, "Quantity: %d\n\n", &invent.quantity);
        		
				if(invent.id == search_id){
					found = 1;
            		printf("\nProduct Found!\n");
            		printf("Product ID: %d\n", invent.id);
            		printf("%s", invent.name);
            		printf("Price: %f\n", invent.price);
            		printf("Quantity: %d\n", invent.quantity);
        			}
    			}
    		if(!found){
        		printf("Product Not Found!\n\n");
        		break;
    		}

    		fclose(fptr);
		}
		
		else if(opt == 4){
			FILE *temp;
			int search_id, found = 0, restock;
			printf("Enter ID To Restock Product: ");
			if(scanf("%d", &search_id) != 1){
				puts("Invalid Value! Enter A Valid Number. Try Again.\n");
				while (getchar() != '\n');
				continue;
			}
			
			fptr = fopen("inventory.txt", "r");
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
			while(fscanf(fptr, "Product ID: %d\n", &invent.id) == 1){
				fgets(invent.name, sizeof(invent.name), fptr);
				fscanf(fptr, "Price: %f\n", &invent.price);
        		fscanf(fptr, "Quantity: %d\n\n", &invent.quantity);
				
				if(invent.id == search_id){
					printf("Enter Restock Amount: ");
					scanf("%d", &restock);
					
					if(restock <= 0){
						printf("Invalid Restock Amount!\n\n");
						found = 2;
					}
					else{
						invent.quantity += restock;
						found = 1;
						printf("Product Has Been Restocked!\n\n");	
					}	
				}					
				fprintf(temp, "Product ID: %d\n", invent.id);
				fprintf(temp, "%s", invent.name);
				fprintf(temp, "Price: %f\n", invent.price);
				fprintf(temp, "Quantity: %d\n\n", invent.quantity);
			}
				fclose(fptr);
				fclose(temp);
				
				if(found == 1){
					remove("inventory.txt");
					rename("temp.txt", "inventory.txt");
				}
				else{
					printf("Product Not Found!\n\n");
					remove("temp.txt");
				}
		}
		
		else if(opt == 5){
			FILE *temp;
			int search_id, found = 0, order;
			printf("Enter ID To Sell Product: ");
			if(scanf("%d", &search_id) != 1){
				puts("Invalid Value! Enter A Valid Number. Try Again.\n");
				while (getchar() != '\n');
				continue;
			}
			
			fptr = fopen("inventory.txt", "r");
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
			while(fscanf(fptr, "Product ID: %d\n", &invent.id) == 1){
				fgets(invent.name, sizeof(invent.name), fptr);
				fscanf(fptr, "Price: %f\n", &invent.price);
        		fscanf(fptr, "Quantity: %d\n\n", &invent.quantity);
				
				if(invent.id == search_id){
					found = 1;
					
					printf("Enter The Quantity To Sell: ");
					if(scanf("%d", &order) != 1){
						scanf("%d", &order);
						while (getchar() != '\n');
						order = 0;
					}
					
					if(order <= 0){	
							printf("Invalid Amount!\n\n");
					}					
					else if(order <= invent.quantity){
						invent.quantity -= order;
						printf("Product Has Been Sold!\n\n");
					}
					else{
						printf("Not Enough Stock!\n\n");	
					}	
				}
				
				fprintf(temp, "Product ID: %d\n", invent.id);
				fprintf(temp, "%s", invent.name);
				fprintf(temp, "Price: %f\n", invent.price);
				fprintf(temp, "Quantity: %d\n\n", invent.quantity);
			}
				fclose(fptr);
				fclose(temp);
				
				if(found == 1){
					remove("inventory.txt");
					rename("temp.txt", "inventory.txt");
				}
				else{
					printf("Product Not Found!\n\n");
					remove("temp.txt");
				}
		}
		
		else if(opt == 6){
			FILE *temp;
			int delete_id, found = 0;
			
			fptr = fopen("inventory.txt", "r");
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
			printf("Enter ID To Delete Product: ");
			scanf("%d", &delete_id);
			while(fscanf(fptr, "Product ID: %d\n", &invent.id) == 1){
				fgets(invent.name, sizeof(invent.name), fptr);
				fscanf(fptr, "Price: %f\n", &invent.price);
				fscanf(fptr, "Quantity: %d\n", &invent.quantity);
				
				if(invent.id == delete_id){
					found = 1;
				}
				else{
					fprintf(temp, "Product ID: %d\n", invent.id);
					fprintf(temp, "Product Name: %s", invent.name);
					fprintf(temp, "Price: %.2f\n", invent.price);	
					fprintf(temp, "Quantity: %d\n", invent.quantity);
				}
			}
			fclose(fptr);
			fclose(temp);
			
			if(found){
				remove("inventory.txt");
				rename("temp.txt", "inventory.txt");
				printf("Record Deleted Successfully!\n\n");
			}
			else{
				remove("temp.txt");
				printf("Product not found!\n\n");
			}
		}
		
		else if(opt == 7){
			int found = 0;
			
			fptr = fopen("inventory.txt", "r");
			if(fptr == NULL){
        		printf("File doesn't exist!\n");
        		continue;
    		}
    		
    		printf("\n--- Low Stock Products ---\n\n");
    		while(fscanf(fptr, "Product ID: %d\n", &invent.id) == 1){
    			fgets(invent.name, sizeof(invent.name), fptr);
				fscanf(fptr, "Price: %f\n", &invent.price);
        		fscanf(fptr, "Quantity: %d\n\n", &invent.quantity);
        		if(invent.quantity == 0){
        			found = 1;
        			printf("Product No. %d Is Out Of Stock!\n\n", invent.id);
				}
    			else if(invent.quantity <= 5){
    				found = 1;
    				printf("Product No. %d Is Low On Stock!\n\n", invent.id);
    			}
			}
			
			if(found == 0){
				printf("No Low Stock Products Found!\n");
			}
			
			fclose(fptr);
		}
		
		else if(opt == 8){
			printf("Thankyou!");
			break;
		}
	}

	return 0;
}
