#include <stdio.h>

void Out();
void In();

int main()
{
    Out();
    return 0;
}

void Out()
{
    int c;
    switch((c = getchar()))
    {
        case EOF:
            return;
        case ' ':case '\t':case '\n':
            Out();
            break;
        default:
            putchar(c);
            In();
            break;    
    }
}
void In()
{
    int c;
    switch((c = getchar()))
    {
        case EOF:
            return;
        case ' ':case '\t':case '\n':
            putchar('\n');
            Out();
            break;
        default:
            putchar(c);
            In();
            break;
    }
}
