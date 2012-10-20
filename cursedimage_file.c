/** cursedimage_file.c **/
/*  Part of the Cursed Image library.
    Comes under the terms of GNU GPL.
        - MEDVEDx64, 2012.10.19 */

#include <stdint.h>
#include "cursedimage_file.h"

cursedimage *cursed_blank(unsigned char w, unsigned char h)
{
    if(!w||!h) return NULL;
	cursedimage *result = (cursedimage*)malloc(sizeof(cursedimage));
    result->magic = CURSED_MAGIC;
    result->version = CURSED_FORMAT_VERSION;
    result->width = w;
    result->height = h;
    result->image = (cursedchar*)malloc(CURSED_BODY_LENGTH(result));
    int i; for(i = 0; i < CURSED_BODY_CHARS(result); i++)
    {
        result->image[i].colorpair   = CURSED_DEFAULT_COLORPAIR;
        result->image[i].sym         = CURSED_DEFAULT_SYM;
    }
    return result;
}

int cursed_empty(cursedimage *img)
{
    if(img == NULL) return -1;
    else if(img->image == NULL) return -1;
    else if(!CURSED_MAGIC_CHECK(img)) return -1;
	else if(img->width && img->height) return 0;
	return 1;
}

cursedimage *cursed_imgload(const char* fname)
{
    FILE* in;
    if((in = fopen(fname,"rb")) == NULL) return NULL;

    long fsize;
    fseek(in, 0, SEEK_END);
    fsize = ftell(in);
    rewind(in);

    if(fsize <= CURSED_HEADER_LENGTH) return NULL;
    cursedimage *out = (cursedimage*)malloc(sizeof(cursedimage));
    if(fread(out, CURSED_HEADER_LENGTH, 1, in));
    if(out->magic != CURSED_MAGIC || out->version != CURSED_FORMAT_VERSION || fsize != CURSED_FILE_LENGTH(out))
    {
        cursed_imgfree(out);
        fclose(in);
        return NULL;
    }

    out->image = (cursedchar*)malloc(fsize-CURSED_HEADER_LENGTH);
    if(fread(out->image, CURSED_BODY_LENGTH(out), 1, in));
    fclose(in);
    return out;
}

int cursed_imgsave(const char* fname, cursedimage *img)
{
    if(fname == NULL || img == NULL) return -1;
    FILE* out;
    if((out = fopen(fname,"wb")) == NULL) return -1;
    if(!CURSED_MAGIC_CHECK(img)) return -1;

    fwrite(img, CURSED_HEADER_LENGTH, 1, out);
    fwrite(img->image, CURSED_BODY_LENGTH(img), 1, out);
    fclose(out);
    return 0;
}

cursedimage *cursed_imgcopy(cursedimage *img)
{
    if(img == NULL) return NULL;
    if(!CURSED_MAGIC_CHECK(img)) return NULL;
    cursedimage *out = cursed_blank(img->width, img->height);
    memcpy(out, img, CURSED_HEADER_LENGTH);
    memcpy(out->image, img->image, CURSED_BODY_LENGTH(img));
    return out;
}
