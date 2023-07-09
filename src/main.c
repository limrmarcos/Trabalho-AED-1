#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

char * longestNiceSubstring( char * s );
bool noUpperCase( char * s );
bool noLowerCase( char * s );

int main( void ) {
    char s[100];
    printf( "Digite a palavra: " );
    scanf( "%s", s );

    char * result = longestNiceSubstring( s );

    printf( "%s", result );
    free( result );
}

char * longestNiceSubstring( char * s ) {
    if( noLowerCase( s ) || noUpperCase( s ) ) {
        char *i = malloc ( sizeof( char ) * 3 );
        i[0] = 34;
        i[1] = 34;
        i[2] = '\0';
        return i;
    }

    char * aux = ( char * ) malloc ( strlen( s ) + 1 );
    char * temp = NULL;

    for( int i = 0; i < strlen( s ); i++ ) {
        for( int j = i + 1; j < strlen( s ); j++ ) {
            bool isNice = true;
            int length = j - i + 1;
            strncpy( aux, &s[i], length );
            aux[length] = '\0';

            for( int k = i; k < j; k++ ) {
                if( islower( s[k] ) && !strchr( s, toupper( s[k] ) ) ) {
                    isNice = false;
                    break;
                }
                if( isupper( s[k] ) && !strchr( s, tolower( s[k] ) ) ) {
                    isNice = false;
                    break;
                }
            }  

            if( isNice ) {
                if (temp == NULL || strlen(aux) > strlen(temp)) {
                    if (temp != NULL) {
                        free(temp);
                    }
                    temp = (char *)malloc(strlen(aux) + 1);
                    strcpy(temp, aux);
                }
            }
        }
    }
    free(aux);
    return temp;
}

bool noLowerCase( char * s ) {
    for( int i = 0; i < strlen( s ); i++ ) {
        if( !islower( s[i] ) ) {
            return false;
        }
    }
    return true;
}

bool noUpperCase( char * s ) {
    for( int i = 0; i < strlen( s ); i++ ) {
        if( !isupper( s[i] ) ) {
            return false;
        }
    }
    return true;
}