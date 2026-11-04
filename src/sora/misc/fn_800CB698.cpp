#include <types.h>
#pragma force_active on
extern "C" u8 fn_800C8548();
extern "C" void netReport__FPCce(const char*, ...);
extern char lbl_80457A48[];
extern char lbl_80457A74[];
extern "C" u16 fn_800CB698(char* self, s32 arg) {
    u8 idx = fn_800C8548();
    char* p;
    char* q;
    if (idx == 0xFF) {
        p = 0;
    } else {
        p = self + idx * 0x218 + 0x70;
    }
    if (p == 0) {
        netReport__FPCce(lbl_80457A48);
        q = 0;
    } else if (!((p[0x78] >> 5) & 1)) {
        netReport__FPCce(lbl_80457A74);
        q = 0;
    } else {
        q = p + arg * 0xA + 0xE4;
    }
    if (q == 0) return 0;
    if ((u8)self[0x1028] == 0) return 0;
    return *(u16*)(q + 8);
}