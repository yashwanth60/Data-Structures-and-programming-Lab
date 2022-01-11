#include <stdio.h>
int main()
{
    char s[30];
    printf("Enter the String: ");
    scanf("%[^\n]",s);
    int n=strlen(s);
    //printf("%d",n);
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        dp[i][i]=1;
    }
    int ans=1,start=0;
    for(int i=0;i<n-1;i++)
    {
      if(s[i]==s[i+1])
      {
        dp[i][i+1]=1;
        if(ans<2)
        {
          ans=2;
          start=i;
        }
      }
    }
    for(int i=3;i<=n;i++)
    {
      for(int j=0;j<n-i+1;j++)
      {
        int k=j+i-1;
        if(s[j]==s[k])
        {
          if(dp[j+1][k-1]==1)
          {dp[j][k]=1;
          if(ans<i)
          ans=i;
            start=j;
          }
        }
      }
    }
    printf("longest palindromic in String is : ");
    for(int i=start;i<start+ans;i++)
    printf("%c",s[i]);
    printf("\n");
    return 0;
}
