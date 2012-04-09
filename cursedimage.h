/// die Cursed Library
 // MEDVEDx64, AlexX © Feb.-April 2012

 // Lib version 0.4.2 beta
/// Powered by the Force of the Dark Side

#ifndef CURSEDIMAGE_H_INCLUDED
#define CURSEDIMAGE_H_INCLUDED
#include <ncurses.h>
#include "cursedimage_file.h"
#include "cursedimage_color.h"

bool cursed_init(bool _nodelay);                                                                    // MEDVEDx64
void cursed_draw_object(int x, int y, TCursedImage img);                                            // MEDVEDx64
void cursed_draw_object_new(int x, int y, TCursedImage img);                                        // AlexX
void cursed_img_modify(TCursedImage img, int addr_x, int addr_y, TCursedChar newchar);              // MEDVEDx64
void cursed_img_modify(TCursedImage img, int addr_x, int addr_y, char newsym, char newcolorpair);   // MEDVEDx64
int  cursed_get_coord(bool y_coord /*else x coord will be returned*/, int pos, int w);              // MEDVEDx64
int  cursed_get_addr(int x, int y, int w);                                                          // AlexX
void cursed_blit(TCursedImage src, TCursedImage dst, int x, int y);                                 // MEDVEDx64
void cursed_blit(TCursedImage src, TCursedImage dst, int x, int y, int x1, int y1, int w, int h);   // MEDVEDx64
void cursed_flip(TCursedImage img, bool is_centered);                                               // MEDVEDx64
void cursed_clean(TCursedImage img);                                                                // MEDVEDx64
void cursed_uninit();                                                                               // MEDVEDx64

TCursedImage cursed_rect(int w, int h, TCursedChar newchar);
TCursedImage cursed_rect(int w, int h, char sym, char colorpair);

#endif // CURSEDIMAGE_H_INCLUDED