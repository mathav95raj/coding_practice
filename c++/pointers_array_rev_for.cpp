#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }
    /* Write the logic to reverse the array. */
    int temp;
    for(i = 0; i < num; i++) {
		if(i == num/2)
    	break;
    	else
    	temp = *(arr+num-i-1);
        *(arr+num-i-1) = *(arr+i);
        *(arr+i) = temp;
    }

    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}

