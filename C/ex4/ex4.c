#include<stdio.h>
int main()
{
   long int num,rem,reverse_num=0;

   //Input number
   printf("\nEnter any number:");
   scanf("%li",&num);

   while (num>=1)
   {
      rem = num % 10;
      reverse_num = reverse_num * 10 + rem;
      /*printf("Reverse number is : %li\n", reverse_num);
      printf("Number is : %li\n", num); */
      num = num / 10;
   }

   printf("\nReverse of input number is: %li\n", reverse_num);
   return 0;
}
