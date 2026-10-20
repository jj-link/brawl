#pragma force_active on
struct Inner {
    char pad[0x1f];
    unsigned char flag;
};

struct Outer {
    Inner* inner;
};

extern "C" {
bool fn_27_111F00(Outer* o) {
    unsigned int b = o->inner->flag;
    return ((b & 0x80) >> 7) != 0;
}
}
