#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern "C" u8 fn_800C8548();
extern "C" void netReport__FPCce(const char*, ...);

extern char lbl_80457A48[];
extern char lbl_80457A74[];

extern "C" u8 fn_800CB0D8(u8* base, s32 idx) {
    u8 i = fn_800C8548();
    u8* p;
    if (i == 0xff) {
        p = 0;
    } else {
        p = base + i * 0x218 + 0x70;
    }
    if (p == 0) {
        netReport__FPCce(lbl_80457A48);
        p = 0;
    } else if (!((p[0x78] >> 5) & 1)) {
        netReport__FPCce(lbl_80457A74);
        p = 0;
    } else {
        p = p + idx * 0xA + 0xE4;
    }
    if (p == 0) return 3;
    return *p;
}
