#include <stdio.h>
int main()
{
        const int a = 12;
        int* p;
        p = &a;
        *p = 70;
        printf("%d\n", a);
        return 0;
}
