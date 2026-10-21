#pragma force_active on
struct Inner {
    char pad[0x18];
    int b;
};

struct Outer {
    char pad[0x78];
    Inner* c;
};

extern "C" int fn_800DCE0C(Outer* o) {
    return o->c->b;
}
