#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count;
void swap(int *a,int *b)
{
 int t=*a;
 *a=*b;
 *b=t;
}
int Partition(int *arr,int l,int r)
{
 int pivot=*(arr+l);
 int i=l;
 int j=r+1;
 

while(i<j)
{
 do
{count++;
i++;
}while(*(arr+i)<pivot);

do
{count++;
j--;
}while(*(arr+j)>pivot);
if(i<j)
{
 swap(&arr[i],&arr[j]);

}
}
swap(&arr[j],&arr[l]);
return j;
}
void QuickSort(int *arr,int l,int r)
{
 if(l<r)
{
int s=Partition(arr,l,r);
QuickSort(arr,l,s-1);
QuickSort(arr,s+1,r);
}

}

int main()
{
int n,*arr,i,t;
FILE *fp1,*fp2;
fp1=fopen("quickbest.txt","a");
fp2=fopen("quickworst.txt","a");
printf("Enter the number of testcases:\n");
scanf("%d",&t);
while(t--)
{
  scanf("%d",&n);
  arr=(int *)malloc(n*sizeof(int));
  /*worst case*/
  *(arr+0)=rand()%100;
  for(i=1;i<n;i++)
  {
   *(arr+i)=*(arr+i-1)+2;
  }
 
  count=0;
  QuickSort(arr,0,n-1);
  fprintf(fp2,"%d %d\n",n,count);
   for(i=0;i<n;i++)
  printf("%d  ",*(arr+i));
  free(arr);

  /*best case*/
  arr=(int *)malloc((n)*sizeof(int));
  *(arr+0)=rand()%10;
  for(i=1;i<n;i++)
  {
   *(arr+i)=*(arr+i-1);
  }
  count=0;
  QuickSort(arr,0,n-1);
  for(i=0;i<n;i++)
  printf("%d  ",*(arr+i));
  fprintf(fp1,"%d %d\n",n,count);
  free(arr);
}
}

