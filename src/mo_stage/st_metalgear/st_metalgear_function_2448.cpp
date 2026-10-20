#pragma force_active on
extern "C" void fn_71_2448(void *obj, unsigned char a, unsigned int b, float c)
{
    unsigned char *p = (unsigned char *)obj;
    p[0x184] = a;
    *(unsigned int *)(p + 0x188) = b;
    *(float *)(p + 0x18c) = c;
}
