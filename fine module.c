#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

#include "general.h"

void finerecording()
{
system("cls");
printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
printf("\t\t\t\t\t  ************************\n\n\n");


int day2,mon2,year2,id,bookid;
printf("Enter the person's ID  : ");
scanf("%d",&id);
printf("Enter Book ID to return : ");
scanf("%d",&bookid);
printf("Enter date:\n");
printf("Enter day:");
scanf("%d",&day2);
printf("Enter month:");
scanf("%d",&mon2);
printf("Enter year:");
scanf("%d",&year2);

FILE *mp;
mp=fopen("borrowed.txt","r");
int i_d,book_id,day1,mon1,year1,flag=0,low=0,day_diff,mon_diff,year_diff;
float newfine,fine;
char book_name[20];
char author_name[20];
while(fscanf(mp,"%d %d %s %s %d %d %d\n",&i_d,&book_id,book_name,author_name,&day1,&mon1,&year1)!=EOF)
{
   if(i_d==id && book_id==bookid)
   {
      flag=1;
      break;
   }

}
fclose(mp);
if(flag==0)
{
   printf("invalid data");
   lmenu();
}

struct stru s;
s=duedate(day1,mon1,year1);
day1=s.fd;
mon1=s.fm;
year1=s.fy;

if(!valid_date(day1,mon1, year1))
   {
        printf("invalid date entered\n");
        getch();
        lmenu();
   }

if(!valid_date(day2, mon2, year2))
   {
        printf("invalid date entered\n");
        getch();
        lmenu();
   }

if(day2 < day1)
   {

        if (mon2 == 3)
        {

            if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0))
            {
                day2 += 29;
            }

            else
            {
                day2 += 28;
            }
        }


       else if (mon2 == 5 || mon2 == 7 || mon2 == 10 || mon2 == 12)
       {
           day2 += 30;
       }


       else
       {
           day2 += 31;
       }

       mon2 = mon2 - 1;
   }

   if (mon2 < mon1)
   {
        mon2 += 12;
        year2 -= 1;
   }

   day_diff = day2 - day1;
   mon_diff = mon2 - mon1;
   year_diff = year2 - year1;

   newfine=(day_diff*0.50)+(mon_diff*15.0)+(year_diff*365*0.50);
   FILE *fp,*temp;
   fp=fopen("fine.txt","r");
   temp=fopen("copy3.txt","w+");
   while(fscanf(fp,"%d %f\n",&i_d,&fine)!=EOF)
   {
      if(i_d!=id)
      {
          fprintf(temp,"%d %f\n",i_d,fine);
      }
      else if(i_d==id)
      {
          low=1;
          fprintf(temp,"%d %f\n",i_d,newfine+fine);
      }
   }
   if (low==0)
   {
       fprintf(temp,"%d %f\n",i_d,newfine);
   }
   printf("fine update successfull");
   getch();
   fclose(fp);
   fclose(temp);
   remove("fine.txt");
   rename("copy3.txt","fine.txt");

}

int valid_date(int day, int mon, int year)
{
    int is_valid = 1, is_leap = 0;

    if (year >= 1800 && year <= 9999)
    {

        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            is_leap = 1;
        }

        if(mon >= 1 && mon <= 12)
        {

            if (mon == 2)
            {
                if (is_leap && day == 29)
                {
                    is_valid = 1;
                }
                else if(day > 28)
                {
                    is_valid = 0;
                }
            }


            else if (mon == 4 || mon == 6 || mon == 9 || mon == 11)
            {
                if (day > 30)
                {
                    is_valid = 0;
                }
            }


            else if(day > 31)
            {
                is_valid = 0;
            }
        }

        else
        {
            is_valid = 0;
        }

    }
    else
    {
        is_valid = 0;
    }

    return is_valid;

}


void view_fine()
{
    system("cls");
    printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    int id,i_d,flag=0;
    float fine;
    printf("Enter the id:");
    scanf("%d",&id);
    FILE *fp;
    fp=fopen("fine.txt","r");
    while(fscanf(fp,"%d %f\n",&i_d,&fine)!=EOF)
    {
        if(id==i_d)
        {
            printf("\n\nFine due : %0.2f",fine);
            getch();
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("No due");
    }
    fclose(fp);
    smenu();
}

void clear_fine()
{
    system("cls");
    printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    int id,i_d,flag=0;
    float remaining,fine,paid;
    printf("Enter the id: ");
    scanf("%d",&id);
    printf("Enter the cash paid: ");
    scanf("%f",&paid);
    FILE *fp,*temp;
    fp=fopen("fine.txt","r");
    temp=fopen("copy3.txt","w+");
    while(fscanf(fp,"%d %f\n",&i_d,&fine)!=EOF)
    {
        if(id!=i_d)
        {
            fprintf(temp,"%d %f\n",i_d,fine);
        }
        else
        {
            remaining=fine-paid;
            fprintf(temp,"%d %f\n",i_d,remaining);
            flag=1;

        }
    }
    if (flag==1)
    {
    printf("PAYMENT SUCCESSFUL\n\n");
    printf("Fine due remaining: %0.2f",remaining);
    getch();
    }
    else
    {
        printf("NO FINE DUE\n\nPAYMENT UNSUCESSFUL");
        getch();
    }
    fclose(fp);
    fclose(temp);
    remove("fine.txt");
    rename("copy3.txt","fine.txt");
    lmenu();
}



