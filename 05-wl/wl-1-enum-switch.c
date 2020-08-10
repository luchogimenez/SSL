#include <stdio.h>

typedef enum State
{
    OUT,IN
}State;

int main()
{
    State state=OUT;
    int c;
    while((c=getchar())!=EOF)
    {
        switch(state)
        {
            case OUT:
                switch(c)
                {
                    case ' ':case '\n':case '\t':
                        break;
                    default:
                        state = IN;
                        putchar(c);
                        break;    
                }
                break;
            case IN:
                switch(c)
                {
                    case ' ':case '\n':case '\t':
                        state = OUT;
                        putchar('\n');
                        break;
                    default:
                        putchar(c);
                        break; 
                }
                break;
        }
        }
    return 0;
}