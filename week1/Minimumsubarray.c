#include <stdio.h>
#include <limits.h>
int index_l=0,index_r=0;
int len = INT_MAX;
int minsubarraylen(int arr[], int n, int k)
{
    int subsum,i,j;
    int sum = 0;
  for(i=0;i<n;i++){
	sum=0;
	for(j=i;j<n;j++){
		sum = sum+arr[j];
		if(sum > k){
			if(index_l==0 && index_r==0){
				index_l=i;
				index_r=j;
			}
			else if((j-i) < (index_r-index_l)){
				index_l=i;
				index_r=j;
			}
		}
	}
	if(sum>subsum)
	subsum=sum;
}

 if(subsum>k){
        len  = index_r-index_l+1;
        return len;
}
else
{
    printf("No such array found\n");
return len;
}

}






int main()
{
   int num,i,arr[1000],n;

    printf("Enter no of numbers in an Array:");
    scanf("%d",&num);
    printf("\nEnter the numbers:");
    for(i=0;i<num;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nEnter n Values:");
    scanf("%d",&n);

    // find the length of the smallest subarray
    int len = minsubarraylen(arr, num, n);



    if (len != INT_MAX) {
        printf("The smallest subarray length is %d:\n", len);
        printf("smallest subarray is :\n");
        for(int i=index_l;i<=index_r;i++)
        {

            printf("%d\t",arr[i]);
        }
        printf("\n");
        printf("smallest subarray after adding length is:\n");
        for(int i=index_l;i<=index_r;i++)
        {
            printf("%d\t",arr[i]+len);
        }
    }



    return 0;
}


