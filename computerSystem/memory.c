/*
 * =====================================================================================
 *
 *       Filename:  memory.c
 *
 *    Description:  for testing & practing
 *
 *        Version:  1.0
 *        Created:  02/14/2017 11:15:22 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	printf("enter size of array\n");
	scanf("%d",&n);
	int *A = (int*)malloc(n*sizeof(int));	//dynamically allocated array
	int *B = (int*)calloc(n,sizeof(int));
	for(int i=0;i<n;i++){
		A[i] = i+1;
		B[i] = i+10;
	}
	//free(A);
	//A[2] = 6;
	//A=NULL;
	int *C = (int*)realloc(A,2*n*sizeof(int));	//equivalent to free(A)
	int *D = (int*)realloc(NULL,n*sizeof(int)); //equivalent to malloc
	printf("prev block address = %d, new address = %d\n",A,C);
	for(int i=0;i<n;i++){
		printf("%d ",A[i]);
		printf("%d ",C[i]);
	}
	printf("\n");
}
