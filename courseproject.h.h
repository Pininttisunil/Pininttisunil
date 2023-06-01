#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#define MAX_EMPLOYEES 100
void main_heading();
void addEmployee();
void replaceEmployee();
void viewEmployees();
void searchEmployee();
void deleteEmployee();
void clearEmployees();
void employeeid();
void employeename();
void employeeage();
void employeesalary();
void employeeHRA();
struct Employee {
    char name[50];
    int age,id;
    float salary,HRA;
};

struct Employee *employees[MAX_EMPLOYEES];
int numEmployees = 0;
void main_heading()
{
    printf("\n\t\t\t\t--------------------------------------------------\t\t\t\t");
    printf("\n\t\t\t\t|              EMPOLYEE DEATILS SYSTEM....            |\t\t");
    printf("\n\t\t\t\t--------------------------------------------------\t\t\t\t");
   
}
menu_bar() {
	main_heading();
    int choice;
    {
        printf("\nMENU:\n");
        printf("-------------------------\n");
        printf("1. Add Employee\n");
        printf("2. Replace Employee\n");
        printf("3. View Employees\n");
        printf("4. Search Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Delete All Employees\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                replaceEmployee();
                break;
            case 3:
                viewEmployees();
                break;
            case 4:
                searchEmployee();
                break;
            case 5:
                deleteEmployee();
                break;
            case 6:
                clearEmployees();
                break;
            case 7:
                exit(0);
            default:
                printf("\t\t\tInvalid choice. Please try again.\n");
        }
    }
}


struct Employee* createEmployee() {
    struct Employee* newEmployee = malloc(sizeof(struct Employee));
     printf("\n\n\t\t\t\t\t\tENTER NEW USER DATA :");
     printf("\n\n\t\t\t\t\tEnter USER_ID : ");
        scanf("%d",&(newEmployee->id));
        printf("\n\n\t\t\t\t\tEnter USER_NAME : ");
        scanf("%s",&(newEmployee->name));
        printf("\n\n\t\t\t\t\tEnter USER_age : ");
        scanf("%d",&(newEmployee->age));
    printf("\n\n\t\t\t\t\tEnter USER_salary : ");
        scanf("%f",&(newEmployee->salary));
        printf("\n\n\t\t\t\t\tEnter USER_HRA : ");
        scanf("%f",&(newEmployee->HRA));
    return newEmployee;
}

void addEmployee() {
    if (numEmployees == MAX_EMPLOYEES) {
        printf("Maximum employee limit reached.\n");
        return;
    }

    struct Employee *newEmployee = createEmployee();
    employees[numEmployees] = newEmployee;
    numEmployees++;

    printf("\t\t\tEmployee added successfully.\n");
    menu_bar();
}

void replaceEmployee() {
    int index;
    printf("\t\t\t\tEnter the index of the employee to replace (0-%d): ", numEmployees - 1);
    scanf("%d", &index);

    if (index >= 0 && index < numEmployees) {
        struct Employee *newEmployee = createEmployee();
        free(employees[index]);
        employees[index] = newEmployee;

        printf("\t\t\tEmployee replaced successfully.\n");
    } else {
        printf("\t\t\tInvalid index.\n");
    }
    menu_bar();
}

void viewEmployees() {
    if (numEmployees == 0) {
        printf("No employees found.\n");
        return;
    }

    printf("\t\t\tEmployee Details:\n");
    printf("\t\t\t-----------------\n");
    int i;
     printf("\n\n\t\t\t\t\tUSER DETAILS ARE AS FOLLOWS :");
    printf("\n\n\t\t\t   User_ID\t\tName of User\t\tAge\t\tsalary\t\tHRA");
    for( i = 0; i < numEmployees; i++) {
        struct Employee *employee = employees[i];
    printf("\n\n\t\t\t\t%d\t\t%s\t\t\t%d\t\t%.2f\t\t%.2f",employee->id,employee->name,employee->age,employee->salary,employee->HRA);

    }
    menu_bar();
}

void searchEmployee() {
    int choice;
    printf("\n\t\t\tEmployee searching System\n\n");
        printf("\t\t\t-------------------------\n");
        printf("\n\t\t\t1.EMPLOYEE ID WISE\n");
        printf("\n\t\t\t2. EMPLOYEE NAME WISE\n");
        printf("\n\t\t\t3. EMPLOYEE AGE WISE\n");
        printf("\n\t\t\t4. EMPLOYEE SALARY WISE\n");
        printf("\n\t\t\t5. EMPLOYEE HRA WISE\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
         switch(choice)
         {
         	case 1:
         		employeeid();
         		break;
         	case 2:
         		employeename();
         		break;
         	case 3:
         		employeeage();
         		break;
         	case 4:
         		employeesalary();
         		break;
         	case 5:
         		employeeHRA();
         		break;
         	default:
         		printf("\n\t\t\tENTER THE INVALID OPTION");
		 }
		 menu_bar();

}
void employeeid()
{
	int id;
    printf("\t\t\tEnter the id of the employee to search for:\n ");
    scanf("%d", &id);
  int i,j=0;
   printf("\t\t\tEmployee found:\n");
   printf("\n\n\t\t\t\t\tUSER DETAILS ARE AS FOLLOWS :");
    printf("\n\n\t\t\t   User_ID\t\tName of User\t\tAge\t\tsalary\t\tHRA");
    for( i = 0; i < numEmployees; i++) {
        struct Employee *employee = employees[i];
        if (employee->id==id) {
        	 
             printf("\n\n\t\t\t\t%d\t\t%s\t\t\t%d\t\t%.2f\t\t%.2f",employee->id,employee->name,employee->age,employee->salary,employee->HRA);
             j=1;
			 }

    }
    if(j==0)
     printf("\n\t\t\tEmployee not found.\n");
    menu_bar();
}
void employeename(){
	char name[50];
    printf("\t\t\tEnter the name to search for: ");
    scanf("%s", name);
  int i,j=0;
   printf("\t\t\tEmployee found:\n");
   printf("\n\n\t\t\t\t\tUSER DETAILS ARE AS FOLLOWS :");
    printf("\n\n\t\t\t   User_ID\t\tName of User\t\tAge\t\tsalary\t\tHRA");
    for( i = 0; i < numEmployees; i++) {
        struct Employee *employee = employees[i];
        if (strcmp(employee->name, name) == 0) {
          
         printf("\n\n\t\t\t\t%d\t\t%s\t\t\t%d\t\t%.2f\t\t%.2f",employee->id,employee->name,employee->age,employee->salary,employee->HRA);
         j=1;
    }
}
 if(j==0)
    printf("\n\t\t\tEmployee not found.\n");
    menu_bar();
}
void employeeage()
{
	int age;
    printf("\t\t\t\tEnter the age to search for: ");
    scanf("%d", &age);
  int i,j=0;
   printf("\t\t\tEmployee found:\n");
   printf("\n\n\t\t\t\t\tUSER DETAILS ARE AS FOLLOWS :");
    printf("\n\n\t\t\t   User_ID\t\tName of User\t\tAge\t\tsalary\t\tHRA");
    for( i = 0; i < numEmployees; i++) {
        struct Employee *employee = employees[i];
        if (employee->age==age) {
            printf("\n\n\t\t\t\t%d\t\t%s\t\t\t%d\t\t%.2f\t\t%.2f",employee->id,employee->name,employee->age,employee->salary,employee->HRA);
            j=1;
        }
    }
   if(j==0)
    printf("\n\t\t\t\tEmployee not found.\n");
    menu_bar();
}
void employeesalary()
{
	float salary;
    printf("\t\t\t\tEnter the salary to search for:\n ");
    scanf("%f", &salary);
  int i,j=0;
   printf("\t\t\tEmployee found:\n");
   printf("\n\n\t\t\t\t\tUSER DETAILS ARE AS FOLLOWS :");
    printf("\n\n\t\t\t   User_ID\t\tName of User\t\tAge\t\tsalary\t\tHRA");
    for( i = 0; i < numEmployees; i++) {
        struct Employee *employee = employees[i];
        if (employee->salary==salary) {
            printf("\n\n\t\t\t\t%d\t\t%s\t\t\t%d\t\t%.2f\t\t%.2f",employee->id,employee->name,employee->age,employee->salary,employee->HRA);
            j=1;
        }
    }
     if(j==0)
    printf("\n\t\t\t\tEmployee not found.\n");
    menu_bar();
}
void employeeHRA()
{
	float HRA;
    printf("\t\t\tEnter the HRA of the employee to search for:\n ");
    scanf("%f", &HRA);
  int i,j=0;
   printf("\t\t\tEmployee found:\n");
   printf("\n\n\t\t\t\t\tUSER DETAILS ARE AS FOLLOWS :");
    printf("\n\n\t\t\t   User_ID\t\tName of User\t\tAge\t\tsalary\t\tHRA");
    for( i = 0; i < numEmployees; i++) {
        struct Employee *employee = employees[i];
        if(employee->HRA==HRA) {
            printf("\n\n\t\t\t\t%d\t\t%s\t\t\t%d\t\t%.2f\t\t%.2f",employee->id,employee->name,employee->age,employee->salary,employee->HRA);
            j=1;
        }
    }
    
    if(j==0)
    printf("\t\t\tEmployee not found.\n");
    menu_bar();
}
void deleteEmployee() {
    int index;
    printf("\t\t\t\tEnter the index of the employee to delete (0-%d): ", numEmployees-1 );
    scanf("%d", &index);

    if (index >= 0 && index < numEmployees) {
        free(employees[index]);
        int i;
        for(i = index; i < numEmployees - 1; i++) {
            employees[i] = employees[i + 1];
        }
        numEmployees--;

        printf("\t\t\t\tEmployee deleted successfully.\n");
    } else {
        printf("\t\t\t\tInvalid index.\n");
    }
    menu_bar();
}

void clearEmployees() {
	int i;
    for( i = 0; i < numEmployees; i++) {
        free(employees[i]);
    }
    numEmployees = 0;

    printf("\t\tAll EMPLOYEES DELETED......IF YOU WANT TO ENTER THE NEW DETAILS OF EMPLOYEES.....USE MENU OPTION GIVEN BELOW....\n");
    menu_bar();
}
