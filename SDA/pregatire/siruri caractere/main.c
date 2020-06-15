#include <stdio.h>
#include <stdlib.h>

//-------------KMP---------------------//

int mmax;   //{lungime maxima model}
int nmax;   //{lungime maxima sir sursa}
char m[mmax],n[nmax]; //model si sursa
void preKmp( char* pattern , int pattern_length, int kmpNext[] )
 {
     int i , j;
     i = 0;
     j = -1;
     kmpNext[ 0 ] = -1;
     while ( i < pattern_length )
     {
         while ( j > -1 && pattern[ i ] != pattern[ j ] )
             j = kmpNext[ j ];
         i++;
         j++;
         if ( pattern[ i ] == pattern[ j ] )
             kmpNext[ i ] = kmpNext[ j ];
         else
             kmpNext[ i ] = j;
     }
 }
 void knuth_morris_pratt( char* pattern , int pattern_length , char* source , int source_length )
 {
     int i , j;
     int kmpNext[ 1024 ]; // tabloul kmpNext trebuie sa aiba cate o intrare pentru fiecare caracter al modelului
     /* Faza de precompilare a modelului */
     preKmp( pattern , pattern_length , kmpNext );
     /* Faza de cautare propriu-zisa */
     i = 0;
     j = 0;
     while ( j < source_length )
     {
         while ( i > -1 && pattern[ i ] != source[ j ] )
             i = kmpNext[ i ];
         i++;
         j++;
         if ( i >= pattern_length )
         {
             printf( "Gasit la pozitia %d\n" , j - i );
             i = kmpNext[ i ];
         }
     }
 }
//-------------KMP---------------------//

//------------Boyer------------------//

int mmax;   //{lungime maxima model}
int nmax;   //{lungime maxima sir sursa}
char m[mmax],n[nmax]; //model si sursa

void preBm( char* pattern , int pattern_length , int bmNext[] )
 {
     int i;
     for ( i = 0 ; i < 256 ; i++ )
         bmNext[ i ] = pattern_length;
     for ( i = 0 ; i < pattern_length - 1 ; i++ )
         bmNext[ pattern[ i ] ] = pattern_length - i - 1;
 }
 void boyer_moore( char* pattern , int pattern_length , char* source , int source_length )
 {
     int i , j;
     int bmNext[ 256 ];
    /* Faza de precompilare a modelului */
     preBm( pattern , pattern_length , bmNext );
    /* Faza de cautare propriu-zisa */
     j = 0;
     while ( j <= source_length - pattern_length )
     {
         for ( i = pattern_length - 1 ; i >= 0 && pattern[i] == source[ i + j ] ; i-- );
         if ( i < 0 )
         {
             printf( "Gasit la pozitia %d\n" , j );
             if (j==0)
              {
               j=1;
              }
              else
               j += bmNext[ source[ i + j ] ];
         }
         else
             j += bmNext[ source[ i + j ] ];
     }
 }
//------------Boyer------------------//








int main()
{
    printf("Hello world!\n");
    return 0;
}
