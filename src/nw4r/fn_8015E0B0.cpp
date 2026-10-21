#pragma force_active on
struct Inner {
    unsigned char pad[0x3];
    unsigned char value;
};

struct Mid {
    unsigned char pad[0x8];
    Inner *inner;
};

struct Outer {
    unsigned char pad[0x14];
    Mid *mid;
};

extern "C" unsigned char fn_8015E0B0(Outer *a) {
    return a->mid->inner->value;
}
