
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

#include "general.h"

void end()
{
    system("cls");
    printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n\n\n");
    printf("\t\t\t\t\t\t  THANK YOU\n");
    getch();
}

void view_borrow()
{
    system("cls");
    printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    char book_name[20];
    char author_name[20];
    int id,dd,mm,yy,mid;
    int book_id;
    printf("Enter your ID: ");
    scanf("%d",&mid);
    FILE *fp;
    fp=fopen("borrowed.txt","r");
    gotoxy(1,5);
    printf("Book ID:");
    gotoxy(15,5);
    printf("Book Name:");
    gotoxy(55,5);
    printf("Author Name:");
    gotoxy(95,5);
    printf("Date:");
    gotoxy(120,5);
    int r=8;
    while(fscanf(fp,"%d %d %s %s %d %d %d\n", &id,&book_id, book_name, author_name,&dd,&mm,&yy)!=EOF)
    {
        if ( mid==id)
        {
                gotoxy(1,r);
                printf("%d",book_id);
                gotoxy(15,r);
                printf("%s",book_name);
                gotoxy(55,r);
                printf("%s",author_name);
                gotoxy(95,r);
                printf("%d-%d-%d",dd,mm,yy);
                gotoxy(120,r);
                r++;
        }
    }
    fclose(fp);
    getch();
    general_menu();
}

void new_book()
{
    system("cls");
    printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    char book_name[20];
    char author_name[20];
    int book_id;
    FILE *fp;
    fp=fopen("arrival.txt","r");
    gotoxy(1,5);
    printf("Book ID:");
    gotoxy(15,5);
    printf("Book Name:");
    gotoxy(55,5);
    printf("Author Name:");
    gotoxy(95,5);
    int r=8;
    while(fscanf(fp,"%d %s %s\n", &book_id, book_name, author_name)!=EOF)
    {
         gotoxy(1,r);
         printf("%d",book_id);
         gotoxy(15,r);
         printf("%s",book_name);
         gotoxy(55,r);
         printf("%s",author_name);
         gotoxy(95,r);
         r++;
    }
    fclose(fp);
    getch();
    general_menu();
}

void check()
{
    system("cls");
    printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    char book_name[20];
    char author_name[20];
    int no_of_copy;
    int ca,cna;
    int book_id;
    FILE *fp;
    fp=fopen("book.txt","r");
    gotoxy(1,5);
    printf("Book ID:");
    gotoxy(15,5);
    printf("Book Name:");
    gotoxy(55,5);
    printf("Author Name:");
    gotoxy(95,5);
    int r=8;
    while(fscanf(fp,"%d %s %s %d %d %d\n", &book_id, book_name, author_name, &no_of_copy, &ca,&cna)!=EOF)
    {
        if ( no_of_copy!=0)
        {
                gotoxy(1,r);
                printf("%d",book_id);
                gotoxy(15,r);
                printf("%s",book_name);
                gotoxy(55,r);
                printf("%s",author_name);
                gotoxy(95,r);
                r++;
        }
    }
    fclose(fp);
    getch();
    general_menu();
}

void gotoxy(short x,short y)
{
    COORD pos ={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void general_menu()
{
    int n;
    system("cls");
    printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    printf("1.Librarian\n2.Student\n3.Faculty\n");
    scanf("%d",&n);
    if (n==1)
    {
        librarian_menu();
    }
    else if(n==2)
    {
        student_menu();
    }
    else if(n==3)
    {
        faculty_menu();
    }
}

void open_screen()
{
    printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    printf("\t\t\t\t        LIBRARY SYSTEM WELCOMES YOU\n\n\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    printf("Press any key...");
    getch();
    system("cls");
    general_menu();
}


