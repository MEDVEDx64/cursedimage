/** cursedimage.c **/
/*  Part of the Cursed Image library.
    Comes under the terms of GNU GPL.
        - MEDVEDx64, 2012.10.19 */

#include "cursedimage.h"

#define SUCCESS     0
#define FAIL        -1
#define RETURN_FAIL_IF_EMPTY(img) if(cursed_empty(img)) return FAIL

int cursed_init(int _nodelay)
{
	if((initscr()) == NULL) return FAIL;
	cbreak();
	noecho(); keypad(stdscr, TRUE);
	if(_nodelay) nodelay(stdscr, TRUE);

	if(cursed_init_color()) return FAIL;
	curs_set(0);

	return SUCCESS;
}

int cursed_draw_object_old(int x, int y, cursedimage *img)
{
	RETURN_FAIL_IF_EMPTY(img);
    clear();
    unsigned int idx;
    for(idx = 0; idx < (img->height*img->width); idx++)
        mvaddch(cursed_get_coord(1, idx, img->width)+y,cursed_get_coord(0, idx, img->width)+x,
            img->image[idx].sym | COLOR_PAIR(img->image[idx].colorpair));
    refresh();
    return SUCCESS;
}

int cursed_draw_object(int x, int y, cursedimage *img)
{
	RETURN_FAIL_IF_EMPTY(img);
	int idx, idy;
    for (idx = 0; idx < COLS ; idx++)
        for (idy = 0; idy < LINES; idy++)
            if (idx >= x && idx < x+img->width && idy >= y && idy<y+img->height)
                mvaddch(idy,idx,img->image[(idy-y)*img->width+idx-x].sym
                    | COLOR_PAIR(img->image[(idy-y)*img->width+idx-x].colorpair));
            else mvaddch(idy,idx,CURSED_DEFAULT_SYM);
    refresh();
	return SUCCESS;
}

int cursed_blit(cursedimage *src, cursedimage *dst, int x, int y)
{
    RETURN_FAIL_IF_EMPTY(src);
    RETURN_FAIL_IF_EMPTY(dst);
    int idx;
	for(idx = 0; idx < CURSED_BODY_CHARS(src); idx++)
		cursed_img_modify(dst, cursed_get_coord(0,idx,src->width)+x,
			cursed_get_coord(1, idx,src->width)+y, src->image[idx].sym, src->image[idx].colorpair);
    return SUCCESS;
}

int cursed_blit_rect(cursedimage *src, cursedimage *dst, int x, int y, int x1, int y1, unsigned int w, unsigned int h)
{
    RETURN_FAIL_IF_EMPTY(src);
    RETURN_FAIL_IF_EMPTY(dst);
    int idx, idy;
	for(idx = x1; idx < x1+w; idx++)
		for(idy = y1; idy < y1+h; idy++)
			if(idx>=0 && idy>= 0 && idx<src->width && idy<src->height)
				cursed_img_modify(dst,idx+x-x1,idy+y-y1,src->image[cursed_get_addr(idx,idy,src->width)].sym,
                      src->image[cursed_get_addr(idx,idy,src->width)].colorpair);
    return SUCCESS;
}

int cursed_flip(cursedimage *img, int is_centered)
{
    int result;
	if(is_centered)
		result = cursed_draw_object(COLS/2-img->width/2,LINES/2-img->height/2,img);
	else
		result = cursed_draw_object(0,0,img);
    return result;
}

int cursed_img_modify(cursedimage *img, int x, int y, char newsym, char newcolorpair)
{
    RETURN_FAIL_IF_EMPTY(img);
	if(x < img->width && y < img->height)
	{
		img->image[cursed_get_addr(x,y,img->width)].sym = newsym;
		img->image[cursed_get_addr(x,y,img->width)].colorpair = newcolorpair;
		return SUCCESS;
	}
	return FAIL;
}

int cursed_clean(cursedimage *img)
{
	RETURN_FAIL_IF_EMPTY(img);
	int idx;
    for(idx = 0; idx < CURSED_BODY_CHARS(img); idx++)
    {
        img->image[idx].sym          = CURSED_DEFAULT_SYM;
        img->image[idx].colorpair    = CURSED_DEFAULT_COLORPAIR;
    }
    return SUCCESS;
}

int cursed_setres(cursedimage *img, unsigned int w, unsigned int h)
{
    if(!w || !h || img == NULL) return FAIL;
    if(!CURSED_MAGIC_CHECK(img) || img->image == NULL) return FAIL;
    cursedimage *buf = cursed_imgcopy(img);
    cursed_imgfree(img);
    img = cursed_blank(w,h);
    cursed_blit_rect(buf,img,0,0,0,0,w,h);
    cursed_imgfree(buf);
    return SUCCESS;
}

void cursed_quit()
{
	endwin();
}

int cursed_rect(cursedimage *img, int x, int y, unsigned int w, unsigned int h, char sym, char colorpair)
{
    RETURN_FAIL_IF_EMPTY(img);
	cursedimage *result = cursed_blank(w,h);
	int idx, idy;
	for(idx = 0; idx < w; idx++)
		for(idy = 0; idy < h; idy++)
			cursed_img_modify(result,idx,idy,sym,colorpair);

	cursed_blit(result,img,x,y);
	cursed_imgfree(result);
	return SUCCESS;
}
