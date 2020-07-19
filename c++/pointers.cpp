#include<stdio.h>
main()
{
	int a = 512, b=12;
	int *ptr1 = &a, *ptr2 = &b, *ptrn = NULL;
	char *p0;
	void *v; //no specific dtatyp
	int **q; //int ** pointer to int * pointer to a
	q = &ptr1;
	//p0 = ptr1; ptr1 is int pointer so compilation error
	p0 = (char*) ptr1;
	v = ptr1; //allowed
	//printf(.., *v, v+1); both are not allowed
	printf("%p\t%p\t%d\n", ptr1, *q,*(*q)); //*q prints value at ptr1 which is address of ptr1  *(*q) prints value at a which is 512
	printf("%p\t%d\n", p0, *p0); //dereference only one byte because p0 is char pointer
	printf("%p\t%p\t%d\n", ptr1, ptr2, *ptr1); //address
	printf("\n%d\t%d\n", ptr1, ptr2); //address in decimal //address stored in stack, recent variable go to top of stack
	int c[3] = {1,69,3}; //first variable is in top of stack
	int *ptr3 = c; //points to top of array stack //note no &operator for array
	int *ptr4 = &c[1]; //points to address of that particular index
	printf("\n%d\t%d\n", *ptr3, ptr3); //value at top of array stack , address of top array stack
	printf("\n%d\t%d\t%d\n", ptr3[0], ptr3[1], ptr3[2]);//gives value at address stored in pointer array
	printf("\n%d\t%d\n", *ptr3, *ptr3); //increments pointer down the stack to second location and prints the value,
									  //takes value at top array stack and increments it
									  //++ptr shifts each pointer to next consecutive locations, last pointer gets garbage location
	
	printf("\n%d\t%d\t%d\n", ptr3, ptr3[1], ptr3[2]); //ptr3 holds address and ptr3[0] gives first value
	int d[2][3] = {0,1,2,3,4,5}, d1[6];
	printf("\n");
	for(int i = 0; i<6; i++)
	{
	scanf("%d", d1+i);
	}
	printf("\n");
	int k = 0;
	for(int i = 0; i<2; i++)
	{
		for(int j =0; j<3; j++)
		{
			//d[i][j] = i;
			//printf("%d",*(*(d+i)+j),"\t"); //accessing elements of array   //note that inner star is encompassing d and i
			printf("%d\t", *(d1+k));
			k = k+1;
			
		}
		printf("\n");
	}
	printf("null is %d", ptrn);
	
}
