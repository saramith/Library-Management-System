#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include "student.h"

void student::view_suggest()
{
    system("cls");
    printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    char book_name[20];
    char author_name[20];
    int n;
    int sem,ID;
    int book_id;
    FILE *fp;
    fp=fopen("suggest.txt","r");
    printf("Enter the staff ID to view their suggestion:");
    scanf("%d",&n);
    gotoxy(1,5);
    printf("SEM:");
    gotoxy(10,5);
    printf("Book ID:");
    gotoxy(25,5);
    printf("Book Name:");
    gotoxy(70,5);
    printf("Author Name:");
    gotoxy(110,5);
    int r=8;
    while(fscanf(fp,"%d %d %d %s %s\n",&ID,&sem,&book_id, book_name, author_name)!=EOF)
    {
        if ( n==ID)
        {
                gotoxy(1,r);
                printf("%d",sem);
                gotoxy(10,r);
                printf("%d",book_id);
                gotoxy(25,r);
                printf("%s",book_name);
                gotoxy(70,r);
                printf("%s",author_name);
                gotoxy(110,r);
                r++;
        }
    }
    fclose(fp);
    getch();
    smenu();
}

void student::smenu()
{
    system("cls");
    printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    printf("\t\t\t\t\t            MENU\n\n");
    printf("1.NO. of Books borrowed\n2.Check availability of Books\n3.New Books\n4.Books suggested by teacher\n5.View fine due\n6.Exit\n");
    int n;
    scanf("%d",&n);
    if(n==1)
    {
        view_borrow();
    }
    else if (n==2)
    {
        check();
    }
    else if (n==3)
    {
        new_book();
    }
    else if (n==4)
    {
        view_suggest();
    }
    else if (n==5)
    {
        view_fine();
    }
    else if(n==6)
    {
        end();
    }
}

void student::student_delete()
{

  struct student
  {
    char First_name[30];
    char Last_name[30];
    char Roll_no[10];
    char Department[30];
    char Password[30];
  }s;
  printf("ACCOUNT DEACTIVATION OF STUDENT\n");
  FILE *fp1,*temp1;
  int flag=0;
  char rn[10];
  fp1=fopen("student.txt","r");
  temp1=fopen("cpy1.txt","w");
  printf("\nEnter Rollno to delete : ");
  scanf("%s",rn);
  while(fscanf(fp1,"%s %s %s %s %s \n",s.First_name, s.Last_name, s.Department, s.Roll_no,s.Password)!=EOF)
  {
    if(strcmp(rn,s.Roll_no)!=0)
    {
      fprintf(temp1,"%s %s %s %s %s\n",s.First_name, s.Last_name, s.Department, s.Roll_no,s.Password);
    }
    else
    {
      flag=1;
    }
  }
  fclose(fp1);
  fclose(temp1);
  if(flag==1)
  {
    remove("student.txt");
    rename("cpy1.txt","student.txt");
    printf("Account deactivated");
    getch();
  }
  else
  {
    printf("Invalid account");
    getch();
  }
  lmenu();
}

void student::cre_acc_student()
{
    struct student
    {
    char First_name[30];
    char Last_name[30];
    char roll[10];
    char Department[30];
    char Password[30];
    }t;
    system("cls");
    printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    printf("STUDENT SIGN IN\n");
    printf("Enter the details\n");
    FILE *fp;
    fp=fopen("student.txt","a");
    printf("\nFirst Name:\n");
    t.First_name[0]=toupper(t.First_name[0]);
    scanf("%s",t.First_name);
    printf("\nLast Name:\n");
    scanf("%s",t.Last_name);
    printf("\nDepartment:\n");
    scanf("%s",t.Department);
    t.Department[0]=toupper(t.Department[0]);
    printf("\nRoll number:\n");
    scanf("%s",t.roll);
    printf("\nPassword:\n");
    scanf("%s",t.Password);
    fprintf(fp,"%s %s %s %s %s \n", t.First_name, t.Last_name, t.Department, t.roll, t.Password);
    fclose(fp);
    student_menu();
}

void student::student_login()
{
    struct student
    {
    char First_name[30];
    char Last_name[30];
    char roll[10];
    char Department[30];
    char Password[30];
    }t;
    system("cls");
    printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    FILE *ek;
    ek=fopen("student.txt","r");
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
        while(fscanf(ek,"%s %s %s %s %s \n", t.First_name, t.Last_name, t.Department, t.roll, t.Password)!=EOF)
        {
            if (strcmp(Username,t.roll)==0 && strcmp(Passwor,t.Password)==0 && num==n)
        {
            printf("\nLogin Successfull...\npress any key to continue");
            getch();
            smenu();
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

void student::student_menu()
{
    system("cls");
    printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
     int n;
    printf("1.LOGIN\n2.Create account\n3.Exit\n");
    scanf("%d",&n);
    if(n==1)
    {
        student_login();
    }
    else if(n==2)
    {
        cre_acc_student();
    }
    else if (n==3)
    {
        end();
    }
}



