/*
 * main.cc
 *
 * ��������� ��� ������������ ��������� ������� ������� �������
 * ��� ������� ���������� ����� ������� ��������.
 *
 * (c) ����� �����, 2012
 *
 * ������: 27 ������ 2012 �.
 *
 */

#include "main.h"

/* ����� ��� ���� ������� ������� */
#include "grid.h"
#include "utils.h"
#include "io.h"

int main( void ) {

    int i, j;
    double x[N+1];                                  /* ������ ��������� ����� ����� */
    double xc[N];                                   /* ������ ��������� ������� ����� ����� */
    double u_prev[N][M];                            /* ������� �������������� ���������� �� n-�� ���� */
    double u_next[N][M];                            /* ������� �������������� ���������� �� (n+1)-�� ���� */
    double boun_v[M];                               /* ������ �������������� ���������� ��� ���������� ���������� ������� */					
    double flux_left[M], flux_right[M];             /* ������ ����� ����� ��������� ������ */
    double dt;                                      /* ��� �� ������� */						
    int steps_num = 0;                              /* ������� ����� ����� */
    double curr_t = 0.0;                            /* ������� ����� */

    /* ����������� ��������� ����� ����� */
    build_grid( x, xc );

    /* ������������� �������-������� */
    init_solution( u_prev );

    /* �������� ���� �� ������� */
    while ( T_END - curr_t > 0 ) {

        dt = calc_time_step( x, u_prev, steps_num );
        double dx = 1. / N;

        /* ���� �� ������� */
	for ( i = 0; i < N; i++ ) {

            /* ������ ������ ����� ����� ����� ������ */
            if ( i != 0 )
                calc_flux( u_prev[i-1], u_prev[i], dt, dx, flux_left );
            else {
                /* ��������� ���������� ������� */
                boundary( u_prev[0], boun_v, LEFT_BOUN );
		calc_flux( boun_v, u_prev[0], dt, dx, flux_left );
            }
			
            /* ������ ������ ����� ������ ����� ������ */
            if ( i != N-1 )
                calc_flux( u_prev[i], u_prev[i+1], dt, dx, flux_right );
            else {
                /* ��������� ���������� ������� */
                boundary( u_prev[N-1], boun_v, RIGHT_BOUN );
                calc_flux( u_prev[N-1], boun_v, dt, dx, flux_right );
            }

            /* ���� �� ����������� ������� */
            for ( j = 0; j < M; j++ )
                u_next[i][j] = u_prev[i][j] - dt * ( flux_right[j] - flux_left[j] ) / ( x[i+1] - x[i] );
            }

            for ( i = 0; i < N; i++ )
                for ( j = 0; j < M; j++ )
                    u_prev[i][j] = u_next[i][j];

            curr_t += dt;
            steps_num += 1;

    }

    printf( "Step %d is finished, current time is %f\n", steps_num, curr_t );

    /* ������ ����������� �� ������ ������ ������� */
    write_solution( xc, u_prev, curr_t );

    system("python ../../front/main.py");

    return 0;

}