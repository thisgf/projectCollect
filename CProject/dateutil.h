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

//获取天数 
int getDays(struct date d)
{
    int ly = checkIsLeapYear(d.year);  //是否闰年
    
    int i;
    
    for(i = 1; i < d.month; i++)
    {
        d.day += day_list[ly][i];
    }
    
    return d.day;
}

//是否闰年(1900之后)
int checkIsLeapYear(int year)
{
    if(year < 1900)
        return 0;
        
    int ly = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    
    return ly;
    
}


