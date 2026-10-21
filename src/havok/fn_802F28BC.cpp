#pragma force_active on
typedef int s32;
typedef signed char s8;

struct Triple {
    s32 x, y, z;
};

extern "C" {
extern Triple lbl_80488624;

void fn_802F291C(s32, s32, s32, s32, Triple*, s32);

void fn_802F28BC(s32 a, s32 b, s32 c, unsigned char* obj, s8* flag) {
    if (*flag == 0) {
        Triple buf = lbl_80488624;
        fn_802F291C(a, b, c, *(s32*)(obj + 0x68), &buf, 0);
    }
}
}
