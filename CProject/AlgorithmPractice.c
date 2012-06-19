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
    
    int l; //����һ��ֵ
    int r; //��һ��ֵ
    
    for(i = 0 ; i < MAX_LEN; i++)
    {
          l = 0;  //ÿ��ѭ����ʼ��ǰֵ
          for(j = 0; j <= i; j++)
          {
                r = a[j];
                a[j] = l + r;  //ǰ����ֵ��� 
                l = r;
                
                printf("%6d", a[j]);
          }
          
          printf("\n");
    } 
    
    return;
          
}



//�����ڽ��в��� 
void handleDate()
{
     struct date today;
     struct date term;  //�����м������ 
     
     int tempyear;
     
     printf("input date:");
     
     scanf("%d%d%d", &today.year, &today.month, &today.day);
     
     term.month = 12;
     term.day = 31;
     
     int totalDay = 0;
     
     //�����м������ 
     for(tempyear = 1900; tempyear < today.year; tempyear++)
     {
         term.year = tempyear;
         
         totalDay += getDays(term);
         
     }
     
     //��������� 
     totalDay += getDays(today);
     
     printf("total day:%d\n", totalDay);
     
     int during = totalDay % 5;
     
     if(during > 0 && during < 4)
     {
         printf("������...\n");
     }
     else
     {
         printf("ɹ����...\n");
     }
     
}

//���ĳ������� 
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



