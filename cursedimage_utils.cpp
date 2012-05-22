#include "cursedimage_utils.h"

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
	if(y_coord)	return _cur_y;
	else		return _cur_x;
}

int cursed_get_addr(int x, int y, int w)
{
	return y*w+x;
}
