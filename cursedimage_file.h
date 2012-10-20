/*

    Cursed Image structures definitions
    and file format functionary.

    Part of the Cursed Image Library
    MEDVEDx64, Feb.-April 2012, Oct. 2012.
    Comes under the terms of GNU GPL.

*/

#ifndef CURSEDIMAGE_FILE_H
#define CURSEDIMAGE_FILE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
  Format version 0x11, format header is _IMG.
  It`s recommended to use ".cmg" extension for Cursed Image files.
*/

#define CURSED_MAGIC                0x474D495F
#define CURSED_MAGIC_T              int
#define CURSED_MAGIC_CHECK(img)     *(CURSED_MAGIC_T*)img == CURSED_MAGIC
#define CURSED_FORMAT_VERSION       0x11
#define CURSED_DEFAULT_SYM          ' '
#define CURSED_DEFAULT_COLORPAIR    0

#define CURSED_BODY_CHARS(img)      (img->width*img->height)
#define CURSED_BODY_LENGTH(img)     CURSED_BODY_CHARS(img)*sizeof(cursedchar)
/* Requires stdint.h! */
#define CURSED_HEADER_LENGTH        (sizeof(cursedimage)-sizeof(intptr_t))
#define CURSED_FILE_LENGTH(img)     CURSED_HEADER_LENGTH+CURSED_BODY_LENGTH(img)

/*
  cursedchar type definition
  Features colorpair and symbol chars.
*/
typedef struct
{
	char colorpair;
	char sym;
} cursedchar;

/*
  cursedimage type definition.
  Have width and height fields,
  consists of cursedchars.
*/
typedef struct
{
    CURSED_MAGIC_T  magic;
    unsigned char   version;
    unsigned int    width, height;
    cursedchar      *image;
} cursedimage;

/*!
\brief Creates a blank cursedimage.
\param w Blank image width.
\param h Blank image height.
\returns pointer to a new image, NULL if input width or height == 0
*/
extern cursedimage *cursed_blank(unsigned char w, unsigned char h);

/*!
\brief Checks image for emptiness.
\param img Target.
\returns 0 if image IS NOT empty, 1 if empty, -1 on fail.
*/
extern int cursed_empty(cursedimage *img);

/*!
\brief Loads a Cursed image.
\param fname Name of the file to be loaded.
\returns pointer to loaded image (of NULL if loading has failed).
*/
extern cursedimage *cursed_imgload(const char* fname);

/*!
\brief Writes Cursed image to file.
\param fname Name of the file to be written.
\param img Pointer to image to be written.
\returns -1 on failure, 0 on success.
*/
extern int cursed_imgsave(const char* fname, cursedimage *img);

/*!
\brief      Creates a copy of image.
\returns    Pointer to copied image, NULL if failed.
*/
extern cursedimage *cursed_imgcopy(cursedimage *img);

/*!
\brief      Destroys image.
\param img  Pointer to image to be freed.
*/
#define cursed_imgfree(img)     \
    do                          \
    {                           \
        if(img != NULL)         \
        {                       \
            free(img->image);   \
            free(img);          \
            img = NULL;         \
        }                       \
    }                           \
    while(0)

#ifdef __cplusplus
}
#endif

#endif // CURSEDIMAGE_FILE_H
