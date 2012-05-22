/*

This file is only needed to operate
with the Cursed image file format

Part of die Cursed Library
MEDVEDx64 © Feb.-April 2012

*/

#ifndef CURSEDIMAGE_FILE_H
#define CURSEDIMAGE_FILE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
Format version 0x10, format header is _IMG
*/

#define FILE_ID "_IMG"
#define FMT_VERSION 0x10
#define DEF_SYM ' '
#define DEF_COLORPAIR 0

/*
TCursedChar type definition
Features colorpair and symbol chars.
*/
struct TCursedChar
{
	TCursedChar();
	char	colorpair;
	char	sym;
};

/*
TCursedImage type definition
Have width and heigth fields,
consists of TCursedChars.
*/
struct TCursedImage
{
	TCursedImage();
	unsigned char width, heigth;
	TCursedChar *image;
};

/*!
\brief Creates a blank TCursedImage.
\param w Blank image width.
\param h Blank image heigth.
\returns it.
*/
TCursedImage	cursed_blank(unsigned char w, unsigned char h);

/*!
\brief Checks image for existence (for emptiness). Can be used to check the image was loaded successfully.
\param img Target.
\returns 0 if image IS NOT empty.
*/
bool		cursed_empty(TCursedImage img);

/*!
\brief Loads a Cursed image.
\param fname Name of the file to be loaded.
\returns Loaded image (of empty image if loading has failed).
*/
TCursedImage	cursed_imgload(const char* fname);

/*!
\brief Writes Cursed image to file.
\param fname Name of the file to be written.
\param img Image to write.
\returns 0 on failure, 1 on success.
*/
bool		cursed_imgsave(const char* fname, TCursedImage img);

#endif // CURSEDIMAGE_FILE_H
