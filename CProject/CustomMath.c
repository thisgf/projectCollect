/*
** Copyright (C) QPSOFT.COM All rights reserved.
** �Զ�����ѧ��ط���
*/

#include <stdio.h>
#include <math.h>

int main()
{
    testPrimes();

    return 0;
}

void testPrimes()
{
    int num;

    int *num_p = &num;

    printf("input a num:");

    scanf("%d", num_p);

    int flag = judgeIsPrimes(num);

    if(flag == 1)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }

}

//�ж��Ƿ�����
int judgeIsPrimes(int num)
{
    int sqrtValue = sqrt(num);

    int i;

    int flag = 1;

    for(i = 2; i <= sqrtValue; i++)
    {
        if(num % i == 0)
        {
            flag = 0;

            break;
        }
    }

    return flag;

}

