#pragma force_active on
struct Inner {
    char pad[0xDC];
    float a;
    float b;
    float c;
};

struct Outer {
    char pad[0x10];
    Inner* inner;
};

extern "C" void fn_800B6E84(float* dst, Outer* src) {
    Inner* t = src->inner;
    if (dst != 0) {
        dst[0] = t->a;
    }
    if (dst + 1 != 0) {
        dst[1] = t->b;
    }
    if (dst + 2 != 0) {
        dst[2] = t->c;
    }
}
