#pragma force_active on
typedef unsigned char u8;
typedef unsigned long u32;

extern u32 lbl_8042B858[];

extern "C" {
u8 fn_80051F10(u8 idx) {
    return (u8)lbl_8042B858[idx];
}
}
