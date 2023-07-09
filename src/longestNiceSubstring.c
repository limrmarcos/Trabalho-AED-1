#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * longestNiceSubstring( char * s );

int main( void )
{
    char string[100], *result, *s;

    printf( "Digite a palavra desejada: " );
    scanf( "%s", string );

    s = ( char * ) malloc ( strlen( string ) * sizeof( char ) );

    strncpy(s, string, strlen( string ) ); 

    result = longestNiceSubstring( s );

    for( int i = 0; i < strlen( result ); i++ ) {
        printf( "%c", string[i] );
    }
    printf( "\n" );

    free( s );
}

char * longestNiceSubstring( char * s ) {
    char * temp = malloc ( strlen( s )* sizeof( char ) );
    int x = 0;

    for( int i = 0; i < strlen( s ); i++ ) {
        switch( s[i] ) {
            case 'a':
                for( int j = i + 1; j < ( strlen( s ) - i ); j++ ) {
                    if ( s[j] == 'A' ) {
                        temp[x] = 'a'; x++;
                        temp[x] = 'A'; x++;
                        if( s[j + 1] == 'a' ) {
                            temp[x] = 'a'; x++;
                        } else if (s[j + 1] == 'A') {
                            temp[x] = 'A'; x++;
                        }
                    }
                }
                break;
            case 'b':
                for( int j = i + 1; j < ( strlen( s ) - i ); j++ ) {
                    if ( s[j] == 'B' ) {
                        temp[x] = 'b'; x++;
                        temp[x] = 'B'; x++;
                        if( s[j + 1] == 'b' ) {
                            temp[x] = 'b'; x++;
                        } else if (s[j + 1] == 'B') {
                            temp[x] = 'B'; x++;
                        }
                    }
                }
                break;


        }
    }
    strcpy( s, temp );

    free( temp );

    return s;
}

/* O switch case não parece ser uma ideia funcional (ou ao menos não a maneira que fiz). 
Se as letras estão próximas, literalmente na próxima posição, lê corretamente, contudo
no caso de a letra estar em posições mais além (como aBA), pega a letra imediatamente a seguir.
*/