#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int binary_search(int *a,int n,int key)
{
        int l=0,u=n-1,m,count=0;
        int res;
        while(l<=u)
        {
                m = (l + u)/2;
                res = *(a+m) == key;
                count++;
                if(res)
                {
                        return count;
                }
                else
                {
                        count++;
                        if(key < *(a+m))
                        {
                                u = m - 1;
                        }
                        else
                        {
                                l = m + 1;
                        }
                       
                }
        }
        return count;
}

int main()
{
        int n,i,ch;
        int *arr;
        FILE *f1,*f2,*f3;

        f1 = fopen("best1.txt","a");
        f2 = fopen("worst1.txt","a");
        
        while(1){
        printf("Enter the size of the array:\n");
        scanf("%d",&n);
        arr = (int*)malloc(n*sizeof(int));
        srand(time(0));
        for(i=0;i<n;i++)
        {
                *(arr+i) = rand()%10000;
        }

        fprintf(f1,"%d %d\n",n,binary_search(arr,n,arr[(n-1)/2]));
        fprintf(f2,"%d %d\n",n,binary_search(arr,n,arr[0]));
        


        free(arr);
        printf("\npress 1 to continue 0 to exit\n");
       
        scanf("%d",&ch);
        if(ch==0){exit(0);}

        }

        return 0;
}
