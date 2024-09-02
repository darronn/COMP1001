/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/


#include <stdio.h> //this library is needed for printf function
#include <stdlib.h> //this library is needed for rand() function
#include <windows.h> //this library is needed for pause() function
#include <time.h> //this library is needed for clock() function
#include <math.h> //this library is needed for abs()


void init();
void q1();


#define N 256 //input size
float A[N][N], B[N][N], C[N][N] ;


int main() {

	//define the timers measuring execution time
	clock_t start_1, end_1; //ignore this for  now

	init();//initialize the arrays

	start_1 = clock(); //start the timer 


	q1(); //main routine
		

	end_1 = clock(); //end the timer 

	printf(" clock() method: %ldms\n", (end_1 - start_1) / (CLOCKS_PER_SEC / 1000));//print the ex.time
	
	system("pause"); //this command does not let the output window to close

	return 0; //normally, by returning zero, we mean that the program ended successfully. 
}


void init() {

	float e = 0.1234f, p = 0.7264f;//if you do not specify the 'f' after 0.0, then double precision data type is assumed (not float which single precision). 

	//MVM
	for (unsigned int i = 0; i < N; i++)
		for (unsigned int j = 0; j < N; j++){
			A[i][j] = ((i - j) % 9) + p;
			B[i][j] = ((i + j) % 11) + e;
			C[i][j] = 0.0f;
			}

}



void q1() {

	for (int i = 0; i < N; i++) 
	 for (int j = 0; j < N; j++) 
	  for (int k = 0; k < N; k++) 
	    C[i][j] += A[i][k] * B[k][j];
	

}

