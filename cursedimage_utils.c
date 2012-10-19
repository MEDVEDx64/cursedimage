/** cursedimage_utils.c **/
/*  Part of the Cursed Image library.
    Comes under the terms of GNU GPL.
        - MEDVEDx64, 2012.10.19 */

#include "cursedimage_utils.h"

int cursed_get_coord(int y_coord, int pos, unsigned int w)
{
	int _cur_x = 0;
	int _cur_y = 0;
	int idx;
	for(idx = 0; idx < pos; idx++)
	{
		_cur_x ++ ;
		if(_cur_x >= w)
		{
			_cur_y ++ ;
			_cur_x = 0;
		}
	}
	if(y_coord)	return _cur_y;
	return _cur_x;
}

int cursed_get_addr(int x, int y, unsigned int w)
{
	return y*w+x;
}
