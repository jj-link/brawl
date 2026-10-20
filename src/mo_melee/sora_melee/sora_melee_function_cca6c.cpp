#pragma force_active on
extern "C" int fn_27_CCA6C(void *p)
{
    unsigned int v = ((unsigned int *)p)[2];
    return (int)((v << 4) & 0xE0000000u) >> 30;
}
