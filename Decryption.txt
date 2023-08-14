#include <stdio.h>
#include<math.h>

int main()
{
    int x,i,j,decimal=0,rem;
    char a;
    printf("enter the text\n");
    for (i=0;;i++)
    {   
        decimal=0;
        scanf("%d",&x);
        if(x>0)
        {    for(j=0;x>0;j++)
            {   rem=x%10;
                decimal+=rem*pow(2,j);
                x/=10;
            }
                
        }
        decimal-=5;
        //printf(" decimal is %d",decimal);
        if(((decimal>=65)&&(decimal<=90))||((decimal>=96)&&(decimal<=122)))
        {   
            printf("%c",decimal);
        }
        scanf("%c",&a);
        if(a==')')
        {   
            printf(" ");
        }
        else if(a=='/')
        {   continue;}
        else if(a=='*')
        {   break;}
        else
            printf ("%c",a);
            
    }
    return 0;
}