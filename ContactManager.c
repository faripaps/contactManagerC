/* 
    Contact Manager
    Programmer: George Papaya
    Date: 31 July 2023
    Level: Beginner Project
*/

#include <stdio.h>
#include <stdlib.h>
// Main Menu
void menu()
{
    printf("Welcome to Contact Manager!!!");
    printf("\n \n");
    printf("1. Create \n");
    printf("2. Edit \n");
    printf("3. Search \n");
    printf("4. Delete \n");
    printf("5. Close \n");
    printf("\n \n");
}
// Create Menu
void CreateCM(){
    FILE *fp; 
    fp = fopen("contact.txt", "w");
    fprintf(fp,"Name: John \n");
    fprintf(fp, "Surname: Doe \n");
    fclose(fp);
}
// Edit Menu
void EditCM(){

}
// Search Menu
void SearchCM(){

}
//Delete Menu
void DeleteCM()
{

}
//Close Menu
void CloseCM(){
    printf("Close Menu:\n");
    printf("Choose from the list below\n");
    printf("1. Return to Menu\n");
    printf("2. Close Program \n");
    int op;
    scanf("%d",&op)
    switch(op);
    {
        case 1:
        menu();
        case 2:
        exit(1);
        default:
        printf("Incorrect Value Selected!\n");
        CloseCM();
    }

}
int main()
{
    menu();
    return 0;
}
