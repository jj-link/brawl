#pragma force_active on
typedef unsigned char u8;

struct Flags {
    u8 a : 2;
    u8 b : 1;
    u8 c : 5;
};

struct Inner {
    u8 pad[0x1c];
    Flags flags;
};

struct Outer {
    Inner* inner;
};

extern "C" bool fn_27_111E60(Outer* outer) {
    return outer->inner->flags.b;
}
