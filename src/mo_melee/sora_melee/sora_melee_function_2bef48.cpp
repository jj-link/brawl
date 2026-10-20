#pragma force_active on
extern "C" void fn_27_2BEF48(void *a, void *b)
{
    float *dst = (float *)((char *)a + 0x8);
    float *src = (float *)((char *)b + 0x4);
    *dst = *dst * *src;
}
