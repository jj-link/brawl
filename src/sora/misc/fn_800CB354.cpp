#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" u8 fn_800C8548();
extern "C" u8 fn_800C851C();
extern "C" void netReport__FPCce(const char*, ...);
extern char lbl_80457A48[];
extern char lbl_80457A74[];

extern "C" u8 fn_800CB354(u8* self, u32 arg1) {
    u8 idx = fn_800C8548();
    u8* p;
    if (idx == 0xFF) {
        p = 0;
    } else {
        p = self + idx * 0x218 + 0x70;
    }
    u8* q;
    if (p == 0) {
        netReport__FPCce(lbl_80457A48);
        q = 0;
    } else if (!((p[0x78] >> 5) & 1)) {
        netReport__FPCce(lbl_80457A74);
        q = 0;
    } else {
        p += arg1 * 10;
        q = p + 0xE4;
    }
    if (q == 0) {
        return 0;
    }
    u8 a = fn_800C851C();
    if (a == 0xFF) {
        a = 4;
    }
    u8 b = q[2];
    for (int i = 0; i < 4; i++) {
        u8* e = self + 0x4C + i * 8;
        if (a == e[0] && b == e[1]) return e[2];
    }
    return 0;
}
