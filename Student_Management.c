#include<stdio.h>
#include<string.h>

typedef struct student_management{
	int id;
	char name[100];
	float cgpa;
}student_m;

int main(){
	FILE *fptr;
	student_m stu;
	int opt, dup = 0;
	char ch;
	
	while(1){
		puts("Menu:\n");
		puts("1. Add Student");
		puts("2. Display All Students");
		puts("3. Search Student");
		puts("4. Update Student Record");
		puts("5. Delete Student");
		puts("6. Exit\n");
		printf("Enter The Option That You Want To Select: ");
		
		if(scanf("%d", &opt) != 1){
			puts("Invalid Value! Only Integers Are Allowed. Try Again.\n");
			while (getchar() != '\n');
			continue;
		}
		else if(opt < 1 || opt > 6){
			puts("Option Should Be Between 1-6. Try Again.\n");
			continue;
		}
		
		//Option 1 From Menu
				
		else if(opt == 1){
			printf("Enter Student ID: ");
			if(scanf("%d", &stu.id) != 1){
				puts("Invalid Value! Only Integers Are Allowed. Try Again.\n");
				while (getchar() != '\n');
				continue;
			}		
			int file_id;

			fptr = fopen("student.txt", "r");
			if(fptr != NULL){
				while(fscanf(fptr, "Student ID: %d\n", &file_id) == 1){
					fgets(stu.name, sizeof(stu.name), fptr);
			    	fscanf(fptr, "CGPA: %f\n\n", &stu.cgpa);
        			if(file_id == stu.id){
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
			printf("Enter Student's Name: ");
			fgets(stu.name, sizeof(stu.name), stdin);

			printf("Enter CGPA: ");
			if(scanf("%f", &stu.cgpa) != 1){
				puts("Invalid Value! Only Integers Are Allowed. Try Again.\n");
				while (getchar() != '\n');
				continue;
			}
			else if(stu.cgpa < 1 || stu.cgpa > 4){
				puts("Invalid Value! CGPA Should Be Between 1-4. Try Again.\n");
				while (getchar() != '\n');
				continue;
			}
			printf("\n");	
			fptr = fopen("student.txt", "a");
			fprintf(fptr, "Student ID: %d\n", stu.id);
			fprintf(fptr, "%s", stu.name);
			fprintf(fptr, "CGPA: %.2f\n\n", stu.cgpa);
			fclose(fptr);
		}
		
		//Option 2 From Menu
		
		else if(opt == 2){
			student_m stu[1000], temp;
			char export_choice;
			int count = 0, i, j;
			printf("How Do You Want To See The Records?\n");
			puts("1. Sorting By ID");
			puts("2. Sorting By CGPA");
			puts("3. Sorting By Name\n");
	
			printf("Enter The Option That You Want To Select: ");
		
			if(scanf("%d", &opt) != 1){
				puts("Invalid Value! Only Integers Are Allowed. Try Again.\n");
				while (getchar() != '\n');
				continue;
			}
			else if(opt < 1 || opt > 3){
				puts("Option Should Be Between 1-3. Try Again.\n");
				continue;
			}
	
			//Option 1 From Opt 2
	
			else if(opt == 1){
				fptr = fopen("student.txt", "r");
    			if(fptr == NULL){
       				printf("File Doesn't Exist!\n");
       				continue;
    			}

    			while(fscanf(fptr, "Student ID: %d\n", &stu[count].id) == 1){
       				fgets(stu[count].name, sizeof(stu[count].name), fptr);
       				fscanf(fptr, "CGPA: %f\n\n", &stu[count].cgpa);
    				count++;				
    			}
    			fclose(fptr);
    	
    			for(i = 0; i < count - 1; i++){
    				for(j = 0; j < count - i - 1; j++){
    					 if(stu[j].id > stu[j + 1].id){
    			 			temp = stu[j];
    					 	stu[j] = stu[j + 1];
    			 			stu[j + 1] = temp;
				 		}
					}
				}
		
				puts("Students Sorted By ID:\n");
		
				for(i = 0; i < count; i++){
    				printf("Student ID: %d\n", stu[i].id);
    				printf("%s", stu[i].name);
    				printf("CGPA: %.2f\n\n", stu[i].cgpa);
    			}				
			}
	
			//Option 2 From Opt 2
			
			else if(opt == 2){
				fptr = fopen("student.txt", "r");
    			if(fptr == NULL){
       				printf("File Doesn't Exist!\n");
       				continue;
    			}
			   	while(fscanf(fptr, "Student ID: %d\n", &stu[count].id) == 1){
       				fgets(stu[count].name, sizeof(stu[count].name), fptr);
       				fscanf(fptr, "CGPA: %f\n\n", &stu[count].cgpa);
       				count++;				
    			}
    			fclose(fptr);
    	
    			for(i = 0; i < count - 1; i++){
    				for(j = 0; j < count - i - 1; j++){
    					 if(stu[j].cgpa > stu[j + 1].cgpa){
    					 	temp = stu[j];
    					 	stu[j] = stu[j + 1];
    					 	stu[j + 1] = temp;
						}
					}
				}
		
				puts("Students Sorted By CGPA:\n");
				
				for(i = 0; i < count; i++){
    				printf("Student ID: %d\n", stu[i].id);
    				printf("%s", stu[i].name);
    				printf("CGPA: %.2f\n\n", stu[i].cgpa);
    			}
			}
	
			//Option 3 From Opt 2
	
			else if(opt == 3){
				fptr = fopen("student.txt", "r");
   				if(fptr == NULL){
       				printf("File Doesn't Exist!\n");
       				continue;
   				}

    			while(fscanf(fptr, "Student ID: %d\n", &stu[count].id) == 1){
        			fgets(stu[count].name, sizeof(stu[count].name), fptr);
        			fscanf(fptr, "CGPA: %f\n\n", &stu[count].cgpa);
        			count++;				
    			}
    			fclose(fptr);
    	
    			for(i = 0; i < count - 1; i++){
    				for(j = 0; j < count - i - 1; j++){
    					 if(strcmp(stu[j].name, stu[j + 1].name) > 0){
    					 	temp = stu[j];
    					 	stu[j] = stu[j + 1];
    					 	stu[j + 1] = temp;
						}
					}
				}
		
				puts("Students Sorted By Name:\n");
		
				for(i = 0; i < count; i++){
    				printf("Student ID: %d\n", stu[i].id);
    				printf("%s", stu[i].name);
    				printf("CGPA: %.2f\n\n", stu[i].cgpa);
    			}
			}
			
			//Export Process
			
			printf("Do you want to export these records to CSV? (Y/N): ");
				scanf(" %c", &export_choice);
				
				if(export_choice == 'Y' || export_choice == 'y'){
					FILE *csv = fopen("students.csv", "w");
					if(csv == NULL){
            			printf("Error Creating CSV File!\n");
        			}
					else{
						fprintf(csv, "ID,Name,CGPA\n");
						for(i = 0; i < count; i++){
							stu[i].name[strcspn(stu[i].name, "\n")] = '\0';
							fprintf(csv, "%d,%s,%.2f\n", stu[i].id, stu[i].name, stu[i].cgpa);
						}
						fclose(csv);
        				printf("Records Exported Successfully To students.csv\n");
					}	
				}
				else{
					printf("Thankyou!");
					break;
				}
		}
		
		//Option 3 From Menu
		
		else if(opt == 3){
			printf("How Do You Want To Search The Records?\n");
			puts("1. Search By ID");
			puts("2. Search By Name\n");
	
			printf("Enter The Option That You Want To Select: ");
		
			if(scanf("%d", &opt) != 1){
				puts("Invalid Value! Only Integers Are Allowed. Try Again.\n");
				while (getchar() != '\n');
				continue;
			}
			else if(opt < 1 || opt > 2){
				puts("Option Should Be Between 1-2. Try Again.\n");
				continue;
			}
			
			//Option 1 From Opt 3
			
			else if(opt == 1){
				int search_id, found = 0;

    			printf("Enter The ID To Search The Student: ");
				if(scanf("%d", &search_id) != 1){
					puts("Invalid Value! Enter A Valid ID. Try Again.\n");
					while (getchar() != '\n');
					continue;
				}
			
				fptr = fopen("student.txt", "r");
    			if(fptr == NULL){
        			printf("File Doesn't Exist!\n");
        			continue;
    			}
	
    			while(fscanf(fptr, "Student ID: %d\n", &stu.id) == 1){
        			fgets(stu.name, sizeof(stu.name), fptr);
        			fscanf(fptr, "CGPA: %f\n\n", &stu.cgpa);
        		
					if(stu.id == search_id){
						found = 1;
            			printf("\nStudent Found!\n\n");
            			printf("Student ID: %d\n", stu.id);
            			printf("%s", stu.name);
            			printf("CGPA: %.2f\n\n", stu.cgpa);
            			}
    				}
    			if(!found){
        			printf("Student Not Found!\n\n");
    			}

    			fclose(fptr);
			}
			
			//Option 2 From Opt 3
			
			else if(opt == 2){
				int found = 0;
				char search_name[100];
				while(getchar() != '\n');
    			printf("Enter Name To Search The Student: ");
				fgets(search_name, sizeof(search_name), stdin);
			
				search_name[strcspn(search_name, "\n")] = '\0';
			
				fptr = fopen("student.txt", "r");
    			if(fptr == NULL){
        			printf("File Doesn't Exist!\n");
        			continue;
    			}

    			while(fscanf(fptr, "Student ID: %d\n", &stu.id) == 1){
    				fgets(stu.name, sizeof(stu.name), fptr);
    				stu.name[strcspn(stu.name, "\n")] = '\0';
        			fscanf(fptr, "CGPA: %f\n\n", &stu.cgpa);
        		
					if(strcmp(search_name, stu.name) == 0){
						found = 1;
            			printf("\nStudent Found!\n\n");
            			printf("Student ID: %d\n", stu.id);
            			printf("%s\n", stu.name);
            			printf("CGPA: %.2f\n\n", stu.cgpa);
            			}
    				}
    			if(!found){
        			printf("Student Not Found!\n\n");
    			}

    			fclose(fptr);
				}
			}
		
			//Option 4 From Menu
		
			else if(opt == 4){
			FILE *temp;
			int change_id, found = 0;
			
			fptr = fopen("student.txt", "r");
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
			printf("Enter ID To Change Student's Record: ");
			scanf("%d", &change_id);
			while(fscanf(fptr, "Student ID: %d\n", &stu.id) == 1){
				fgets(stu.name, sizeof(stu.name), fptr);
				fscanf(fptr, "CGPA: %f\n", &stu.cgpa);
				
				if(stu.id == change_id){
					found = 1;
					while(getchar() != '\n');
					printf("Enter Student's Name: ");
					fgets(stu.name, sizeof(stu.name), stdin);
					printf("Enter CGPA: ");
					if(scanf("%f", &stu.cgpa) != 1){
						puts("Invalid Value! Only Integers Are Allowed. Try Again.\n");
						while (getchar() != '\n');
						continue;
					}
					else if(stu.cgpa < 1 || stu.cgpa > 4){
						puts("Invalid Value! CGPA Should Be Between 1-4. Try Again.\n");
						while (getchar() != '\n');
						continue;
					}
					printf("\n");	
					fprintf(temp, "Student ID: %d\n", stu.id);
					fprintf(temp, "%s", stu.name);
					fprintf(temp, "CGPA: %.2f\n\n", stu.cgpa);
				}
				else{
					fprintf(temp, "Student ID: %d\n", stu.id);
					fprintf(temp, "%s", stu.name);
					fprintf(temp, "CGPA: %.2f\n\n", stu.cgpa);
				}
			}
			fclose(fptr);
			fclose(temp);
			
			if(found){
				remove("student.txt");
				rename("temp.txt", "student.txt");
				printf("Student Record Changed Successfully!\n\n");
			}
			else{
				remove("temp.txt");
				printf("Student Record not found!\n\n");
			}
		}
		
		//Option 5 From Menu
		
		else if(opt == 5){
			FILE *temp;
			int delete_id, found = 0;
			
			fptr = fopen("student.txt", "r");
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
			printf("Enter ID To Delete Student's Record: ");
			scanf("%d", &delete_id);
			while(fscanf(fptr, "Student ID: %d\n", &stu.id) == 1){
				fgets(stu.name, sizeof(stu.name), fptr);
				fscanf(fptr, "CGPA: %f\n", &stu.cgpa);
				
				if(stu.id == delete_id){
					found = 1;
				}
				else{
					fprintf(temp, "Student ID: %d\n", stu.id);
					fprintf(temp, "%s", stu.name);
					fprintf(temp, "CGPA: %.2f\n\n", stu.cgpa);
				}
			}
			fclose(fptr);
			fclose(temp);
			
			if(found){
				remove("student.txt");
				rename("temp.txt", "student.txt");
				printf("Student Record Deleted Successfully!\n\n");
			}
			else{
				remove("temp.txt");
				printf("Student Record not found!\n\n");
			}
		}
		
		else{
			printf("Thankyou!");
			break;		
		}
	}
	
	return 0;
}
