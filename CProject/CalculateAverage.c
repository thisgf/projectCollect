/*
** Copyright (C) QPSOFT.COM All rights reserved.
*  计算平均值
*/

#include <stdio.h>
#include <math.h>

main()
{
    int integer;
    int i;
    int max = -32768;  //init num
    int min = 32767;
    int sum = 0;

    int x = 5;
    int *p = &x;

    printf("value x = %d, point x = %d\n",x, p);

    int integers[10];

    for(i = 0; i < 10; i++)
    {
        printf("Input Number %d = ", i);
        scanf("%d", &integer);

        sum += integer;

        if(integer > max)
        {
            max = integer;
        }
        if(integer < min)
        {
            min = integer;
        }

        integers[i] = integer;

    }

    printf("get max value: %d, min value:%d\n", max, min);

    int average = (sum - max - min)/8;

    printf("get average value: %d\n", average);

    int tempMin = 32767;

    int temp = 0;

    int maxGap = 0;
    int minGap = 0;

    for(i = 0; i < 10; i++)
    {
        integer = integers[i];

        temp = integer - average;

        temp = abs(temp);

        if(temp <tempMin)
        {
            tempMin = temp;

            minGap = integer;
        }

    }

    if(average - min < max - average)
    {
        maxGap = max;
    }
    else
    {
        maxGap = min;
    }

    printf("get max gap value: %d, min gap value:%d\n", maxGap, minGap);

}

