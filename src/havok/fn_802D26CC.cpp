#pragma force_active on

struct Object {
    int value;
    char padding[0x5C];
};

extern "C" void __ct__14Class_802D279CFv(Object*, int*);

extern "C" int fn_802D26CC() {
    Object a __attribute__((aligned(16)));
    int b __attribute__((aligned(16)));
    int zero = 0;
    if (&a != 0) {
        b = zero;
        __ct__14Class_802D279CFv(&a, &b);
    }
    return a.value;
}
