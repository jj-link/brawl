#pragma force_active on
typedef unsigned char u8;

struct Inner {
    char pad[0x1c];
    u8 a : 4;
    u8 b : 1;
    u8 c : 3;
};

struct Outer {
    Inner* inner;
};

extern "C" bool fn_27_111DD0(Outer* o) {
    return o->inner->b;
}
