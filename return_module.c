#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

#include "general.h"

void return_book1()
{
    finerecording();

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
   FILE *fp, *temp1,*temp2,*ek;

   fp=fopen("book.txt","r");
   temp1=fopen("copy1.txt","w+");

  printf("Enter the person's ID  : ");
  scanf("%d",&id);
  printf("Enter Book ID to return : ");
  scanf("%d",&bookid);
  while(fscanf(fp,"%d %s %s %d %d %d\n", &b.book_id, b.book_name, b.author_name, &b.no_of_copy, &b.ca,&b.cna)!=EOF)
  {
      if(bookid!=b.book_id)
      {
        fprintf(temp1,"%d %s %s %d %d %d\n", b.book_id, b.book_name, b.author_name, b.no_of_copy, b.ca,b.cna);
      }
      else
      {

            b.no_of_copy++;
            b.ca--;
            fprintf(temp1,"%d %s %s %d %d %d\n", b.book_id, b.book_name, b.author_name, b.no_of_copy, b.ca,b.cna);
      }
    }
    fclose(fp);
    fclose(temp1);
    remove("book.txt");
    rename("copy1.txt","book.txt");





  int flag=0,dd,mm,yy;

  ek=fopen("borrowed.txt","r");
  temp2=fopen("cpy1.txt","w");
  while(fscanf(ek,"%d %d %s %s %d %d %d\n", &id,&b.book_id, b.book_name, b.author_name,&dd,&mm,&yy)!=EOF)
  {
    if(bookid!=b.book_id)
    {
       fprintf(temp2,"%d %d %s %s %d %d %d\n", id,b.book_id, b.book_name, b.author_name,dd,mm,yy);
    }
    else
    {
      flag=1;
    }
  }
  fclose(ek);
  fclose(temp2);
  if(flag==1)
  {
    remove("borrowed.txt");
    rename("cpy1.txt","borrowed.txt");
  }
  printf("\nBOOK RETURN SUCCESSFUL");
  getch();
  lmenu();
}




