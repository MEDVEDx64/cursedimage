/*
 * =================================================
 *
 *  Cursed Color, part of the Cursed Image library.
 *
 *  How it stores the color:
 *	    bits 6-7 - dummy;
 *	    bits 3-5 - foreground bool RGB color;
 *	    bits 0-2 - background bool RGB color.
 *		    Only one byte is enough.
 *
 *  MEDVEDx64, 2012.04.04,
 *          upd. 2012.05.22,
 *          upd. 2012.10.19.
 *
 *
 *  Comes under the terms of GNU GPL.
 *
 * ================================================
 */

#ifndef CURSEDIMAGE_COLOR_H
#define CURSEDIMAGE_COLOR_H

#include <stdio.h>
#ifndef __WIN32__
#	include <ncurses.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Color definitions */

enum
{
// *K
	COL_KK = 0x00, // 0b000000
	COL_RK = 0x20, // 0b100000
	COL_YK = 0x30, // 0b110000
	COL_GK = 0x10, // 0b010000
	COL_CK = 0x18, // 0b011000
	COL_BK = 0x08, // 0b001000
	COL_MK = 0x28, // 0b101000
	COL_WK = 0x38, // 0b111000
// *R
	COL_KR = 0x04, // 0b000100
	COL_RR = 0x24, // 0b100100
	COL_YR = 0x34, // 0b110100
	COL_GR = 0x14, // 0b010100
	COL_CR = 0x1C, // 0b011100
	COL_BR = 0x0C, // 0b001100
	COL_MR = 0x2C, // 0b101100
	COL_WR = 0x3C, // 0b111100
// *Y
	COL_KY = 0x06, // 0b000110
	COL_RY = 0x26, // 0b100110
	COL_YY = 0x36, // 0b110110
	COL_GY = 0x16, // 0b010110
	COL_CY = 0x1E, // 0b011110
	COL_BY = 0x0E, // 0b001110
	COL_MY = 0x2E, // 0b101110
	COL_WY = 0x3E, // 0b111110
// *G
	COL_KG = 0x02, // 0b000010
	COL_RG = 0x42, // 0b100010
	COL_YG = 0x32, // 0b110010
	COL_GG = 0x12, // 0b010010
	COL_CG = 0x1A, // 0b011010
	COL_BG = 0x0A, // 0b001010
	COL_MG = 0x2A, // 0b101010
	COL_WG = 0x3A, // 0b111010
// *C
	COL_KC = 0x03, // 0b000011
	COL_RC = 0x23, // 0b100011
	COL_YC = 0x33, // 0b110011
	COL_GC = 0x13, // 0b010011
	COL_CC = 0x1B, // 0b011011
	COL_BC = 0x0B, // 0b001011
	COL_MC = 0x2B, // 0b101011
	COL_WC = 0x3B, // 0b111011
// *B
	COL_KB = 0x01, // 0b000001
	COL_RB = 0x21, // 0b100001
	COL_YB = 0x31, // 0b110001
	COL_GB = 0x11, // 0b010001
	COL_CB = 0x19, // 0b011001
	COL_BB = 0x09, // 0b001001
	COL_MB = 0x29, // 0b101001
	COL_WB = 0x39, // 0b111001
// *M
	COL_KM = 0x05, // 0b000101
	COL_RM = 0x25, // 0b100101
	COL_YM = 0x35, // 0b110101
	COL_GM = 0x15, // 0b010101
	COL_CM = 0x1D, // 0b011101
	COL_BM = 0x0D, // 0b001101
	COL_MM = 0x2D, // 0b101101
	COL_WM = 0x3D, // 0b111101
// *W
	COL_KW = 0x07, // 0b000111
	COL_RW = 0x27, // 0b100111
	COL_YW = 0x37, // 0b110111
	COL_GW = 0x17, // 0b010111
	COL_CW = 0x1F, // 0b011111
	COL_BW = 0x0F, // 0b001111
	COL_MW = 0x2F, // 0b101111
	COL_WW = 0x3F  // 0b111111

};

#ifndef __WIN32__
/* Returns 0 on success, -1 on failure */
extern int cursed_init_color();
#endif

#ifdef __cplusplus
}
#endif

#endif // CURSEDIMAGE_COLOR_H
