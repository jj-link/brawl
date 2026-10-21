#pragma force_active on
typedef int s32;
typedef unsigned char u8;

extern s32 fn_803D5EC8(void* p);
extern void fn_803D6008(s32 a, void* p);

s32 fn_803D60FC(s32 arg0) {
    u8 sp8[0x50];
    s32 temp_r3;

    temp_r3 = fn_803D5EC8(sp8);
    if (temp_r3 == 0) {
        fn_803D6008(arg0, sp8);
    }
    return temp_r3;
}
