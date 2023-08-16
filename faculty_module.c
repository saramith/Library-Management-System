#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

#include "general.h"


void suggest()
{
    system("cls");
    printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    char book_name[20];
    char author_name[20];
    int no_of_copy;
    int ca,cna;
    int book_id;
    FILE *fp,*ek;
    int cc,ID;
    printf("Enter Your ID");
    scanf("%d",&ID);
    printf("Enter the book ID to add");
    scanf("%d",&cc);
    fp=fopen("book.txt","r");
    while(fscanf(fp,"%d %s %s %d %d %d\n", &book_id, book_name, author_name, &no_of_copy, &ca,&cna)!=EOF)
    {
        if ( cc==book_id)
        {
                int sem;
                printf("Enter semester number");
                scanf("%d",&sem);
                ek=fopen("suggest.txt","w");
                fprintf(ek,"%d %d %d %s %s\n",ID,sem,book_id, book_name, author_name);
                fclose(ek);
        }
    }
    fclose(fp);
    fmenu();
}

void fmenu()
{
    system("cls");
    printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    printf("\t\t\t\t\t            MENU\n\n");
    printf("1.NO. of Books borrowed\n2.Check availability of Books\n3.New Book\n4.Suggest books for students\n5.View fine due\n6.Exit");
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
        suggest();
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

void faculty_delete()
{

  struct student
  {
    char First_name[30];
    char Last_name[30];
    char Staff_ID[10];
    char Department[30];
    char Password[30];
  }s;
  printf("ACCOUNT DEACTIVATION OF FACULTY\n");
  FILE *fp1,*temp1;
  int flag=0;
  char rn[10];
  fp1=fopen("staff.txt","r");
  temp1=fopen("cpy1.txt","w");
  printf("\nEnter ID Number to delete : ");
  scanf("%s",rn);
  while(fscanf(fp1,"%s %s %s %s %s \n",s.First_name, s.Last_name, s.Department, s.Staff_ID,s.Password)!=EOF)
  {
    if(strcmp(rn,s.Staff_ID)!=0)
    {
      fprintf(temp1,"%s %s %s %s %s\n",s.First_name, s.Last_name, s.Department, s.Staff_ID,s.Password);
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
    remove("staff.txt");
    rename("cpy1.txt","staff.txt");
    printf("Account deactivated");
  }
  else
  {
    printf("Invalid account");
  }
  lmenu();
}

void cre_acc_faculty()
{
    struct staff
    {
    char First_name[30];
    char Last_name[30];
    char Staff_ID[10];
    char Department[30];
    char Password[30];
    }t;
    system("cls");
    printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    printf("FACULTY SIGN IN\n");
    printf("Enter the details\n");
    FILE *fp;
    fp=fopen("staff.txt","a");
    printf("\nFirst Name:\n");
    t.First_name[0]=toupper(t.First_name[0]);
    scanf("%s",t.First_name);
    printf("\nLast Name:\n");
    scanf("%s",t.Last_name);
    printf("\nDepartment:\n");
    scanf("%s",t.Department);
    t.Department[0]=toupper(t.Department[0]);
    printf("\nStaff_ID:\n");
    scanf("%s",t.Staff_ID);
    printf("\nPassword:\n");
    scanf("%s",t.Password);
    fprintf(fp,"%s %s %s %s %s \n", t.First_name, t.Last_name, t.Department, t.Staff_ID, t.Password);
    fclose(fp);
    faculty_menu();
}

void faculty_login()
{
    system("cls");
    printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    FILE *ek;
    ek=fopen("staff.txt","r");
    int e=0	;
    char Username[15];
    char Passwor[15];
    char First_name[30];
    char Last_name[30];
    char Staff_ID[10];
    char Department[30];
    char Password[30];
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
        while(fscanf(ek,"%s %s %s %s %s \n", First_name, Last_name, Department, Staff_ID, Password)!=EOF)
        {
            if (strcmp(Username,Staff_ID)==0 && strcmp(Password,Passwor)==0 && num==n)
        {
            printf("\nLogin Successfull...\npress any key to continue");
            fmenu();
            getch();
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

void faculty_menu()
{
    system("cls");
    printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    int n;
    printf("1.LOGIN\n2.Create account\n3.Exit\n");
    scanf("%d",&n);
    if(n==1)
    {
        faculty_login();
    }
    else if(n==2)
    {
        cre_acc_faculty();
    }
    else if (n==3)
    {
        end();
    }
}



