#pragma force_active on
struct Inner {
    unsigned char pad[0x48f];
    unsigned char flag;
};

struct Outer {
    Inner* inner;
};

extern "C" {
unsigned int fn_27_112E60(Outer* o) {
    unsigned int v = o->inner->flag;
    return (unsigned int)(-v | v) >> 31;
}
}
