/*
** Copyright (C) QPSOFT.COM All rights reserved.
*/

#include <stdio.h>
#include <math.h>
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

/*
** 存款最大值(穷举方式, 注意循环条件) 
*/
float depositRate(float capital, int years)
{
      if(years <= 0)
          return capital;
     
     //年方式的次数 
     int n1;
     int n2;
     int n3;
     int n5;
     int n8;
     
     int l1;
     int l2;
     int l3;
     int l5;
     int l8;
     
     //年利率 
     double r1 = 0.0063;
     double r2 = 0.0066;
     double r3 = 0.0069;
     double r5 = 0.0075;
     double r8 = 0.0084;
     
     float max = 0.0;
     float temp; 
     
     //应该用值保存各年的最大值。。 
     for(n8 = 0; n8 <= years/8; n8++)
     {
            for(n5 = 0; n5 <= (years - n8 * 8) / 5; n5++)
            {
                   for(n3 = 0; n3 <= (years - n8 * 8 - n5 * 5) / 3; n3++)
                   {
                          for(n2 = 0; n2 <= (years - n8 * 8 - n5 * 5 - n3 * 3)/2; n2++)
                          {
                                 n1 = years - n8 * 8 - n5 * 5 - n3 * 3 - n2 * 2;
                                 
                                 temp = capital * pow((double)(1 + 12 * r1), (double)n1) 
                                                * pow((double)(1 + 12 * r2 * 2), (double)n2) 
                                                * pow((double)(1 + 12 * r3 * 3), (double)n3)
                                                * pow((double)(1 + 12 * r5 * 5), (double)n5)
                                                * pow((double)(1 + 12 * r8 * 8), (double)n8);
                                        
                                        
                                 if(temp > max)
                                 {
                                     max = temp;
                                     l1 = n1;
                                     l2 = n2;
                                     l3 = n3;
                                     l5 = n5;
                                     l8 = n8;
                                 }
                          }
                   }
            }
     }
     
     /*
     printf("max value:%.2f\n", max);
     printf("number 8 years:%d\n", l8);
     printf("number 5 years:%d\n", l5);
     printf("number 3 years:%d\n", l3);
     printf("number 2 years:%d\n", l2);
     printf("number 1 years:%d\n", l1);
     */
     
     return max;
      
}

/*
** 结合存款利率进行供楼... 
*/
void repaymentHouse()
{
     float capital = 20000.0;  //本金
     
     float saves[4] = {0.2, 0.15, 0.1, 0.0}; //优惠
     
     int years[4] = {0, 5, 10, 20};
     
     float everyYearPay;
     
     float max = depositRate(capital * saves[0], 20 - years[0]);
     
     printf("%.2f\n", max);
     
     float remainValue;
     
     int i;
     int j;
     for(i = 1; i < 4; i++)
     {
         everyYearPay = capital * (float)(1 - saves[i]) / (float)years[i];
         
         printf("%.2f  ", everyYearPay);
         
         for(j = 0; j < years[i]; j++)
         {
               capital = depositRate(capital - everyYearPay, 1);
         }
         
         printf("%.2f\n", capital);
         
         capital = depositRate(capital, 20 - years[i]);         
         
         if(capital > max)
         {
               max = capital;
         }
     }
     
     printf("max remain value: %.2f\n", max);  
      
}

/*
** 分鱼 
*/
void allocaFish()
{
     int i;
     int j;
     int step;
     
     int flag = 1;
     
     for(step = 6; flag; step += 1)
     {
           for(i = step, j = 1; j <= 5 && flag; j++)   //全部分完 
           {
                 if((i - 1) % 5 == 0)
                 {
                     i = (i - 1) * 4 / 5;
                 }
                 else
                 {
                     flag = 0;
                 }
           }
           
           if(flag)
           {
               break;
           }
           else
           {
               flag = 1;
           }
     }
     
     printf("total fish:%d\n", step);
          
         
}

/*
** 卖鱼 
*/
void sellFish()
{

}

int main()
{
    sellFish();
    
    system("pause");
    
    return 0;
}



