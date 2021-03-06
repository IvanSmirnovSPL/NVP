/*
 * main.h
 *
 * ????????? ??? ???????????? ????????? ????
 * ??? ??????? ?????????? ????? ??????? ????????.
 *
 * (c) ????? ?????, 2012
 *
 * ??????: 27 ?????? 2012 ?.
 *
 */

#ifndef __MAIN_H_
#define __MAIN_H_

#include <stdio.h>
#include <math.h>

#define M               3			/* ??????????? ???????-??????? */

/* ??? ?????????? ??????? */

#define	WALL		1                       /* ?????? */
#define	FREE		2			/* ????????? ????????/????????? */

/* ????? ??????? ??????? */

#define	CIR		1		        /* ????? ???????-????????-??? */

/* CFL */
#define N1              5                       /* ?????????? ????????? ?????, ? ??????? ??????? ?????? ???? ? CFL1 */
#define CFL1            0.2                     /* ????? CFL ??? ?????? N1 ????? */
#define CFL2            0.2                    /* ???????? ????? CFL */

/* ???????? ?????? */

#define TASK_NUMER      1                       /* ????? ????? */
#define	SCHEME		CIR			/* ????? ??????? ??????? */

#if ( TASK_NUMER == 1 )                         /* "???? ????" */

#define	GAMMA		1.4			/* ?????????? ???????? */
#define	CELLS_LEFT	50			/* ?????????? ????? ????? ?? ??????????????? ??????? */
#define	N               100		        /* ????? ???????? ????????? ?????????? ??????? */
#define T_END	        3e-2			/* ????? ??????? */
#define LEFT_BOUN	FREE		        /* ??? ?????? ?????????? ??????? */
#define RIGHT_BOUN	FREE		        /* ??? ??????? ?????????? ??????? */

/* ???????????????? ????????? ????? ?? ??????? */

#define LEFT_R		5.99924
#define	LEFT_U		19.5975
#define	LEFT_P		460.894

/* ???????????????? ????????? ?????? ?? ??????? */

#define RIGHT_R		5.99242
#define	RIGHT_U		-6.19633
#define	RIGHT_P		46.0950

#endif

#endif /* __MAIN_H_ */