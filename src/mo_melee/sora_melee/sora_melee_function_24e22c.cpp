#pragma force_active on
struct Inner {
    char pad[0xF];
    unsigned char flag;
};

struct Outer {
    char pad[0x18];
    Inner* inner;
};

extern Outer* g_GameGlobal;

extern "C" unsigned int fn_27_24E22C() {
    Inner* p = g_GameGlobal->inner;
    if (p == 0) {
        return 0;
    }
    return (unsigned int)(1 - (int)p->flag) >> 31;
}
