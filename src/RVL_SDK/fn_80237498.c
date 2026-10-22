#pragma force_active on
extern void *fn_8022EE58(unsigned short size);
extern void fn_80232034(unsigned char *dst, const unsigned char *src);
extern void fn_802324E0(void *arg);
extern void *memcpy(void *dst, const void *src, unsigned long n);
extern void *memset(void *dst, int c, unsigned long n);

void fn_80237498(const unsigned char *arg0, short arg1, unsigned char arg2, unsigned char arg3, const void *arg4)
{
    unsigned char *temp_r31;

    temp_r31 = (unsigned char *)fn_8022EE58(0x1C);
    if (temp_r31 != 0) {
        memset(temp_r31, 0, 0x1C);
        *(short *)(temp_r31 + 0x0) = 0x170A;
        *(short *)(temp_r31 + 0x10) = 0xB;
        *(short *)(temp_r31 + 0x6) = 0xFF;
        *(short *)(temp_r31 + 0xE) = arg1;
        temp_r31[0x12] = arg2;
        temp_r31[0x13] = arg3;
        memcpy(temp_r31 + 0x14, arg4, 8);
        fn_80232034(temp_r31 + 8, arg0);
        fn_802324E0(temp_r31);
    }
}
