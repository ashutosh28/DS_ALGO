#include<stdio.h>
#include<stdlib.h>
/**
 *  * @input A : Integer
 *   * 
 *    * @Output Integer 0 / 1. Return 0 if the number is not palindrome, else return 1
 *     */


int (*funcArr2[10])(float,char,char) = {NULL};
int isPalindrome(int A) {
        int number=0;
            int temp=A;
                while(temp!=0)
                        {
                                    number= number*10;
                                            number= number + temp%10;
                                                    temp= temp/10;
                                                        }
                    if(number==A) return 1;
                        else return 0;
}
int main()
{
    printf("%d",isPalindrome(-2147447412));
    return 0;
}
