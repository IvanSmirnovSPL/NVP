/*
 * io.cc
 *
 * ‘ункции ввода/вывода.
 *
 * (c) ”ткин ѕавел, 2012
 *
 * —оздан: 25 марта 2012 г.
 *
 */

#include <stdio.h>

#include "io.h"
#include "utils.h"

/* «апись решени€ в файл
   xc[N] - координаты центров €чеек (in)
   v_cons[N][M] - вектора консервативных переменных в центрах €чеек (in)
   time - момент времени, которому соответствуют распределени€ (in) */
void write_solution( double xc[N], double v_cons[N][M], double time ) {

    char file_name[MAX_FILE_NAME];
    FILE *f_out;
    double v_ncons[M];
    int i, j;

    sprintf_s( file_name, "../../front/exp/solution.dat" ); 

    fopen_s( &f_out, file_name, "wt" );
    if ( NULL == f_out ) {
        printf( "Error - can't open file %s for writing.\n" );
    }

    for ( i = 0; i < N; i++ ) {
        fprintf( f_out, "%e", xc[i] );
        convert_cons_to_noncons( v_cons[i], v_ncons );
        for ( j = 0; j < M; j++ )
            fprintf( f_out, " %e", v_ncons[j] );
        fprintf( f_out, " %e", v_ncons[2] / v_ncons[0] / ( GAMMA - 1.0 ) );
        fprintf( f_out, "\n" );
    }

    fclose( f_out );

}