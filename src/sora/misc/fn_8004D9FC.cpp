#pragma force_active on
struct Inner {
    char pad[0x82a];
    unsigned char field;
};

struct Outer {
    char pad[0x24];
    Inner* inner;
};

extern "C" int fn_8004D9FC(Outer* obj) {
    return obj->inner->field == 1;
}
