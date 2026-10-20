#pragma force_active on
struct Inner {
    char pad[0x2c];
    float f;
};

struct Outer {
    Inner *ptr;
};

extern "C" float fn_27_1118A0(const Outer *o) {
    return o->ptr->f;
}
