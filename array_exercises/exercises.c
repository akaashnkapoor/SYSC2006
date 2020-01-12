/* SYSC 2006 Winter 2019 Lab 3. 

 * Incomplete implementations of the functions that will be coded during the lab.
 */

#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "exercises.h"

/* Exercise 1. */

/* Return the average magnitude of the signal represented by
 * the n doubles in arr[].
 * This function assumes that parameter n is >= 1.
 */
double avg_mag(double arr[], double n)
{
	int counter = 0;//Initialize counter.
	double sum = 0;
	for (; counter < n; counter++)
	{
		sum = sum + fabs(arr[counter]);
	}
	return sum / n;
}

/* Exercise 2. */

/* Return the average power of the signal represented by
 * the n doubles in arr[].
 * This function assumes that parameter n is >= 1.
 */
double avg_pow(double arr[], double n)
{
	int counter = 0;
	double sum = 0;
	for (; counter < n; counter++)
	{
		sum = sum + pow(arr[counter], 2);
	}

	return sum / n;
}

/* Exercise 3. */

/* Return the largest of the n doubles in arr[]. 
 * This function assumes that parameter n is >= 1.
 */
double max(double arr[], int n)
{
	int MAX;
	int counter = 0;
	for (; counter < n; counter++)
	{

		if (counter == 0)//When the loop starts, initialize the Max value first. 
		{
			MAX = arr[counter];
		}
		else if (arr[counter] > MAX)//Checks if new value is greater than the Max value. 
		{
			MAX = arr[counter];
		}
	}
	return MAX;
}

/* Exercise 4. */

/* Return the smallest of the n doubles in arr[]. 
 * This function assumes that parameter n is >= 1.
 */
double min(double arr[], int n)
{
	int MIN;
	int counter = 0;
	for (; counter < n; counter++)
	{

		if (counter == 0)
		{
			MIN = arr[counter];//Function is similar to max with small changes.
		}
		else if (arr[counter] < MIN)
		{
			MIN = arr[counter];
		}
	}
	return MIN;
}

/* Exercise 5. */

/* Normalize the n doubles in arr[].
 * This function assumes that parameter n is >= 2, and that at least
 * two of the values in arr[] are different.
 */
void norm(double arr[], int n)
{
	int MIN = min(arr, n);//Find the min value of the array
	int MAX = max(arr, n);//Find the max value of the array. 
	int counter = 0;

	for (; counter < n; counter++)
	{
		arr[counter] = (arr[counter] - MIN) / (MAX - MIN);//Replaces the values in array with corresponding normalized values. 
	}
			
}
