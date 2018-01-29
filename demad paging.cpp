#include<iostream>
#include<conio.h> 
#include<stdio.h>
#include<math.h>
#include <cstdlib>
using namespace std;
 
int main()
{
	int mno,pages,i,list[10],status[10],j,allocation[10],time[10],check,status2[10],k;
	
	cout<<"Enter number of memory block:";
	cin>>mno;
	cout<<endl;
	
	cout<<"Enter 10 sequence of demanded pages:";
	for(i = 0; i < 10; i++){
        cin>>list[i];
    }
    
    for(i = 0; i < 10; i++){
        status[i]=0;
        status2[i]=0;
        time[i]=-1;
       
    }
    
    for(i=0;i<10;i++){
    	
    	cout<<"Memory no.  Page no.\n";
    	check=0;
    	for(j=0;j<mno;j++){
    		
    		if(status[j]==0){
    			allocation[j]=list[i];	
    			time[i]=list[i];
    			status[j]=1;
    			check=1;
    			break;
			}
			else if(allocation[j]== list[i]){
    			time[i]=list[i];
    			check=1;
    			
    			for(k=0;k<i;k++){
    				if(time[k]==list[i]){
    					status2[k]=1;
					}
				}
    			break;
			}
			
		}
		
		if(check==0){

			for(j=0;j<10;j++){
				
				if(status2[j]==0){
					time[i]=list[i];
					status2[j]=1;
					
					for(k=0;k<mno;k++){
						
	    				if(allocation[k]==time[j]){
	    					allocation[k]=list[i];
	    					break;
						}
					}
					break;
				}
				
			
			}
				
		}
		
		for(j = 0; j < mno; j++){
			if(status[j]==0){
				cout<<"   "<<j<<"\t\t"<<"empty"<<endl;
			}
			else{
			
        	cout<<"   "<<j<<"\t\t"<<allocation[j]<<endl;
        	}
        	
        		
   		}
    	
    	cout<<endl;
    	
	}
    
    
    
    
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
