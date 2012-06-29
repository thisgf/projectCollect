/*
** Copyright (C) QPSOFT.COM All rights reserved. 
*/

#include <stdio.h>

/*
** 10000-100000 6尾数被3整除 
*/
void sixExceptThree()
{
     int i = 0;
     
     int j;
     
     int value;
     
     for(j = 1000; j < 9999; j++)
     {
         value = j * 10 + 6;
               
         if(value % 3==0)
         {
             printf("%d ", value);
             i++;
         }
     }
     
     printf("\ncount = %d\n", i);

}

/*
** 获取位数相加=5 
*/
void getCountFive()
{
     int i;
     int j;
     int k;
     
     for(i = 1; i <= 5; i++)
     {
           for(j = 0; j <= 5 - i; j++)
           {
                 for(k = 0; k <= 5 - i - j; k++)
                 {
                       if(i + j + k == 5)
                       {
                            printf("%d ", i * 100 + j * 10 + k);
                       }
                 }
           }
     }
     
     printf("\n");
     
}

/*
** 4位的相反数 
*/
void fourOpposite()
{
     int i;
     
     for(i = 1002; i <= 1111; i++)
     {
           if(i % 10 * 1000 + i / 10 % 10 * 100 + i / 100 % 10 * 10 + i / 1000 == i * 9)
           {
                printf("result = %d\n", i);
           }           
     }
}

int main()
{
    fourOpposite();
    
    system("pause");
    
   return 0;  
} 
