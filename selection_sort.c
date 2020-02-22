#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count;
void swap(int *xp,int *yp)
{
int temp=*xp;
*xp=*yp;
*yp=temp;
}
void selectionsort(int arr[],int n)
{
int i,j,min;
for(i=0;i<=n-2;i++)
{
 min=i;
 for(j=i+1;j<=n-1;j++)
 {count++;
  if(arr[j]<arr[min])
  min=j;
  
 }
 swap(&arr[min],&arr[i]);
 
}

}
int main()
{
int n,*arr,i,t;
FILE *fp1;
fp1=fopen("sele.txt","a");
printf("Enter the number of testcases:\n");
scanf("%d",&t);
while(t--)
{
  printf("Enter array size\n");
  scanf("%d",&n);
  arr=(int *)malloc(n*sizeof(int));
  count=0;
  srand(time(0));
  for(i=0;i<n;i++)
  {*(arr+i)=rand()%10005;
  }
  selectionsort(arr,n);
  fprintf(fp1,"%d %d\n",n,count);
  printf("count = %d\n",count );
}
return 0;
}
