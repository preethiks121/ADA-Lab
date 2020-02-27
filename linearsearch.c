#include <stdio.h>
#include<time.h>
#include<stdlib.h>
FILE *fp3, *fp1, *fp2;
int count=0;
int linear(int *a, int n, int key)
{
	int i=0;
	while(i<n && a[i] != key)
	i++;
	if(i<n)
		printf("%d found at position %d\n",key,i );
	return i+1;
}
int main()
{
	int n, key, i, r;
	int size, *a;
	printf("Enter the number of times to run the program:\n");
	scanf("%d",&n);
	fp1 = fopen("best.txt","a");
	fp2 = fopen("worst.txt","a");
	fp3 = fopen("average.txt","a");

	while(n--)
	{
		
		printf("Enter the input size:\n");
		scanf("%d",&size);
		fprintf(fp1,"%d",size);
		fprintf(fp2,"%d",size);
		fprintf(fp3,"%d",size);
		a = (int*)malloc(size*sizeof(int));
		srand(time(0));
		for(i=0;i<size;i++)
			*(a+i) = rand()%10005;

		fprintf(fp1, "%d\n",linear(a,size,*a) );
		fprintf(fp2, "%d\n",linear(a,size,*(a+size-1)) );
		fprintf(fp3, "%d\n",,linear(a,size,*(a+rand()%size)) );

	}
	return 0;
}
