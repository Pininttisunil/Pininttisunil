#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"course.h"

int main()
{
	

    printf("\n\t\t\t\t--------------------------------------------------\t\t\t\t");
    printf("\n\t\t\t\t|       WELCOME TO SOFTWARE COMPANY....       |\t\t");
    printf("\n\t\t\t\t--------------------------------------------------\t\t\t\t\n");

{
	printf("\n---------------------");
    printf("\n|LOGIN AS A ADMIN....|");
    printf("\n--------------------\n");
}

 {
    char username[100];
    char password;
    char pass[30];
    int i=0;
    printf("Please enter your password: ");
   while((password=_getch())!=13){
   	pass[i]=password;
   	i++;
   	printf("*");
   }
   pass[i]='\0';
   
    printf("\nPlease enter your username: ");
    scanf("%s", username);
    
    if (strcmp(username, "software") == 0 && strcmp(password, "123") == 0) {
        printf("Login successful!");
        menu_bar();
    } else {
        printf("Login failed. Please try again.");
    }
}
}
