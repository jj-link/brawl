#pragma force_active on

void fn_8026B2C4(unsigned char *src, unsigned char *dst)
{
    unsigned short h, w;
    unsigned char x;
    int v;

    *(unsigned short *)(dst + 0xC) = 0;
    *(unsigned short *)(dst + 0xE) = 0;
    *(int *)(dst + 0x10) = 0;
    *(int *)(dst + 0x14) = *(int *)(src + 0x20);
    w = *(unsigned short *)(src + 0x1580);
    *(unsigned short *)(dst + 0x1C) = w;
    h = *(unsigned short *)(src + 0x1582);
    *(unsigned short *)(dst + 0x1E) = h;
    *(int *)(dst + 0x18) = w * h;
    x = src[0x1594];
    dst[0x20] = x;
    dst[0x21] = src[0x1595];
    dst[0x22] = src[0x1588];
    dst[0x23] = src[0x1589];
    if (src[0x1588] == 0)
        v = (w + 1) * x;
    else
        v = (w - 1) * x;
    *(int *)(dst + 0x24) = v;
    if (src[0x1589] == 0)
        v = (*(unsigned short *)(dst + 0x1E) + 1) * dst[0x21];
    else
        v = (*(unsigned short *)(dst + 0x1E) - 1) * dst[0x21];
    *(int *)(dst + 0x28) = v;
    dst[0x2C] = 1;
    dst[0x2E] = src[0];
    *(unsigned short *)(dst + 0x30) = *(unsigned short *)(src + 2);
    *(unsigned short *)(dst + 0x32) = *(unsigned short *)(src + 4);
    *(unsigned short *)(dst + 0x34) = *(unsigned short *)(src + 6);
    *(unsigned short *)(dst + 0x36) = *(unsigned short *)(src + 8);
    *(int *)(dst + 0x38) = dst[0x20] * *(unsigned short *)(dst + 0x1C);
    *(int *)(dst + 0x3C) = dst[0x21] * *(unsigned short *)(dst + 0x1E);
    *(int *)(dst + 0x40) = src[0x15C8] * *(unsigned short *)(dst + 0x1C);
    *(int *)(dst + 0x44) = src[0x15C9] * *(unsigned short *)(dst + 0x1E);
}
