# include<stdio.h>
# include<math.h>



int main(void)
{
    int n;
    void pyramid(int n);

    printf("please input the number:");
    scanf("%d",&n);
    pyramid(n);
    return 0;
}

void pyramid(int n){                  
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n-i;j++)printf(" ");
        for(j=1;j<=i;j++)printf("%d ",i);
        putchar('\n');
    }
    
}
