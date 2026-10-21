#pragma force_active on
typedef unsigned short u16;
typedef int s32;

s32 fn_803D6504(u16 *arg0) {
    u16 *p = arg0;
    while (*p != 0) {
        p++;
    }
    return (s32)((char*)p - (char*)arg0) >> 1;
}
