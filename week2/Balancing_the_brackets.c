#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{

    char arr[50];
    int i,p=0,pc=0,b=0,bc=0,sb=0,sbc=0,indp=0,indpc=0,indb=0,indbc=0,indsb=0,indsbc=0;
    printf("Enter string:");
    scanf("%s",arr);
    for(i=0;i<strlen(arr);i++)
    {
        if(arr[i]=='(')
        {
            p++;
            indp=i;

        }
        else if((arr[i]==')') && (i!=0) && p!=0)
        {

            pc++;
            indpc=i;
            if((indp+2==indpc)&&(arr[indpc-1]!=')'))
            {
                printf("false");
                exit(0);
            }
        }
        else if(arr[i]=='{')
        {
            b++;
            indb=i;
        }
        else if((arr[i]=='}') && (i!=0) && b!=0)
        {
            bc++;
               indbc=i;
            if((indb+2==indbc)&&(arr[indbc-1]!='}'))
            {
                printf("false");
                exit(0);
            }
        }
        else if(arr[i]=='[')
        {
            sb++;
            indsb=i;
        }
        else if((arr[i]==']') && (i!=0) && sb!=0)
        {
            sbc++;
               indsbc=i;
            if((indsb+2==indsbc)&&(arr[indsbc-1]!=']'))
            {
                printf("false");
                exit(0);
            }
        }
        else{

            printf("false");
            exit(0);
        }


    }

    if((p==pc)&&(b==bc)&&(sb==sbc))
    {
        printf("true");
    }
    else{
        printf("false");
    }

return 0;

}
