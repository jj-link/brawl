#pragma force_active on

struct Object {
    int value;
    char padding[0x9C];
};

extern "C" void fn_802F031C(Object*, int*);

extern "C" int fn_802F0094() {
    Object a __attribute__((aligned(16)));
    int b __attribute__((aligned(16)));
    int zero = 0;
    if (&a != 0) {
        b = zero;
        fn_802F031C(&a, &b);
    }
    return a.value;
}
