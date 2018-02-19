#include<stdio.h>
 
int main()
{
    int n,bt[10],at[10],ct[10],wt[10],tat[10],avwt=0,avtat=0,i,j,k;
    
    start:
    	
    printf("Enter total number of processes(min:5 max: 10):");
    scanf("%d",&n);
    
    if(n<5||n>10)
    {
    	printf("\n\t\tError\n\n");
    	system("pause");
    	system("cls");
		goto start;	
	}
	else
	{
	    printf("\nEnter Process Burst Time\n");
	    for(i=0;i<n;i++)
	    {
	        printf("P[%d]:",i+1);
	        scanf("%d",&bt[i]);
	    }
	    
	    printf("\nEnter Process Arrival Time\n");
	    for(i=0;i<n;i++)
	    {
	        printf("P[%d]:",i+1);
	        scanf("%d",&at[i]);
	    }
		
		for(i=1;i<=n;i++)
	    {
	    	printf("\n\nProcess\t\tStart Time\tCompletion Time");
	    	ct[i]=0;
	    	tat[i]=0;
	    	wt[i]=0;
	    	
	    	for(j=0;j<i;j++)
	    	{
	    		ct[0]=0;
	    		ct[i]+=bt[j];
	    		tat[i]=ct[i]-at[j];
	    		wt[i]=tat[i]-bt[j];
	    		
	    		if(i>j)
	    		{
	    			printf("\nP[%d]\t\t%d\t\t%d",j+1,ct[j],ct[i]);
				}
			}
			
		}
	}
	
	
    return 0;
}
