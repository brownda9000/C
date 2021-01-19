/*************************************************************
Author : David Brown
Description: Narcissistic Number
Version :
Date:
**************************************************************/
#include <stdio.h>
#include <strings.h>
#include <math.h>

int power( int x, int pow ) {
    int num=x,i;
	
	for (i=1; i < pow; i++)
		num = num * x;
	
	return num;	
}

int special_num( int num ) {
// Special number 
    int number=num, rem;
	int acc=0;
	int result = 0 ; // 0 equals number is not a ...

    while ( number > 0 ) {
     	rem = number % 10; // get left most digit of number
		
        acc = acc + power(rem,5); // add this digit to the power of 3 to an accumalator
        
		number = number / 10 ; // move digits ine place to the left
		
    }
	
	if ( num == acc ) result = 1;
 
    return result; 

}

int main()
{
    int i;

    //printf("Enter a number: \n");
    //scanf("%d", &num);
	
	for (i=0; i < 100000000;  i++ ) {
		if ( special_num(i) ) printf("%d is a special number\n",i);
	}
	
	
	
	

   return 0;
}
