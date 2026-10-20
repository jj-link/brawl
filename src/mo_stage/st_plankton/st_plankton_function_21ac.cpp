#pragma force_active on
extern "C" int fn_74_21AC(void* self)
{
    unsigned char* b = (unsigned char*)self;
    int r = 0;
    if (b[0x4ac] == 3) goto done;
    r = 1;
    if (b[0x4cc] == 3) goto done;
    r = 2;
    if (b[0x4ec] == 3) goto done;
    r = 3;
    if (b[0x50c] == 3) goto done;
    r = 4;
    if (b[0x52c] == 3) goto done;
    r = 5;
    if (b[0x54c] == 3) goto done;
    r = 6;
    if (b[0x56c] == 3) goto done;
    r = 7;
    if (b[0x58c] == 3) goto done;
    r = 8;
done:
    return r;
}
