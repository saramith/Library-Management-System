#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

#include "general.h"


void lent()
{
    system("cls");
    printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    char book_name[20];
    char author_name[20];
    int id,dd,mm,yy,count=0;
    int book_id;
    FILE *fp;
    fp=fopen("borrowed.txt","r");
    gotoxy(1,5);
    printf("ID:");
    gotoxy(15,5);
    printf("Book ID:");
    gotoxy(30,5);
    printf("Book Name:");
    gotoxy(70,5);
    printf("Author Name:");
    gotoxy(100,5);
    printf("Date:");
    gotoxy(120,5);
    int r=8;
    while(fscanf(fp,"%d %d %s %s %d %d %d\n", &id,&book_id, book_name, author_name,&dd,&mm,&yy)!=EOF)
    {
        gotoxy(1,r);
        printf("%d",id);
        gotoxy(15,r);
        printf("%d",book_id);
        gotoxy(30,r);
        printf("%s",book_name);
        gotoxy(70,r);
        printf("%s",author_name);
        gotoxy(100,r);
        printf("%d-%d-%d",dd,mm,yy);
        gotoxy(120,r);
        r++;
        count++;
    }
    fclose(fp);
    printf("\n\n\nTotal number of books lent : %d",count);
    getch();
    lmenu();
}

void borrow()
{
    system("cls");
    printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    struct book
    {
        int book_id;
        char book_name[100];
        char author_name[50];
        int no_of_copy;
        int ca;
        int cna;
    }b;
  int bookid,id;
  FILE *fp, *temp;
    fp=fopen("book.txt","r");
    temp=fopen("copy.txt","w+");
    printf("Enter the person's ID  : ");
    scanf("%d",&id);
    printf("Enter Book ID to borrow : ");
    scanf("%d",&bookid);
    int mm,dd,yy;
    printf("Enter date:\n");
    printf("Enter day:");
    scanf("%d",&dd);
    printf("Enter month:");
    scanf("%d",&mm);
    printf("Enter year:");
    scanf("%d",&yy);
    if(!valid_date(dd, mm, yy))
    {
        printf("invalid date entered\n");
        getch();
        lmenu();
    }
    while(fscanf(fp,"%d %s %s %d %d %d\n", &b.book_id, b.book_name, b.author_name, &b.no_of_copy, &b.ca,&b.cna)!=EOF)
    {
      if(bookid!=b.book_id)
      {
        fprintf(temp,"%d %s %s %d %d %d\n", b.book_id, b.book_name, b.author_name, b.no_of_copy, b.ca,b.cna);
      }
      else
      {
        if(b.no_of_copy>0)
        {
            FILE *mp;
            mp=fopen("borrowed.txt","a");
            b.no_of_copy--;
            b.ca++;
            fprintf(temp,"%d %s %s %d %d %d\n", b.book_id, b.book_name, b.author_name, b.no_of_copy, b.ca,b.cna);
            fprintf(mp,"%d %d %s %s %d %d %d\n", id,b.book_id, b.book_name, b.author_name,dd,mm,yy);
            fclose(mp);
            printf("SUCCESSFUl\n");
        }
         else
        {
            printf("Book not available");
            continue;
        }
      }
    }
    fclose(fp);
    fclose(temp);
    remove("book.txt");
    rename("copy.txt","book.txt");
    getch();
    lmenu();
}


void delete_book()
{
    struct book
    {
        int book_id;
        char book_name[100];
        char author_name[50];
        int no_of_copy;
        int ca;
        int cna;
    }b;
  int bookid,n,i,flag=0;
  printf("Enter number of books to be deleted : ");
  scanf("%d",&n);
  FILE *fp, *temp;
  for(i=0;i<n;i++)
  {
    fp=fopen("book.txt","r");
    temp=fopen("copy.txt","w+");
    printf("Enter Book ID for the book to be deleted : ");
    scanf("%d",&bookid);
    while(fscanf(fp,"%d %s %s %d %d %d\n", &b.book_id, b.book_name, b.author_name, &b.no_of_copy, &b.ca,&b.cna)!=EOF)
    {
      if(bookid!=b.book_id)
      {
        fprintf(temp,"%d %s %s %d %d %d\n", b.book_id, b.book_name, b.author_name, b.no_of_copy, b.ca,b.cna);
      }
      else
      {
        flag=1;
      }
    }
    fclose(fp);
    fclose(temp);
    if(flag==1)
    {
      remove("book.txt");
      rename("copy.txt","book.txt");
      printf("Book deleted");
    }
    else
    {
      printf("Book not found");
    }
    lmenu();
}
}

void delete_account()
{
    system("cls");
    printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    int n;
    printf("1.Student\n2.Faculty\n3.Back\n");
    scanf("%d",&n);
    if(n==1)
    {
        student_delete();
    }
    else if(n==2)
    {
        faculty_delete();
    }
    else if (n==3)
    {
        lmenu();
    }

}

void read_book()
{
  system("cls");
  printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
  printf("\t\t\t\t\t  ************************\n\n\n");
  char book_name[20];
  char author_name[20];
  int no_of_copy;
  int ca=0,cna=0;
  int book_id;
  int i,n;
  printf("Enter number of books to be added\n");
  scanf("%d",&n);
  FILE *ek,*fp;
  for(i=0;i<n;i++)
      {
           if(i==0)
            {
                ek=fopen("book.txt","a");
                fp=fopen("arrival.txt","w");
                printf("Enter the book ID\n");
                scanf("%d",&book_id);
                printf("Enter Book name (no spaces use underscore)\n");
                scanf("%s",book_name);
                printf("Enter Author name (no spaces use underscore)\n");
                scanf("%s",author_name);
                printf("Enter No. of Copies\n");
                scanf("%d",&no_of_copy);
                fprintf(ek,"%d %s %s %d %d %d\n", book_id, book_name, author_name, no_of_copy, ca,cna);
                fprintf(fp,"%d %s %s\n",book_id, book_name, author_name);
                fclose(ek);
                fclose(fp);
            }
            else
            {
                ek=fopen("book.txt","a");
                fp=fopen("arrival.txt","a");
                printf("Enter the book ID\n");
                scanf("%d",&book_id);
                printf("Enter Book name (no spaces use underscore)\n");
                scanf("%s",book_name);
                printf("Enter Author name (no spaces use underscore)\n");
                scanf("%s",author_name);
                printf("Enter No. of Copies\n");
                scanf("%d",&no_of_copy);
                fprintf(ek,"%d %s %s %d %d %d\n", book_id, book_name, author_name, no_of_copy, ca,cna);
                fprintf(fp,"%s  %s\n", book_name, author_name);
                fclose(ek);
                fclose(fp);
            }
      }
      lmenu();
}

void lmenu()
{
    system("cls");
    printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    printf("\t\t\t\t\t            MENU\n\n");
    printf("1.Adding new book\n2.No. of Books lent\n3.Borrow Book\n4.Return Book\n5.Delete account\n6.Delete Book\n7.Clear fine\n8.Exit\n");
    int n;
    scanf("\n%d",&n);
    if(n==1)
    {
        read_book();
    }
    else if (n==2)
    {
        lent();
    }
    else if (n==3)
    {
        borrow();
    }
    else if (n==4)
    {
        return_book1();
    }
    else if (n==5)
    {
        delete_account();
    }
    else if(n==6)
    {
        delete_book();
    }
    else if (n==7)
    {
        clear_fine();
    }
    else if(n==8)
    {
        end();
    }
}

void cre_acc_librarian()
{
    struct librarian
    {
    char First_name[30];
    char Last_name[30];
    char Staff_ID[10];
    char Password[30];
    }t;
    system("cls");
    printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    printf("LIBRARIAN SIGN IN\n");
    printf("Enter the details\n");
    FILE *fp;
    fp=fopen("libra.txt","a");
    printf("\nFirst Name:\n");
    t.First_name[0]=toupper(t.First_name[0]);
    scanf("%s",t.First_name);
    printf("\nLast Name:\n");
    scanf("%s",t.Last_name);
    printf("\nStaff_ID:\n");
    scanf("%s",t.Staff_ID);
    printf("\nPassword:\n");
    scanf("%s",t.Password);
    fprintf(fp,"%s %s %s %s \n", t.First_name, t.Last_name, t.Staff_ID, t.Password);
    fclose(fp);
    general_menu();
}

void librarian_login()
{
    struct librarian
    {
    char First_name[30];
    char Last_name[30];
    char Staff_ID[10];
    char Password[30];
    }t;
    system("cls");
    printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    FILE *ek;
    ek=fopen("libra.txt","r");
    int e=0	;
    char Username[15];
    char Passwor[15];
    do
    {
        int num=rand();
        int n;
        printf("\nEnter your Username and Password");
        printf("\nUSERNAME:");
        scanf("%s",Username);
        printf("\nPASSWORD:");
        scanf("%s",Passwor);
        printf("\n\nCAPTCHA\n");
        printf("%d\n",num);
        printf("Enter the captcha:\n");
        scanf("%d",&n);
        while(fscanf(ek,"%s %s %s %s \n", t.First_name, t.Last_name, t.Staff_ID, t.Password)!=EOF)
        {
            if (strcmp(Username,t.Staff_ID)==0 && strcmp(Passwor,t.Password)==0 && num==n)
        {
            printf("\nLogin Successfull...\npress any key to continue");
            getch();
            lmenu();
            break;
        }
            else
            {
                printf("\nIncorrect login,Try Again ");
                e++;
                getch();
            }
        }

    }while(e<=2);
    if(e>2)
    {
    printf("\nYou have crossed the limit. You cannot login");
    end();
    getch();
    }
}

void librarian_menu()
{
    system("cls");
    printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
     int n;
    printf("1.LOGIN\n2.Create account\n3.Exit\n");
    scanf("%d",&n);
    if(n==1)
    {
        librarian_login();
    }
    else if(n==2)
    {
        cre_acc_librarian();
    }
    else if (n==3)
    {
        end();
    }
}



