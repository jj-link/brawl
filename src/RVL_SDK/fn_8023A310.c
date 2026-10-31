#pragma force_active on

extern char lbl_80529CF8[];
extern char lbl_8059EDF8;
extern void *memcpy(void *dst, const void *src, unsigned long size);
extern void fn_80231FB0(void *p, int a, int b);
extern void fn_80245D40(void);

void fn_8023A310(void)
{
    char *base = lbl_80529CF8;

    memcpy(base + 0x648, &lbl_8059EDF8, 3);
    *(short *)(base + 0x64C) = 0x1400;
    *(int *)(base + 0x584) = 1;
    *(int *)(base + 0x5A0) = 2;
    *(int *)(base + 0x5BC) = 4;
    *(unsigned short *)(base + 0x654) = 0xCC18;
    *(short *)(base + 0x656) = 0x3F;
    *(unsigned char *)(base + 0x27BD) = 0xFF;
    *(unsigned char *)(base + 0x27BE) = 0xFF;
    *(unsigned char *)(base + 0x64E) = 0;
    *(unsigned char *)(base + 0x64F) = 5;
    fn_80231FB0(base + 0x574, 1, 4);
    fn_80245D40();
}
