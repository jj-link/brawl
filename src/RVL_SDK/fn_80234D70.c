#pragma force_active on
extern void *fn_8022EE58(unsigned short size);
extern void fn_80232034(unsigned char *dst, const unsigned char *src);
extern void fn_802324E0(void *arg);
extern void *memcpy(void *dst, const void *src, unsigned long n);

void fn_80234D70(const unsigned char *arg0, unsigned char arg1, unsigned char arg2, const unsigned char *arg3) {
    unsigned char *temp_r3;

    temp_r3 = (unsigned char *)fn_8022EE58(0x20);
    if (temp_r3 != 0) {
        *(unsigned short *)temp_r3 = 0x107;
        fn_80232034(temp_r3 + 8, arg0);
        temp_r3[0xE] = arg1;
        if (arg1 != 0) {
            temp_r3[0xF] = arg2;
            memcpy(temp_r3 + 0x10, arg3, arg2);
        }
        fn_802324E0(temp_r3);
    }
}
