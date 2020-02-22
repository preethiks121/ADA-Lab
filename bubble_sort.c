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
void bubblesort(int arr[],int n)
{
int i,j,flag;
for(i=0;i<n-1;i++)
{
 flag=0;
 for(j=0;j<(n-i-1);j++)
 {count++;
  if(arr[j+1]<arr[j])
  {
  swap(&arr[j+1],&arr[j]);
  flag=1;
  }
  
 }
 if(flag==0)
 return;
 }
}


int main()
{
int n,*arr,i,t;
FILE *fp1,*fp2;
fp1=fopen("bubworst.txt","a");
fp2=fopen("bubbest.txt","a");
printf("Enter the number of testcases:\n");
scanf("%d",&t);
while(t--)
{
  scanf("%d",&n);
  arr=(int *)malloc(n*sizeof(int));
  *(arr+0)=rand()%1000;
  for(i=1;i<n;i++)
  {
   *(arr+i)=*(arr+i-1)-2;
  }
  
  count=0;
  
  bubblesort(arr,n);
  fprintf(fp1,"%d %d\n",n,count);
  printf("count = %d \n",count );
 
  
  *(arr+0)=rand()%1000;
  for(i=1;i<n;i++)
  {
   *(arr+i)=*(arr+i-1)+2;
  }
  
  count=0;
  
  bubblesort(arr,n);
  fprintf(fp2,"%d %d\n",n,count);
  printf("count = %d \n",count );
  free(arr);
}

}
