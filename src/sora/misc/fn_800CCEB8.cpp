#pragma force_active on
typedef unsigned char u8;

extern void* lbl_805A0434;

extern "C" {
u8 fn_800CCEB8(void) {
    return *(u8*)((char*)lbl_805A0434 + 0x33F6);
}
}
