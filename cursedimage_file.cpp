#include "cursedimage_file.h"

TCursedChar::TCursedChar()
{
    sym         = DEF_SYM;
    colorpair   = DEF_COLORPAIR;
}

TCursedImage::TCursedImage()
{
    width   = 0;
    heigth  = 0;
}

TCursedImage cursed_blank(unsigned char w, unsigned char h)
{
    TCursedImage result = TCursedImage();
    if(w&&h)
    {
        result.width    = w;
        result.heigth   = h;
        result.image = new TCursedChar[(w*h)*2];
        return result;
    }
    else return result;
}

TCursedImage cursed_imgload(const char* fname)
{
    TCursedImage out;
    FILE* in;
    char* file_id;
    char  version;

    if((in = fopen(fname,"r")) == NULL) return TCursedImage();

    // thanks to cplusplus.com
    long fsize;
    fseek(in , 0 , SEEK_END);
    fsize = ftell(in);
    rewind(in);
    //

    file_id = (char*)malloc(sizeof(char)*4);
    // reading file headef @ 0x00
        // step-by-step
    for(char i = 0; i < 4; i++)
        if(fread(file_id+i, 1, 1, in));
    // gettin' format version @ 0x04
    if(fread(&version, 1, 1, in));
    // if it's allright, ..
    if(!strcmp(FILE_ID, file_id) && version == FMT_VERSION)
    {
        // ..then reading width and heigth valuse @ 0x05, 0x06
        if(fread(&out.width,  1, 1, in));
        if(fread(&out.heigth, 1, 1, in));

        out.image = (TCursedChar*)malloc(fsize);

        // caching 'em all from 0x07 'til the end
        int idx = 0;
        while(!feof(in))
        {
            if(fread(&out.image[idx].sym,       1, 1, in));
            if(fread(&out.image[idx].colorpair, 1, 1, in));
            idx++;
        }
    }

    else return TCursedImage();
    fclose(in);
    return out;
}

bool cursed_imgsave(const char* fname, TCursedImage img)
{
    FILE* out;
    const char* file_id = FILE_ID;
    char  version = FMT_VERSION;

    if((out = fopen(fname,"w+")) == NULL) return false;
    for(char i = 0; i < 4; i++)
        fwrite(file_id+i, 1, 1, out);
    fwrite(&version, 1, 1, out);

    fwrite(&img.width,  1, 1, out);
    fwrite(&img.heigth, 1, 1, out);

    int idx = 0;
    while(idx < (img.width*img.heigth))
    {
        fwrite(&img.image[idx].sym,       1, 1, out);
        fwrite(&img.image[idx].colorpair, 1, 1, out);
        idx++;
    }
    fclose(out);
    return true;
}