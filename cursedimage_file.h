// This file is only needed to operate
//      with the Cursed image file format

    /// Part of die Cursed Library
     // MEDVEDx64 © Feb.-April 2012

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

TCursedImage    cursed_blank(unsigned char w, unsigned char h);
TCursedImage    cursed_imgload(const char* fname);
bool            cursed_imgsave(const char* fname, TCursedImage img);

#endif // CURSEDIMAGE_FILE_H_INCLUDED
