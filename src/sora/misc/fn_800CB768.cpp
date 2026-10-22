#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" u8 fn_800C8548();
extern "C" void netReport__FPCce(const char*, ...);
extern char lbl_80457A48[];
extern char lbl_80457A74[];

extern "C" u8 fn_800CB768(char* self, u32 arg1) {
    u8 idx = fn_800C8548();
    char* p;
    if (idx == 0xFF) {
        p = 0;
    } else {
        p = self + idx * 0x218 + 0x70;
    }
    char* q;
    if (p == 0) {
        netReport__FPCce(lbl_80457A48);
        q = 0;
    } else if (!(((u8)p[0x78] >> 5) & 1)) {
        netReport__FPCce(lbl_80457A74);
        q = 0;
    } else {
        q = p + arg1 * 10 + 0xE4;
    }
    if (q != 0) {
        return (u8)q[6];
    }
    return 0;
}
