#pragma force_active on
extern void *fn_8022EE58(unsigned short size);
extern void fn_80232034(unsigned char *dst, const unsigned char *src);
extern void fn_802324E0(void *arg);

void fn_8023584C(const unsigned char *arg0, unsigned char arg1, unsigned short arg2, unsigned char arg3) {
    unsigned char *temp_r3;

    temp_r3 = (unsigned char *)fn_8022EE58(0x14);
    if (temp_r3 != 0) {
        *(unsigned short *)temp_r3 = 0x109;
        temp_r3[0xE] = arg1;
        *(unsigned short *)(temp_r3 + 0x10) = arg2;
        temp_r3[0x12] = arg3;
        fn_80232034(temp_r3 + 8, arg0);
        fn_802324E0(temp_r3);
    }
}
