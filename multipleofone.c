#include<stdio.h>
#include<stdlib.h>

void  print_multiple_of_all_ones(int num)
{
        int count=1,rem=1;

            while(rem)
                    {
                                rem = ( rem*10 + 1 ) % num;
                                        count++;
                                            }

                while(count--)
                            printf("1");

                    printf("\n");
}

int main()
{
        int num;
            scanf("%d",&num);
                print_multiple_of_all_ones(num);
                    return 0;
}
