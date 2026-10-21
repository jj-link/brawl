#pragma force_active on
typedef unsigned short u16;

extern "C" void fn_800A6624(void *arg0)
{
    unsigned char *a = (unsigned char *)arg0;
    unsigned char *r5 = *(unsigned char **)a;
    u16 r0;

    *(float *)(r5 + 0xCC) = *(float *)(a + 0x14);
    r0 = *(u16 *)(r5 + 0xFA);
    *(u16 *)(r5 + 0xFA) = (u16)(r0 | 0x80);
    *(float *)(r5 + 0x60) = *(float *)(a + 0x18);
    *(float *)(r5 + 0x64) = *(float *)(a + 0x1C);
    *(float *)(r5 + 0x68) = *(float *)(a + 0x20);
    *(u16 *)(r5 + 0xFA) = (u16)(r0 | 0x82);
    *(float *)(r5 + 0xD0) = *(float *)(a + 0x24);
}
