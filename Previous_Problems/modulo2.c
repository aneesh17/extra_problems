#include<stdio.h>
main()
{
    int b,e,m,x=1;
    scanf("%d%d%d",&b,&e,&m);
    while(e>0)
    {
        if(e%2==1)
        {
            x=(x*b)%m;
            e=e-1;
        }
        else
        {
            b=(b*b)%m;
            e=e/2;
        }
    }
    printf("%d",x);

}
