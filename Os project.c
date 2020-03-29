#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void roundrobin(int arrivalT[10], int burstT[10],int number,int remainingT[10],int CurrentT);

int main()
{
	 information_display:
{   
	    
	    
		printf("                                     |     Process Scheduler C PROGRAM      |     \n");
		printf("                                     |        Made by Hritik Agrawal        |     \n");
		printf("                                     |           11801676|K18FG             |     \n");
		printf("                                     |     Submitted to: Navneet Maam       |     \n");
		
}
	int Processnumber,z,number,CurrentT,RemainingProcess,indicator,timequantum,wait,turnaroundtime;
	int arrivalT[10],burstT[10],remainingT[10],x=1;
	
	turnaroundtime = 0;
	wait = 0;
	indicator = 0;
	
	printf("Please enter the desired number of processes: ");
	scanf("%d",&number);
	RemainingProcess = number;

	printf("\nPlease enter the Required details:\n");
	for(Processnumber = 0;Processnumber < number;Processnumber++)
	{
		printf("\nProcess P%d\n",Processnumber+1);
		printf("Please enter the Arrival time: ");
		scanf("%d",&arrivalT[Processnumber]);
		printf("Please enter the Burst time: ");
		scanf("%d",&burstT[Processnumber]);
		remainingT[Processnumber]=burstT[Processnumber];
	}
	printf("Time Quantum (First-Pass):3\n");
	timequantum=3;
	CurrentT=0;
	for(Processnumber=0;RemainingProcess!=0;)
	{
		if(remainingT[Processnumber]<=timequantum && remainingT[Processnumber]>0)
		{
			CurrentT+=remainingT[Processnumber];
			remainingT[Processnumber]=0;
			indicator=1;
		}
		else if(remainingT[Processnumber]>0)
		{
			remainingT[Processnumber]-=timequantum;
			CurrentT+=timequantum;
		}
		if(remainingT[Processnumber]==0 && indicator==1)
		{ printf("%d",Processnumber);
			RemainingProcess--;
			printf("P %d",Processnumber+1);
			printf("\t\t\t%d",CurrentT-arrivalT[Processnumber]);
			printf("\t\t\t%d\n",CurrentT-burstT[Processnumber]-arrivalT[Processnumber]);
			wait+=CurrentT-arrivalT[Processnumber]-burstT[Processnumber];
			turnaroundtime+=CurrentT-arrivalT[Processnumber];
			indicator=0;

		}
		if(Processnumber==number-1){
			x++;
			if(x==2){
				Processnumber=0;
				timequantum=6;

				printf("Time Quantum (Second-Pass): 6. \n");
			}
			else{
				break;
			}
		}
		else if(CurrentT >= arrivalT[Processnumber+1]){
			Processnumber++;
		}
		else{
			Processnumber=0;
		}
	}

	roundrobin(arrivalT,burstT,number,remainingT,CurrentT);

	return 0;
}


void roundrobin(int arrivalT[10], int burstT[10],int number,int remainingT[10],int CurrentT){

	float averagewait,averagetutime;
    int a,b,n=number,temp,btime[20],Processnumber[20],wtime[20],turnaroundtime[20],total=0,loc;

    printf("Third-Pass (Least Execution Time):\n");

    for(a=0;a<n;a++)
    {
        btime[a]=remainingT[a];
        wtime[a]=CurrentT-arrivalT[a]-btime[a];
		Processnumber[a]=a+1;
    }

    for(a=0;a<n;a++)
    {
        loc=a;
        for(b=a+1;b<n;b++)
        {
            if(btime[b]<btime[loc]){
            	loc=b;
            }
        }
        temp=btime[a];
        btime[a]=btime[loc];
        btime[loc]=temp;
        temp=Processnumber[a];
        Processnumber[a]=Processnumber[loc];
        Processnumber[loc]=temp;
    }

    for(a=1;a<n;a++)
    {
        for(b=0;b<a;b++){
        	wtime[a]+=btime[b];
        }
        total+=wtime[a];
    }

    averagewait=(float)total/n;
    total=0;
    printf("\nProcess Number\t\tTurnaround Time\t\tWaiting Time\t\tBurst Time");
    for(a=0;a<n;a++)
    {
        turnaroundtime[a]=btime[a]+wtime[a];
        total=total + turnaroundtime[a];
        printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t%d",Processnumber[a],turnaroundtime[a],wtime[a],btime[a]);
    }
    averagetutime=(float)total/n;
    printf("\n\n The Average waiting time for the given problem is: %f",averagewait);
    printf("\n While the Average turnaround time for the given problem is: %f\n",averagetutime);

}
