#include "array.h"
int isNumber(const char* A) {
        int N=0;
            //char *x=A;
                int len=sizeof(A)/sizeof(char);
                    /*while(*A) {
                                len++;
                                        A++;
                                            }*/

                        int i,j=0,flag=0,z=0;
                            for(i=0;i<len;++i) {
                                        if(A[i] == ' ') {
                                                        if(z) {
                                                                            if(A[i+1] != ' ') return 0;
                                                                                            else continue;
                                                                                                        }else continue;
                                                                }
                                                if(A[i] == '-' || A[i] == '+') {
                                                                if(!flag) {
                                                                                    flag=1;
                                                                                                    continue;
                                                                                                                }else return 0;
                                                                        }
                                                        if(A[i] == '0') { 
                                                                        if(A[i+1]) {
                                                                                        if( A[i+1]<'0' || A[i+1]>'9') {
                                                                                                            if(A[i+1] == ' ' ) {z=1;continue;}
                                                                                                                            else if(A[i+1] == '.') {z=1;continue;}
                                                                                                                                            else return 0;
                                                                                                                                                        }else z=1;
                                                                                                    }
                                                                                    z=1;continue;
                                                                                            }
                                                                if(A[i] == '.') {
                                                                                if(!j) {
                                                                                                    j=1;
                                                                                                                    continue;
                                                                                                                                }else return 0;
                                                                                        }if(A[i]>= '0' && A[i] <= '9') {
                                                                                                        if(A[i+1]){
                                                                                                                        if(A[i+1]<'0' || A[i+1]>'9') {
                                                                                                                                            if(A[i+1] == ' ' ) {z=1;continue;}
                                                                                                                                                            else if(A[i+1] == '.') {z=1;continue;}
                                                                                                                                                                            else return 0;
                                                                                                                                                                                        }else z=1;
                                                                                                                             }
                                                                                                                    z=1;
                                                                                                                            }
                                                                            
                                                                    }
                                if(z) return 1;
                                    return 0;
}
                                                                                                                                        
int main() {
    char *str = "0";
    cin>>str;
    cout<<isNumber(str) <<endl;
    return 0;
}
