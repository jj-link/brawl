#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

extern "C" u8 fn_800C8548();
extern "C" void netReport__FPCce(const char*, ...);

extern char lbl_80457A48[];
extern char lbl_80457A74[];

extern "C" u8 fn_800CB568(u8* arg0, u32 arg1) {
    u8 idx = fn_800C8548();
    u8* p;
    u8* r;
    if (idx == 0xFF) {
        p = 0;
    } else {
        p = arg0 + idx * 0x218 + 0x70;
    }
    if (p == 0) {
        netReport__FPCce(lbl_80457A48);
        r = 0;
    } else if (!((p[0x78] >> 5) & 1)) {
        netReport__FPCce(lbl_80457A74);
        r = 0;
    } else {
        r = p + arg1 * 0xA + 0xE4;
    }
    if (r != 0) {
        return r[4];
    }
    return 0;
}
