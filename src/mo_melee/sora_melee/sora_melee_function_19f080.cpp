#pragma force_active on
extern "C" int fn_27_19F080(void *p)
{
    unsigned int x = ((unsigned int *)p)[2];
    unsigned int r = ((x << 3) | (x >> 29)) & 0xF0000000;
    return (int)r >> 29;
}
