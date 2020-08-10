#include <stdio.h>

int main()
{
    int c;
    OUT:
        switch((c = getchar()))
        {
            case EOF:
                goto EXIT;
            case ' ':case '\t':case '\n':
                ;
                goto OUT;
            default:
                putchar(c);
                goto IN;    
        }
    IN:   
        switch((c = getchar()))
        {
            case EOF:
                goto EXIT;
            case ' ':case '\t':case '\n':
                putchar('\n');
                goto OUT;
            default:
                putchar(c);
                goto IN;
        }
    EXIT:
        return 0;
}