/** cursedimage_color.c **/
/*  Part of the Cursed Image library.
    Comes under the terms of GNU GPL.
        - MEDVEDx64, 2012.10.19 */

#include "cursedimage_color.h"

int cursed_init_color()
{
#ifndef __WIN32__

	start_color();

	/** Initializing color pairs **/
// *K
	init_pair(COL_KK, COLOR_BLACK,	COLOR_BLACK);
	init_pair(COL_RK, COLOR_RED,	COLOR_BLACK);
	init_pair(COL_YK, COLOR_YELLOW,	COLOR_BLACK);
	init_pair(COL_GK, COLOR_GREEN,	COLOR_BLACK);
	init_pair(COL_CK, COLOR_CYAN,	COLOR_BLACK);
	init_pair(COL_BK, COLOR_BLUE,	COLOR_BLACK);
	init_pair(COL_MK, COLOR_MAGENTA,COLOR_BLACK);
	init_pair(COL_WK, COLOR_WHITE,	COLOR_BLACK);
// *R
	init_pair(COL_KR, COLOR_BLACK,	COLOR_RED);
	init_pair(COL_RR, COLOR_RED,	COLOR_RED);
	init_pair(COL_YR, COLOR_YELLOW,	COLOR_RED);
	init_pair(COL_GR, COLOR_GREEN,	COLOR_RED);
	init_pair(COL_CR, COLOR_CYAN,	COLOR_RED);
	init_pair(COL_BR, COLOR_BLUE,	COLOR_RED);
	init_pair(COL_MR, COLOR_MAGENTA,COLOR_RED);
	init_pair(COL_WR, COLOR_WHITE,	COLOR_RED);
// *Y
	init_pair(COL_KY, COLOR_BLACK,	COLOR_YELLOW);
	init_pair(COL_RY, COLOR_RED,	COLOR_YELLOW);
	init_pair(COL_YY, COLOR_YELLOW,	COLOR_YELLOW);
	init_pair(COL_GY, COLOR_GREEN,	COLOR_YELLOW);
	init_pair(COL_CY, COLOR_CYAN,	COLOR_YELLOW);
	init_pair(COL_BY, COLOR_BLUE,	COLOR_YELLOW);
	init_pair(COL_MY, COLOR_MAGENTA,COLOR_YELLOW);
	init_pair(COL_WY, COLOR_WHITE,	COLOR_YELLOW);
// *G
	init_pair(COL_KG, COLOR_BLACK,	COLOR_GREEN);
	init_pair(COL_RG, COLOR_RED,	COLOR_GREEN);
	init_pair(COL_YG, COLOR_YELLOW,	COLOR_GREEN);
	init_pair(COL_GG, COLOR_GREEN,	COLOR_GREEN);
	init_pair(COL_CG, COLOR_CYAN,	COLOR_GREEN);
	init_pair(COL_BG, COLOR_BLUE,	COLOR_GREEN);
	init_pair(COL_MG, COLOR_MAGENTA,COLOR_GREEN);
	init_pair(COL_WG, COLOR_WHITE,	COLOR_GREEN);
// *C
	init_pair(COL_KC, COLOR_BLACK,	COLOR_CYAN);
	init_pair(COL_RC, COLOR_RED,	COLOR_CYAN);
	init_pair(COL_YC, COLOR_YELLOW,	COLOR_CYAN);
	init_pair(COL_GC, COLOR_GREEN,	COLOR_CYAN);
	init_pair(COL_CC, COLOR_CYAN,	COLOR_CYAN);
	init_pair(COL_BC, COLOR_BLUE,	COLOR_CYAN);
	init_pair(COL_MC, COLOR_MAGENTA,COLOR_CYAN);
	init_pair(COL_WC, COLOR_WHITE,	COLOR_CYAN);
// *B
	init_pair(COL_KB, COLOR_BLACK,	COLOR_BLUE);
	init_pair(COL_RB, COLOR_RED,	COLOR_BLUE);
	init_pair(COL_YB, COLOR_YELLOW,	COLOR_BLUE);
	init_pair(COL_GB, COLOR_GREEN,	COLOR_BLUE);
	init_pair(COL_CB, COLOR_CYAN,	COLOR_BLUE);
	init_pair(COL_BB, COLOR_BLUE,	COLOR_BLUE);
	init_pair(COL_MB, COLOR_MAGENTA,COLOR_BLUE);
	init_pair(COL_WB, COLOR_WHITE,	COLOR_BLUE);
// *M
	init_pair(COL_KM, COLOR_BLACK,	COLOR_MAGENTA);
	init_pair(COL_RM, COLOR_RED,	COLOR_MAGENTA);
	init_pair(COL_YM, COLOR_YELLOW,	COLOR_MAGENTA);
	init_pair(COL_GM, COLOR_GREEN,	COLOR_MAGENTA);
	init_pair(COL_CM, COLOR_CYAN,	COLOR_MAGENTA);
	init_pair(COL_BM, COLOR_BLUE,	COLOR_MAGENTA);
	init_pair(COL_MM, COLOR_MAGENTA,COLOR_MAGENTA);
	init_pair(COL_WM, COLOR_WHITE,	COLOR_MAGENTA);
// *W
	init_pair(COL_KW, COLOR_BLACK,	COLOR_WHITE);
	init_pair(COL_RW, COLOR_RED,	COLOR_WHITE);
	init_pair(COL_YW, COLOR_YELLOW,	COLOR_WHITE);
	init_pair(COL_GW, COLOR_GREEN,	COLOR_WHITE);
	init_pair(COL_CW, COLOR_CYAN,	COLOR_WHITE);
	init_pair(COL_BW, COLOR_BLUE,	COLOR_WHITE);
	init_pair(COL_MW, COLOR_MAGENTA,COLOR_WHITE);
	init_pair(COL_WW, COLOR_WHITE,	COLOR_WHITE);

	return 0;
#else
	return -1;
#endif // __WIN32__
}
