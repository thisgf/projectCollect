/*
** Copyright (C) QPSOFT.COM All rights reserved.
*/

int main()
{
    iteratorBooks();
    return 0;
}

/**
 * Çî¾ÙÊé±¾
 */
void iteratorBooks()
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

}
