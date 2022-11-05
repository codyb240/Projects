/*------------------------------------------------
Programmer:		Cody Bruehl
Professor:		Zhao
Date:			11/13/2021
Purpose:
The purpose of this program is to generate the AWT
and ATT of the numbers within a randomly generated
array.
------------------------------------------------*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>
#include<semaphore.h>
#define MAX_CUSTOMERS 25	//max customers allowed

void *customer(void *num);

void *barber(void *);

void randwait(int secs);

sem_t Lobby;	//Handle customers from Lobby

sem_t barberChair;	//Handle access to the chair of the barber

sem_t barberSleep;	//Handles length of barber sleep

sem_t Seated;		//Handles customer being in chair of barber until haircut is done

int NoMore = 0;		//Handles stopping the barber when all customers are gone

int main(int argc, char *argv[]){								
	
	pthread_t btid;
	pthread_t tid[MAX_CUSTOMERS];
	long RandSeed;
	int i, numCustomers, numChairs;
	int Number[MAX_CUSTOMERS];

	printf("Enter number of Customers : "); 
	scanf("%d",&numCustomers);
	printf("Enter number of Chairs : "); 
	scanf("%d",&numChairs);

	if(numCustomers > MAX_CUSTOMERS)
	{
		printf("The max Customers is %d.\n", MAX_CUSTOMERS);
		exit(-1);
	}

	for(i=0; i<MAX_CUSTOMERS; i++)
	{
		Number[i] = i;
	}

	sem_init(&Lobby, 0, numChairs);		//start semaphore
	sem_init(&barberChair, 0, 1);
	sem_init(&barberSleep, 0, 0);
	sem_init(&Seated, 0, 0);

	pthread_create(&btid, NULL, barber, NULL);	//create barber thread

	for(i=0; i<numCustomers; i++)	//create customers
	{
		pthread_create(&tid[i], NULL, customer, (void *)&Number[i]);
		sleep(1);
	}

	for(i=0; i<numCustomers; i++)
	{
		pthread_join(tid[i],NULL);
		sleep(1);
	}

	NoMore = 1;		//stop barber
	sem_post(&barberSleep);	//Wake barber 
	pthread_join(btid,NULL);
}																

void *customer(void *number)
{
	int num = *(int *)number;

	printf("Customer %d leaving for barber shop.\n", num);		//customer's random time for arrival at barber
	randwait(2);
	printf("Customer %d arrived at barber shop.\n", num);

	sem_wait(&Lobby);	//wait for seat in lobby
	printf("Customer %d entering waiting room.\n", num);

	sem_wait(&barberChair);		//wait for barber chair

	sem_post(&Lobby);	//leave lobby to get haircut

	printf("Customer %d waking the barber.\n", num);	//wake barber
	sem_post(&barberSleep);

	sem_wait(&Seated);	//stop here until haircut finishes

	sem_post(&barberChair);		//leave barber shop
	printf("Customer %d leaving barber shop.\n", num);
}																	

void *barber(void *junk)
{
	while(!NoMore)	//customers still around
	{
		printf("The barber is sleeping\n");		//barber sleep until customer comes
		sem_wait(&barberSleep);

		if(!NoMore)
		{
			printf("The barber is cutting hair\n");		//do the haircut in a random amount of time
			randwait(2);
			printf("The barber has finished cutting hair.\n");

			sem_post(&Seated);	//customer leaves
		}else	//no more customers
		{
			printf("Barber goes home for the day.\n");
		}
	}
}

void randwait(int secs)
{
	int len;
	
	len = (int) ((1 * secs) + 1);	//generate random wait time
	sleep(len);
}
