/*
** Copyright (C) QPSOFT.COM All rights reserved.
*/

#include <stdio.h>
#include <dateutil.h>

#define MAX_LEN 12


/**
 * iterator book
 */
int iteratorBooks()
{
    int max_book = 5;
    int a, b, c;

    int count = 0;

    for(a = 1; a <= max_book; a++)
    {
        for(b = 1; b <= max_book; b++)
        {
            if(a != b)
            {
                for(c = 1; c <= max_book; c++)
                {
                    if(c != a && c != b)
                    {
                        printf("count:%d, scheme:%d, %d, %d\n", ++count, a, b, c);
                    }
                }
            }
        }
    }
    
    return 0;

}


int yangHuiTriangle()
{
     int i;
     int j;
     int len = 12;
     
     printf("len = ");
     
     //while(len > MAX_LEN)
         //scanf("%d", &len);
     
     printf("\n");
     
     for(i = 0; i <= len; i++)
     {
           for(j = 0; j < MAX_LEN - i; j++)
           {
                 printf(" ");
           }
           
           for(j = 1; j < i + 2; j++)
           {
                 printf("%6d", recursive(i, j));
           }
           
           printf("\n");
           
     }
        
     return 0;
}

int recursive(int x, int y)
{
    int result;
    
    if(y == 1 || y == x + 1)
        return 1;
    
    result = recursive(x - 1, y - 1) + recursive(x - 1, y);
    
    return result;
}

void yanghuiTriangle2()
{
    int a[MAX_LEN] = {1};
    
    int i;
    int j;
    
    int l; //左上一个值
    int r; //上一个值
    
    for(i = 0 ; i < MAX_LEN; i++)
    {
          l = 0;  //每次循环初始化前值
          for(j = 0; j <= i; j++)
          {
                r = a[j];
                a[j] = l + r;  //前两个值相加 
                l = r;
                
                printf("%6d", a[j]);
          }
          
          printf("\n");
    } 
    
    return;
          
}



//对日期进行操作 
void handleDate()
{
     struct date today;
     struct date term;  //计算中间的日期 
     
     int tempyear;
     
     printf("input date:");
     
     scanf("%d%d%d", &today.year, &today.month, &today.day);
     
     term.month = 12;
     term.day = 31;
     
     int totalDay = 0;
     
     //计算中间的天数 
     for(tempyear = 1900; tempyear < today.year; tempyear++)
     {
         term.year = tempyear;
         
         totalDay += getDays(term);
         
     }
     
     //今年的天数 
     totalDay += getDays(today);
     
     printf("total day:%d\n", totalDay);
     
     int during = totalDay % 5;
     
     if(during > 0 && during < 4)
     {
         printf("打鱼中...\n");
     }
     else
     {
         printf("晒网中...\n");
     }
     
}

//输出某年的日历 
void outputCalendar()
{
     struct date d;
     
     printf("input year:");
     scanf("%d", &d.year);
     
     int ly = checkIsLeapYear(d.year);
     
     d.month = 12;
     d.day = 31;
     
     int i;
     int j;
     
     int day;
     
     printf("year:%d\n", d.year);
     for(i = 1; i <= d.month; i++)
     {
           printf("month:%3d\n", i);
           
           day = day_list[ly][i - 1];
                
           for(j = 1; j <= day; j++)
           {
                 printf("day:%3d   ", j);
           }
           
           printf("\n");
           
     }
     
}

int main()
{
    outputCalendar();
    
    system("pause");
    
    return 0;
}



