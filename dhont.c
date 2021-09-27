#include <stdio.h>
#include "hw5_lib.h"
#include <math.h>
#include <stdlib.h> //for exit function
void dhondt_method (int* partyA, int* partyB, int* partyC, int* partyD, int* partyE, int numberOfSeats)
{
	int i=0;
	int a= *partyA;
	int b= *partyB; /* assing the number of seats */
	int c= *partyC;
	int d= *partyD;
	int e= *partyE;
	int count_a=0;
	int count_b=0; /*number of seats for each party */
	int count_c=0;
	int count_d=0;
	int count_e=0;
	int divide_a=2,divide_b=2,divide_c=2,divide_d=2,divide_e=2; /* dividers */
	int max;
	int new_a=a;
	int new_b=b; /*stored number of vote */
	int new_c=c;
	int new_d=d;
	int new_e=e;
	max=compareNumbs(a,b,c,d,e);
	while(i<=numberOfSeats){ 
		max=compareNumbs(new_a,new_b,new_c,new_d,new_e); /* take the numbers and compare and find the max number */
		if(i==numberOfSeats){ /* if the number of seats are equal than break */
			break;
		}
	if(new_a==max&& i<=numberOfSeats){
		new_a=a/divide_a;
		divide_a++;
		count_a++; 	/* dividing the number of votes at each iteration then icrement i*/
		i++;	
	}
	if(new_b==max && i<=numberOfSeats){
		new_b=b/divide_b;
		divide_b++;
		count_b++;
		i++;
	
	}
	if(new_c==max&& i<=numberOfSeats){
		new_c=c/divide_c;
		divide_c++;
		count_c++;
		i++;
		
	}
	if(new_d==max&& i<=numberOfSeats){
		new_d=d/divide_d;
		divide_d++;
		count_d++;
		i++;
	}
	if(new_e==max&& i<=numberOfSeats){
		new_e=e/divide_e;
		divide_e++;
		count_e++;
		i++;
		}
	}	
	*partyA=count_a;
	*partyB=count_b; 
	*partyC=count_c;
	*partyD=count_d; /* assign the last valeus */
	*partyE=count_e;
}
