#pragma force_active on
struct Inner {
    unsigned char pad[0x98];
    unsigned char a0;
    unsigned char b0;
    unsigned char pad1[0xF4 - 0x9A];
    unsigned char a1;
    unsigned char b1;
    unsigned char pad2[0x150 - 0xF6];
    unsigned char a2;
    unsigned char b2;
    unsigned char pad3[0x1AC - 0x152];
    unsigned char a3;
    unsigned char b3;
};
struct Global {
    int x0, x4;
    Inner* inner;
};
extern Global* g_GameGlobal;

#define CHK(a, b) \
    if (p->b != 3) { \
        unsigned char k = p->a; \
        if (k == 0x1d) return 1; \
        if (k == 0x1f) return 1; \
        if (k == 0x21) return 1; \
    }

extern "C" int fn_27_2249E0() {
    Inner* p = g_GameGlobal->inner;
    CHK(a0, b0)
    CHK(a1, b1)
    CHK(a2, b2)
    CHK(a3, b3)
    return 0;
}