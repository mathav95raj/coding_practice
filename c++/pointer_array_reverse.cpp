#include <stdio.h>
#include <stdlib.h>
void rev(int *b, int i, int j, int num) //or int b[]
	{
        //printf("%d", i);
		if(i == (num/2))
        return;
      //  else if(num%2 != 0 && i == (num/2))
       // return 0;
        else
        {
        int temp = *(b+j);  //b[j]
        *(b+j) = *(b+i);
        *(b+i) = temp;
        i= i+1;
        j = j-1;
		rev(b, i, j, num);
        }
    }
int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }
    /* Write the logic to reverse the array. */
    
	rev(arr, 0, num-1, num);
 

    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}

