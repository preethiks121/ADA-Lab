#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int count;
int pattern(char *t)
{
    int n = strlen(t);
    int i,ca=0, cp=0;
    for(i =0;i<n;i++)
    {
        if(*(t+i)=='a' )
            ca++;
        if(*(t+i)=='b')
            cp = cp + ca;
        count+=2;
    }
    return cp;
}
int main()
{
    int n;
    char *text;
    FILE *fp,*fcount;
    fcount = fopen("pattercount.txt","a");
    while(1)
    {
        printf("Enter text size:\n");
        scanf("%d",&n);
        fp = fopen("input.txt","r");
        text = (char*)malloc(n*sizeof(char));
        fgets(text,n,fp);
        printf("%s\n",text );
        count=0;
        printf("No of pattern = %d\n ",pattern(text));
        printf("count = %d\n",count );
        fprintf(fcount, "%d %d\n",n,count );
        free(text);
    }
    return 0;
}