#pragma force_active on
struct Inner {
    unsigned char pad[0x38];
    unsigned short value;
};

struct Outer {
    unsigned char pad[0x20];
    Inner *inner;
};

extern "C" unsigned short fn_8000D518(Outer *arg0) {
    return arg0->inner->value;
}
