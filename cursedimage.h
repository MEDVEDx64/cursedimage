/*
	die Cursed Library
	MEDVEDx64, AlexX © Feb.-April 2012
	Powered by the Force of the Dark Side

	Cursed Image is a pseudo-graphic image
	& file format API with SDL-like
	drawing system.

	This is a free software and can be
	redistributed under the terms of GNU GPL.
*/

#ifndef CURSEDIMAGE_H
#define CURSEDIMAGE_H

#include <ncurses.h>
#include "cursedimage_file.h"
#include "cursedimage_color.h"
#include "cursedimage_utils.h"

#define CURSEDIMAGE_VERSION "0.4.8"

/*!
\brief Inits ncurses and color pairs with some recommended params by default.
\param _nodelay Decines, pause the program when calling getch() or no, useful for games.
*/
bool cursed_init(bool _nodelay);

/*!
\brief Object drawing. Obsolete, OK for for single-layered drawings.
\param x coordinate.
\param y coordinate.
\param img object (image) which will be drawn.
*/
void cursed_draw_object(int x, int y, TCursedImage img);

/*!
\brief Redesigned object drawing.
\param x coordinate.
\param y coordinate.
\param img object (image) which will be drawn.
*/
void cursed_draw_object_new(int x, int y, TCursedImage img);

/*!
\brief Changes a symbol and it`s color at desired coordinates.
\param img Object (image) which will be modified
\param addr_x coordinate at the target image.
\param addr_y coordinate at the target image.
\param newchar Symbol & color to replace an old one at addr_x, addr_y coords.
\param newsym Symbol to replace an old one at addr_x, addr_y coords.
\param newcolorpair Color to replace an old one at addr_x, addr_y coords.
*/
void cursed_img_modify(TCursedImage img, int addr_x, int addr_y, TCursedChar newchar);
void cursed_img_modify(TCursedImage img, int addr_x, int addr_y, char newsym, char newcolorpair);

/*!
\brief Takes an area of the source image (or entrie image) and pastes it to the dest. image at desired coords.
\param src Source image.
\param dst Destination image.
\param x coord at the destination image, where source (area) will be pasted.
\param y coord at the destination image, where source (area) will be pasted.
\param x1 the start coordinate of the rectangle to be copied from source.
\param y1 the start coordinate of the rectangle to be copied from source.
\param w Width of the area rectangle to be copied from source.
\param h Heigth of the area rectangle to be copied from source.
*/
void cursed_blit(TCursedImage src, TCursedImage dst, int x, int y);
void cursed_blit(TCursedImage src, TCursedImage dst, int x, int y, int x1, int y1, int w, int h);

/*!
\brief Draws an image. Basically it's simply uses cursed_draw_object_new() with predefined coords.
\param img Image to draw.
\param is_centered If true, image will be drawn at the screen`s center; else at 0,0.
*/
void cursed_flip(TCursedImage img, bool is_centered);

/*!
\brief Completely erases the target image, but doesn't changes it`s resolution.
\param img Target image.
*/
void cursed_clean(TCursedImage img);

/*!
\brief Changes resolution of the source image.
\param w New width.
\param h New heigth.
\returns Image with new resolution.
*/
TCursedImage cursed_setres(TCursedImage src, unsigned char w, unsigned char h);

/*!
\brief Just calls endwin() to leave ncurses mode. Obsolete.
*/
void cursed_uninit();

/*!
\brief Generates a rectangle filled by desired symbol.
\param w Rectangle width.
\param h Rectangle heigth.
\param newchar Desired symbol.
\param sym Desired symbol.
\param colorpair Desired color.
\returns Rectangle image.
*/
TCursedImage cursed_rect(int w, int h, TCursedChar newchar);
TCursedImage cursed_rect(int w, int h, char sym, char colorpair);

#endif // CURSEDIMAGE_H
