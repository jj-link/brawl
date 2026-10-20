#pragma force_active on
struct Inner {
    char pad[0x64];
    int value;
};

struct Outer {
    char pad[0xd8];
    Inner* inner;
};

extern "C" int fn_27_2DA3C0(Outer* outer) {
    return outer->inner->value;
}
