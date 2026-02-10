#include<stdio.h>

typedef struct student_grade{
	int roll;
	char name[100];
	int marks[4];
	int total;
	float per;
	float average;
	char grade;
} student; 

int main(){
	FILE *fptr;
	student stu;
	int i;
	puts("\t\t\t\t------(Student Grading System)------\n");
	while(1){
		printf("Enter Your Name(Enter 'E' To Exit The Program): ");
		fgets(stu.name, sizeof(stu.name), stdin);
		if(stu.name[0] == 'E' || stu.name[0] == 'e'){
			break;
		}
		printf("Enter Your Roll No.:");
		if(scanf("%d", &stu.roll) != 1){
			printf("Invalid Input! Only Integers Are Allowed.\n");
			while (getchar() != '\n');
			continue;
		}
		while (getchar() != '\n');
		for(i = 0; i < 4; i++){
			printf("Enter Your Marks For Subject %d: ", i + 1);
			if(scanf("%d", &stu.marks[i]) != 1){
			printf("Invalid Input! Only Integers Are Allowed.\n");
			while (getchar() != '\n');
			i--;
			continue;
			}
			if(stu.marks[i] > 100 || stu.marks[i] < 0){
			printf("Marks Should Be Between 0-100. Try Again!\n");
			i--;
			}
		}
		while (getchar() != '\n');
		
		fptr = fopen("result.txt", "a");
		fprintf(fptr, "Name: %s", stu.name);
		fprintf(fptr, "Roll No.: %d\n", stu.roll);
		for(i = 0; i < 4; i++){
		fprintf(fptr, "Subject %d: %d\n", i + 1, stu.marks[i]);	
		}
		fclose(fptr);
		
		fptr = fopen("result.txt", "r");
		fgets(stu.name, sizeof(stu.name), fptr);
		fscanf(fptr, "%d", &stu.roll);
		for(i = 0; i < 4; i++){
			fscanf(fptr, "%d", &stu.marks[i]);
		}
		fclose(fptr);		
		
		printf("\n\n%s", stu.name);
		printf("Roll No.: %d\n", stu.roll);
		for(i = 0; i < 4; i++){
		printf("Marks Of Subject %d Are: %d", i+1, stu.marks[i]);
		printf("\n");
		}
		
		stu.total = stu.marks[0] + stu.marks[1] + stu.marks[2] + stu.marks[3];
		stu.per = (stu.total/400.00) * 100;
		printf("Total Marks: %d\n", stu.total);
		printf("Percantage: %.2f\n", stu.per);
		stu.average = stu.total/4.00;
		printf("Average: %.2f\n", stu.average);
		
		if(stu.per >= 95){
			stu.grade = 'A';
			printf("Grade: A\n\n");
		}
		else if(stu.per >= 80){
			stu.grade = 'B';
			printf("Grade: B\n\n");
		}
		else if(stu.per >= 70){
			stu.grade = 'C';
			printf("Grade: C\n\n");
		}
		else if(stu.per >= 60){
			stu.grade = 'D';
			printf("Grade: D\n\n");
		}
		else if(stu.per >= 50){
			stu.grade = 'E';
			printf("Grade: E\n\n");
		}
		else{
			stu.grade = 'F';
			printf("Grade: F\n\n");
		}
		
		fptr = fopen("result.txt", "a");
		fprintf(fptr, "Percentage: %.2f\n", stu.per);
		fprintf(fptr, "Average: %.2f\n", stu.average);
		fprintf(fptr, "Grade: %c", stu.grade);
		fprintf(fptr, "\n\n");
		fclose(fptr);
	}
	
	return 0;
}
