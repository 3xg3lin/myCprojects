#include <stdio.h>

double calc( double operand1 , double operand2 , char operator) {
    double result = 0.0;

    printf( "%g %c %g = " , operand1 , operator , operand2 );

    if ( operator == '+' )
        result = operand1 + operand2;
    else if ( operator == '-' )
        result = operand1 - operand2;
    else if ( operator == '*' )
        result = operand1 * operand2;
    else if (operator == '/')
        if (operand2 == 0.0){
            printf( "*** ERROR *** division by %g is undefined.\n", operand2 );
            return result;
        }
        else {
            result = operand1 / operand2;
        }
    else if ( operator == '%')
        result = (int) operand1 % (int) operand2;
    else {
        printf( "*** ERROR *** unknown operator; operator must be + - * / or %%\n" );
        return result;
    }
    printf( "%g\n" , result );
    return result;
}

int main() {

    calc( 1.0 , 2.0 , '+' );
    calc( 10.0 , 7.0 , '-' );
    calc( 4.0 , 2.3 , '*' );
    calc( 5.0 , 0.0 , '/' );
    calc( 5.0 , 2.0 , '%' );
    calc( 1.0 , 2.0 , '?' );

    return 0;
}
