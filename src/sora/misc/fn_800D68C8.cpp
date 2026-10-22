#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

extern "C" u8 fn_800C8548();

extern "C" s32 fn_800D68C8(char* arg0, s8* arg1) {
    u8 idx = fn_800C8548();
    char* p;
    if (idx == 0xFF) {
        p = 0;
    } else {
        p = arg0 + idx * 0x218 + 0x70;
    }
    if (p == 0 || (*(s32*)(arg0 + 0xFCC) >> 24) < 3) {
        return -1;
    }
    if (arg1 != 0) {
        *arg1 = (p[0x56] >> 2) & 1;
    }
    return *(s32*)(p + 8);
}
