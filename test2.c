#include <stdio.h>
int main()
{
    int mmd[] = {1, 2, 3, 4, 5};
    int *mmdptr = mmd;

    printf("%d\n", *mmdptr);
    int y = 10;
    const int *const yptr = &y;
    printf("%p\n%d\n%p\n", yptr, *yptr, &yptr);
}