#include "cursedimage.h"

int cursed_get_coord(bool y_coord, int pos, int w)
{
    int _cur_x = 0;
    int _cur_y = 0;
    for(int idx = 0; idx < pos; idx++)
    {
        _cur_x ++ ;
        if(_cur_x >= w)
        {
            _cur_y ++ ;
            _cur_x = 0;
        }
    }
    if(y_coord) return _cur_y;
    else        return _cur_x;
}

bool cursed_init(bool _nodelay)
{
    if((initscr()) == NULL) return false;
    #ifndef NO_CBREAK
    cbreak();
    #else
    raw();
    #endif
    noecho(); keypad(stdscr, TRUE);
    if(_nodelay) nodelay(stdscr, TRUE);

    if(!cursed_init_color()) return false;
    curs_set(0);

    return true;
}

void cursed_draw_object(int x, int y, TCursedImage img)
{
    if(img.width > 0 && img.heigth > 0)
    {
        #ifndef NOCLEAR
        clear();
        #endif
        for(unsigned int idx = 0; idx < (img.heigth*img.width); idx++)
            mvaddch(cursed_get_coord(true, idx, img.width)+y,cursed_get_coord(false, idx, img.width)+x,
                    img.image[idx].sym | COLOR_PAIR(img.image[idx].colorpair));
        refresh();
    }
}

void cursed_draw_object_new(int x, int y, TCursedImage img)
{
    if(img.width > 0 && img.heigth > 0)
    {
        for (int idx = 0; idx < COLS ; idx++)
            for (int idy = 0; idy < LINES; idy++)
                if (idx >= x && idx < x+img.width && idy >= y && idy<y+img.heigth)
                    mvaddch(idy,idx,img.image[(idy-y)*img.width+idx-x].sym
                            | COLOR_PAIR(img.image[(idy-y)*img.width+idx-x].colorpair));
                else mvaddch(idy,idx,' ');
        refresh();
    }
}

void cursed_blit(TCursedImage src, TCursedImage dst, int x, int y)
{
    for(int idx = 0; idx < (src.width*src.heigth); idx++)
        cursed_img_modify(dst, cursed_get_coord(false,idx,src.width)+x,
                               cursed_get_coord(true ,idx,src.width)+y, src.image[idx]);
}

void cursed_blit(TCursedImage src, TCursedImage dst, int x, int y, int x1, int y1, int w, int h)
{
    for(int idx = x1; idx < x1+w; idx++)
        for(int idy = y1; idy < y1+h; idy++)
            if(idx>=0 && idy>= 0 && idx<src.width && idy<src.heigth)
                cursed_img_modify(dst,idx+x-x1,idy+y-y1,src.image[cursed_get_addr(idx,idy,src.width)]);
}

void cursed_flip(TCursedImage img, bool is_centered)
{
    if(is_centered)
        cursed_draw_object_new(COLS/2-img.width/2,LINES/2-img.heigth/2,img);
    else
        cursed_draw_object_new(0,0,img);
}

int cursed_get_addr(int x, int y, int w)
{
    return y*w+x;
}

void cursed_img_modify(TCursedImage img, int addr_x, int addr_y, TCursedChar newchar)
{
    if(addr_x < img.width && addr_y < img.heigth)
        img.image[cursed_get_addr(addr_x,addr_y,img.width)] = newchar;
}

void cursed_img_modify(TCursedImage img, int addr_x, int addr_y, char newsym, char newcolorpair)
{
    if(addr_x < img.width && addr_y < img.heigth)
    {
        img.image[cursed_get_addr(addr_x,addr_y,img.width)].sym = newsym;
        img.image[cursed_get_addr(addr_x,addr_y,img.width)].colorpair = newcolorpair;
    }
}

void cursed_clean(TCursedImage img)
{
    if(img.width > 0 && img.heigth > 0)
        for(int idx = 0; idx < (img.width*img.heigth); idx++)
        {
            img.image[idx].sym          = DEF_SYM;
            img.image[idx].colorpair    = DEF_COLORPAIR;
        }
}

void cursed_uninit()
{
    endwin();
}

TCursedImage cursed_rect(int w, int h, TCursedChar newchar)
{
    TCursedImage result = cursed_blank(w,h);
    for(int idx = 0; idx < w; idx++)
        for(int idy = 0; idy < h; idy++)
            cursed_img_modify(result,idx,idy,newchar);

    return result;
}

TCursedImage cursed_rect(int w, int h, char sym, char colorpair)
{
    TCursedImage result = cursed_blank(w,h);
    for(int idx = 0; idx < w; idx++)
        for(int idy = 0; idy < h; idy++)
            cursed_img_modify(result,idx,idy,sym,colorpair);

    return result;
}