/* SYSC 2006 Summer 2019 Lab 11. */

#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "recursive_functions.h"

/* Return x raised to the power n for n >= 0. */
double power(double x, int n)
{
	if(n == 0){
		return 1;
	}
	
	return x * power(x,n-1);
}

/* Return the count of the number of times target occurs in the first 
 * n elements of array a.
 */
int count(int a[], int n, int target)
{
	int counter = 0;
	if(n==0){
		return counter;
	}

	counter = count(a,n-1,target);

	if (target == a[n-1]){
		counter++;
	}
	return counter;

}

/* Return the count of the number of times target occurs in the 
 * linked list pointed to by head. 
 */
int occurrences(node_t *head, int target)
{
	int counter;
	if (head == NULL) {
      return 0;
    }

	counter = occurrences(head->next,target);
	
	if(target == head->data){
		counter++;
	}
    return counter;
}

/* Return the last element in the linked list pointed to by head.
 * Terminate (via assert) if the list is empty.
 */
int last(node_t *head)
{
    if (head->next == NULL) {
      return head->data;
    }


	return last(head->next);

}

/* Extra-practice exercises. */

/* Return the number of digits in integer n, n >= 0. */
int num_digits(int n)
{
	int counter;
	if(n < 10){
		return 1;
	}

	counter = 1 + num_digits(n / 10);


    return counter;
}

/* Return x raised to the power n for n >= 0. */
double power2(double x, int n)
{
	printf("x = %.1f, n = %d\n", x, n);
	if(n == 0){
		return 1;
	}

	if(n % 2 == 0){
		return  power2(x,n/2) * power2(x,n/2);
	} else {
		return x * power2(x,n/2) * power2(x,n/2);
	}
    
}
