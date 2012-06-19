/*
** date tools
*/

struct date{
       int year;
       int month;
       int day;
};

static int day_list[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                              {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

//��ȡ���� 
int getDays(struct date d)
{
    int ly = checkIsLeapYear(d.year);  //�Ƿ�����
    
    int i;
    
    for(i = 1; i < d.month; i++)
    {
        d.day += day_list[ly][i];
    }
    
    return d.day;
}

//�Ƿ�����(1900֮��)
int checkIsLeapYear(int year)
{
    if(year < 1900)
        return 0;
        
    int ly = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    
    return ly;
    
}


