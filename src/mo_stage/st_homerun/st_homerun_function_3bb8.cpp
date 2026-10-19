#pragma force_active on
struct Inner {
    char pad[0x63];
    unsigned char b;
};

struct Outer {
    char pad[8];
    Inner *p;
};

extern Outer *g_GameGlobal;

extern "C" unsigned char fn_88_3BB8() {
    Inner *i = g_GameGlobal->p;
    if (i == 0) {
        return 0;
    }
    return i->b;
}
