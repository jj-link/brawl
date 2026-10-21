#pragma force_active on
struct Inner {
    char pad[0x10];
    float f10;
    float f14;
};

struct Outer {
    char pad[8];
    struct Inner* inner;
};

struct Src {
    char pad[8];
    float f8;
};

extern "C" {
void fn_802F073C(struct Src* arg0, struct Outer* arg1) {
    arg1->inner->f10 = arg0->f8;
    arg1->inner->f14 = arg0->f8;
}
}
