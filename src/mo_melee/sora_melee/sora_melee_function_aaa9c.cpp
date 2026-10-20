#pragma force_active on
extern "C" {
int fn_27_AAA9C(void* p)
{
    unsigned int x = ((unsigned int*)p)[2];
    unsigned int r = (x << 10) | (x >> 22);
    return ((int)(r & 0xFC000000u)) >> 27;
}
}
