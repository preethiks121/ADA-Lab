#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int count;

int search(char *pat,char *txt)
{
int m=strlen(pat);
int n=strlen(txt);
int j,i;
for( i=0;i<=n-m;i++)
{
 j=0;
 while((j<m)&&(pat[j]==txt[i+j]))
 {
   j++;
   count++; 
 }
 if(j==m)
 return i;
count++;
}
return -1;
}

int main()
{
int t,res,i,j,m,n;
FILE *fp1,*fp2;
 char *txt, *pat;
 printf("Enter text size\n");
    scanf("%d",&n);
    txt = (char*)malloc(n*sizeof(char));
    for(i=0;i<n;i++)
        *(txt+i) = '0';
    *(txt+i) = '\0';
    
fp1=fopen("patworst.txt","a");
fp2=fopen("patbest.txt","a");
printf("Enter the number of testcases:\n");
scanf("%d",&t);
while(t--)
{
  
        printf("Enter pattern size\n");
    scanf("%d",&m);
    pat = (char*)malloc(m*sizeof(char));
    for(i=0;i<m;i++)
    {    *(pat+i) = '0';}
    
    *(pat+i) = '\0';
    count=0;
    res = search(pat,txt);
    fprintf(fp2,"%d %d\n",strlen(pat),count);
      printf(" res = %d count = %d\n",res,count);
    
  
    pat = (char*)malloc(m*sizeof(char));
    for(i=0;i<m-1;i++)
        {*(pat+i) = '0';}
    *(pat+i) = '1';
    i++;
    *(pat+i) = '\0';
    count=0;
    res = search(pat,txt);
    fprintf(fp1,"%d %d\n",strlen(pat),count);
      printf(" res = %d count = %d\n",res,count);
   
 
}
return 0;
}
