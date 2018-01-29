#include<iostream>
#include<conio.h> 
#include<stdio.h>
#include<math.h>
#include <cstdlib>
using namespace std;
 
int main()
{
	int mno,pno,psize[10],i,status[10],allocation[10],msize[10],out,j,check;
	
	cout<<"Enter number of memory blocks:";
	cin>>mno;
	
	cout<<"\nEnter total no. of processes: ";
    cin>>pno;
    
    cout<<"\nEnter size of each process: ";
    for(i = 0; i < pno; i++){
        cin>>psize[i];
    }
    
    for(i = 0; i < 10; i++)
    {
        status[i] = 0;
        allocation[i] = -1;
    }
    
    for(i = 0; i < pno-mno ; i++)
    {
    check=0;
       for(j = 0; j <mno ; j++)
    	{
       		if(psize[i+5]< psize[j]){
       			check=1;
       			break;
			}
    	}
    	if(check==0){
    		status[i+5]=2;
		}
    
    }
    
    cout<<"\nBlock no.\tsize\t\tprocess no.\t\tsize";
    for(i=0;i<mno;i++){
    	
    	msize[i]=psize[i];
    	allocation[i]=i;
    	status[i]=1;
    	
    
    	cout<<"\n"<< i+1<<"\t\t"<<msize[i]<<"\t\t";
    	cout<<allocation[i]+1<<"\t\t\t"<<psize[i];
	}
	
	i=0;
	while(i< (pno-mno)){
		
		out=rand()%5;
		status[out]=0;
		
		cout<<"\n"<<"deallocation of block no."<<out+1<<"\n\n";
		
		check=0;
		if(status[out]==0 && psize[i+mno]< msize[out]){
			allocation[out]=i+mno;
			status[out]=1;
			check=1;
		}
		
			
			cout<<"\nBlock no.\tsize\t\tprocess no.\t\tsize";
			for(j=0;j<mno;j++){
				
				 cout<<"\n"<< j+1<<"\t\t"<<msize[j]<<"\t\t";
			        
					if(status[j] == 1){
			            cout<<allocation[j]+1<<"\t\t\t"<<psize[allocation[j]];
			        }
			        else{
			        	cout<<"Not allocated";
					}
			}
			
			if(check==0){
				if(status[i+mno]!=2){
					i--;
				}
			}
			
			i++;
	
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
