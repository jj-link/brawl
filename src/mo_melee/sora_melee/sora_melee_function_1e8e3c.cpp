#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

extern u8 lbl_27_data_47BF8;

extern "C" u32 fn_27_1E8E3C(void) {
    s32 x = (signed char)lbl_27_data_47BF8;
    return (u32)((-x) & ~x) >> 31;
}
