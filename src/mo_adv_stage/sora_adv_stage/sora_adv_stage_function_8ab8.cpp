#pragma force_active on
extern "C" void fn_40_8AB8(void *a, unsigned char b, int c, float d)
{
    unsigned char *p = (unsigned char *)a;
    p[0x184] = b;
    *(int *)(p + 0x188) = c;
    *(float *)(p + 0x18C) = d;
}
