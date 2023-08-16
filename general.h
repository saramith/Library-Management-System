#ifndef GENERAL_H_INCLUDED
#define GENERAL_H_INCLUDED


void end();
void view_borrow();
void new_book();
void check();
void gotoxy(short x,short y);
void general_menu();
void open_screen();

void return_book1();

void suggest();
void fmenu();
void faculty_delete();
void cre_acc_faculty();
void faculty_login();
void faculty_menu();

void view_suggest();
void smenu();
void student_delete();
void cre_acc_student();
void student_login();
void student_menu();

void lent();
void borrow();
void delete_book();
void delete_account();
void read_book();
void lmenu();
void cre_acc_librarian();
void librarian_login();
void librarian_menu();

int valid_date(int date, int mon, int year);
void finerecording();
void view_fine();
void clear_fine();

struct stru
{
    int fd;
    int fm;
    int fy;
};
struct stru duedate(int d,int m,int y);

#endif // GENERAL_H_INCLUDED
