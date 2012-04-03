// This file is only needed to operate
//      with the Cursed image format

    /// Part of die Cursed Library
     // MEDVEDx64 © Feb., March 2012

#ifndef CURSEDIMAGE_FILE_H_INCLUDED
#define CURSEDIMAGE_FILE_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Format version 0x10, format header is _IMG

#define FILE_ID "_IMG"
#define FMT_VERSION 0x10
#define DEF_SYM ' '
#define DEF_COLORPAIR 0

struct TCursedChar
{
    TCursedChar();
    char    colorpair;
    char    sym;
};

struct TCursedImage
{
    TCursedImage();
    unsigned char width, heigth;
    TCursedChar *image;
};

enum
{
    COL_WK, COL_RK, COL_YK, COL_GK, COL_BK, COL_CK, COL_MK,
    COL_KW, COL_KR, COL_KY, COL_KG, COL_KB, COL_KC, COL_KM,
    COL_WW, COL_WR, COL_WY, COL_WG, COL_WB, COL_WC, COL_WM,
    COL_KK = 0xFF
};

TCursedImage    cursed_blank(unsigned char w, unsigned char h);
TCursedImage    cursed_imgload(const char* fname);
void            cursed_imgsave(const char* fname, TCursedImage img);

#endif // CURSEDIMAGE_FILE_H_INCLUDED
