#include<stdio.h>
 
int main()
{
    int n,bt[10],at[10],ct[10],wt[10],tat[10],avwt=0,avtat=0,i,j;
    printf("Enter total number of processes(maximum 10):");
    scanf("%d",&n);
 
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
    
    printf("\nProcess\t\tBurst Time\tArrival Time");
    for(i=0;i<n;i++)
    {
    	printf("\nP[%d]\t\t%d\t\t%d",i+1,bt[i],at[i]);
	}
	
	printf("\n\nProcess\t\tCompletion Time\tTurnaround Time\tWaiting Time");
	for(i=1;i<=n;i++)
    {
    	ct[i]=0;
    	tat[i]=0;
    	wt[i]=0;
    	
    	for(j=0;j<i;j++)
    	{
    		ct[i]+=bt[j];
    		tat[i]=ct[i]-at[j];
    		wt[i]=tat[i]-bt[j];
		}
		
		printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i,ct[i],tat[i],wt[i]);
	}
	
	
//	printf("\n\nAverage Turnaround Time = %d",avtat);
 
    return 0;
}
