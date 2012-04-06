/*
 * ============================================
 *
 * Cursed Color
 *
 * How it stores the color:
 *	bits 1-2 - dummy;
 *	bits 3-5 - foreground bool RGB color;
 *	bits 6-8 - background bool RGB color.
 *		Only one byte is enough
 *
 * MEDVEDx64, 2012.04.04
 *
 * ============================================
 */

#include <stdio.h>
#ifndef __WIN32__
#	include <ncurses.h>
#endif

/* Color definitions */

enum
{
// *K
	COL_KK = 0b000000,
	COL_RK = 0b100000,
	COL_YK = 0b110000,
	COL_GK = 0b010000,
	COL_CK = 0b011000,
	COL_BK = 0b001000,
	COL_MK = 0b101000,
	COL_WK = 0b111000,
// *R
	COL_KR = 0b000100,
	COL_RR = 0b100100,
	COL_YR = 0b110100,
	COL_GR = 0b010100,
	COL_CR = 0b011100,
	COL_BR = 0b001100,
	COL_MR = 0b101100,
	COL_WR = 0b111100,
// *Y
	COL_KY = 0b000110,
	COL_RY = 0b100110,
	COL_YY = 0b110110,
	COL_GY = 0b010110,
	COL_CY = 0b011110,
	COL_BY = 0b001110,
	COL_MY = 0b101110,
	COL_WY = 0b111110,
// *G
	COL_KG = 0b000010,
	COL_RG = 0b100010,
	COL_YG = 0b110010,
	COL_GG = 0b010010,
	COL_CG = 0b011010,
	COL_BG = 0b001010,
	COL_MG = 0b101010,
	COL_WG = 0b111010,
// *C
	COL_KC = 0b000011,
	COL_RC = 0b100011,
	COL_YC = 0b110011,
	COL_GC = 0b010011,
	COL_CC = 0b011011,
	COL_BC = 0b001011,
	COL_MC = 0b101011,
	COL_WC = 0b111011,
// *B
	COL_KB = 0b000001,
	COL_RB = 0b100001,
	COL_YB = 0b110001,
	COL_GB = 0b010001,
	COL_CB = 0b011001,
	COL_BB = 0b001001,
	COL_MB = 0b101001,
	COL_WB = 0b111001,
// *M
	COL_KM = 0b000101,
	COL_RM = 0b100101,
	COL_YM = 0b110101,
	COL_GM = 0b010101,
	COL_CM = 0b011101,
	COL_BM = 0b001101,
	COL_MM = 0b101101,
	COL_WM = 0b111101,
// *W
	COL_KW = 0b000111,
	COL_RW = 0b100111,
	COL_YW = 0b110111,
	COL_GW = 0b010111,
	COL_CW = 0b011111,
	COL_BW = 0b001111,
	COL_MW = 0b101111,
	COL_WW = 0b111111

};

bool cursed_init_color();
