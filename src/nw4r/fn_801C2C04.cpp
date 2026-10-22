#pragma force_active on

typedef unsigned char u8;
typedef signed char s8;

extern "C" {
void fn_801C2244(void*);
extern u8 lbl_804C1D00[0x2D8];
extern u8 lbl_805A05A0;

void* fn_801C2C04() {
    u8* base;
    if ((s8)lbl_805A05A0 == 0) {
        base = lbl_804C1D00;
        base[0] = 0;
        u8* p = base + 0x38;
        do {
            fn_801C2244(p);
            p += 0xA8;
        } while (p < base + 0x2D8);
        *(int*)(base + 0x70) = 0;
        *(int*)(base + 0x118) = 1;
        *(int*)(base + 0x1C0) = 2;
        *(int*)(base + 0x268) = 3;
        lbl_805A05A0 = 1;
    }
    return lbl_804C1D00;
}
}
