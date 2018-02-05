#include<iostream>
#include<conio.h> 
#include<stdio.h>
#include<math.h>
#include <cstdlib>
#include<string>
#include<sstream>

using namespace std;

void firstfit();
void fifo();
void lru();

int main()
{
	string line;
	int op;
	
	start:
		
	cout<<endl<<"\t\tOPERATIONS"<<endl<<endl;
	cout<<"[1] BEST FIT"<<endl<<"[2] FIRST FIT"<<endl<<"[3] WORST FIT"<<endl<<"[4] FIFO"<<endl<<"[5] LRU"<<endl<<"[6] EXIT"<<endl;
	cout<<endl<<"Choose Operation: ";

	while(getline(cin,line))
    {
        stringstream ss(line);
        if(ss>>op)
        {
            if (ss.eof())
            {   
            	switch(op)
				{
					case 1		:	system("cls");
									cout<<endl<<"\t\tBEST FIT"<<endl<<endl;
									cout<<"best fit";
									break;
						
					case 2		:	system("cls");
									cout<<endl<<"\t\tFIRST FIT"<<endl<<endl;
									firstfit();
									break;
						
					case 3		:	system("cls");
									cout<<endl<<"\t\tWORST FIT"<<endl<<endl;
									cout<<"worst fit";
									break;
						
					case 4		:	system("cls");
									cout<<endl<<"\t\tFIFO"<<endl<<endl;
									fifo();
									break;
						
					case 5		:	system("cls");
									cout<<endl<<"\t\tLRU"<<endl<<endl;
									lru();
									getch();
									break;
					
					case 6		:	return 0;
									break;
									
					default		:	cout<<endl<<"Invalid Choice";
									break;
				}
				
				cout<<endl<<endl;
				system("pause");
				system("cls");
				goto start;
                break;
            }
        }
       	cout<<endl<<endl;
		system("pause");
		system("cls");
		goto start;
        break;
    }
	
	return 0;
}

void firstfit()
{
	int mno,pno,psize[10],i,status[10],allocation[10],msize[10],out,j,check;
	
	cout<<"Enter number of memory blocks:";
	cin>>mno;
	
	cout<<"\nEnter total no. of processes: ";
    cin>>pno;
    
    cout<<"\nEnter size of each process: ";
    for(i = 0; i < pno; i++){
        cin>>psize[i];
	     if(psize[i]>1000){
        	cout<<endl<<"enter sizes less than 1000!"<<endl;
        	i--;
		}
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
		
		out=rand()%mno;
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
}

char fr[12];

void fifo()
{
	int i,j;
	char page[12];
	int flag1[12],flag2[12],pf=0,frsize,top=0;
	
	cout<<"No. of memory blocks: ";
	cin>>frsize;
	
	printf("Enter Reference String [12 pages]: ");
	for(i=0;i<12;i++)
	{
		cin>>page[i];
	}
	
	for(i=0;i<12;i++)
	{
		fr[i]=-1;					//frame is empty
		flag1[i]=0;
		flag2[i]=0;
	}
	
	for(j=0;j<12;j++)
	{
		cout<<endl<<"Memory no.  Page no.\n";
		for(i=0;i<frsize;i++)
		{
			if(fr[i]==page[j])		//page exist in frame
			{	
				flag1[i]=1;
				flag2[i]=1;
				break;		
			}
		}
		if(flag1[i]==0)				//page doesn't exist frame
		{
			for(i=0;i<frsize;i++)	//traverse in each frame
			{
				if(fr[i]==-1)		//there is an empty frame
				{
					fr[i]=page[j];
					flag2[i]=1;
					pf++;
					break;
				}
			}
		}
		
		if(flag2[i]==0)			//no empty frame
		{
			fr[top]=page[j];	//replace top with page referred
			top++;				//ang sunod na number from the victim page is considered the oldest in the block
			pf++;				//increment page fault counter
			if(top>=frsize)		//if ang page naa sa last na mem block ang victim page balik na sa first na block ang order
			{
				top=0;
			}
		}
		
		for(i = 0; i < frsize; i++)
		{
			if(flag2[i]==0)
			{
				cout<<"   "<<i<<"\t\t"<<"empty"<<endl;
			}
			else
			{
	        	cout<<"   "<<i<<"\t\t"<<fr[i]<<endl;
	        }
   		}
	}
	
	cout<<endl<<endl<<"Number of page faults: "<<pf;
	getch();
}

void lru()
{
	int mno,pages,i,status[10],j,time[10],check,status2[10],k;
	char list[10],allocation[10];
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
}
