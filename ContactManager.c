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
    int mn;
    scanf("%d",&mn);
    switch(mn){
case 1:
    CreateCM();
    break;
case 2:
    EditCM();
        break;
case 3:
    SearchCM();
        break;
case 4:
    DeleteCM();
    break;
case 5:
    CloseCM();
default:
    printf("Invalid Option Selected! \n");
    menu();
    }
}
// Create Menu
void CreateCM(){
    FILE *fp;
    fp = fopen("contact.txt", "w+");
    fprintf(fp,"Name: John \n");
    fprintf(fp,"Surname: Doe \n");
    fprintf(fp,"Number: 0774141450 \n");
    fclose(fp);
}
// Edit Menu
void EditCM(){
    printf("Please make your choice: ");
    printf("1. Edit");
    int ch,count;
    FILE *fp;
    fp = fopen("contact.txt", "w");
       while ((ch = getc(fp)) != EOF)
    {
        putc(ch,stdout);
        count++;
    }
    fclose(fp);
}
// Search Menu
void SearchCM(){
 printf("Search By Number:[Sn] \n");
 printf("Search By Name: [Ns]\n");
}
//Delete Menu
void DeleteCM()
{
    printf("Please make your choice: \n");
    printf("1. Search Value to delete: \n");
}
//Close Menu
void CloseCM(){
    printf("Close Menu:\n");
    printf("Choose from the list below\n");
    printf("1. Return to Menu\n");
    printf("2. Close Program \n");
    int op;
    scanf("%d",&op);
    switch(op)
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
