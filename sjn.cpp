#include<iostream>
#include<stdio.h>
  using namespace std;
int main()
{
    int burst_time[20],process[20],waiting_time[20],tat[20],i,j,n,total=0,pos,temp;
    float wait_avg,TAT_avg;
  cout<<"Enter number of process: ";
    cin>>n;
  
   cout<<"\nEnter Burst time: \n";
    for(i=0;i<n;i++)
    {
       cout<<"Process["<<i+1<<"]: ";
       cin>>burst_time[i];
        process[i]=i+1;           //Process Number
    }
  
//Sorting
       for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(burst_time[j]<burst_time[pos])
                pos=j;
        }
  
        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;
  
        temp=process[i];
        process[i]=process[pos];
        process[pos]=temp;
    }
  //First process has 0 waiting time 
    waiting_time[0]=0;           
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        waiting_time[i]=0;
        for(j=0;j<i;j++)
            waiting_time[i]+=burst_time[j];
  
      
    }
     //Calculating Average waiting time 

   
    for(i=0;i<n;i++)
    {
    	cout<<"\n\nProcess\t    Burst Time    \tWaiting Time";
    	for(j=0;j<n;j++){
    		
    		if(j<=i){
    	
   
       		 cout<<"\np"<<process[j]<<"\t\t"<<burst_time[j]<<"\t\t"<<waiting_time[j];
			}
			
			else{
				 cout<<"\np"<<"--"<<"\t\t"<<"--"<<"\t\t"<<"--";
			}
		
        
    	}
    }
  

  
}
