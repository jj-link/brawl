#pragma force_active on
typedef unsigned char u8;
typedef int s32;
typedef unsigned long u32;

extern char lbl_80529CF8[];
void* memcpy(void* dst, const void* src, u32 n);
void* fn_8022EFF8(s32);
void fn_802465B4(void* a, void* b);

s32 fn_8023B3A4(void* arg0) {
    void* p;
    memcpy(lbl_80529CF8 + 0x648, arg0, 3);
    if (*(u8*)(lbl_80529CF8 + 0x64E) <= 1) {
        return 0xC;
    }
    p = fn_8022EFF8(2);
    if (p != 0) {
        fn_802465B4(p, arg0);
        return 0;
    }
    return 3;
}
