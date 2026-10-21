#pragma force_active on
extern "C" int fn_57_ACDC(void *p)
{
    int x = ((int*)p)[2];
    return ((x << 2) & (int)0xE0000000) >> 30;
}
