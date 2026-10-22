#pragma force_active on

struct Value {
    void* ptr;
    char pad[0x54];
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    char pad2[0x20];
    int g;
    int h;
    int i;
};

extern "C" void fn_802F0438(Value*, int*);
extern "C" int lbl_80488220[];

extern "C" void* fn_802E7904() {
    Value v __attribute__((aligned(16)));
    int in;
    int zero = 0;
    if (&v != 0) {
        in = zero;
        fn_802F0438(&v, &in);
        v.a = zero;
        v.b = zero;
        v.c = 0x80000000;
        v.d = zero;
        v.e = zero;
        v.f = 0x80000000;
        v.ptr = lbl_80488220;
        v.g = zero;
        v.h = zero;
        v.i = 0x80000000;
    }
    return v.ptr;
}
