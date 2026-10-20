#pragma force_active on
extern "C" {
int fn_54_5BB8(void *p);
}

extern "C" int fn_54_5BB8(void *p)
{
    unsigned int x = *(unsigned int *)((char *)p + 8);
    return (int)((x << 2 | x >> 30) & 0xE0000000) >> 30;
}
