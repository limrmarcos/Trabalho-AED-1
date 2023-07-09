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

    for( int c = 0; c < strlen( s ); c++ ) {
        for( int co = c + 1; co < strlen( s ); co++ ) {
            bool isNice = true;
            int length = co - c + 1;
            strncpy( aux, &s[c], length );
            aux[length] = '\0';

            for( int con = c; con < co; con++ ) {
                if( islower( s[con] ) && !strchr( s, toupper( s[con] ) ) ) {
                    isNice = false;
                    break;
                }
                if( isupper( s[con] ) && !strchr( s, tolower( s[con] ) ) ) {
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