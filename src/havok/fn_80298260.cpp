#pragma force_active on

typedef signed int s32;
typedef unsigned char u8;

extern "C" {
s32 fn_80298260(u8 *arg0, s32 arg1) {
    return ((s32)*arg0 >> (arg1 * 2)) & 3;
}
}
