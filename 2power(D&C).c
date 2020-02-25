#include<stdio.h>

int count;
int power( unsigned int n) 
{ 
    if(n==0)
        return 1;
    if (n == 1) 
        return 2; 
    else if (n%2 == 0) 
    {
        count++;
        return power(n/2)*power(n/2);
         
    }
    else
    {
        count+=2;
        return 2*power(n/2)*power( n/2); 
        
    }
} 
int main() 
{ 
    int n;
    printf("Enter n \n");
    scanf("%d",&n);
    count =0;
    printf("%d", power(n)); 
    printf("count = %d\n",count );
    return 0; 
} 