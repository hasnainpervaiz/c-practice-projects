#include<stdio.h>

typedef struct book_management{
	int id;
	char title[100];
	char name[100];
	int quantity;
	int count;	
}book_m;

int main(){
	FILE *fptr;
	book_m book;
	int opt, dup = 0, count = 0;
	char ch;
	
	while(1){
		// DisplayMenu()
		puts("Menu:\n");
		puts("Enter 1 To Add Books.");
		puts("Enter 2 To Display All Books.");
		puts("Enter 3 To Search Book.");
		puts("Enter 4 To Delete Book.");
		puts("Enter 5 To Issue Book.");
		puts("Enter 6 To Return Book.");
		puts("Enter 7 To Exit Program.\n");
		printf("Enter The Option That You Want To Select: ");
		
		// ValidateInput()
		if(scanf("%d", &opt) != 1){
			puts("Invalid Value! Only Integers Are Allowed. Try Again.\n");
			while (getchar() != '\n');
			continue;
		}
		else if(opt < 1 || opt > 7){
			puts("Option Should Be Greater Than 0. Try Again.\n");
			continue;
		}
		
		else if(opt == 1){
			printf("Enter Book ID: ");
			if(scanf("%d", &book.id) != 1){
				puts("Invalid Value! Only Integers Are Allowed. Try Again.\n");
				while (getchar() != '\n');
				continue;
			}		
			int file_id;

			fptr = fopen("library.txt", "r");
			if(fptr != NULL){
			    // checkDuplicate
				while(fscanf(fptr, "ID: %d", &file_id) == 1){
        			if(file_id == book.id){
            			printf("ID already exists!\n\n");
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
			printf("Enter Title: ");
			fgets(book.title, sizeof(book.title), stdin);
			printf("Enter Author's Name: ");
			fgets(book.name, sizeof(book.name), stdin);
			printf("Enter The Quantity: ");
			if(scanf("%d", &book.quantity) != 1){
				puts("Invalid Value! Only Integers Are Allowed. Try Again.\n");
				while (getchar() != '\n');
				continue;
			}
				
			fptr = fopen("library.txt", "a");
			fprintf(fptr, "ID: %d\n", book.id);
			fprintf(fptr, "Title: %s", book.title);
			fprintf(fptr, "Author: %s", book.name);
			fprintf(fptr, "Quantity Available: %d\n", book.quantity);
			fprintf(fptr, "Count: %d\n\n", count);
			fclose(fptr);
						
		}
		else if(opt == 2){
			fptr = fopen("library.txt", "r");
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
    		scanf("%d", &search_id);
			while (getchar() != '\n');
			
			fptr = fopen("library.txt", "r");
    		if(fptr == NULL){
        		printf("File Doesn't Exist!\n");
        		continue;
    		}

    		while(fscanf(fptr, "ID: %d\n", &book.id) == 1){
        		fgets(book.title, sizeof(book.title), fptr);
        		fgets(book.name, sizeof(book.name), fptr);
        		fscanf(fptr, "Quantity Available: %d\n", &book.quantity);
        		fscanf(fptr, "Count: %d\n\n", &count);
        		
				if(book.id == search_id){
					found = 1;
            		printf("\nID Found!\n");
            		printf("ID: %d\n", book.id);
            		printf("%s", book.title);
            		printf("%s", book.name);
            		printf("Quantity Available: %d\n", book.quantity);
        			}
    			}
    		if(!found){
        		printf("Book Not Found!\n\n");
        		break;
    		}

    		fclose(fptr);
		}
		else if(opt == 4){
			FILE *temp;
			int delete_id, found = 0;
			
			fptr = fopen("library.txt", "r");
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
			printf("Enter ID To Delete: ");
			scanf("%d", &delete_id);
			while(fscanf(fptr, "ID: %d\n", &book.id) == 1){
				fgets(book.title, sizeof(book.title), fptr);
				fgets(book.name, sizeof(book.name), fptr);
				fscanf(fptr, "Quantity Available: %d\n", &book.quantity);
				fscanf(fptr, "Count: %d\n\n", &count);
				
				if(book.id == delete_id){
					found = 1;
				}
				else{
					fprintf(temp, "ID: %d\n", book.id);
					fprintf(temp, "Title: %s", book.title);
					fprintf(temp, "Author: %s", book.name);
					fprintf(temp, "Quantity Available: %d\n", book.quantity);
					fprintf(temp, "Count: %d\n\n", count);
					
				}
			}
				fclose(fptr);
				fclose(temp);
				
				if(found){
					remove("library.txt");
					rename("temp.txt", "library.txt");
					printf("Record Deleted Successfully!\n\n");
				}
				else{
					remove("temp.txt");
					printf("ID not found!\n\n");
				}
		}
		else if(opt == 5){
			FILE *temp;
			int search_id, found = 0, count = 0;
			printf("Enter ID To Issue Book: ");
			scanf("%d", &search_id);
			
			fptr = fopen("library.txt", "r");
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
			while(fscanf(fptr, "ID: %d\n", &book.id) == 1){
				fgets(book.title, sizeof(book.title), fptr);
				fgets(book.name, sizeof(book.name), fptr);
				fscanf(fptr, "Quantity Available: %d\n", &book.quantity);
				fscanf(fptr, "Count: %d\n\n", &count);
				
				if(book.id == search_id){
					if(book.quantity > 0){
						book.quantity -= 1;
						count += 1;
						found = 1;
						printf("\nBook Issued Successfully!\n");	
					}
					else{
						printf("\nBook is out of stock!\n");
						found = 2;
					}
				}
				fprintf(temp, "ID: %d\n", book.id);
				fprintf(temp, "%s", book.title);
				fprintf(temp, "%s", book.name);
				fprintf(temp, "Quantity Available: %d\n", book.quantity);
				fprintf(temp, "Count: %d\n\n", count);
			}
				fclose(fptr);
				fclose(temp);
				
				if(found == 1){
					remove("library.txt");
					rename("temp.txt", "library.txt");
				}
				else if (found == 0){
					printf("Book ID Not Found!\n\n");
					remove("temp.txt");
				}
				else{
					remove("temp.txt");
				}
		}
		else if(opt == 6){
			FILE *temp;
			int search_id, found = 0, count = 0;
			printf("Enter ID To Return Book: ");
			scanf("%d", &search_id);
			
			fptr = fopen("library.txt", "r");
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
			while(fscanf(fptr, "ID: %d\n", &book.id) == 1){
				fgets(book.title, sizeof(book.title), fptr);
				fgets(book.name, sizeof(book.name), fptr);
				fscanf(fptr, "Quantity Available: %d\n", &book.quantity);
				fscanf(fptr, "Count: %d\n\n", &count);
				
				if(book.id == search_id){
					book.quantity += 1;
					if(count < 1){
						count = 0;
					}
					else{
						count -= 1;
					}
					found = 1;
					printf("\nBook Returned Successfully!\n");	
				}					
				else{
					printf("\nBook Not Present!\n");
					found = 2;
				}
				fprintf(temp, "ID: %d\n", book.id);
				fprintf(temp, "%s", book.title);
				fprintf(temp, "%s", book.name);
				fprintf(temp, "Quantity Available: %d\n", book.quantity);
				fprintf(temp, "Count: %d\n\n", count);
			}
				fclose(fptr);
				fclose(temp);
				
				if(found == 1){
					remove("library.txt");
					rename("temp.txt", "library.txt");
				}
				else if (found == 0){
					printf("Book ID Not Found!\n\n");
					remove("temp.txt");
				}
				else{
					remove("temp.txt");
				}
		}
		else{
			printf("Thankyou!");
			break;
		}
	}
	return 0;
}
