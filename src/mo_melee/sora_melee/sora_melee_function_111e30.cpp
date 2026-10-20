#pragma force_active on
typedef unsigned char u8;

struct Inner {
    char pad[0x1c];
    u8 a : 1;
    u8 flag : 1;
    u8 b : 6;
};

struct Outer {
    Inner *inner;
};

extern "C" {
bool fn_27_111E30(Outer *p) {
    return p->inner->flag;
}
}
