#include<stdio.h>
#include<stdlib.h>
/**
 *  * @input A : String termination by '\0'
 *   * 
 *    * @Output Integer
 *     */

#define max 1000003
void swap(char *a,char *b)
{
        *a=*a^*b;
            *a =*a^*b;
                *b=*a^*b;
}
int partition(char *A,int s,int l);
void quicksort(char *A,int s,int l)
{
        if(s<l)
                {
                            int p=partition(A,s,l);
                                    quicksort(A,s,p-1);
                                            quicksort(A,p+1,l);
                                                }
}
int partition(char *A,int s,int l)
{
        int x=s-1;
            int y = A[l];
                int i;
                    for(i=s;i<l;++i)
                            {
                                        if(A[i]<=y)
                                                    {
                                                                    x++;
                                                                                swap(&A[x],&A[i]);
                                                                                        }
                                            }
                        swap(&A[x+1],&A[l]);
                            return x+1;
}
static int g=0;
char **hashtable=(char**)malloc(max*sizeof(char*));
void permutation(char *A,int s,int l)
{
        int i;
            if(s==l)
                    {
                                hashtable[g]=(char*)malloc((l+1)*sizeof(char));
                                        int j;
                                        for(j=0;j<=l;++j)
                                        {
                                            hashtable[g][j]=A[j];
                                        }
                                        printf("%s\n %s\n",hashtable[g],A);
                                        g++;
                                            }else{
                                                        for(i=s;i<=l;++i){
                                                                    swap((A+l),(A+i));
                                                                            permutation(A,s+1,l);
                                                                                    swap((A+l),(A+i));
                                                                                            }
                                                            }
                
}
int compare(char *A,char *B,int len)
{
        int i;
            for(i=0;i<=len;++i)
                    {
                                if(A[i]!=B[i]){
                                                return 0;
                                                        }
                                    }
                return 1;
}
int findRank(char* A) {
        int len=0;
            char *temp=A;
                while(*temp){
                            len++;
                                    temp++;
                                        }
                    char *a=(char*)malloc(len*sizeof(char));
                        int j;
                            for(j=0;j<len;j++){
                                        a[j]=A[j];
                                            }
                                quicksort(a,0,len-1);
                                printf("%s",a);
                                    permutation(a,0,len-1);
                                        int i=0;
                                           /* do
                                                    {
                                                                int kl=compare(hashtable[i],A,len-1);
                                                                           if(kl) {
                                                                                break;
                                                                                       //     return (i+1)%1000003;
                                                                                                    }
                                                                  }while(++i);*/
                                       /* for(i=0;i<5;i++)
                                        {
                                        printf("%s\n",hashtable[i]);
                                        }*/
                                            
                                                                                            return (i+1)%1000003;
}
int main()
{
    char A[]="ACB";
    printf("%d",findRank(A));
    return 0;
}
