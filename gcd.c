#include <stdio.h>
#include<stdlib.h>
FILE *fp, *fp1, *fp2;
int gcd(long int m, long int n)
{
	long int r;
	int count=0;
	while(n!= 0)
	{
		r = m%n;
		m = n;
		n = r;
		count++;
	}
	printf("Basic operation count = %d\n",count );
	fprintf(fp, "%d\n",count );
	return m;
}
int consecutive(long int m, long int n)
{
	long int min;
	int count=0;
	min = (m<n?m:n);
	while(min > 0)
	{
		count++;
		if(m % min == 0)
		{
			count++;
			if(n % min == 0)
			{
				fprintf(fp1, "%d\n",count );
				printf("Basic operation count = %d\n",count );
				return min;
			}
		}
		
		min--;
	}
	fprintf(fp1, "%d\n",count );
	printf("Basic operation count = %d\n",count );
	return min;
}

int gcd_modified(long int m, long int n)
{
	int count=0;
	while(n != 0)
	{
		if(m < n)
		{
			long int temp;
			temp = m;
			m = n;
			n = temp;
		}
		m = m - n;
		count++;
	}
	fprintf(fp2, "%d\n",count );
	printf("Basic operation count = %d\n",count );
	return m;
}
int main()
{
	long int a,b,r;
	int i, choice;
	
	a = 83;
	b = 86;
	while(1)
	{
		printf("1.Euclid's alogrithm\n2.Consecutive integer checking method\n3.Modified Euclid's algorithm\n4.EXIT\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					a = 83;
					b = 86;
					fp = fopen("Euclid.txt","a");
					for(i = 0; i<10; i++)
					{
						fprintf(fp, "%ld ",(a<b?a:b) );
						r = gcd(a,b);
						
						printf("Gcd of %ld and %ld = %ld\n\n",a,b,r );
						a = a + 10000;
						b = b + 5000;
					}
					break;
			case 2:
					a = 83;
					b = 86;
					fp1 = fopen("consecutive.txt","a");
					for(i = 0; i<10; i++)
					{
						fprintf(fp1, "%ld ",(a<b?a:b) );
						r = consecutive(a,b);
						
						printf("Gcd of %ld and %ld = %ld\n\n",a,b,r );
						a = a + 10000;
						b = b + 5000;
					}
					break;
			case 3: 
					a = 83;
					b = 86;
					fp2 = fopen("modified_euclid.txt","a");
					for(i = 0; i<10; i++)
					{
						fprintf(fp2, "%ld ",(a<b?a:b) );
						r = gcd_modified(a,b);
						printf("Gcd of %ld and %ld = %ld\n\n",a,b,r );
						a = a + 10000;
						b = b + 5000;
					}
					break;
			default: exit(0);
		}
	}
	
	return 0;
}
