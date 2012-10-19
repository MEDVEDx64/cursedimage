/** Part of the Cursed Image library **/
/*  Comes under the terms of GNU GPL. */

#ifndef CURSEDIMAGE_UTILS_H
#define CURSEDIMAGE_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
  Useful utilities to work directly
  with symbols in cursed images.
**/

/* Finds XY coordinates in symbols array.
   Use y_coord to get Y coordinate insteas of X. */
extern int cursed_get_coord(int y_coord, int pos, unsigned int w);
/* Returns an address of symbol. */
extern int cursed_get_addr(int x, int y, unsigned int w);
/* Both of them requires to know your cursed image's width. */

#ifdef __cplusplus
}
#endif

#endif // CURSEDIMAGE_UTILS_H
