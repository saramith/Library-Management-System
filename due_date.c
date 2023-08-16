#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

#include "general.h"


struct stru duedate(int d,int m,int y)
{
    struct stru s;
    int leap=0;
    if((y%400==0)||((y%100!=0)&&(y%4==0)))
    {
        leap=1;
    }
    d=d+10;
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
    {
        if(d>31)
        {
            d=d-31;
            if(m==12)
            {
                m=1;
                y=y+1;
            }
            else
            {
                m=m+1;
            }
        }

    }
    else if(m==4||m==5||m==6||m==9||m==11)
    {
        if(d>30)
        {
            d=d-30;
            m=m+1;
        }
    }
    else if(m==2)
    {
        if(leap==0&&d>28)
        {
            d=d-28;
            m=m+1;
        }
        else if(leap==1 && d>29)
        {
            d=d-29;
            m=m+1;
        }
    }
    s.fd=d;
    s.fm=m;
    s.fy=y;
    return s;
}
