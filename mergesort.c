#include<stdio.h>
#include<stdlib.h>

int count = 0;

void merge(int arr[], int l, int m, int r)
{
    int i,j,k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L,*R;
    L = (int*)malloc(n1*sizeof(int));
    R = (int*)malloc(n2*sizeof(int));

    for(i=0;i<n1;i++)
        L[i] = arr[l+i];
    for(j=0;j<n2;j++)
        R[j] = arr[m+1+j];
    i = 0;
    j = 0;
    k = l;
    while(i<n1 && j<n2)
    {
        count++;
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if(l<r)
    {
        int m = l + (r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main()
{
    int arr[1000],n,i,tmp,b[1000],j,k,var,t;
    FILE *fp1,*fp2;
    
    fp1 = fopen("mergeBest.txt","a");
    fp2 = fopen("mergeWorst.txt","a");
    scanf("%d",&t);
    while(t--)
    {
    printf("Enter array size: ");
    scanf("%d",&n);
    tmp = rand()%1000;
    for(i=0;i<n;i++)
    {
        arr[i] = tmp;
        tmp++;
    }
    count=0;
    mergeSort(arr,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",arr[i] );
    fprintf(fp1,"%d %d\n",n,count);

    j = 1;
    k = 2;
    for(i=0;i<=(n-1)/2;i++)
    {
        b[i] = j;
        j += 2;
    }
    for(i=(n+1)/2;i<n;i++)
    {
        b[i] = k;
        k += 2;
    }
    
    j = 1;
    k = (n-1)/2 - 1;
    while(j<k)
    {
        var = b[j];
        b[j] = b[k];
        b[k] = var;
        j++;
        k--;
    }
    
    j = (n+1)/2 + 1;
    k = n-2;
    while(j<k)
    {
        var = b[j];
        b[j] = b[k];
        b[k] = var;
        j++;
        k--;
    }

   
  

    count = 0;
    mergeSort(b,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",b[i] );
    fprintf(fp2,"%d %d\n",n,count);
}
    fclose(fp1);
    fclose(fp2);
    
    return 0;
}
