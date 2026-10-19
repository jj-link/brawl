#pragma force_active on
extern "C" void fn_57_37A8(void *obj, unsigned char val8, unsigned int val32, float valF)
{
    unsigned char *p = (unsigned char *)obj;
    p[0x184] = val8;
    *(unsigned int *)(p + 0x188) = val32;
    *(float *)(p + 0x18c) = valF;
}
