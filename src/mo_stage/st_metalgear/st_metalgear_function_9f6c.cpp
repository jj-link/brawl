#pragma force_active on
extern "C" int fn_71_9F6C(unsigned int *p)
{
    unsigned int r = p[2];
    r = (r << 2) | (r >> 30);
    return (int)(r & 0xE0000000) >> 30;
}
