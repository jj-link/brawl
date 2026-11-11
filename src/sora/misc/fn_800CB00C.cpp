#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern "C" u8 fn_800C8548();
extern "C" u8 fn_800C851C();
extern "C" void netReport__FPCce(const char*, ...);
extern "C" void fn_8014B130(int);

extern char lbl_80457A10[];

struct Entry {
    char raw[0x218];
};

struct Parent {
    char pad[0x70];
    Entry entries[5];
};

extern "C" s32 fn_800CB00C(u8* base) {
    if (!((base[0xFC9] >> 4) & 1)) {
        return 0;
    }
    u8 idx = fn_800C8548();
    u8* p;
    if (idx == 0xFF) {
        p = 0;
    } else {
        p = (u8*)&((Parent*)base)->entries[idx];
    }
    if (p == 0) {
        netReport__FPCce(lbl_80457A10);
        fn_8014B130(0xC);
        return 0;
    }
    if ((p[0x78] >> 5) & 1) {
        u8 r3 = fn_800C851C();
        if (r3 == 0xFF) {
            r3 = 4;
        }
        (base + r3 * 0x218)[0x73] = p[3];
    }
    return (p[0x78] >> 5) & 1;
}
