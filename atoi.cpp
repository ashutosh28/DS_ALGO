#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main( void )
    {      
    char    *str = NULL;
    int     value = 0;

    // An example of the atoi function.
    str = "  -2309 ";
    value = atoi( str );
    printf( "Function: atoi( \"%s\" ) = %d\n", str, value );
    //
    //                 // Another example of the atoi function.
    str = "31412764";
    value = atoi( str );
    printf( "Function: atoi( \"%s\" ) = %d\n", str, value );

    // Another example of the atoi function 
    // with an overflow condition occuring.
    str = "3336402735171707320";
    value = atoi( str );
    printf( "Function: atoi( \"%s\" ) = %d\n", str, value );
    
    scanf("%s\n",str);
    value = atoi( str );
    printf( "Function: atoi( \"%s\" ) = %d\n", str, value );
    
    if (errno == ERANGE)
    {
    printf("Overflow condition occurred.\n");
    }
            }
