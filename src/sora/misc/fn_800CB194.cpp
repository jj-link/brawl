#include <types.h>
#pragma force_active on

extern "C" u8 fn_800C8548();
extern "C" void netReport__FPCce(const char*, ...);
extern char lbl_80457A48[];
extern char lbl_80457A74[];

extern "C" u8 fn_800CB194(char* self, s32 arg) {
    u8 idx = fn_800C8548();
    char* p;
    char* q;
    if (idx == 0xFF) {
        p = 0;
    } else {
        p = self + (s32)idx * 0x218 + 0x70;
    }
    if (p == 0) {
        netReport__FPCce(lbl_80457A48);
        q = 0;
    } else if (!((((u8)p[0x78]) >> 5) & 1)) {
        netReport__FPCce(lbl_80457A74);
        q = 0;
    } else {
        q = p + arg * 0xA + 0xE4;
    }
    if (q == 0) {
        return 0xFF;
    }
    return (u8)q[1];
}
