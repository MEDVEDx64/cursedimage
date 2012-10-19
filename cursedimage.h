/*
	the Cursed Image Library
	MEDVEDx64, AlexX © Feb.-April 2012, Oct. 2012
	Powered by the Force of the Dark Side

	Cursed Image is a pseudo-graphic image
	& file format API with SDL-like
	drawing system.

	This is a free software and it can be
	redistributed under the terms of GNU GPL.
*/

#ifndef CURSEDIMAGE_H
#define CURSEDIMAGE_H

#include <ncurses.h>
#include "cursedimage_file.h"
#include "cursedimage_color.h"
#include "cursedimage_utils.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CURSEDIMAGE_VERSION_MAJOR   0
#define CURSEDIMAGE_VERSION_MINOR   5
#define CURSEDIMAGE_VERSION_MICRO   0

/*!
\brief  Inits ncurses and color pairs with some recommended params by default.
\param _nodelay Decines, pause the program when calling getch() or no. Useful for games.
\returns        0 on success, -1 on failure.
*/
extern int cursed_init(int _nodelay);

/*!
\brief Object drawing.
\param x    coordinate.
\param y    coordinate.
\param img  Pointer to object (image) which will be drawn.
\returns    0 on success, -1 on failure.
*/
extern int cursed_draw_object(int x, int y, cursedimage *img);

/*!
\brief Object drawing. Obsolete, OK for for single-layered drawings.
\param x    coordinate.
\param y    coordinate.
\param img  Pointer to object (image) which will be drawn.
\returns    0 on success, -1 on failure.
*/
extern int cursed_draw_object_old(int x, int y, cursedimage *img);

/*!
\brief          Changes a symbol and it`s color at desired coordinates.
\param img              Pointer to object (image) which will be modified
\param x                coordinate at the target image.
\param y                coordinate at the target image.
\param newsym           Symbol to replace an old one at addr_x, addr_y coords.
\param newcolorpair     Color to replace an old one at addr_x, addr_y coords.
\returns                0 on success, -1 on failure.
*/
extern int cursed_img_modify(cursedimage *img, int x, int y, char newsym, char newcolorpair);

/*!
\brief      Takes an area of the source image (or entrie image) and pastes it to the destination image at desired coords.
\param src  Source image (pointer).
\param dst  Destination image (pointer).
\param x    coord at the destination image, where source (area) will be pasted.
\param y    coord at the destination image, where source (area) will be pasted.
\param x1   the start coordinate of the rectangle to be copied from source.
\param y1   the start coordinate of the rectangle to be copied from source.
\param w    Width of the area rectangle to be copied from source.
\param h    Height of the area rectangle to be copied from source.
\returns    0 on success, -1 on failure.
*/
extern int cursed_blit(cursedimage *src, cursedimage *dst, int x, int y);
extern int cursed_blit_rect(cursedimage *src, cursedimage *dst, int x, int y, int x1, int y1, unsigned int w, unsigned int h);

/*!
\brief              Draws an image. It calls cursed_draw_object() with predefined coords.
\param img          Image to draw.
\param is_centered  If != 0, image will be drawn at the screen`s center; else at 0,0.
\returns            0 on success, -1 on failure.
*/
extern int cursed_flip(cursedimage *img, int is_centered);

/*!
\brief      Erases the target image, but doesn't changes it`s resolution.
\param img  Pointer to target image.
\returns    0 on success, -1 on failure.
*/
extern int cursed_clean(cursedimage *img);

/*!
\brief      Changes resolution of the source image.
\param w    New width.
\param h    New height.
\returns    0 on success, -1 on failure.
*/
extern int cursed_setres(cursedimage *img, unsigned int w, unsigned int h);

/*!
\brief      Just calls endwin() to leave ncurses mode. Obsolete.
*/
extern void cursed_quit();

/*!
\brief      Draws a rectangle filled by desired symbol.
\param img      Target image (pointer).
\param x        X position of the recrangle.
\param y        Y position of the recrangle.
\param w        Rectangle width.
\param h        Rectangle height.
\param newchar  Desired symbol.
\param sym      Desired symbol.
\param colorpair    Desired color.
\returns            0 on success, -1 on fail.
*/
extern int cursed_rect(cursedimage *img, int x, int y, unsigned int w, unsigned int h, char sym, char colorpair);

#ifdef __cplusplus
}
#endif

#endif // CURSEDIMAGE_H
