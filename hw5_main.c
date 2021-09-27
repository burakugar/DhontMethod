/*
** main.c:
**
** The test/driver program for the homework.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.04.02.23.55
** 
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "hw5_lib.h"


void test_operate_polynomials () 
{
	char op;
	double a3=0,a2=0,a1=0,a0=0,b3=0,b2=0,b1=0,b0=0; /*taking the coefficients from the user */
	int d;
	char t;
	int temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8;
	printf("Enter the operator:");
	op=getc(stdin);
	t=getc(stdin);
	printf("Enter first polynomial's coefficients:");
	scanf("(%d,%lf),(%d,%lf),(%d,%lf),(%d,%lf)",&temp1,&a3,&temp2,&a2,&temp3,&a1,&temp4,&a0);
	/*getting the coefficients from the user */
	check_input(&temp1,&a3,&temp2,&a2,&temp3,&a1,&temp4,&a0);
	printf("Enter second polynomial's coefficients:");
	scanf("%d",&d);
	scanf("(%d,%lf),(%d,%lf),(%d,%lf),(%d,%lf)",&temp5,&b3,&temp6,&b2,&temp7,&b1,&temp8,&b0);
	check_input(&temp5,&b3,&temp6,&b2,&temp7,&b1,&temp8,&b0);
	operate_polynomials(&a3,&a2,&a1,&a0,&b3,&b2,&b1,&b0,op);
}


void test_four_d_vectors ()
{
	double mean_a0=0.0, mean_a1=0.0, mean_a2=0.0, mean_a3=0.0, longest_distance=0.0;
	int N=5;
	four_d_vectors (&mean_a0, &mean_a1, &mean_a2, &mean_a3, &longest_distance, N);
	printf("Mean a0: %f\nMean a1: %f\nMean a2: %f\nMean a3: %f\nThe longest distance between two points: %f\n\n\n", mean_a0, mean_a1, mean_a2, mean_a3, longest_distance);
}


void test_dhondt_method ()
{
	int partyA=1000, partyB=2000, partyC=3000, partyD=4000, partyE=5000, numberOfSeats=40;
	dhondt_method (&partyA, &partyB, &partyC, &partyD, &partyE, numberOfSeats);
	printf("Party A: %d seat(s).\nParty B: %d seat(s).\nParty C: %d seat(s).\nParty D: %d seat(s).\nParty E: %d seat(s).\n\n\n", partyA, partyB, partyC, partyD, partyE);
}


void test_order_2d_points_cc ()
{
	double x1,x2,x3,y1,y2,y3;	
	printf("\nEnter the first point's coordinates (first x second y):");
	scanf("%lf %lf",&x1,&y1);
	printf("Enter the second point's coordinates (first x second y):");
	scanf("%lf %lf",&x2,&y2);
	printf("Enter the third point's coordinates (first x second y):");
	scanf("%lf %lf",&x3,&y3);
	order_2d_points_cc (&x1, &y1, &x2, &y2, &x3, &y3);
	printf("Counter-Clockwise Order: (%f,%f) - (%f,%f) - (%f,%f)\n\n\n", x1, y1, x2, y2, x3, y3);
}


void test_number_encrypt ()
{
	printf("\nPlease enter the number will be encrypted: ");
	unsigned char number;
	scanf("%hhu",&number); /*taking the number will be encrypted */
	number_encrypt (&number);
}


/*
** main function for testing the functions...
**
*/
int main(void) {
	test_operate_polynomials ();
	test_four_d_vectors ();
	test_dhondt_method ();
	test_order_2d_points_cc ();
	test_number_encrypt (); /*sometimes it gives error when taking the input since it has in the last order you could try with itself alone (it maybe occurs because of stdin is not empty i guess but sometimes it does not give errors */
	return (0);
} /* end main */
