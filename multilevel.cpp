#include <iostream>
#include<conio.h> 
#include<stdio.h>
#include<math.h>
#include <cstdlib>

using namespace std;

int main(){
	
	int total,arrival[10],burst[10],priority[10],i,totaltime=0,process[10],j,temp,final[10],wait[10],totalburst,rq1[10],rq2[10],tot1=0,tot2=0;
	int check1[10],check2[10],reach,flag;
	cout<<"Enter Number Of Processes [max:10]:";
	cin>>total;
	
	while(total<0 || total>10){
		cout<<endl<<"Enter Number Of Processes [max:10]:";
		cin>>total;
	}
	
	for(i=0;i<total;i++){
		cout<<endl<<"P"<<i<<" arrival time:";
		cin>>arrival[i];
		
		cout<<"P"<<i<<" burst time:";
		cin>>burst[i];
		
		cout<<"P"<<i<<" priority [0/1]:";
		cin>>priority[i];	
		
		while(priority[i]>1 || priority[i]<0){
			cout<<endl<<"Priority Should Only Be 1 or 0!";
			cout<<endl<<"P"<<i<<" priority [0/1]:";
			cin>>priority[i];
			
		}
	
		process[i]=i;
		check1[i]=0;
		check2[i]=0;
		rq1[i]=-1;
		rq2[i]=-1;
		
		totaltime=totaltime+burst[i];
		
	}
	
	for(i=0;i<total;i++){
		
		for(j=1;j<total;j++){
			
			if(arrival[j]<arrival[j-1]){
				temp=process[j];
				process[j]=process[j-1];
				process[j-1]=temp;
				
				temp=arrival[j];
				arrival[j]=arrival[j-1];
				arrival[j-1]=temp;
				
				temp=burst[j];
				burst[j]=burst[j-1];
				burst[j-1]=temp;
				
				temp=priority[j];
				priority[j]=priority[j-1];
				priority[j-1]=temp;
			}
		}
		
		
	}
	
	final[0]=process[0];
	wait[0]=0;
	reach=0;
	totalburst=burst[0];
	
	for(i=1;i<total;i++){
		
		
	

		for(j=reach;j<total;j++){
			if(arrival[j]<=totalburst){
				
					reach=j;
			}
		}
	
	
		for(j=i;j<=reach;j++){
			if(priority[j]==0){
				if(rq1[tot1-1]==j){
					continue;
				}
				else{
				rq1[tot1]=j;
				tot1+=1;
				}
			}
			else{
				if(rq2[tot2-1]==j){
					continue;
				}
				else{
				rq2[tot2]=j;
				tot2+=1;
				}
			}
		}

		flag=0;
	 if(rq1[0] != -1){
			for(j=0;j<tot1;j++){
				if(check1[j]==0){
					final[i]=rq1[j];
					check1[j]=1;
					totalburst+=burst[rq1[j]];
					flag=1;
					break;
				}
			}
	}
		
	if(rq1[0]==-1 ||flag==0){
			for(j=0;j<tot2;j++){
				if(check2[j]==0){
					final[i]=rq2[j];
					check2[j]=1;
					totalburst+=burst[rq2[j]];
					break;
				}
			}
		}
		
		
	}
	
	totalburst=0;
/*	for(i=0;i<total;i++){
		wait[i]=totalburst;
		 totalburst=totalburst+burst[final[i]];
	}*/
	
	 for(i=0;i<total;i++)
    {
    		
    		wait[i]=totalburst;
    	printf("\n\nProcess    Burst Time    \tWaiting Time");
      	for(j=0;j<total;j++){
    		
    		if(j<=i){
    			
    	
   
       		 printf("\nP[%d]\t\t  %d\t\t    %d",final[j],burst[final[j]],wait[j]);
       		 
       	
			}
			
			else{
				 printf("\nP[-]\t\t  --\t\t    --");
			}
		
        
    	}
    		
       totalburst=totalburst+burst[final[i]];
       
    }
 
	
	
	
	
	
	return 0;
}
