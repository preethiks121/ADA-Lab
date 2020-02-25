#include<stdio.h>
#include<stdlib.h>
int count;
void polynomial(int n, int x, int *p)
{
    int res = p[0];
    int px = 1,i;
    for(i=1;i<=n;i++)
    {
        px = px * x;
        res = res+p[i]*px;
        count+=2;
    }
    printf("result = %d\n",res );
}
int main()
{
    int n,i,x,*p, choice;
    FILE *fp;
    fp = fopen("polycount.txt","a");
    x =2;
    while(1)
    {
        printf("Enter n\n");
        scanf("%d",&n);
        p = (int *)malloc((n+1)*sizeof(int));

        for(i=0;i<=n;i++)
            *(p+i) = i+1;
        count =0;
        polynomial(n,x,p);
        fprintf(fp, "%d %d\n",n,count );
        free(p);
        printf("To continue press 1, to exit press 0\n");
        scanf("%d",&choice);
        if(choice == 0)
            break;
    }

    return 0;
}