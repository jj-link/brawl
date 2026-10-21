#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" void fn_27_11FADC(u8* arg0, s32 arg1) {
    u8 i = 0;
    s32 n;
    u8* p;
    for (n = 0; n < 2; n++) {
        p = arg0 + i * 0x30;
        if (*(s32*)(p + 0x338) != -1 && arg1 == *(s32*)(p + 0x330)) {
            p[0x33C] = 1;
        }
        i++;
        p = arg0 + i * 0x30;
        if (*(s32*)(p + 0x338) != -1 && arg1 == *(s32*)(p + 0x330)) {
            p[0x33C] = 1;
        }
        i++;
        p = arg0 + i * 0x30;
        if (*(s32*)(p + 0x338) != -1 && arg1 == *(s32*)(p + 0x330)) {
            p[0x33C] = 1;
        }
        i++;
        p = arg0 + i * 0x30;
        if (*(s32*)(p + 0x338) != -1 && arg1 == *(s32*)(p + 0x330)) {
            p[0x33C] = 1;
        }
        i++;
    }
}
