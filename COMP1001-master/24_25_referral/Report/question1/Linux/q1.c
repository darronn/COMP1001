/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/



#include <stdio.h> //this library is needed for printf function
#include <stdlib.h> //this library is needed for rand() function
#include <time.h> //this library is needed for clock() function
#include <math.h> //this library is needed for abs()


void init();
void q1();


#define N 128 //input size
float sum[N][N][N],A[N][N][N],C[N][N];


int main() {

	//define the timers measuring execution time
	clock_t start_1, end_1; //ignore this for  now

	init();//initialize the arrays

	start_1 = clock(); //start the timer 

	q1(); //main routine
		

	end_1 = clock(); //end the timer 

	printf(" clock() method: %ldms\n", (end_1 - start_1) / (CLOCKS_PER_SEC / 1000));//print the ex.time

	
	return 0; //normally, by returning zero, we mean that the program ended successfully. 
}



void init() {

float e = 0.121f, p = 0.721f;//if you do not specify the 'f' after 0.0, then double precision data type is assumed (not float which single precision). 
unsigned int i,j,k;
	
	for ( i = 0; i < N; i++) { 
		for (j = 0; j < N; j++) {
			C[i][j] = (j % 9) + p; 
		}
	}
	   
	for ( i = 0; i < N; i++) { 
		for (j = 0; j < N; j++) {
                  for (k = 0; k < N; k++) {
			sum[i][j][k] = 0.0f; 
			A[i][j][k]= ( ((i+j)%99) +e);
		}
		}
	      }
}



void q1() {

int r,q,s,p;

  for (r = 0; r < N; r++)
    for (q = 0; q < N; q++)  
      for (s = 0; s < N; s++)
       for (p = 0; p < N; p++)  
	  sum[r][q][p] = sum[r][q][p] + A[r][q][s] * C[s][p];
	

}

